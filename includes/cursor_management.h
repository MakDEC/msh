/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : cursor_management.h                                            **
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

#ifndef CURSOR_MANAGEMENT_H
# define CURSOR_MANAGEMENT_H

# include "line_edition_struct.h"

int							check_first_char(
								t_line_edition_data *line_edition_data);

int							check_first_line(
								t_line_edition_data *line_edition_data);

int							check_last_char(
								t_line_edition_data *line_edition_data);

int							check_last_line(
								t_line_edition_data *line_edition_data);

int							convert_right_buffer_move_into_frontward_cursor_move(
								t_line_edition_data *line_edition_data,
								int moves);

int							convert_left_buffer_move_into_backward_cursor_move(
								t_line_edition_data *line_edition_data,
								int moves);

int							get_available_space_until_end_of_screen(
								t_line_edition_data *line_edition_data);

int							go_to_beginning_of_next_line(
								t_line_edition_data *line_edition_data);

int							go_to_end_of_previous_line(
								t_line_edition_data *line_edition_data);

int							move_cursor_backward(
								int size_of_move);

int							move_cursor_to(
								int line,
								int column);

int							move_cursor_to_line_beginning(
								t_line_edition_data *line_edition_data);

int							reception(int c);

int							restore_cursor_position(void);

int							ring_bell();

int							replace_cursor_to_beginning(
								t_line_edition_data *line_edition_data);

int							save_cursor_position(void);

int							set_cursor_values(
								t_line_edition_data *line_edition_data);

int							scroll_line_up_and_print_previous_line(
								t_line_edition_data *line_edition_data);

int							simulate_end_touch(
								t_line_edition_data *line_edition_data);

#endif
