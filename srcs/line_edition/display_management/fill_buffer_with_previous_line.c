/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : fill_buffer_with_previous_line.c                               **
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

#include "display_management.h"
#include <stddef.h>

int							fill_buffer_with_previous_line(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data)
{
	while (temp_data->buffer_index >= 0)
	{
		temp_data->buffer[temp_data->buffer_index] = temp_data->temp_buffers_case->buffer[temp_data->temp_index];
		temp_data->temp_index--;
		if (temp_data->temp_index < 0)
		{
			if (temp_data->temp_buffers_case->previous == NULL)
				return (print_first_line_with_prompt(
							line_edition_data,
							temp_data->buffer,
							temp_data->buffer_index));
			temp_data->temp_buffers_case = temp_data->temp_buffers_case->previous;
			temp_data->temp_index = temp_data->temp_buffers_case->buffer_index - 1;
		}
		temp_data->buffer_index--;
	}
	return (print_previous_line(line_edition_data, temp_data));
}
