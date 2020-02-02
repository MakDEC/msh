/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : create_and_intialize_shell_stat_structure.c                    **
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
#include <stdlib.h>

t_line_edition_data			*g_line_edition_data;

static int			set_shell_data_structure_variables(
						t_shell_data *shell_data)
{
	shell_data->env = NULL;
	shell_data->pwd = NULL;
	shell_data->oldpwd = NULL;
	shell_data->home = NULL;
	shell_data->children_shell_level = NULL;
	shell_data->hash_begin = NULL;
	shell_data->local_variables = NULL;
	return (0);
}

t_shell_data		*create_and_initialize_shell_data_structure(
						char **env)
{
	t_shell_data	*shell_data;

	if (!(shell_data = (t_shell_data *)malloc(sizeof(t_shell_data))))
		exit (-1);
	set_shell_data_structure_variables(shell_data);
	shell_data->env = env;
	config_terminal_and_signal(shell_data);
	shell_data->line_edition_data = create_line_edition_data();
	g_line_edition_data = shell_data->line_edition_data;
	return (shell_data);
}
