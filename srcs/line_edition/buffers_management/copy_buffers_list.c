/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : copy_buffers_list.c                                            **
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

t_buffers_list				*copy_buffers_list(
								t_buffers_list	*list_to_copy)
{
	t_buffers_list			*new_list;
	t_buffers_list			*new_list_first_case;

	new_list = create_buffers_list_case(
			list_to_copy->next,
			list_to_copy->previous,
			list_to_copy->buffer);
	new_list_first_case = new_list;
	new_list->buffer_index = list_to_copy->buffer_index;
	list_to_copy = list_to_copy->next;
	while (list_to_copy != NULL)
	{
		new_list->next = create_buffers_list_case(
				list_to_copy->next,
				list_to_copy->previous,
				list_to_copy->buffer);
		new_list = new_list->next;
		new_list->buffer_index = 0;
		list_to_copy = list_to_copy->next;
	}
	return (new_list_first_case);
}
