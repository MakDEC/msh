/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : load_previous_history_case.c                                   **
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
#include "cursor_management.h"
#include "le_buffers_management.h"
#include <stddef.h>

static int				load_previous_history_case(
							t_line_edition_data *line_edition_data)
{
	if (CURRENT_HISTORY_CASE == FIRST_HISTORY_CASE)
	{
		FIRST_BUFFER_CASE = TEMP_FIRST_BUFFER;
		TEMP_FIRST_BUFFER = NULL;
		CURRENT_HISTORY_CASE = NULL;
	}
	else
	{
		CURRENT_HISTORY_CASE = CURRENT_HISTORY_CASE->previous_case;
		FIRST_BUFFER_CASE = CURRENT_HISTORY_CASE->first_buffers_case;
	}
	GLOBAL_INDEX = 0;
	CURRENT_BUFFER_CASE = FIRST_BUFFER_CASE;
	set_global_input_size_and_reset_buffers_index(line_edition_data);
	return (0);
}

int						previous_history_management(
							t_line_edition_data *line_edition_data)
{
	if (CURRENT_HISTORY_CASE == NULL)
	{
		ring_bell();
		return (0);
	}
	replace_cursor_to_beginning(line_edition_data);
	load_previous_history_case(line_edition_data);
	history_displayer(line_edition_data);
	return (0);
}
