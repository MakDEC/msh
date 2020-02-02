#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : le_buffers_management.mk                                       **
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

#
#							Files List
#

LE_BUFFERS_MANAGEMENT_FILES = \
			srcs/line_edition/buffers_management/check_actual_buffer_size.c\
			srcs/line_edition/buffers_management/check_empty_buffers.c\
			srcs/line_edition/buffers_management/change_buffers_and_control_variables_for_backward_move.c\
			srcs/line_edition/buffers_management/change_buffers_and_control_variables_for_frontward_move.c\
			srcs/line_edition/buffers_management/compare_buffers_list.c\
			srcs/line_edition/buffers_management/copy_buffers_list.c\
			srcs/line_edition/buffers_management/go_to_end_of_buffers_list_and_return_moves_needed.c\
			srcs/line_edition/buffers_management/go_to_beginning_of_buffers_list_and_return_moves_needed.c\
			srcs/line_edition/buffers_management/set_global_input_size_and_reset_buffers_index.c\
			srcs/line_edition/buffers_management/split_buffers.c

#
#							Path substitution for compilation
#
#
LE_BUFFERS_MANAGEMENT_OBJS = $(patsubst srcs/%.c,objs/%.o,$(LE_BUFFERS_MANAGEMENT_FILES))


#
# 							Dependencies List
#

$(LE_BUFFERS_MANAGEMENT_OBJS): \
							includes/le_buffers_management.h \
							includes/buffers_struct.h \

#
#							Group of dependencies
#

le_buffers_management_dependencies = \
					objs/line_edition/cursor_management/replace_cursor_to_beginning.o \
					objs/line_edition/cursor_management/simulate_end_touch.o \
					objs/line_edition/display_management/reprint_all_buffers_and_erase_rest.o \
					objs/line_edition/history/load_next_history_case.o \
					objs/line_edition/history/previous_history_management.o \
					objs/line_edition/history/export_current_history_case_as_current_buffer_case.o \

$(le_buffers_management_dependencies): includes/le_buffers_management.h

