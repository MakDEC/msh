/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : move_cursor_to_line_beginning.c                                 **
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

int						browse_empty_buffers(
							t_line_edition_data *line_edition_data)
{
	while (CURRENT_BUFFER_INDEX == 0 && PREVIOUS_BUFFER_CASE)
		CURRENT_BUFFER_CASE = PREVIOUS_BUFFER_CASE;
	return (0);
}

int						move_cursor_to_line_beginning(
							t_line_edition_data *line_edition_data)
{
	while (CURSOR_CURRENT_COLUMN > 0)
	{
		if (CURRENT_BUFFER_INDEX == 0)
			browse_empty_buffers(line_edition_data);
		if (GLOBAL_INDEX == 0)
			break ;
		CURRENT_BUFFER_INDEX--;
		CURSOR_CURRENT_COLUMN--;
		GLOBAL_INDEX--;
	}
	move_cursor_to(
		CURSOR_CURRENT_LINE,
		CURSOR_CURRENT_COLUMN);
	return (0);
}
