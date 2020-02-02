/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : display_rest_of_buffers_in_available_space.c                   **
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

#include "cursor_management.h"
#include "libft.h"

static int			end_of_display_management(
						t_buffers_list			*buffers_case,
						int						available_space)
{
	if (buffers_case != NULL && available_space > 0)
	{
		if ((size_t)available_space > ft_strlen(buffers_case->buffer))
		{
			write(1, buffers_case->buffer, ft_strlen(buffers_case->buffer));
			write(1, " ", 1);
		}
		else		
			write(1, buffers_case->buffer, available_space);
	}
	else if (available_space > 0)
		write(1, " ", 1);
	return (0);
}

int					display_rest_of_buffers_in_available_space(
						t_line_edition_data		*line_edition_data,
						t_buffers_list			*buffers_case)
{
	int				available_space;
	int				rest_to_display_size;

	save_cursor_position();
	available_space = get_available_space_until_end_of_screen(line_edition_data);
	rest_to_display_size = ft_strlen(&buffers_case->buffer[buffers_case->buffer_index]);
	write(1, &buffers_case->buffer[buffers_case->buffer_index], rest_to_display_size < available_space ? rest_to_display_size : available_space);
	available_space -= ft_strlen(&buffers_case->buffer[buffers_case->buffer_index]);
	buffers_case = buffers_case->next;
	while (buffers_case != NULL && buffers_case->buffer_size < available_space)
	{
		ft_putstr(buffers_case->buffer);
		available_space -= buffers_case->buffer_size;
		buffers_case = buffers_case->next;
	}
	end_of_display_management(
		buffers_case,
		available_space);
	restore_cursor_position();
	return (0);
}
