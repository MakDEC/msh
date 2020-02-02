/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : free_line_edition_data_struct.c                                **
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

#include "line_edition_struct.h"
#include "history.h"
#include <stdlib.h>

static int		free_states(
					t_line_edition_data *line_edition_data)
{
	free(line_edition_data->basic_state->states[27]->states[91]->states[50]);
	free(line_edition_data->basic_state->states[27]->states[91]->states[51]);
	free(line_edition_data->basic_state->states[27]->states[79]);
	free(line_edition_data->basic_state->states[27]->states[91]);
	free(line_edition_data->basic_state->states[27]);
	free(line_edition_data->basic_state);
	return (0);
}

int				free_line_edition_data_struct(
					t_line_edition_data *line_edition_data)
{
	free_states(line_edition_data);
	free_history(line_edition_data->history);
	free(line_edition_data->prompt);
	free(line_edition_data);
	return (0);
}
