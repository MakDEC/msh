/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : add_char_in_buffers.c                                          **
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

#include "state_machine.h"

int					add_char_in_buffers(
						t_state_machine_data *state_machine_data,
						char buffer)
{
	if (state_machine_data->current_buffer->
			buffer[state_machine_data->current_buffer->buffer_index] != 0)
		split_buffer(state_machine_data);
	state_machine_data->current_buffer->
		buffer[state_machine_data->current_buffer->buffer_index] = buffer;
	return (0);
}
