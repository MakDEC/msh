/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : go_to_beginning_of_buffers_list_and_return_moves_needed.c      **
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

int				go_to_beginning_of_buffers_list_and_return_moves_needed(
					t_line_edition_data *line_edition_data)
{
	int			moves;
	
	moves = 0;
	while (line_edition_data->current_buffer != NULL)
	{
		moves += line_edition_data->current_buffer->buffer_index;
		line_edition_data->current_buffer->buffer_index = 0;
		line_edition_data->current_buffer = line_edition_data->current_buffer->previous;
	}
	line_edition_data->current_buffer = line_edition_data->first_buffer;
	return (moves);
}
