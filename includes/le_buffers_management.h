/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : le_buffers_management.h                                        **
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

#ifndef LE_BUFFERS_MANAGEMENT_H
# define LE_BUFFERS_MANAGEMENT_H

# include "line_edition_struct.h"

int							add_char_in_buffers(
								t_line_edition_data *line_edition_data,
								char buffer);

int							change_buffers_and_control_variables_for_backward_move(
								t_line_edition_data *line_edition_data,
								int	number_of_moves);

int							change_buffers_and_control_variables_for_frontward_move(
								t_line_edition_data *line_edition_data,
								int	number_of_moves);

int							check_current_buffer_size(
								t_line_edition_data *line_edition_data);

int							check_empty_buffers(
								t_buffers_list *start_buffer);

t_buffers_list				*create_buffers_list_case(
								t_buffers_list *next_case,
								t_buffers_list *previous_case,
								char *string_to_copy);

int							compare_buffers_list(
								t_buffers_list *list1,
								t_buffers_list *list2);

t_buffers_list				*copy_buffers_list(
								t_buffers_list	*list_to_copy);

int							free_buffers_list(
								t_buffers_list *list_to_remove);

int							go_to_beginning_of_buffers_list_and_return_moves_needed(
								t_line_edition_data *line_edition_data);

int							go_to_end_of_buffers_list_and_return_moves_needed(
								t_line_edition_data *line_edition_data);

int							prepare_buffers_data(
								t_line_edition_data *line_edition_data);

int							set_global_input_size_and_reset_buffers_index(
								t_line_edition_data *line_edition_data);

void						split_buffer(
								t_line_edition_data *line_edition_data);

#endif
