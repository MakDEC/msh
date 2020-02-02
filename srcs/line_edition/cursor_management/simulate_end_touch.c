/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : simulate_end_touch.c                                           **
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
#include "le_buffers_management.h"

int				simulate_end_touch(
					t_line_edition_data *line_edition_data)
{
	int				moves;
	
	moves = go_to_end_of_buffers_list_and_return_moves_needed(line_edition_data);
	convert_right_buffer_move_into_frontward_cursor_move(
		line_edition_data,
		moves);
	return (0);
}
