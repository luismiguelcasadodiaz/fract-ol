/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:16:07 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/09 20:07:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <stdio.h>

t_complex	create(float x, float y)
{
	t_complex r;
	r.x = x;
	r.y = y;
	return (r);
}


short	equal(t_complex a, t_complex b)
{
	return (a.x == b.x && a.y == b.y);
}

t_complex	add(t_complex a, t_complex b) 
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	substract(t_complex a, t_complex b) 
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	multiply_by_float(t_complex a, float r) 
{
	t_complex	c;

	c.x = a.x * r;
	c.y = a.y * r;
	return (c);
}

t_complex	multiply(t_complex a, t_complex b) 
{
	t_complex	c;

	c.x = (a.x * b.x) - (a.y * b.y);
	c.y = (a.x * b.y) + (a.y * b.x);
	return (c);
}

t_complex	divide_by_float(t_complex a, float r) 
{
	t_complex	c;

	c.x = a.x / r;
	c.y = a.y / r;
	return (c);
}

t_complex	divide(t_complex a, t_complex b) 
{
	t_complex	c;
	float		divisor;

	divisor = b.x * b.x + b.y * b.y;
	c.x = ((a.x * b.x) + (a.y * b.y)) / divisor;
	c.y = ((a.y * b.x) - (a.x * b.y)) / divisor;
	return (c);
}

void	print(t_complex a)
{
	if (a.y > 0)
		printf("%f + %f i\n", a.x, a.y);
	else
		printf("%f  %f i\n", a.x, a.y);

}
