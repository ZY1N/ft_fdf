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
#define FDF_H

#include "./libft/libft.h"
#include <stdio.h>
#include "minilibx/mlx.h"
#include <math.h>

typedef struct map
{
	char	**full_map;
	int		**int_map;
	int		x;
	int		y;
} map;

/*typedef struct vector

	float	x;
	float	y;
	float	z;
} vector; */

typedef	struct matrix
{
	float rotatex[3][3];
} matrix;

typedef struct vector
{	
	int		x;
	int		y;
	int		z;
} vector;

vector	iso(vector v);
void	rotate_x(float *y, float *z, double alpha);
void	rotate_y(float *x, float *z, double beta);
void	rotate_z(float *x, float *y, double gamma);


void	draw_line(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr);
vector	mathmult(vector point);
vector	mathmult2(vector point, float angle);
void	bresenham(int x1, int y1, int x2, int y2, void *mlx_ptr, void * win_ptr);
void	bresenham2(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr) ;
void	draw_line6(vector f, vector s, void * mlx_ptr, void * win_ptr);
vector	rotation(vector point, float angle_x, float angle_y, float angle_z);
//void	render(map this, void *mlx_ptr, void *win_ptr);
vector	iso_rotation(vector point, float angle_x, float angle_y);
vector	rotate_test(vector v, float radx, float rady);
//vector	rotationdriver(vector point, float angle_x, float angle_y, float angle_z);
vector	rotationdriver(vector point, float a_x, float a_y, float a_z);
vector	rotatez(vector point, float angle_x, float angle_y, float angle_z);
vector	rotatey(vector point, float angle_x, float angle_y, float angle_z);
vector	rotatex(vector point, float angle_x, float angle_y, float angle_z);
void	render(map this, void *mlx_ptr, void *win_ptr, float angle);

#endif
