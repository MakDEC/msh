/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : history.h                                                      **
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

#ifndef HISTORY_H
# define HISTORY_H

# include "line_edition_struct.h"

int							add_to_history(
								t_line_edition_data *line_edition_data);

t_history_case				*create_history_case(
								t_buffers_list *command_to_save,
								t_history_case *next_case);

int							create_history_data(
								t_line_edition_data *line_edition_data);

int							export_current_history_case_as_current_buffer_case(
								t_line_edition_data *line_edition_data);

int							free_history(
								t_history_data *history_data);

int							load_next_history_case(
								t_line_edition_data *line_edition_data);

int							previous_history_management(
								t_line_edition_data *line_edition_data);

void						get_screen_size(
								t_line_edition_data *line_edition_data);

#endif
