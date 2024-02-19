/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:56:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/19 10:16:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include "fractol.h"

/******************************************************************************/
/**
   @file is_ship.c
   @brief is_ship() Calculates if z belongs to the orbit of c.

   @param[in]  z: a complex number to determine if belongs or not ot the orbit
   of the c complex number.
   @param[in]  c: a complex number to determine if z belongs to c's orbit.
   @param[in]  palette: a RGB integer to multiply by escape iterations.

   @details
   Loops MAX_ITERATIONS times calculating 
   Zn = (|Re(Zn)| + i|Im(Zn)|)2 + C 
   while the real and the imaginary part of Zn are smaller than 2.

   if either the real or the imaginary part 'Escape' the boundaries (<= 2) then
   z does not belong to the ship set and deserves a color.
   if loop exhausts the iterations then z belongs to the ship set and gets the
   black color.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
int	is_ship(t_complex z0, t_complex c, int palette)
{
	t_complex	zn;
	short		n;

	n = 0;
	while ((z0.x <= 2) && (z0.y <= 2) && (n <= MAX_ITERATIONS))
	{
		zn = add(multiply(z0, z0), c);
		z0 = absolutize(zn);
		n++;
	}
	if (n <= MAX_ITERATIONS)
		return (n * palette);
	else
		return (BLACK);
}
