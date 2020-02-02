#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : prerequisites.mk                                               **
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

prerequisites: libft_comp create_directories

libft_comp :
	@printf '\033[33;01m'
	@make -C libft/ -w
	@printf '\033[0m'

create_directories :
	@mkdir -p objs/interpreter/
	@mkdir -p objs/line_edition/buffers_management
	@mkdir -p objs/line_edition/cursor_management
	@mkdir -p objs/line_edition/data_management
	@mkdir -p objs/line_edition/display_management
	@mkdir -p objs/line_edition/touch_functions
	@mkdir -p objs/line_edition/history
	@mkdir -p objs/line_edition/state_machine/state_machine_creation
	@mkdir -p objs/terminal_interaction
	@mkdir -p objs/shell_data_management
