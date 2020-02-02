/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : backspace.c                                                    **
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

#include "state_machine.h"
#include "cursor_management.h"
#include "touch_functions.h"
#include <stddef.h>

static int		control_variables_adjustement(
					t_line_edition_data *line_edition_data)
{
	
	line_edition_data->current_buffer->buffer_index--;
	line_edition_data->global_index--;
	if (line_edition_data->current_column == 0)
		return (go_to_end_of_previous_line(line_edition_data));
	line_edition_data->current_column--;
	return (0);
}

static int		left_arrow_bis(
					t_line_edition_data *line_edition_data)
{
	if (line_edition_data->current_buffer->buffer_index == 0)
	{
		if (line_edition_data->current_buffer->previous == NULL)
		{
			ring_bell();
			return (1);
		}
		line_edition_data->current_buffer = line_edition_data->
			current_buffer->previous;
	}
	control_variables_adjustement(line_edition_data);
	move_cursor_to(line_edition_data->current_line,
			line_edition_data->current_column);
	return (0);
}

int				backspace(
					t_line_edition_data *line_edition_data,
					char buffer)
{
	if (check_first_char(line_edition_data) != 0)
	{
		change_state(line_edition_data, buffer);
		return (0);
	}
	if (left_arrow_bis(line_edition_data) != 0)
	{
		change_state(line_edition_data, buffer);
		return (1);
	}
	deletion(line_edition_data, buffer);
	return (0);
}
