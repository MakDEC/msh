/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : reprint_all_buffer_and_erase_rest.c                            **
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
#include "le_buffers_management.h"
#include "libft.h"

static int			erase_rest_of_available_space(
						int available_space)
{
	char			*temp_buffer;
	int				temp_index;

	save_cursor_position();
	temp_index = available_space;
	if (!(temp_buffer = (char *)malloc(sizeof(char) * temp_index)))
		exit (-1);
	while (--temp_index >= 0)
		temp_buffer[temp_index] = ' ';
	write(1, temp_buffer, available_space - 1);
	free(temp_buffer);
	restore_cursor_position();
	return (0);
}

int					reprint_all_buffers_and_erase_rest(
						t_line_edition_data		*line_edition_data)
{
	int				available_space;
	t_buffers_list	*temp_case;

	temp_case = FIRST_BUFFER_CASE;
	available_space = get_available_space_until_end_of_screen(line_edition_data);
	write(1, temp_case->buffer, temp_case->buffer_size);
	available_space -= temp_case->buffer_size;
	change_buffers_and_control_variables_for_frontward_move(
		line_edition_data,
		temp_case->buffer_size);
	temp_case = temp_case->next;
	while (temp_case != NULL)
	{
		ft_putstr(temp_case->buffer);
		change_buffers_and_control_variables_for_frontward_move(
			line_edition_data,
			temp_case->buffer_size);
		available_space -= temp_case->buffer_size;
		temp_case = temp_case->next;
	}
	erase_rest_of_available_space(available_space);
	return (0);
}
