/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/16 22:31:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_data;

int win_h_key_press(int keysym, t_data *data);
int win_h_key_relea(int keysym, t_data *data);

#endif
