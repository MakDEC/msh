/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : print_last_screen.c                                            **
**                                                                            **
**		License :                                                             **
**                      This file is part of Msh                              **
**		  Msh is free software: you can redistribute it and/or modify         **
**	  it under the terms of the GNU General Public License as published by    **
**	  the Free Software Foundation, version 3.                                **
**	    Msh is distributed in the hope that it will be useful,                **
**	  but WITHOUT ANY WARRANTY; without even the implied warranty of          **
**	  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **
**	  GNU General Public License for more details.                            **
**	    You should have received a copy of the GNU General Public License     **
**	  along with Msh.  If not, see <https://www.gnu.org/licenses/>.           **
**                                                                            **
**		Copyright 2020 - Antoine Anger                                        **
**                                                                            **
********************************************************************************
***************************************************************************//**/

#include "cursor_management.h"
#include <stdlib.h>
#include <unistd.h>


static int		calc_end_of_line_gap(
					t_line_edition_data *line_edition_data)
{
	int			last_screen_input_size;
	int			return_value;

	last_screen_input_size =
			((line_edition_data->prompt_size
					% (line_edition_data->available_column))
				+ line_edition_data->total_input_size)
			% line_edition_data->available_column; 
	return_value = (line_edition_data->available_column - last_screen_input_size);
	return (return_value);
}

static int					prepare_temp_data(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data)
{
	if (!(temp_data->buffer = (char *)malloc(sizeof(char) * (line_edition_data->screen_size + 1))))
		exit (-1);
	temp_data->buffer[line_edition_data->screen_size] = 0;
	temp_data->buffer_index = line_edition_data->screen_size - 1;
	return (0);
}

static int					change_current_line_and_column(
								t_line_edition_data *line_edition_data,
								int end_of_line_gap)
{
	line_edition_data->current_column = line_edition_data->available_column - end_of_line_gap;
	line_edition_data->current_line = line_edition_data->available_line - 1;
	return (0);
}

static int					finish_to_fill_with_prompt(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data)
{
	temp_data->temp_index = line_edition_data->prompt_size - 1;
	while (temp_data->buffer_index >= 0)
	{
		temp_data->buffer[temp_data->buffer_index] = line_edition_data->prompt[temp_data->temp_index--];
		temp_data->buffer_index--;
	}
	return (0);
}

static int					fill_new_buffer(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data,
								int end_of_line_gap)
{
	while (--end_of_line_gap >= 0)
	{
		temp_data->buffer[temp_data->buffer_index] = ' ';
		temp_data->buffer_index--;
	}
	temp_data->temp_buffers_case = line_edition_data->current_buffer;
	temp_data->temp_index = temp_data->temp_buffers_case->buffer_index - 1;
	while (temp_data->buffer_index >= 0)
	{
		if (temp_data->temp_index < 0)
		{
			temp_data->temp_buffers_case = temp_data->temp_buffers_case->previous;
			if (temp_data->temp_buffers_case == NULL)
					break ;
			temp_data->temp_index = temp_data->temp_buffers_case->buffer_size - 1;
		}
		else
		{
			temp_data->buffer[temp_data->buffer_index] = temp_data->temp_buffers_case->buffer[temp_data->temp_index--];
			temp_data->buffer_index--;
		}
	}
	if (temp_data->buffer_index >= 0)
		finish_to_fill_with_prompt(
			line_edition_data,
			temp_data);
	return (0);

}

int							print_last_screen(
								t_line_edition_data *line_edition_data)
{
	int						end_of_line_gap;
	t_new_line_temp_buffer	temp_data;
	
	move_cursor_to(0, 0);
	end_of_line_gap = calc_end_of_line_gap(line_edition_data);
	prepare_temp_data(
		line_edition_data,
		&temp_data);
	change_current_line_and_column(
		line_edition_data,
		end_of_line_gap);
	fill_new_buffer(
		line_edition_data,
		&temp_data,
		end_of_line_gap);
	write(1, temp_data.buffer, line_edition_data->screen_size);
	move_cursor_to(line_edition_data->current_line, line_edition_data->current_column);
	return (0);
}
