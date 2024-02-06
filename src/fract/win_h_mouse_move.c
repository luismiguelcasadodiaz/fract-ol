/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:40:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/06 13:05:45 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	win_h_mouse_move(int x, int y, t_win *w)
{
	if ((0 <= x && x <= w->w) && (0 <= y && y <= w->h))
		printf("in window %s, mouse_move (%d, %d) \n", w->title, x , y);
	else
		printf("buy from window %s\n", w->title);
	return (0);
}

