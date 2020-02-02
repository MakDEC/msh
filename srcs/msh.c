/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : msh.c                                                          **
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

#include "shell.h"
#include "terminal_interaction.h"

/*
**	POSIX specifications :
**	https://pubs.opengroup.org/onlinepubs/9699919799/
*/

int					shell_routine(
						t_shell_data *shell_data)
{
	while (1)
	{
		if (line_edition(shell_data->line_edition_data) == 2)
			break ;
		write(1, "\n", 1);
	}
	return (0);
}

int					main(int argc, char **argv, char **env)
{
	t_shell_data	*shell_data;
	(void)argc;
	(void)argv;

	shell_data = create_and_initialize_shell_data_structure(env);
	shell_routine(shell_data);
	tcsetattr(0, 0, &shell_data->terminal_configuration.original_config);
	free_shell_data_struct(shell_data);
	write(1, "\n", 1);
	return (0);
}
