/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : check_last_char.c                                              **
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

int				check_last_char(
					t_line_edition_data *line_edition_data)
{
	t_buffers_list	*temp_case;

	temp_case = CURRENT_BUFFER_CASE;
	while (temp_case->buffer[temp_case->buffer_index] == 0 && temp_case->next != NULL)
		temp_case = temp_case->next;
	if (temp_case->buffer[temp_case->buffer_index] == 0)
	{
		ring_bell();
		return (1);
	}
	return (0);
}

