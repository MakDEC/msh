#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : le_data_management.mk                                          **
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

LE_DATA_MANAGEMENT_FILES = \
			srcs/line_edition/data_management/create_buffers_list_case.c\
			srcs/line_edition/data_management/create_line_edition_data.c\
			srcs/line_edition/data_management/create_new_prompt.c\
			srcs/line_edition/data_management/free_buffers_list.c\
			srcs/line_edition/data_management/free_history.c\
			srcs/line_edition/data_management/free_line_edition_data_struct.c\
			srcs/line_edition/data_management/prepare_buffers_data.c\
			srcs/line_edition/data_management/termcaps_initialization.c\

LE_DATA_MANAGEMENT_OBJS = $(patsubst srcs/%.c,objs/%.o,$(LE_DATA_MANAGEMENT_FILES))
