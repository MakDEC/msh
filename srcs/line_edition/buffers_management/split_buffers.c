/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : split_buffers.c                                                **
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
#include <stddef.h>

void	split_buffer(
			t_line_edition_data *line_edition_data)
{
	int	index;

	if (line_edition_data->current_buffer->next != NULL
			&& line_edition_data->current_buffer->next->buffer_size == 0)
		line_edition_data->current_buffer
			= line_edition_data->current_buffer->next;
	else
		line_edition_data->current_buffer->next
				= create_buffers_list_case(
					line_edition_data->current_buffer->next,
					line_edition_data->current_buffer,
					&CURRENT_BUFFER[CURRENT_BUFFER_INDEX]);
	index = CURRENT_BUFFER_INDEX - 1;
	while (line_edition_data->current_buffer->buffer[++index] != 0)
		line_edition_data->current_buffer->buffer[index] = 0;
	line_edition_data->current_buffer->buffer_size = line_edition_data->current_buffer->buffer_index;
}
