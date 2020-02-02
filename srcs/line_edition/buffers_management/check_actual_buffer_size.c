/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : check_current_buffer_size.c                                    **
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
#include <stddef.h>

int					check_current_buffer_size(
						t_line_edition_data *line_edition_data)
{
	if (CURRENT_BUFFER_INDEX == 1023)
	{
		if (NEXT_BUFFER_CASE == NULL
				|| line_edition_data->current_buffer->next->buffer_size != 0)
			NEXT_BUFFER_CASE = create_buffers_list_case(
				NEXT_BUFFER_CASE,
				CURRENT_BUFFER_CASE,
				"");
		CURRENT_BUFFER_CASE = NEXT_BUFFER_CASE;
	}
	return (0);
}
