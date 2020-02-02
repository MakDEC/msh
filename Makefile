#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : Makefile                                                       **
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

NAME = msh

FILE = srcs/msh.c

LIBFT = libft/libft.a

OBJ = $(patsubst srcs/%.c,objs/%.o,$(FILE))

objects = \
			$(OBJ) \
			$(INTERPRETER_OBJS) \
			$(LINE_EDITION_OBJS)  \
			$(SHELL_DATA_MANAGEMENT_OBJS) \
			$(TERMINAL_INTERACTION_OBJS)

all: prerequisites $(NAME)

include		\
			.mk/prerequisites.mk \
			.mk/compilation_rules.mk \
			.mk/interpreter.mk \
			.mk/line_edition_main_file.mk \
			.mk/shell_data_management.mk \
			.mk/terminal_interaction.mk \

$(NAME): $(objects) $(LIBFT)
	@$(CC) -o $(NAME) $(FLAGS) $(objects) -ltermcap $(LIBFT)
	@printf '\033[34;01m\033[1m%s\n\033[0m' 'Objects successfully linked : $(NAME) available'

clean:
	@make clean -C libft/
	@rm -rf objs
	@printf '\033[31;01m%s\n\033[0m' 'Deletion of objects (binary files)'

fclean: clean
	@rm -rf $(NAME).dSYM
	@rm -rf libft/libft.a
	@printf '\033[31;01m%s\n\033[0m' 'Deletion of libft.a'
	@rm -rf $(NAME)
	@printf '\033[31;01m%s\n\033[0m' 'Deletion of $(NAME)'

re: clean all

.PHONY: all clean fclean re

