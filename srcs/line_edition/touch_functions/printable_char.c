/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : printable_char.c                                               **
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

#include "le_buffers_management.h"
#include "display_management.h"
#include "history.h"
#include <unistd.h>

static int			check_last_column(
						t_line_edition_data *line_edition_data)
{
	if (line_edition_data->current_column != line_edition_data->available_column)
		return (0);
	line_edition_data->current_column = 0;
	if (line_edition_data->available_line - 1  > line_edition_data->current_line)
		line_edition_data->current_line++;
	write(1, "\n", 1);
	return (0);
}

int					add_char_in_buffers(
						t_line_edition_data *line_edition_data,
						char buffer)
{
	if (CURRENT_BUFFER[CURRENT_BUFFER_INDEX] != 0)
		split_buffer(line_edition_data);
	CURRENT_BUFFER[CURRENT_BUFFER_INDEX] = buffer;
	return (0);
}

/* si on ajoute au debut d un buffer ca decale les index parce que la taille va augmenter alors qu un strlen lavait deja bien definie */

int					change_buffers_data_values_next_to_adding_char(
						t_line_edition_data *line_edition_data)
{
	line_edition_data->current_buffer->buffer_size++;
	line_edition_data->current_buffer->buffer_index++;
	line_edition_data->total_input_size++;
	line_edition_data->current_column++;
	line_edition_data->global_index++;
	return (0);
}

static int			display_rest_of_buffers(
						t_line_edition_data *line_edition_data)
{
	if (line_edition_data->current_buffer->
			buffer[line_edition_data->current_buffer->buffer_index] != 0
			|| line_edition_data->current_buffer->next != NULL)
	{
		display_rest_of_buffers_in_available_space(
			line_edition_data,
			line_edition_data->current_buffer);
	}
	return (0);
}

int					printable_character_input(
						t_line_edition_data *line_edition_data,
						char buffer)
{
	if (CURRENT_HISTORY_CASE != NULL)
		export_current_history_case_as_current_buffer_case(line_edition_data);
	add_char_in_buffers(line_edition_data, buffer);
	change_buffers_data_values_next_to_adding_char(line_edition_data);
	write(1, &buffer, 1);
	check_last_column(line_edition_data);
	display_rest_of_buffers(line_edition_data);
	check_current_buffer_size(line_edition_data);
	return (0);
}
