/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : save_original_terminal_configuration_                          **
**                                     and_set_to_shell_condiguration.c       **
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

int		save_original_terminal_configuration_and_set_to_shell_configuration(
			struct termios *original_config,
			struct termios *edition_config)
{
	if (tcgetattr(0, original_config) != 0)
		return (-1);
	if (tcgetattr(0, edition_config) != 0)
		return (-1);
	edition_config->c_lflag &= ~(ICANON | ECHO);
	edition_config->c_lflag &= ~(ISIG);
	tcsetattr(0, 0, edition_config);
	return (0);
}
