/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : replace_cursor_to_beginning.c                                  **
**                                                                            **
**		License :                                                             **
**                      This file is part of DevOps Shell                     **
**		  Dosh is free software: you can redistribute it and/or modify        **
**	  it under the terms of the GNU General Public License as published by    **
**	  the Free Software Foundation, version 3.                                **
**	    Msh is distributed in the hope that it will be useful,                **
**	  but WITHOUT ANY WARRANTY; without even the implied warranty of          **
**	  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **
**	  GNU General Public License for more details.                            **
**	    You should have received a copy of the GNU General Public License     **
**	  along with Dosh.  If not, see <https://www.gnu.org/licenses/>.          **
**                                                                            **
**		Copyright 2020 - Antoine Anger                                        **
**                                                                            **
********************************************************************************
***************************************************************************//**/

#include "cursor_management.h"
#include "le_buffers_management.h"
#include "terminal_interaction.h"
#include <unistd.h>

static int		replace_cursor_to_top_screen_and_print_prompt(
					t_line_edition_data *line_edition_data)
{
	move_cursor_to(0, 0);
	write(2, line_edition_data->prompt, line_edition_data->prompt_size);
	save_first_cursor_position(line_edition_data);
	return (0);
}

static int		check_if_input_bigger_than_screen(
					t_line_edition_data *line_edition_data)
{
	int			space_needed;
	int			available_space;
	
	space_needed = line_edition_data->total_input_size + line_edition_data->prompt_size;
	available_space = line_edition_data->available_column * line_edition_data->available_line;
	if (space_needed > available_space && (line_edition_data->global_index + line_edition_data->prompt_size) >= available_space)
	{
		replace_cursor_to_top_screen_and_print_prompt(line_edition_data);
		line_edition_data->global_index = 0;
		return (1);
	}
	line_edition_data->global_index = 0;
	return (0);
}

int						replace_cursor_to_beginning(
							t_line_edition_data *line_edition_data)
{
	int					moves;

	moves = go_to_beginning_of_buffers_list_and_return_moves_needed(line_edition_data);
	if (check_if_input_bigger_than_screen(line_edition_data) != 0)
		return (0);
	convert_left_buffer_move_into_backward_cursor_move(line_edition_data, moves);
	return (0);
}
