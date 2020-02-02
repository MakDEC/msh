/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : create_new_prompt.c                                            **
**                                                                            **
**		License :                                                             **
**                      This file is part of Msh                              **
**		  Msh is free software: you can redistribute it and/or modify         **
**	  it under the terms of the GNU General Public License as published by    **
**	  the Free Software Foundation, version 3.                                **
**	    Msh is distributed in the hope that it will be useful,                **
**	  but WITHOUT ANY WARRANTY; without even the implied warranty of          **
**	  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **
**	  GNU General Public License for more details.                            **
**	    You should have received a copy of the GNU General Public License     **
**	  along with Msh.  If not, see <https://www.gnu.org/licenses/>.           **
**                                                                            **
**		Copyright 2020 - Antoine Anger                                        **
**                                                                            **
********************************************************************************
***************************************************************************//**/

#include "line_edition_struct.h"
#include "libft.h" 

int				create_new_prompt(
					t_line_edition_data *line_edition_data)
{
	int			size_to_malloc;

	size_to_malloc = 41;
	if (line_edition_data->prompt != NULL)
		free(line_edition_data->prompt);
	if (!(line_edition_data->prompt = (char *)malloc(sizeof(char) * size_to_malloc)))
		exit (-1);
	ft_bzero(line_edition_data->prompt, size_to_malloc);
	ft_strcat(line_edition_data->prompt, "prompt de 40                          > ");
	line_edition_data->prompt_size = ft_strlen(line_edition_data->prompt);
	return (0);
}
