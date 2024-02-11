/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:22:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 11:23:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

int	main(void)
{
	t_complex	a;
	t_complex	b;
	t_complex	c;

	a = create(3, -2);
	print(a);
	b = create(5, 6);
	print(b);
	c = add(a, b);
	print(c);
	c = multiply(a, b);
	print(c);
	a = create(5, -3);
	b = create(4, 2);
	c = divide(a, b);
	print(c);
}
