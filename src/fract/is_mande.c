/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:13:17 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/15 10:08:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_complex.h"
#include "fractol.h"
#include <stdio.h>

/******************************************************************************/
/**
   @file is_mande.c
   @brief is_mande() Calculates if z belongs to the orbit of c.

   @param[in]  z: a complex number to determine if belongs or not ot the orbit
   of the c complex number.

   @details
   Loops the 9 times calculating Zn = (Zn-1)2 + C.
   Verifies if it is a growing secuence.

   if it is not a growing secuence returns zero, (black color).
   if it is a growing secuence returns a color. A color made of the bigger
   number of the secuence module 255 * 255 * 255 (RGB NUM COLORS)

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
int	is_mande(t_complex c, t_complex z0, int palette)
{
	t_complex	zn;
	short		n;

	n = 0;
	while ((z0.x <= 2) && (z0.y <= 2) && (n <= MAX_ITERATIONS))
	{
		zn = add(multiply(z0, z0), c);
		z0 = zn;
		n++;
	}
//	printf("%d\n ", n);
	if (n <= MAX_ITERATIONS)
		return (n * palette);
	else
		return (BLACK);
}
