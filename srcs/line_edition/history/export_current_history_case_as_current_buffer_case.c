/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : export_current_history_case_as_current_buffer_case.c           **
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

int			export_current_history_case_as_current_buffer_case(
				t_line_edition_data *line_edition_data)
{
	free_buffers_list(TEMP_FIRST_BUFFER);
	TEMP_FIRST_BUFFER = NULL;
	FIRST_BUFFER_CASE = copy_buffers_list(CURRENT_HISTORY_CASE->first_buffers_case);
	CURRENT_BUFFER_CASE = FIRST_BUFFER_CASE;
	CURRENT_HISTORY_CASE = NULL;
	return (0);
}
