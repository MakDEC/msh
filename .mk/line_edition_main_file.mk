#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : line_edition_main_file.mk                                          **
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

include		\
			.mk/cursor_management.mk \
			.mk/display_management.mk \
			.mk/history.mk \
			.mk/le_buffers_management.mk \
			.mk/le_data_management.mk \
			.mk/le_state_machine.mk \
			.mk/touch_functions.mk \

LINE_EDITION_MAIN_FILE = \
			srcs/line_edition/line_edition.c\

LINE_EDITION_MAIN_OBJ = $(patsubst srcs/%.c,objs/%.o,$(LINE_EDITION_MAIN_FILE))

LINE_EDITION_OBJS = \
					$(LE_BUFFERS_MANAGEMENT_OBJS) \
					$(LE_CURSOR_MANAGEMENT_OBJS) \
					$(LE_DATA_MANAGEMENT_OBJS) \
					$(LE_DISPLAY_MANAGEMENT_OBJS) \
					$(LE_HISTORY_OBJS) \
					$(LE_STATE_MACHINE_OBJS) \
					$(LE_TOUCH_FUNCTIONS_OBJS) \
					$(LINE_EDITION_MAIN_OBJ) \

$(LINE_EDITION_OBJS): includes/line_edition_struct.h
