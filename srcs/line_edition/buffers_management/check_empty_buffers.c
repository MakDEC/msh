/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : check_empty_buffers.c                                          **
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

#include "line_edition_struct.h"
#include <stddef.h>

int					check_empty_buffers(
						t_buffers_list *start_buffer)
{
	int				temp_index;

	while (start_buffer != NULL)
	{
		temp_index = -1;
		while (start_buffer->buffer[++temp_index] != 0)
			if (start_buffer->buffer[temp_index] != ' ')
				return (1);
		start_buffer = start_buffer->next;
	}
	return (0);
}
