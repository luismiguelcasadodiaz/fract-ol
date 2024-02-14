/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/14 12:26:23 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	show_usage()
{
	ft_printf("USAGE:./fractol <name> <real part> <imaginary part>\n");
	ft_printf("WHERE:<name> Mandelbrot or Julia.\n");
	ft_printf("NOTE: Mandelbrot does not consider other arguments.\n");
	return ;
}
