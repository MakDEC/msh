/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : 27_state.c                                                     **
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

static void			set_arrows(
						t_state **state)
{
	(*state)->actions['h'] = left_arrow;
	(*state)->actions['j'] = down_arrow;
	(*state)->actions['k'] = up_arrow;
	(*state)->actions['l'] = right_arrow;
	(*state)->states['h'] = *state;
	(*state)->states['j'] = *state;
	(*state)->states['k'] = *state;
	(*state)->states['l'] = *state;
}

t_state				*create_state_27(void)
{
	t_state			*state;

	state = create_state();
	state->actions[79] = change_state;
	state->states[79] = create_state_27_79();
	state->actions['['] = change_state;
	state->states['['] = create_state_27_91();
	state->actions['i'] = change_state;
	state->states['i'] = state;
	set_arrows(&state);
	return (state);
}
