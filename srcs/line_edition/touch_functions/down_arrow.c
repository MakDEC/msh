/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : down_arrow.c                                                   **
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

#include "history.h"
#include "state_machine.h"
#include "le_buffers_management.h"
#include "cursor_management.h"

int				down_arrow(
					t_line_edition_data *line_edition_data,
					char buffer)
{
	change_state(line_edition_data, buffer);
	if (check_last_line(line_edition_data) == 0)
	{
		previous_history_management(line_edition_data);
		return (0);
	}
	change_buffers_and_control_variables_for_frontward_move(
		line_edition_data,
		line_edition_data->available_column);
	move_cursor_to(line_edition_data->current_line, line_edition_data->current_column);
	return (0);
}
