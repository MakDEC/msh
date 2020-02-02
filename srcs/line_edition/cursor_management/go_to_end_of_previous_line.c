/**//***************************************************************************
********************************************************************************
**                                                                            **
**                                                                            **
**      File : go_to_end_of_previous_line.c                                   **
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

#include "cursor_management.h"

/*
**
**		On etait sur la premiere colonne, on cherche a aller sur la fin de la ligne percedente
**			- >On commence par donner la valeur de la largeur de l'ecran - 1 (premiere colonne == 0) a notre colonne actuelle
**			-> On verifie si on se trouve sur la premiere ligne 
**			-> Si c est le cas on passe a la ligne precedente
**				-> Sinon on va reecrire la ligne superieure
**			->On replace le curseur
**
*/

int				go_to_end_of_previous_line(
					t_line_edition_data *line_edition_data)
{
	line_edition_data->current_column = line_edition_data->available_column - 1;
	if (line_edition_data->current_line > 0)
		line_edition_data->current_line--;
	else
		scroll_line_up_and_print_previous_line(line_edition_data);
	move_cursor_to(line_edition_data->current_line, line_edition_data->current_column);	
	return (0);
}
