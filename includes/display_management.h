/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : display_management.h                                           **
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


#ifndef DISPLAY_MANAGEMENT_H
# define DISPLAY_MANAGEMENT_H

# include "line_edition_struct.h"

int							create_new_prompt(
								t_line_edition_data *line_edition_data);

int							display_rest_of_buffers_in_available_space(
								t_line_edition_data *line_edition_data,
								t_buffers_list	*buffers_case);

int							fill_buffer_with_previous_line(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data);

int							history_displayer(
								t_line_edition_data *line_edition_data);

int							print_first_line_with_prompt(
								t_line_edition_data *line_edition_data,
								char *buffer,
								int index);

int							print_first_screen(
								t_line_edition_data *line_edition_data);

int							print_last_screen(
								t_line_edition_data *line_edition_data);

int							print_previous_line(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data);

int							reprint_all_buffers_and_erase_rest(
								t_line_edition_data		*line_edition_data);

#endif
