/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : state_machine.h                                                **
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

#ifndef STATE_MACHINE_H
# define STATE_MACHINE_H

# include "line_edition_struct.h"

t_state						*basic_edition_state_creation(void);

int							change_state(
								t_line_edition_data *line_edition_data,
								char buffer);

t_state						*create_state(void);

t_state						*create_state_27(void);

t_state						*create_state_27_79(void);

t_state						*create_state_27_91(void);

t_state						*create_state_27_91_50(void);

t_state						*create_state_27_91_51(void);

void						set_back_to_basic_state_paths(
								t_line_edition_data *line_edition_data);

#endif
