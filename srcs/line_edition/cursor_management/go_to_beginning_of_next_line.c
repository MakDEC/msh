/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : go_to_beginning_of_next_line.c                                 **
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
#include <unistd.h>
#include "display_management.h"

int				go_to_beginning_of_next_line(
					t_line_edition_data *line_edition_data)
{
	line_edition_data->current_column = 0;
	if (line_edition_data->current_line == (line_edition_data->available_line - 1))
	{
		write(1, "\n", 1);
		display_rest_of_buffers_in_available_space(line_edition_data, line_edition_data->current_buffer);
	}
	else
	{
		line_edition_data->current_line++;
		move_cursor_to(line_edition_data->current_line, line_edition_data->current_column);
	}
	return (0);
}
