/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : move_cursor_to.c                                               **
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

#include "libft.h"
#include "line_edition_struct.h"

#include <stdio.h>

int				move_cursor_to(
					int line,
					int column)
{
	char		buffer[25];
	char		*temp_buf;

	//printf("On va bouger a la ligne %d et a la collone %d\n", line, column);
	ft_bzero(buffer, 25);
	ft_strcat(buffer, "\e[");
	temp_buf = ft_itoa(line + 1);
	ft_strcat(buffer, temp_buf);
	free(temp_buf);
	ft_strcat(buffer, ";");
	temp_buf = ft_itoa(column + 1);
	ft_strcat(buffer, temp_buf);
	free(temp_buf);
	ft_strcat(buffer, "f");
	write(1, buffer, ft_strlen(buffer));
	return (0);
}
