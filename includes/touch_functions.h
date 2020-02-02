/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : touch_functions.h                                              **
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

#ifndef TOUCH_FUNCTIONS_H
# define TOUCH_FUNCTIONS_H

#include "line_edition_struct.h"

int							backspace(
								t_line_edition_data *line_edition_data,
								char buffer);

int							control_c(
								t_line_edition_data *line_edition_data,
								char buffer);

int							control_d(
								t_line_edition_data *line_edition_data,
								char buffer);

int							control_z(
								t_line_edition_data *line_edition_data,
								char buffer);

int							deletion(
								t_line_edition_data *line_edition_data,
								char buffer);

int							down_arrow(
								t_line_edition_data *line_edition_data,
								char buffer);

int							end(
								t_line_edition_data *line_edition_data,
								char buffer);

int							f1(
								t_line_edition_data	*line_edition_data,
								char buffer);

int							f2(
								t_line_edition_data	*line_edition_data,
								char buffer);

int							home(
								t_line_edition_data	*line_edition_data,
								char buffer);

int							insert(
								t_line_edition_data	*line_edition_data,
								char buffer);

int							left_arrow(
								t_line_edition_data *line_edition_data,
								char buffer);

int							printable_character_input(
								t_line_edition_data *line_edition_data,
								char buffer);

int							tabulation(
								t_line_edition_data *line_edition_data,
								char buffer);

int							right_arrow(
								t_line_edition_data *line_edition_data,
								char buffer);
int							up_arrow(
								t_line_edition_data *line_edition_data,
								char buffer);

#endif
