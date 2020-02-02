/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : state_creation.c                                               **
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

#include "state_machine.h"
#include "touch_functions.h"
#include <stdlib.h>

int					no_pattern_detected(
						t_line_edition_data *line_edition_data,
						char buffer)
{
		(void)buffer;
	line_edition_data->current_state = line_edition_data->basic_state;
	return (0);
}

static void			set_state_memory(
						t_state	*state)
{
	int				index;

	index = -1;
	while (++index < (UCHAR_MAX + 1))
	{
		state->actions[index] = no_pattern_detected;
		state->states[index] = NULL;
	}
	state->actions[3] = control_c;
	state->actions[4] = control_d;
	state->actions[26] = control_z;
}

t_state				*create_state(void)
{
	t_state			*state;

	if (!(state = (t_state *)malloc(sizeof(t_state))))
		return (NULL);
	set_state_memory(state);
	return (state);
}
