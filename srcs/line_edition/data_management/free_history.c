/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : free_history.c                                                 **
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
#include <stdlib.h>

int				free_history(
					t_history_data *history_data)
{
	if (history_data->first_history_case != NULL)
	{
		while (history_data->first_history_case->next_case != NULL)
		{
			free_buffers_list(history_data->first_history_case->first_buffers_case);
			history_data->first_history_case = history_data->first_history_case->next_case;
			free(history_data->first_history_case->previous_case);
		}
		free_buffers_list(history_data->first_history_case->first_buffers_case);
		free(history_data->first_history_case);
	}
	free(history_data);
	return (0);
}
