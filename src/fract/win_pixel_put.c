/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:54:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/19 10:30:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

void	win_pixel_put(t_win w, int x, int y, int color)
{
	char	*dst;
	int		offset_y;
	int		offset_x;

	offset_y = y * w.img.line_length;
	offset_x = x * (w.img.bits_per_pixel / 8);
	dst = w.img.addr + offset_y + offset_x;
	*(unsigned int *)dst = color;
}
