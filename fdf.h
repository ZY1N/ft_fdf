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
# include "get_next_line.h"

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
	int		elongate;
	int		scale;
	void	*mlx_ptr;
	void	*win_ptr;
	double	anglex;
	double	angley;
	double	anglez;
	int		scalex;
	int		scaley;
	int		scalez;
	int		color;
	int		coloradj;
	int		gradon;
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

#define ESC 53
#define UP 126
#define RIGHT 124
#define DOWN 125
#define LEFT 123 
#define OKEY 31
#define PKEY 35
#define RKEY 15
#define TKEY 17
#define YKEY 16
#define FKEY 3
#define GKEY 5
#define HKEY 4
#define ONEKEY 18
#define TWOKEY 19
#define ZKEY 6
#define UKEY 32
#define IKEY 34
#define CKEY 8
#define VKEY 9

void			drawl(t_vector f, t_vector s, void *mlx_ptr, void *win_ptr, t_map this);
t_vector		rotdriver(t_vector point, double a_x, double a_y, double a_z);
void			render(t_map this, void *mlx_ptr, void *win_ptr, double angle);
int			keys(int key, void *map);
void		key_1(int key, void *map, t_map maps);
void		key_2(int key, void *map, t_map maps);
void		key_3(int key, void *map, t_map maps);
void		key_4(int key, void *map, t_map maps);
void		key_5(int key, void *map, t_map maps);
t_map		copymapfrompointer(t_map *map);
t_map	standard_settings(void *mlx_ptr, void *win_ptr, t_map main_map);
t_map	copymapfrompointer(t_map *map);
void	freestuff(int y_size, t_map main_map, int i);
int		is_anum(char *s);
void	gofindstuff(char *s, int *x_size, int *y_size);

#endif
