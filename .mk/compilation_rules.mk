#/**//**************************************************************************
#*******************************************************************************
#*                                                                            **
#*                                                                            **
#*      File : compilation_rules.mk                                           **
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

CC = gcc

FLAGS = \
	-Wall -Werror -Wextra		\
	-g -fsanitize=address			\
	-fno-omit-frame-pointer			\
	-fsanitize-address-use-after-scope	\
	-fstack-protector-strong			\
	-fsanitize=leak	\
	-fsanitize=undefined \
	-fsanitize=pointer-overflow \

objs/%.o: srcs/%.c
	@$(CC) -c $< $(FLAGS) -o $@ -I includes
	@printf '\033[34;01m%s\n\033[0m' 'Transforming $< into object'
