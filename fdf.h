/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:23:44 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/07 20:29:09 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <stdio.h>
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_map
{
	char	**full_map;
	int		**int_map;
	int		x;
	int		y;
	int		upshift;
	int		downshift;
	int		leftshift;
	int		rightshift;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_map;

typedef struct	s_vector
{
	int		x;
	int		y;
	int		z;
}				t_vector;

typedef struct s_rad
{
	double radx;
	double rady;
	double radz;
}				t_rad;

typedef struct s_coord
{
	int		x;
	int		y;
}				t_coord;

void			drawl(t_vector f, t_vector s, void *mlx_ptr, void *win_ptr);
t_vector		rotdriver(t_vector point, double a_x, double a_y, double a_z);
void			render(t_map this, void *mlx_ptr, void *win_ptr, double angle);

#endif
