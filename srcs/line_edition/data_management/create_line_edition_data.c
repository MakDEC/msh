/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : create_line_edition_data.c                                     **
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
#include "line_edition_struct.h"
#include "terminal_interaction.h"
#include "history.h"
#include "state_machine.h"
#include <stdlib.h>
#include <unistd.h>

void						create_machine_states(
								t_line_edition_data *line_edition_data)
{
	line_edition_data->basic_state = basic_edition_state_creation();
	line_edition_data->current_state = line_edition_data->basic_state;
	set_back_to_basic_state_paths(line_edition_data);
}

int						set_display_prompt(
							t_line_edition_data *line_edition_data)
{
	if ((write(2, "", 0) == -1) || (isatty(2) != 0))
		line_edition_data->display_prompt = 0;
	else
		line_edition_data->display_prompt = 1;
	return (0);
}

t_line_edition_data		*create_line_edition_data(void)
{
	t_line_edition_data	*line_edition_data;

	if (!(line_edition_data = (t_line_edition_data *)malloc(sizeof(
			t_line_edition_data))))
		return (NULL);
	create_machine_states(line_edition_data);
	get_screen_size(line_edition_data);
	termcaps_initialization(line_edition_data);
	line_edition_data->prompt = NULL;
	create_history_data(line_edition_data);
	create_new_prompt(line_edition_data);
	set_display_prompt(line_edition_data);
	return (line_edition_data);
}
