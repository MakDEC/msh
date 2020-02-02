/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : compare_buffers_list.c                                         **
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

int					compare_buffers_list(
						t_buffers_list *list1,
						t_buffers_list *list2)
{
	int				temp_index;

	while (list1 != NULL)
	{
		if (list2 == NULL)
			return (1);
		temp_index = 0;
		while (temp_index < list1->buffer_size)
		{
			if (list1->buffer[temp_index] != list2->buffer[temp_index])
				return (1);
			temp_index++;
		}
		list1 = list1->next;
		list2 = list2->next;
	}
	return (0);
}
