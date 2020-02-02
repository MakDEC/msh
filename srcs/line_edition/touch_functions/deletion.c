/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : deletion.c                                                     **
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

#include "display_management.h"
#include "line_edition_struct.h"
#include "history.h"
#include "cursor_management.h"
#include "le_buffers_management.h"
#include "state_machine.h"
#include <stddef.h>

static int		erase_char(
					t_line_edition_data *line_edition_data)
{
	int			temp_index;

	temp_index = CURRENT_BUFFER_INDEX;
	while (CURRENT_BUFFER[temp_index] != 0)
	{
		CURRENT_BUFFER[temp_index] = CURRENT_BUFFER[temp_index + 1];
		temp_index++;
	}
	CURRENT_BUFFER_SIZE--;
	line_edition_data->total_input_size--;
	return (0);
}

int				deletion(
					t_line_edition_data *line_edition_data,
					char buffer)
{
	change_state(line_edition_data, buffer);
	if (check_last_char(line_edition_data) != 0)
		return (ring_bell());
	if (CURRENT_HISTORY_CASE != NULL)
		export_current_history_case_as_current_buffer_case(line_edition_data);
	if (CURRENT_BUFFER[CURRENT_BUFFER_INDEX] == 0)
	{
		if (NEXT_BUFFER_CASE != NULL)
		{
			while (NEXT_BUFFER_CASE != NULL && CURRENT_BUFFER_SIZE == 0)
				CURRENT_BUFFER_CASE = NEXT_BUFFER_CASE;
		}
		else
		{
			ring_bell();
			return (0);
		}
	}
	erase_char(line_edition_data);
	display_rest_of_buffers_in_available_space(
		line_edition_data,
		line_edition_data->current_buffer);
	return (0);
}
