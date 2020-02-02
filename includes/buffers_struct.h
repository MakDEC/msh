/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : buffers_struct.h                                               **
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

#ifndef BUFFERS_STRUCT_H
#define BUFFERS_STRUCT_H

typedef struct				s_buffers_list
{
	char					*buffer;
	int						buffer_index;
	int						buffer_size;

	struct s_buffers_list	*next;
	struct s_buffers_list	*previous;
}							t_buffers_list;


typedef struct				s_new_line_temp_buffer
{
	char					*buffer;
	int						buffer_index;
	int						temp_index;
	t_buffers_list			*temp_buffers_case;
}							t_new_line_temp_buffer;

#endif
