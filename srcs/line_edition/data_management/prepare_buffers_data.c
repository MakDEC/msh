/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : prepare_buffers_data.c                                         **
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

#include "le_buffers_management.h"
#include <stddef.h>

int							prepare_buffers_data(
								t_line_edition_data *line_edition_data)
{
	line_edition_data->first_buffer = create_buffers_list_case(NULL, NULL, "");
	line_edition_data->current_buffer = line_edition_data->first_buffer;
	line_edition_data->temp_first_buffer = NULL;
	line_edition_data->total_input_size = 0;
	line_edition_data->global_index = 0;
	line_edition_data->current_column = 0;
	line_edition_data->current_line = 0;
	line_edition_data->finish_status = 0;
	line_edition_data->history->current_history_case = NULL;
	line_edition_data->number_of_buffers = 0;
	return (0);
}
