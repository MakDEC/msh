/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : free_buffers_list.c                                            **
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
#include <stdlib.h>

int							free_buffers_list(
								t_buffers_list *list_to_remove)
{
	while (list_to_remove->next != NULL)
	{
		free(list_to_remove->buffer);
		list_to_remove = list_to_remove->next;
		free(list_to_remove->previous);
	}
	free(list_to_remove->buffer);
	free(list_to_remove);
	return (0);
}
