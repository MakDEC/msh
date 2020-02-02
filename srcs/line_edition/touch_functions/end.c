/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : end.c                                                          **
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
#include "state_machine.h"
#include "le_buffers_management.h"
#include "cursor_management.h"

static int		check_if_reprint_is_needed(
					t_line_edition_data *line_edition_data,
					int	moves)
{
	int			space_needed;
	int			available_space;
	
	space_needed = line_edition_data->total_input_size + line_edition_data->prompt_size;
	available_space = line_edition_data->available_column * line_edition_data->available_line;
	if (space_needed > available_space
			&& (moves + (line_edition_data->current_column + (line_edition_data->current_line * line_edition_data->available_column))) > available_space)
	{
		print_last_screen(line_edition_data);
		line_edition_data->global_index = line_edition_data->total_input_size;
		return (1);
	}
	line_edition_data->global_index = line_edition_data->total_input_size;
	return (0);
}

int					end(
						t_line_edition_data *line_edition_data,
						char buffer)
{
	int				moves;

	change_state(line_edition_data, buffer);
	if (check_last_char(line_edition_data) != 0)
	{
		ring_bell();
		return (0);
	}
	moves = go_to_end_of_buffers_list_and_return_moves_needed(line_edition_data);
	if (check_if_reprint_is_needed(line_edition_data, moves) != 0)
		return (0);
	convert_right_buffer_move_into_frontward_cursor_move(
		line_edition_data,
		moves);
	return (0);
}
