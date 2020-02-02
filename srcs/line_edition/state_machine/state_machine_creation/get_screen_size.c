/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : get_screen_size.c                                              **
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
#include <stdlib.h>
#include <sys/ioctl.h>

void		get_screen_size(
				t_line_edition_data *line_edition_data)
{
	struct winsize	ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		exit(-1);
	line_edition_data->available_column = ws.ws_col;
	line_edition_data->available_line = ws.ws_row;
	line_edition_data->screen_size = (ws.ws_col * ws.ws_row);
}
