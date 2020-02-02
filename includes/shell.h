/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : shell.h                                                        **
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

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "shell_data_struct.h"
# include "line_edition_struct.h"

t_shell_data		*create_and_initialize_shell_data_structure(
						char **env);

t_line_edition_data	*create_line_edition_data(void);

int					free_line_edition_data_struct(
						t_line_edition_data *line_edition_data);

int					free_shell_data_struct(
						t_shell_data *shell_data);

int					line_edition(t_line_edition_data *line_edition_data);

int					monitor(t_shell_data *data);

#endif
