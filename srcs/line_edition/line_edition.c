/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : line_edition.c                                                 **
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

#include "history.h"
#include "le_buffers_management.h"
#include <unistd.h>
#include "terminal_interaction.h"

/*
**			Etapes : 
**				- initialise sa memoire
**				- Ecrit le prompt sur stderr (POSIX)
**				- Recupere la position du curseur
**				- lance la machine a etat
**				- retourne le retour de la machine
*/

void						input_reading_state_machine(
								t_line_edition_data *line_edition_data)
{
	unsigned char			buffer;

	buffer = 0;
	while (line_edition_data->finish_status == 0)
	{
		read(0, &buffer, 1);
		line_edition_data->current_state->
			actions[(int)buffer](line_edition_data, buffer);
		//printf("sequence recue : %d\n", (int)buffer);
	}
}

int							line_edition(
								t_line_edition_data *line_edition_data)
{
	prepare_buffers_data(line_edition_data);
	write(2, line_edition_data->prompt, line_edition_data->prompt_size);
	save_first_cursor_position(line_edition_data);
	input_reading_state_machine(line_edition_data);
	if (line_edition_data->finish_status < 3)
		add_to_history(line_edition_data);
	else
		free_buffers_list(line_edition_data->first_buffer);
	return (line_edition_data->finish_status - 1);
}
