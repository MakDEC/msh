/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : print_previous_line.c                                          **
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
#include <term.h>
#include "libft.h"

int							print_previous_line(
								t_line_edition_data *line_edition_data,
								t_new_line_temp_buffer *temp_data)
{
	tputs(line_edition_data->scroll_up, 1, reception);
	move_cursor_to(0, 0);
	write(1, temp_data->buffer, ft_strlen(temp_data->buffer));
	return (0);
}
