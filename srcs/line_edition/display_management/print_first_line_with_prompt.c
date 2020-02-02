/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : print_first_line_with_prompt.c                                 **
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
#include <term.h>

int					print_first_line_with_prompt(
						t_line_edition_data *line_edition_data,
						char *buffer,
						int index)
{
	int				scroll_needed;
	int				over_line;

	over_line = line_edition_data->prompt_size / line_edition_data->available_column;
	scroll_needed = 1 + over_line;
	line_edition_data->current_line += over_line;
	if (line_edition_data->current_line >= line_edition_data->available_line)
		line_edition_data->current_line = line_edition_data->available_line - 1;
	if (scroll_needed < line_edition_data->available_line)
		while (scroll_needed-- > 0)
			tputs(line_edition_data->scroll_up, 1, reception);
	move_cursor_to(0, 0);
	write(2, line_edition_data->prompt, line_edition_data->prompt_size);
	write(1, &buffer[index], ft_strlen(&buffer[index]));
	return (0);
}
