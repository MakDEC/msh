/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : 27_91_state.c                                                  **
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

int					set_actions(
						t_state *state)
{
	state->actions[65] = up_arrow;
	state->actions[66] = down_arrow;
	state->actions[67] = right_arrow;
	state->actions[68] = left_arrow;
	state->actions[70] = end;
	state->actions[72] = home;
	return (0);
}

t_state				*create_state_27_91(void)
{
	t_state			*state;

	state = create_state();
	set_actions(state);
	state->actions[50] = change_state;
	state->states[50] = create_state_27_91_50();
	state->actions[51] = change_state;
	state->states[51] = create_state_27_91_51();
	return (state);
}
