/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : check_last_line.c                                              **
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

int					check_last_line(
						t_line_edition_data *line_edition_data)
{
	t_buffers_list	*temp_case;
	size_t			space_until_end_of_line;

	space_until_end_of_line = line_edition_data->available_column - line_edition_data->current_column;
	temp_case = CURRENT_BUFFER_CASE;
	if (ft_strlen(&temp_case->buffer[temp_case->buffer_index]) > space_until_end_of_line)
		return (1);
	space_until_end_of_line -= ft_strlen(&temp_case->buffer[temp_case->buffer_index]);
	temp_case = temp_case->next;
	while (temp_case != NULL)
	{
		if (ft_strlen(temp_case->buffer) > space_until_end_of_line)
			return (1);
		space_until_end_of_line -= ft_strlen(temp_case->buffer);
		temp_case = temp_case->next;
	}
	return (0);
}
