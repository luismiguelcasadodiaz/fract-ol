/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_not_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:23:56 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/12 12:46:01 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include "ft_printf.h"
#include "mlx.h"

int	win_h_not_event(t_win *w)
{
	t_point	ul;
	t_point	lr;

	if (w == NULL)
		return (-1);
	ft_printf("not event in windows %s\n", w->title);
	ul.x = w->md_x;
	ul.y = w->md_y;
	lr.x = w->mu_x;
	lr.y = w->mu_y;
	///draw_square_2(*w, ul, lr);
	//if (w->mlx_ptr && w->win_ptr)
	//	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr, 0, 0);
	return (0);
}
