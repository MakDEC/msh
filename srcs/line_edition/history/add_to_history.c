/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : add_to_history.c                                               **
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

#include "history.h"
#include "le_buffers_management.h"
#include <stddef.h>

int					create_history(
						t_line_edition_data *line_edition_data)
{
	line_edition_data->history->first_history_case =
			create_history_case(
				line_edition_data->first_buffer,
				NULL);
	line_edition_data->history->last_history_case =
		line_edition_data->history->first_history_case;
	return (0);
}

int					insert_in_history(
						t_line_edition_data *line_edition_data)
{
	if (CURRENT_HISTORY_CASE != NULL)
	{
		if (TEMP_FIRST_BUFFER != NULL)
			free_buffers_list(TEMP_FIRST_BUFFER);
		if (compare_buffers_list(
					CURRENT_HISTORY_CASE->first_buffers_case,
					FIRST_HISTORY_CASE->first_buffers_case) == 0)
			return (0);
		FIRST_BUFFER_CASE = copy_buffers_list(CURRENT_HISTORY_CASE->first_buffers_case);
		CURRENT_HISTORY_CASE = NULL;
	}
	if (FIRST_HISTORY_CASE != NULL
			&& compare_buffers_list(
				FIRST_BUFFER_CASE,
				FIRST_HISTORY_CASE->first_buffers_case) == 0)
	{
		free_buffers_list(line_edition_data->first_buffer);
		return (0);
	}
	line_edition_data->history->first_history_case =
			create_history_case(
				line_edition_data->first_buffer,
				line_edition_data->history->first_history_case);	
	return (0);
}

int					add_to_history(
						t_line_edition_data *line_edition_data)
{
	if (check_empty_buffers(line_edition_data->first_buffer) == 0)
	{
			free_buffers_list(line_edition_data->first_buffer);
			line_edition_data->finish_status = 2;
			return (1);
	}
	if (line_edition_data->history->first_history_case == NULL)
		create_history(line_edition_data);
	else
		insert_in_history(line_edition_data);
	return (0);
}
