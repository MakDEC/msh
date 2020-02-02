#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : display_management.mk                                          **
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

LE_DISPLAY_MANAGEMENT_FILES = \
			srcs/line_edition/display_management/display_rest_of_buffers_in_available_space.c\
			srcs/line_edition/display_management/display_rest_of_buffers_in_available_space_and_erase_rest_of_screen.c\
			srcs/line_edition/display_management/print_first_line_with_prompt.c\
			srcs/line_edition/display_management/print_previous_line.c\
			srcs/line_edition/display_management/print_last_screen.c\
			srcs/line_edition/display_management/fill_buffer_with_previous_line.c\
			srcs/line_edition/display_management/scroll_line_up_and_print_previous_line.c\
			srcs/line_edition/display_management/print_first_screen.c\
			srcs/line_edition/display_management/reprint_all_buffers_and_erase_rest.c\

LE_DISPLAY_MANAGEMENT_OBJS = $(patsubst srcs/%.c,objs/%.o,$(LE_DISPLAY_MANAGEMENT_FILES))

$(LE_DISPLAY_MANAGEMENT_OBJS): includes/display_management.h

display_management_dependencies = \
			objs/line_edition/cursor_management/go_to_beginning_of_next_line.o \
			objs/line_edition/display_management/scroll_line_up_and_print_previous_line.o \
			objs/line_edition/display_management/fill_buffer_with_previous_line.o \
			objs/line_edition/display_management/print_first_screen.o \
			objs/line_edition/history/history_displayer.o \

$(display_management_dependencies): includes/display_management.h
