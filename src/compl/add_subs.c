/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_subs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:18:09 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 11:18:18 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.mod2 = c.x * c.x + c.y * c.y;
	return (c);
}

t_complex	substract(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.mod2 = c.x * c.x + c.y * c.y;
	return (c);
}
