/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : save_first_cursor_position.c                                   **
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

#include "terminal_interaction.h"
#include "shell_data_struct.h"

int							save_first_cursor_position(
								t_line_edition_data *line_edition_data)
{
	int						cursor_position[2];

	get_cursor_position(cursor_position);
	line_edition_data->current_line = cursor_position[0];
	line_edition_data->current_column = cursor_position[1];
	line_edition_data->first_column = cursor_position[1];
	return (0);
}
