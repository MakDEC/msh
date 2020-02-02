/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : shell_data_struct.h                                            **
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

#ifndef SHELL_DATA_STRUCT_H
# define SHELL_DATA_STRUCT_H

# include <termios.h>
# include <signal.h>
# include "line_edition_struct.h"

/*
** 		Local Variables Structure, content the local variables name,
**		the associated value and a pointer to the next case
*/

typedef struct							s_local_variables
{
	char								*variable_name;
	char								*variable_value;
	struct s_local_variables			*next;
}										t_local_variables;

/*
**		History chain
*/

typedef struct							s_history
{
	struct s_bufstock					*buffers;
	int									nbr;
	struct s_history					*previous;
	struct s_history					*next;
}										t_history;

typedef struct							s_hash_tab
{
	struct s_hash_tab					*hash_tab[95];
	char								*name;
	char								*path;
}										t_hash_tab;

/*
** 						Data Structure
*/

typedef struct							s_terminal_configuration
{
	struct termios						original_config;
	struct termios						edition_config;
}										t_terminal_configuration;

typedef struct							s_shell_data
{
	char								**env;

	char								*home;
	char								*oldpwd;
	char								*pwd;
	char								*children_shell_level;

	t_line_edition_data					*line_edition_data;

	struct s_hash_tab					*hash_begin;

	struct s_local_variables			*local_variables;

	struct s_history					*history;

	struct s_terminal_configuration		terminal_configuration;
}										t_shell_data;

/*
int							(*parsing_functions[96])(struct s_data *data,
										t_parse_vars *vars, char **buf);

*/
#endif
