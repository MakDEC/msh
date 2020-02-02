/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : config_terminal_and_signal.c                                   **
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

#include "shell_data_struct.h"
#include "terminal_interaction.h"
#include <signal.h>

int					config_terminal_and_signal(
						t_shell_data *shell_data)
{
	save_original_terminal_configuration_and_set_to_shell_configuration(
		&shell_data->terminal_configuration.original_config,
		&shell_data->terminal_configuration.edition_config);
	signal(SIGWINCH, sigwinch_handler);
	return (0);
}
