/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : check_first_line.c                                             **
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

int				check_first_line(
					t_line_edition_data *line_edition_data)
{
	if (((line_edition_data->prompt_size % line_edition_data->available_column)
				+ line_edition_data->global_index)
		< line_edition_data->available_column)
			return (1);
	return (0);
}
