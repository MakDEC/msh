/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : job_struct.h                                                   **
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

#ifndef JOB_STRUCT_H
# define JOB_STRUCT_H

typedef struct					s_command_struct
{
	char						**argv;
	int							argc;

	int							command_return_status;

	struct s_command_struct		*previous_piped_command;
	struct s_command_struct		*next_piped_command;
}								t_command_struct;

#endif
