/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : basic_edition_state_creation.c                                 **
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

#include "touch_functions.h"
#include "state_machine.h"

int					set_finish_status(
						t_line_edition_data *line_edition_data,
						char buffer)
{
	(void)buffer;
	line_edition_data->finish_status = 1;
	return (0);
}

t_state				*basic_edition_state_creation(void)
{
	t_state			*state;
	int				index;

	index = 31;
	state = create_state();
	while (++index < 127)
		state->actions[index] = printable_character_input; 
	state->actions[10] = set_finish_status;
	state->actions[9] = tabulation;
	state->states[9] = state;
	state->actions[127] = backspace;
	state->states[127] = state;
	state->actions[27] = change_state;
	state->states[27] = create_state_27();
	return (state);
}
