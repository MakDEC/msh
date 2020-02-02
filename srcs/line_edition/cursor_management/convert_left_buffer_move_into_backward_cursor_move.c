/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : convert_left_buffer_move_into_backward_cursor_move.c           **
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

int				convert_left_buffer_move_into_backward_cursor_move(
					t_line_edition_data *line_edition_data,
					int moves)
{
	int			vertical_move;
	int			horizontal_move;

	vertical_move = moves / line_edition_data->available_column;
	horizontal_move = moves % line_edition_data->available_column;
	if (line_edition_data->current_column < horizontal_move)
	{
			line_edition_data->current_line--;
			horizontal_move -= line_edition_data->current_column;
			line_edition_data->current_column = line_edition_data->available_column;
	}
	line_edition_data->current_column = line_edition_data->current_column - horizontal_move;
	line_edition_data->current_line = line_edition_data->current_line - vertical_move;
	move_cursor_to(line_edition_data->current_line, line_edition_data->current_column);
	line_edition_data->global_index = 0;
	return (0);
}

