/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/15 11:21:38 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fractol.h"

void	show_usage()
{
	int w_ran;
	int h_ran;

	w_ran = WINDOW_W / 2;
	h_ran = WINDOW_H / 2;

	ft_printf("USAGE:./fractol <name> <real part> <imaginary part>\n");
	ft_printf("WHERE:<name> Mandelbrot or Julia.\n");
	ft_printf("NOTE: Mandelbrot does not consider other arguments.\n");
	ft_printf("NOTE: <real part> in range [-%d..%d]\n", w_ran, w_ran);
	ft_printf("NOTE: <imaginary> in range [-%d..%d]\n", h_ran, h_ran);
	return ;
}
