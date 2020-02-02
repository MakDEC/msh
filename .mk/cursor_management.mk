#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : cursor_management.mk                                           **
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

LE_CURSOR_MANAGEMENT_FILES = \
			srcs/line_edition/cursor_management/check_first_char.c\
			srcs/line_edition/cursor_management/check_first_line.c\
			srcs/line_edition/cursor_management/check_last_char.c\
			srcs/line_edition/cursor_management/check_last_line.c\
			srcs/line_edition/cursor_management/convert_right_buffer_move_into_frontward_cursor_move.c\
			srcs/line_edition/cursor_management/convert_left_buffer_move_into_backward_cursor_move.c\
			srcs/line_edition/cursor_management/get_available_space_until_end_of_screen.c\
			srcs/line_edition/cursor_management/go_to_beginning_of_next_line.c\
			srcs/line_edition/cursor_management/go_to_end_of_previous_line.c\
			srcs/line_edition/cursor_management/move_cursor_backward.c\
			srcs/line_edition/cursor_management/move_cursor_to.c\
			srcs/line_edition/cursor_management/move_cursor_to_line_beginning.c\
			srcs/line_edition/cursor_management/replace_cursor_to_beginning.c\
			srcs/line_edition/cursor_management/restore_cursor_position.c\
			srcs/line_edition/cursor_management/ring_bell.c\
			srcs/line_edition/cursor_management/save_cursor_position.c\
			srcs/line_edition/cursor_management/simulate_end_touch.c\

LE_CURSOR_MANAGEMENT_OBJS = $(patsubst srcs/%.c,objs/%.o,$(LE_CURSOR_MANAGEMENT_FILES))

$(LE_CURSOR_MANAGEMENT_OBJS): includes/cursor_management.h

cursor_management_dependencies = \
					objs/line_edition/buffers_management/change_buffers_and_control_variables_for_backward_move.o \
					objs/line_edition/buffers_management/change_buffers_and_control_variables_for_frontward_move.o \
					objs/line_edition/display_management/display_rest_of_buffers_in_available_space.o \
					objs/line_edition/display_management/display_rest_of_buffers_in_available_space_and_erase_rest_of_screen.o \
					objs/line_edition/display_management/print_first_line_with_prompt.o \
					objs/line_edition/display_management/print_first_screen.o \
					objs/line_edition/display_management/print_last_screen.o \
					objs/line_edition/display_management/print_previous_line.o \
					objs/line_edition/display_management/reprint_all_buffers_and_erase_rest.o \
					objs/line_edition/history/previous_history_management.o \


$(cursor_management_dependencies): includes/cursor_management.h
