/**//***************************************************************************
********************************************************************************
**                                                                            **
**      File : line_edition_struct.h                                          **
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

#ifndef LINE_EDITION_STRUCTS_H
# define LINE_EDITION_STRUCTS_H

#include <limits.h>
#include "history_struct.h"

typedef struct				s_line_edition_data
{
	int						finish_status;

	struct s_state			*basic_state;
	struct s_state			*current_state;

	int						available_column;
	int						available_line;
	int						screen_size;

	int						current_line;
	int						first_column;
	int						current_column;

	int						total_input_size;

	int						global_index;

	struct s_buffers_list	*first_buffer;
	struct s_buffers_list	*current_buffer;
	struct s_buffers_list	*temp_first_buffer;

	char					*scroll_up;

	char					*prompt;
	int						prompt_size;
	int						display_prompt;

	struct s_history_data	*history;

	int						number_of_buffers;
}							t_line_edition_data;

typedef struct				s_state
{	
	int						(*actions[UCHAR_MAX + 1])(
								struct s_line_edition_data *line_edition_data,
								char buffer);
	struct s_state			*states[UCHAR_MAX + 1];
}							t_state;

# define CURRENT_BUFFER line_edition_data->current_buffer->buffer
# define CURRENT_BUFFER_INDEX line_edition_data->current_buffer->buffer_index
# define CURRENT_BUFFER_SIZE line_edition_data->current_buffer->buffer_size
# define NEXT_BUFFER_CASE line_edition_data->current_buffer->next
# define PREVIOUS_BUFFER_CASE line_edition_data->current_buffer->previous
# define CURRENT_BUFFER_CASE line_edition_data->current_buffer
# define GLOBAL_INDEX line_edition_data->global_index
# define TOTAL_INPUT_SIZE line_edition_data->total_input_size
# define FIRST_BUFFER_CASE line_edition_data->first_buffer
# define CURSOR_CURRENT_COLUMN line_edition_data->current_column
# define CURSOR_CURRENT_LINE line_edition_data->current_line
# define AVAILABLE_LINE line_edition_data->available_line
# define AVAILABLE_COLUMN line_edition_data->available_column
# define CURRENT_HISTORY_CASE line_edition_data->history->current_history_case
# define FIRST_HISTORY_CASE line_edition_data->history->first_history_case
# define TEMP_FIRST_BUFFER line_edition_data->temp_first_buffer

#endif
