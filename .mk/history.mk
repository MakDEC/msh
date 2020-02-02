#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : history.mk                                                     **
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

LE_HISTORY_FILES = \
			srcs/line_edition/history/add_to_history.c \
			srcs/line_edition/history/create_history_case.c \
			srcs/line_edition/history/create_history_data.c \
			srcs/line_edition/history/export_current_history_case_as_current_buffer_case.c \
			srcs/line_edition/history/history_displayer.c \
			srcs/line_edition/history/load_next_history_case.c \
			srcs/line_edition/history/previous_history_management.c \

LE_HISTORY_OBJS  =$(patsubst srcs/%.c,objs/%.o,$(LE_HISTORY_FILES))

$(LE_HISTORY_OBJS): includes/history.h includes/history_struct.h
