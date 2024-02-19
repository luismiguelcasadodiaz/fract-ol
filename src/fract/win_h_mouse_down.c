/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/19 18:38:25 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "keys_mac.h"

int	win_h_mouse_down(int button, int x, int y, t_win *w)
{
	if ((button == MOUSE_SCROLL_DOWN) && (w->zoom < w->iteractions))
	{
		w->zoom++;
		draw_fractal(*w);
	}
	else if ((button == MOUSE_SCROLL_UP) && (w->zoom > INITIAL_ZOOM))
	{
		w->zoom--;
		draw_fractal(*w);
	}
	else if (button == MOUSE_BUTTON_LEFT)
	{
		draw_fractal(*w);
	}
	ft_printf("dowm (%d, %d) button %d zoom %d \n", x, y, button, w->zoom);
	return (0);
}
