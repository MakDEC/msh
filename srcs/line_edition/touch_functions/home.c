/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : home.c                                                         **
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
#include "display_management.h"
#include "state_machine.h"
#include "terminal_interaction.h"

static int		check_if_input_bigger_than_screen(
					t_line_edition_data *line_edition_data)
{
	int			space_needed;
	int			available_space;
	
	space_needed = line_edition_data->total_input_size + line_edition_data->prompt_size;
	available_space = line_edition_data->available_column * line_edition_data->available_line;
	if (space_needed > available_space && (line_edition_data->global_index + line_edition_data->prompt_size) >= available_space)
	{
		print_first_screen(line_edition_data);
		line_edition_data->global_index = 0;
		return (1);
	}
	line_edition_data->global_index = 0;
	return (0);
}

int				home(
					t_line_edition_data *line_edition_data,
					char buffer)
{
	int			moves;

	change_state(line_edition_data, buffer);
	if (check_first_char(line_edition_data) != 0)
		return (0);
	moves = go_to_beginning_of_buffers_list_and_return_moves_needed(line_edition_data);
	if (check_if_input_bigger_than_screen(line_edition_data) != 0)
		return (0);
	convert_left_buffer_move_into_backward_cursor_move(line_edition_data, moves);
	return (0);
}
