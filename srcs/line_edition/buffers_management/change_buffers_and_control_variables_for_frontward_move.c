/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : change_buffers_and_control_variables_for_frontward_move.c      **
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

#include "le_buffers_management.h"
#include "cursor_management.h"

static int		actualize_buffers_control_variables(
					t_line_edition_data *line_edition_data)
{
	if (CURRENT_BUFFER[CURRENT_BUFFER_INDEX] != 0)
	{
		CURRENT_BUFFER_INDEX++;
		GLOBAL_INDEX++;
	}
	else
	{
		while (NEXT_BUFFER_CASE && CURRENT_BUFFER[CURRENT_BUFFER_INDEX] == 0)
			CURRENT_BUFFER_CASE = NEXT_BUFFER_CASE;
		if (CURRENT_BUFFER[CURRENT_BUFFER_INDEX] == 0)
			return (1);
		CURRENT_BUFFER_INDEX++;
		GLOBAL_INDEX++;
	}
	return (0);
}

int				change_buffers_and_control_variables_for_frontward_move(
					t_line_edition_data *line_edition_data,
					int	number_of_moves)
{
	while (number_of_moves > 0)
	{
		if (actualize_buffers_control_variables(line_edition_data) != 0)
			return (0);
		if (CURSOR_CURRENT_COLUMN == AVAILABLE_COLUMN - 1)
		{
			go_to_beginning_of_next_line(line_edition_data);
		}
		else
			CURSOR_CURRENT_COLUMN++;
		number_of_moves--;
	}
	return (0);
}

