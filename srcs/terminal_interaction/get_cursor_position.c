/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : get_cursor_position.c                                          **
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

int			get_cursor_position(
				int cursor_position[2])
{
	char				buffer[1024];
	char				read_buf[1024];
	ssize_t				read_return_value;

	if (write(1, "\033[6n", 4) == -1)
		return (-1);
	ft_bzero(buffer, 1024);
	while (ft_strchr(buffer, 'R') == NULL)
	{
			read_return_value = read(0, read_buf, 1023);
			if (read_return_value > 0)
			{
				read_buf[read_return_value] = 0;
				ft_strcat(buffer, read_buf);
			}
	}
	cursor_position[0] = ft_atoi(&buffer[2]) - 1;
	cursor_position[1] = ft_atoi(ft_strchr(buffer, ';') + 1) - 1;
	return (0);
}
