/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : print_first_screen.c                                           **
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
#include "cursor_management.h"
#include "terminal_interaction.h"
#include <unistd.h>

int				print_first_screen(
					t_line_edition_data *line_edition_data)
{
	move_cursor_to(0, 0);
	write(2, line_edition_data->prompt, line_edition_data->prompt_size);
	save_first_cursor_position(line_edition_data);
	display_rest_of_buffers_in_available_space(
		line_edition_data,
		line_edition_data->current_buffer);
	return (0);
}
