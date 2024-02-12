/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:13:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/12 09:26:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <stdio.h>

t_complex	create(float x, float y)
{
	t_complex	r;

	r.x = x;
	r.y = y;
	r.mod2 = x * x + y * y;
	return (r);
}

short	equal(t_complex a, t_complex b)
{
	return (a.x == b.x && a.y == b.y);
}

short	is_a_smaller_than_b(t_complex a, t_complex b)
{
	return (a.mod2 < b.mod2);
}

void	print(t_complex a)
{
	if (a.y > 0)
		printf("%f + %f i\n", a.x, a.y);
	else
		printf("%f  %f i\n", a.x, a.y);
}
