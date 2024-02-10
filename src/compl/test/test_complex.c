/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:09:54 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/09 20:16:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

int	main(void)
{
	t_complex a;
	t_complex b;
	t_complex c;

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
	
