/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : history_displayer.c                                            **
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

int			check_full_input_in_one_screen(
				t_line_edition_data *line_edition_data)
{
	if ((line_edition_data->total_input_size + line_edition_data->prompt_size)
			> line_edition_data->screen_size)
		return (1);
	return (0);
}

int			history_displayer(
				t_line_edition_data *line_edition_data)
{
	if (check_full_input_in_one_screen(line_edition_data) == 0)
		reprint_all_buffers_and_erase_rest(line_edition_data);
	else
		display_rest_of_buffers_in_available_space(
			line_edition_data,
			line_edition_data->first_buffer);
	return (0);
}
