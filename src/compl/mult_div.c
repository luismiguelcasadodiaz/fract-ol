/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:18:37 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/19 18:03:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex	multiply_by_float(t_complex a, float r)
{
	t_complex	c;

	c.x = a.x * r;
	c.y = a.y * r;
	c.mod2 = c.x * c.x + c.y * c.y;
	return (c);
}

t_complex	multiply(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = (a.x * b.x) - (a.y * b.y);
	c.y = (a.x * b.y) + (a.y * b.x);
	c.mod2 = c.x * c.x + c.y * c.y;
	return (c);
}

t_complex	divide_by_float(t_complex a, float r)
{
	t_complex	c;

	c.x = a.x / r;
	c.y = a.y / r;
	c.mod2 = c.x * c.x + c.y * c.y;
	return (c);
}

t_complex	divide(t_complex a, t_complex b)
{
	t_complex	c;
	float		divisor;

	divisor = b.x * b.x + b.y * b.y;
	c.x = ((a.x * b.x) + (a.y * b.y)) / divisor;
	c.y = ((a.y * b.x) - (a.x * b.y)) / divisor;
	c.mod2 = c.x * c.x + c.y * c.y;
	return (c);
}
