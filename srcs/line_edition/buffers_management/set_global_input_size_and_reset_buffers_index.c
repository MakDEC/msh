/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : set_global_input_size_and_reset_buffers_index.c                **
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
#include <stddef.h>

int						set_global_input_size_and_reset_buffers_index(
							t_line_edition_data *line_edition_data)
{
	t_buffers_list		*temp_case;

	temp_case = FIRST_BUFFER_CASE;
	TOTAL_INPUT_SIZE = 0;
	while (temp_case != NULL)
	{
		temp_case->buffer_index = 0;
		TOTAL_INPUT_SIZE += temp_case->buffer_size;
		temp_case = temp_case->next;
	}
	return (0);
}
