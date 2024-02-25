/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:24:03 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 00:47:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include <stdio.h>

void	show_data(t_win w)
{
	ft_printf("===============================\n");
	ft_printf("window size:\t(%d, %d)\n", w.size.x, w.size.y);
	ft_printf("window coor:\t lu=(%d, %d)", w.lu.x, w.lu.y);
	ft_printf("	.. rd=(%d, %d)\n", w.rd.x, w.rd.y);
	ft_printf("mouse down:\t(%d, %d)\n", w.md.x, w.md.y);
	ft_printf("mouse up:\t(%d, %d)\n", w.mu.x, w.mu.y);
	ft_printf("mouse move:\t(%d, %d)\n", w.mm.x, w.mm.y);
	ft_printf("shift:\t(%d, %d)\n", w.shift.x, w.shift.y);
	ft_printf("zoom:\t %d\n", w.zoom);
	ft_printf("iterations:\t%d\n", w.iteractions);
	ft_printf("image size:\t(%d, %d)\n", w.img.size.x, w.img.size.y);
	ft_printf("image coor:\t lu=(%d, %d)", w.img.lu.x, w.img.lu.y);
	ft_printf("	.. rd=(%d, %d)\n", w.img.rd.x, w.img.rd.y);
	ft_printf("image (0, 0):\t(%d, %d)\n", w.img.x_0, w.img.y_0);
	printf("image ratios:\t(%f, %f)\n", w.img.r_x, w.img.r_y);
	printf("image complex area:\t (%f, i%f)\n", w.img.real, w.img.imag);
	ft_printf("===============================\n");
}
