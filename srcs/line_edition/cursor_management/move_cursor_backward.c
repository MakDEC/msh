/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : move_cursor_backward.c                                         **
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

int				move_cursor_backward(
					int size_of_move)
{
	char		buffer[30];
	char		*ret_itoa;

	ft_bzero(buffer, 30);
	ft_strcat(buffer, "\e[");
	ret_itoa = ft_itoa(size_of_move);
	ft_strcat(buffer, ret_itoa);
	free(ret_itoa);
	ft_strcat(buffer, "D");
	write(1, buffer, ft_strlen(buffer));
	return (0);
}
