/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : change_buffers_and_control_variables_for_backward_move.c       **
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
#include <stddef.h>

int				change_buffers_and_control_variables_for_backward_move(
					t_line_edition_data *line_edition_data,
					int	number_of_moves)
{
	while (number_of_moves > 0)
	{
		if (CURRENT_BUFFER_INDEX > 0)
		{
			CURRENT_BUFFER_INDEX--;
			GLOBAL_INDEX--;
		}
		else
		{
			while (CURRENT_BUFFER_CASE && CURRENT_BUFFER_INDEX == 0)
				CURRENT_BUFFER_CASE = PREVIOUS_BUFFER_CASE;
			if (CURRENT_BUFFER_CASE == NULL)
			{
				CURRENT_BUFFER_CASE = FIRST_BUFFER_CASE;
				return (1);
			}
			CURRENT_BUFFER_INDEX--;
			GLOBAL_INDEX--;
		}
		if (CURSOR_CURRENT_COLUMN == 0)
		{
			if (CURSOR_CURRENT_LINE > 0)
				CURSOR_CURRENT_LINE--;
			else
				scroll_line_up_and_print_previous_line(line_edition_data);
			CURSOR_CURRENT_COLUMN = line_edition_data->available_column - 1;
		}
		else
			CURSOR_CURRENT_COLUMN--;
		number_of_moves--;
	}
	return (0);
}
