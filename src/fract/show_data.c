/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:24:03 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/22 12:49:30 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include <stdio.h>

void	show_data(t_win w)
{
	ft_printf("===============================\n");
	ft_printf("window size:\t(%d, %d)\n", w.w,  w.h);
	ft_printf("window coor:\t lu=(%d, %d)", w.lu_x, w.lu_y);
	ft_printf("	.. rd=(%d, %d)\n", w.rd_x, w.rd_y);
	ft_printf("mouse down:\t(%d, %d)\n", w.md_x, w.md_y);
	ft_printf("mouse up:\t(%d, %d)\n", w.mu_x, w.mu_y);
	ft_printf("mouse move:\t(%d, %d)\n", w.mm_x, w.mm_y);
	ft_printf("shift:\t(%d, %d)\n", w.shift_x, w.shift_y);
	ft_printf("zoom:\t %d\n", w.zoom);
	ft_printf("iterations:\t%d\n", w.iteractions);
	ft_printf("image size:\t(%d, %d)\n", w.img.w, w.img.h);
	ft_printf("image coor:\t lu=(%d, %d)", w.img.lu_x, w.img.lu_y);
	ft_printf("	.. rd=(%d, %d)\n", w.img.rd_x, w.img.rd_y);
	ft_printf("image (0, 0):\t(%d, %d)\n", w.img.x_0, w.img.y_0);
	printf("image ratios:\t(%f, %f)\n", w.img.r_x, w.img.r_y);
	printf("image complex area:\t (%f, i%f)\n", w.img.real, w.img.imag);
	ft_printf("===============================\n");
}
