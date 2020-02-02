/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : scroll_line_up_and_print_previous_line.c                       **
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

#include "display_management.h"
#include "libft.h"

static int					prepare_new_line_buffer_control_variables(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data)
{
	temp_data->buffer_index = line_edition_data->available_column - 1;
	if (!(temp_data->buffer =
			(char *)malloc(sizeof(char) * temp_data->buffer_index + 1)))
		exit (-1);
	ft_bzero(temp_data->buffer, (temp_data->buffer_index + 1));
	temp_data->temp_index = line_edition_data->current_buffer->buffer_index;
	temp_data->temp_buffers_case = line_edition_data->current_buffer;
	return (0);
}

int							scroll_line_up_and_print_previous_line(
								t_line_edition_data *line_edition_data)
{
	t_new_line_temp_buffer	temp_data;

	prepare_new_line_buffer_control_variables(
		line_edition_data,
		&temp_data);
	fill_buffer_with_previous_line(line_edition_data, &temp_data);
	free(temp_data.buffer);
	return (0);
}
