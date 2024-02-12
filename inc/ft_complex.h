/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:05:17 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/12 08:16:14 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

/* ************************************************************************** */
/* x: holds the real part of a complex number.                                */
/* y: holds the imaginary part of a complex number.                           */
/* mod2 : holds the square of the module. I do that to avoid sqrt()           */
/* ************************************************************************** */
typedef struct s_complex
{
	float	x;
	float	y;
	float	mod2;
}	t_complex;

t_complex	create(float x, float y);
short		equal(t_complex a, t_complex b);
short		is_a_smaller_than_b(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);
t_complex	substract(t_complex a, t_complex b);
t_complex	multiply_by_float(t_complex a, float r);
t_complex	multiply(t_complex a, t_complex b);
t_complex	divide_by_float(t_complex a, float r);
t_complex	divide(t_complex a, t_complex b);
void		print(t_complex a);

# endif
