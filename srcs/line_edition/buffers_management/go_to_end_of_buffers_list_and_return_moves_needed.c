/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : go_to_end_of_buffers_list_and_return_moves_needed.c            **
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

#include "line_edition_struct.h"
#include <stddef.h>

int					go_to_end_of_buffers_list_and_return_moves_needed(
						t_line_edition_data *line_edition_data)
{
	int				moves;
	t_buffers_list	*temp_case;

	moves = 0;
	moves += (line_edition_data->current_buffer->buffer_size - line_edition_data->current_buffer->buffer_index);
	line_edition_data->current_buffer->buffer_index = line_edition_data->current_buffer->buffer_size;
	temp_case = line_edition_data->current_buffer;
	line_edition_data->current_buffer = line_edition_data->current_buffer->next;
	while (line_edition_data->current_buffer != NULL)
	{
		moves += line_edition_data->current_buffer->buffer_size;
		line_edition_data->current_buffer->buffer_index = line_edition_data->current_buffer->buffer_size;
		temp_case = line_edition_data->current_buffer;
		line_edition_data->current_buffer = line_edition_data->current_buffer->next;
	}
	line_edition_data->current_buffer = temp_case;
	return (moves);
}
