/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:40:21 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 16:34:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

int	win_h_mouse_move(int x, int y, t_win *w)
{
	if ((0 <= x && x <= w->w) && (0 <= y && y <= w->h))
		ft_printf("in window %s, mouse_move (%d, %d) \n", w->title, x, y);
	else
		ft_printf("buy from window %s\n", w->title);
	w->mm_x = x;
	w->mm_y = y;
	return (0);
}
