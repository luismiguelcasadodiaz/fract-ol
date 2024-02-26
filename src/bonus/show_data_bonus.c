/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:24:03 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 12:23:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

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
	ft_printf("bpp =(%d)\n", w.img.bits_per_pixel);
	ft_printf("ll=(%d)\n", w.img.line_length);
	ft_printf("endian=(%d)\n", w.img.endian);
	ft_printf(" addr=(%s)\n", w.img.addr);
	ft_printf("===============================\n");
}
