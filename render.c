/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:37:26 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/13 19:45:22 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	rot_scale_projection(t_coord coord, t_map map, float scale, t_rad r)
{
	t_vector v;

	v.x = coord.x * scale;
	v.y = coord.y * scale;
	v.z = map.int_map[coord.y][coord.x] * -scale;
	v = rotdriver(v, r.radx, r.rady, r.radz);
	v.x += 750;
	v.y += 750;
	v.z += 750;
	return (v);
}

void		draw_verticle(t_map this, void *mlx_ptr, void *win_ptr, t_rad rad)
{
	int			flag;
	t_vector	v;
	t_vector	temp;
	float		scale;
	t_coord		coord;

	coord.x = 0;
	flag = 0;
	scale = 10;
	while (coord.x < this.x)
	{
		coord.y = 0;
		while (coord.y < this.y)
		{
			v = rot_scale_projection(coord, this, scale, rad);
			if (flag == 1)
				drawl(temp, v, mlx_ptr, win_ptr);
			temp = v;
			flag = 1;
			coord.y++;
		}
		coord.x++;
	}
}

void		draw_horizontal(t_map this, void *mlx_ptr, void *win_ptr, t_rad rad)
{
	int			flag;
	t_vector	v;
	t_vector	temp;
	float		scale;
	t_coord		coord;

	flag = 0;
	coord.y = 0;
	scale = 10;
	while (coord.y < this.y)
	{
		coord.x = 0;
		while (coord.x < this.x)
		{
			v = rot_scale_projection(coord, this, scale, rad);
			if (flag == 1)
				drawl(temp, v, mlx_ptr, win_ptr);
			temp = v;
			flag = 1;
			coord.x++;
		}
		coord.y++;
	}
}

void		render(t_map this, void *mlx_ptr, void *win_ptr, double angle)
{
	t_rad rad;

	rad.radx = angle * 3.14 / 180;
	rad.rady = angle * 3.14 / 180;
	rad.radz = angle * 3.14 / 180;
	draw_horizontal(this, mlx_ptr, win_ptr, rad);
	draw_verticle(this, mlx_ptr, win_ptr, rad);
}
