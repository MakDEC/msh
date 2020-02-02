#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : terminal_interaction.mk                                        **
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

TERMINAL_INTERACTION_FILES = \
			srcs/terminal_interaction/sigwinch_handler.c\
			srcs/terminal_interaction/config_terminal_and_signal.c\
			srcs/terminal_interaction/get_cursor_position.c\
			srcs/terminal_interaction/save_first_cursor_position.c

TERMINAL_INTERACTION_OBJS = $(patsubst srcs/%.c,objs/%.o,$(TERMINAL_INTERACTION_FILES))

$(TERMINAL_INTERACTION_OBJS): \
			includes/terminal_interaction.h \
			includes/shell_data_struct.h \

terminal_interaction_dependencies = \
			objs/line_edition/cursor_management/replace_cursor_to_beginning.o \
			objs/line_edition/display_management/print_first_screen.o \
			objs/shell_data_management/create_and_initialize_shell_data_structure.o \

$(terminal_interaction_dependencies): includes/terminal_interaction.h
