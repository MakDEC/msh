#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : le_state_machine.mk                                            **
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

LE_STATE_MACHINE_FILES = \
			srcs/line_edition/state_machine/change_state.c\
			srcs/line_edition/state_machine/state_machine_creation/27_state.c\
			srcs/line_edition/state_machine/state_machine_creation/27_79_state.c\
			srcs/line_edition/state_machine/state_machine_creation/27_91_state.c\
			srcs/line_edition/state_machine/state_machine_creation/27_91_50_state.c\
			srcs/line_edition/state_machine/state_machine_creation/27_91_51_state.c\
			srcs/line_edition/state_machine/state_machine_creation/basic_edition_state_creation.c\
			srcs/line_edition/state_machine/state_machine_creation/get_screen_size.c\
			srcs/line_edition/state_machine/state_machine_creation/set_back_to_basic_state_paths.c\
			srcs/line_edition/state_machine/state_machine_creation/state_creation.c\

LE_STATE_MACHINE_OBJS = $(patsubst srcs/%.c,objs/%.o,$(LE_STATE_MACHINE_FILES))

$(LE_STATE_MACHINE_OBJS): includes/state_machine.h includes/touch_functions.h

