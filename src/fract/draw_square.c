/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/21 09:54:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

/* ************************************************************************** */
/*          a           b                                                     */
/*  |..............x..........|                                               */
/*  O                         W                                               */
/*                                                                            */
/*  OW/(OW-Ox) = rb         600/(600-400) = 3                                 */
/*  OW/Ox      = ra         600/400       = 1,5                               */
/*  rb/ra      = r          3/1,5         = 2                                 */
/*  x = r * (OW / rb)       2 * (600 / 3) = 400                               */
/*                                                                            */
/* ************************************************************************** */
/*
static int	calculate_center(int ow, int x, float *rb)
{
	float	r;
	float	ra;
	float	fx;

	fx = 1.0 * x;
	*rb = ow / (ow - fx);
	ra = ow / fx;
	r = *rb / ra;
	return ((int)r * ow / *rb);
}
*/

void	draw_fractal(t_win w)
{
	if (!ft_strncmp(w.title, "Mandelbrot", 10))
		draw_mande(w);
	else if (!ft_strncmp(w.title, "Julia", 5))
		draw_julia(w);
	else if (!ft_strncmp(w.title, "Ship", 4))
		draw_ship(w);
	else
		draw_white(w);
	return ;
}
