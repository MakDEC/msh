/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : create_history_data.c                                          **
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

int						create_history_data(
							t_line_edition_data *line_edition_data)
{
	if (!(line_edition_data->history = (t_history_data *)malloc(sizeof(t_history_data))))
		exit (-1);
	line_edition_data->history->limit = 100;
	line_edition_data->history->ever_in_file_lines = 0;
	line_edition_data->history->first_history_case = NULL;
	line_edition_data->history->current_history_case = NULL;
	line_edition_data->history->last_history_case = NULL;
	return (0);
}
