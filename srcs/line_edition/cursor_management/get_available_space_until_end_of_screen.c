/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : get_available_space_until_end_of_screen.c                      **
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

int					get_available_space_until_end_of_screen(
						t_line_edition_data *line_edition_data)
{
	int				available_space;

	available_space =
		line_edition_data->available_column
		- line_edition_data->current_column;
	available_space += ((line_edition_data->available_line
		- line_edition_data->current_line - 1)
		* line_edition_data->available_column);
	return (available_space);
}
