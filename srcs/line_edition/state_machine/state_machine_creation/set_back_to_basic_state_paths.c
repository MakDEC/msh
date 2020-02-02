/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : set_back_to_basic_state_paths.c                                **
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

void						set_back_to_basic_state_paths(
								t_line_edition_data *line_edition_data)
{
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[50]->
			states[126] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[51]->
			states[126] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[65] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[66] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[67] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[68] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[70] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[91]->
			states[72] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[79]->
			states[80] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[79]->
			states[81] = line_edition_data->basic_state;
		line_edition_data->basic_state->
			states[27]->
			states[105] = line_edition_data->basic_state;
}
