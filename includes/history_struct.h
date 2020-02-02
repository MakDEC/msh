/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : history_struct.h                                               **
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

#ifndef HISTORY_STRUCT_H
# define HISTORY_STRUCT_H

#include "buffers_struct.h"

typedef struct				s_history_data
{
	struct s_history_case	*first_history_case;
	struct s_history_case	*current_history_case;
	struct s_history_case	*last_history_case;
	unsigned int			limit;
	unsigned int			ever_in_file_lines;
}							t_history_data;

typedef struct				s_history_case
{
	t_buffers_list			*first_buffers_case;

	unsigned long			history_number;
	struct s_history_case	*previous_case;
	struct s_history_case	*next_case;
}							t_history_case;

#endif
