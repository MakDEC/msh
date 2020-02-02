#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : touch_functions.mk                                             **
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

LE_TOUCH_FUNCTIONS_FILES = \
			srcs/line_edition/touch_functions/backspace.c\
			srcs/line_edition/touch_functions/control_a.c\
			srcs/line_edition/touch_functions/control_c.c\
			srcs/line_edition/touch_functions/control_d.c\
			srcs/line_edition/touch_functions/control_z.c\
			srcs/line_edition/touch_functions/deletion.c\
			srcs/line_edition/touch_functions/down_arrow.c\
			srcs/line_edition/touch_functions/end.c\
			srcs/line_edition/touch_functions/f1.c\
			srcs/line_edition/touch_functions/f2.c\
			srcs/line_edition/touch_functions/home.c\
			srcs/line_edition/touch_functions/insert.c\
			srcs/line_edition/touch_functions/left_arrow.c\
			srcs/line_edition/touch_functions/printable_char.c\
			srcs/line_edition/touch_functions/right_arrow.c\
			srcs/line_edition/touch_functions/tabulation.c\
			srcs/line_edition/touch_functions/up_arrow.c\

LE_TOUCH_FUNCTIONS_OBJS = $(patsubst srcs/%.c,objs/%.o,$(LE_TOUCH_FUNCTIONS_FILES))

$(LE_TOUCH_FUNCTIONS_OBJS): \
						includes/touch_functions.h \
						includes/cursor_management.h \
						includes/display_management.h \
						includes/le_buffers_management.h \
						includes/history.h \
						includes/state_machine.h \

#le_touch_function_dependencies = \
			objss/line_edition/state_machine/state_machine_creation/basic_edition_state_creation.o \
			objs/line_edition/state_machine/state_machine_creation/27_91_state.o \

#$(le_touch_functions_dependencies): includes/touch_functions.h
