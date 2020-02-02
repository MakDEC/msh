/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : create_buffers_list_case.c                                     **
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
#include "libft.h"

t_buffers_list				*create_buffers_list_case(
								t_buffers_list *next_case,
								t_buffers_list *previous_case,
								char *string_to_copy)
{
	t_buffers_list			*new_buffer_case;

	if (!(new_buffer_case = (t_buffers_list *)malloc(sizeof(t_buffers_list))))
		exit (-1);
	if (!(new_buffer_case->buffer = (char *)malloc(sizeof(char) * 1024)))
		exit (-1);
	ft_bzero(new_buffer_case->buffer, 1024);
	ft_strcat(new_buffer_case->buffer, string_to_copy);
	new_buffer_case->next = next_case;
	if (next_case != NULL)
		next_case->previous = new_buffer_case;
	new_buffer_case->previous = previous_case;
	new_buffer_case->buffer_index = 0;
	new_buffer_case->buffer_size = ft_strlen(new_buffer_case->buffer);
	return (new_buffer_case);
}
