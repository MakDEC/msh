/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : terminal_interaction.h                                         **
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

#ifndef TERMINAL_INTERACTION_H
# define TERMINAL_INTERACTION_H

#include "shell_data_struct.h"

int			config_terminal_and_signal(
				t_shell_data *shell_data);

int			get_cursor_position(
				int cursor_position[2]);

int			save_first_cursor_position(
				t_line_edition_data *line_edition_data);

int			save_original_terminal_configuration_and_set_to_shell_configuration(
				struct termios *original_config,
				struct termios *edition_config);

void		sigwinch_handler(
				int signum);

int			termcaps_initialization(
				t_line_edition_data *line_edition_data);

#endif
