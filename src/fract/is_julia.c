/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:56:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 16:35:12 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

/******************************************************************************/
/**
   @file is_julia.c
   @brief is_julia() Calculates if z belongs to the orbit of c.

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
int	is_julia(t_complex z, t_complex c)
{
	t_complex	z0;
	t_complex	zn[8];
	short		n;
	short		grows;

	zo = z;
	n = 0;
	while (n <= 8)
	{
		zn[n] = add(multiply(z0, z0), c);
		z0 = zn[n++];
		print(zn[n]);
	}
	n = 0;
	grows = 1;
	while (n < 8)
	{
		grows = grows && is_a_smaller_than_b(z[n], z[n + 1]);
		n++;
	}
	if (grows)
		return (zn[8].mod2 % (255 * 255 * 255));
	else
		return (0);
}
