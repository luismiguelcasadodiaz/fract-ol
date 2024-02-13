/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/13 14:52:55 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "keys_mac.h"

int	win_h_mouse_down(int button, int x, int y, t_win *w)
{
	if ((button == MOUSE_SCROLL_DOWN) && (w->zoom < MAX_ITERATIONS))
	{
		w->zoom++;
		draw_fractal(*w);
	}
	else if ((button == MOUSE_SCROLL_UP) &&(w->zoom > 0))
	{
		w->zoom--;
		draw_fractal(*w);
	}
	else if (button == MOUSE_BUTTON_LEFT)
	{
		ft_printf(" mouse_dowm (%d, %d) button %d\n", x, y, button);
		w->md_x = x;
		w->md_y = y;
		draw_fractal(*w);
	}
	return (0);
}
