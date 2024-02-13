/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/13 13:19:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "keys_mac.h"

int	win_h_mouse_down(int button, int x, int y, t_win *w)
{
	ft_printf("w=%s, mouse_dowm (%d, %d) button %d\n", w->title, x, y, button);
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
	w->md_x = x;
	w->md_y = y;
	return (0);
}
