/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:59:02 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/19 18:04:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H
# define COMPLEX_REAL_MAX 2.0
# define COMPLEX_IMAG_MAX 2.0
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
t_complex	absolutize(t_complex a);
short		equal(t_complex a, t_complex b);
short		is_a_smaller_than_b(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);
t_complex	substract(t_complex a, t_complex b);
t_complex	multiply_by_float(t_complex a, float r);
t_complex	multiply(t_complex a, t_complex b);
t_complex	divide_by_float(t_complex a, float r);
t_complex	divide(t_complex a, t_complex b);
void		print(t_complex a);

#endif
