/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : create_history_case.c                                          **
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

t_history_case					*create_history_case(
									t_buffers_list *command_to_save,
									t_history_case *next_case)
{
	t_history_case				*new_case;

	if (!(new_case = (t_history_case *)malloc(sizeof(t_history_case))))
			exit (-1);
	new_case->next_case = next_case;
	if (next_case != NULL)
	{
		next_case->previous_case = new_case;
		new_case->history_number = (next_case->history_number + 1);
	}
	else
		new_case->history_number = 1;
	new_case->previous_case = NULL;
	new_case->first_buffers_case = command_to_save;
	return (new_case);
}
