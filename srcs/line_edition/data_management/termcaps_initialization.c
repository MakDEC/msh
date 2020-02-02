/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : termcaps_initialization.c                                       **
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

#include <termios.h>
#include <stdlib.h>
#include <term.h>
#include "libft.h"
#include "line_edition_struct.h"

int				reception(int c)
{
	ft_putchar((char)c);
	return (0);
}

static void		init_terminal_data(void)
{
	char			term_type[15];
	int				ret_tgetent;

	ft_bzero(term_type, 15);
	ft_strcat(term_type, "xterm-256color");
	term_type[14] = 0;
	if (term_type == NULL)
	{
		ft_putstr("Terminal type unspecify\nPlease specify a terminal ");
		ft_putstr("typing 'TERM=<type>' and then 'export'.\n");
		exit(-1);
	}
	ret_tgetent = tgetent(NULL, term_type);
	if (ret_tgetent < 0)
	{
		ft_putstr("Failed while trying acces to the terminal database.\n");
		exit(-1);
	}
	if (ret_tgetent == 0)
	{
		ft_putstr("Terminal type ");
		ft_putstr(term_type);
		ft_putstr("seems not defined\n");
		exit(-1);
	}
}

static void		termcap_initialisation_error(char *buf)
{
	ft_putstr_fd("msh : ", 2);
	ft_putstr_fd(buf, 2);
	ft_putstr_fd(" termcap is not supported by this terminal, ", 2);
	ft_putstr_fd("please launch with a terminal who support it\n", 2);
	exit(-1);
}

int				termcaps_initialization(
					t_line_edition_data *line_edition_data)
{
	init_terminal_data();
	if ((line_edition_data->scroll_up = tgetstr("sr", NULL)) == NULL)
		termcap_initialisation_error("sr");
	return (0);
}
