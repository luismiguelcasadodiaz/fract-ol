/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 12:47:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

void	draw_fractal(t_win w)
{
	show_data(w);
	if (!ft_strncmp(w.title, "Mandelbrot", 10))
		draw_mande(w);
	else if (!ft_strncmp(w.title, "Julia", 5))
		draw_julia(w);
	else
		draw_white(w);
	return ;
}
