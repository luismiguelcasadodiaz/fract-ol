/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 11:30:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_square(t_win w1, t_point ul, t_point lr, int color)
{
	int	i;

	if ((lr.x - ul.x) > w1.img.w || (lr.y - ul.y) > w1.img.h)
		return ;
	i = ul.x;
	while (i <= lr.x)
		win_pixel_put(w1, i++, ul.y, color);
	i = ul.x;
	while (i <= lr.x)
		win_pixel_put(w1, i++, lr.y, color);
	i = ul.y;
	while (i <= lr.y)
		win_pixel_put(w1, ul.x, i++, color);
	i = ul.y;
	while (i <= lr.y)
		win_pixel_put(w1, lr.x, i++, color);
}

void	draw_square_2(t_win w1, t_point ul, t_point lr)
{
	int	i;

	if ((lr.x - ul.x) > w1.img.w || (lr.y - ul.y) > w1.img.h)
		return ;
	i = ul.x;
	while (i <= lr.x)
	{
		win_pixel_put(w1, i, ul.y, col_create(0, 0, i, ul.y));
		i++;
	}
	i = ul.x;
	while (i <= lr.x)
	{
		win_pixel_put(w1, i, lr.y, col_create(0, 0, i, lr.y));
		i++;
	}
	i = ul.y;
	while (i <= lr.y)
	{
		win_pixel_put(w1, ul.x, i, col_create(0, 0, i, ul.x));
		i++;
	}
	i = ul.y;
	while (i <= lr.y)
	{
		win_pixel_put(w1, lr.x, i, col_create(0, 0, i, lr.x));
		i++;
	}
}
