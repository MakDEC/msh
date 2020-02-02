#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : shell_data_management.mk                                       **
#*                                                                            **
#*		License :                                                             **
#*                      This file is part of Msh                              **
#*		  Msh is free software: you can redistribute it and/or modify         **
#*	  it under the terms of the GNU General Public License as published by    **
#*	  the Free Software Foundation, version 3.                                **
#*	    Msh is distributed in the hope that it will be useful,                **
#*	  but WITHOUT ANY WARRANTY; without even the implied warranty of          **
#*	  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **
#*	  GNU General Public License for more details.                            **
#*	    You should have received a copy of the GNU General Public License     **
#*	  along with Msh.  If not, see <https://www.gnu.org/licenses/>.           **
#*                                                                            **
#*		Copyright 2020 - Antoine Anger                                        **
#*                                                                            **
#*******************************************************************************
#**************************************************************************//**/

SHELL_DATA_MANAGEMENT_FILES = \
			srcs/shell_data_management/create_and_initialize_shell_data_structure.c\
			srcs/shell_data_management/free_shell_data_struct.c\
			srcs/shell_data_management/save_original_terminal_configuration_and_set_to_shell_configuration.c

SHELL_DATA_MANAGEMENT_OBJS = $(patsubst srcs/%.c,objs/%.o,$(SHELL_DATA_MANAGEMENT_FILES))

$(SHELL_DATA_MANAGEMENT_OBJS): includes/shell.h
