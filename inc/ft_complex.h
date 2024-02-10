/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:05:17 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/09 19:34:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	float	x;
	float	y;
	float	phi;
}	t_complex;

t_complex	create(float x, float y);
short		equal(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);
t_complex	substract(t_complex a, t_complex b);
t_complex	multiply_by_float(t_complex a, float r);
t_complex	multiply(t_complex a, t_complex b);
t_complex	divide_by_float(t_complex a, float r);
t_complex	divide(t_complex a, t_complex b);
void		print(t_complex a);

# endif
