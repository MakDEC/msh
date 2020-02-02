/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : control_a.c                                                    **
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
#include "cursor_management.h"

int			control_a(
				t_line_edition_data *line_edition_data,
				char buffer)
{
	change_state(line_edition_data, buffer);
	move_cursor_to_line_beginning(line_edition_data);
	return (0);
}
