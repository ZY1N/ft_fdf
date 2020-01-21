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

void	draw_verticle(map this, void *mlx_ptr, void *win_ptr, float radx, float rady)
{
	int		flag;
	vector	v;
	vector	temp;
	int		x;
	int		y;

	x = 0;
	flag = 0;
	while (x < this.x)
	{
		y = 0;
		while (y < this.y)
		{
			v.x = x * 10;
			v.y = y * 10;
			v.z = this.int_map[y][x] * -10;
			v = rotationdriver(v, radx, rady, radx);
			v.x += 750;
			v.y += 750;
			v.z += 750;
			if (flag == 1)
				draw_line6(temp, v, mlx_ptr, win_ptr);
			temp.x = v.x;
			temp.y = v.y;
			temp.z = v.z;
			flag = 1;
			y++;
		}
		x++;
	}
}

void	draw_horizontal(map this, void *mlx_ptr, void *win_ptr, float radx, float rady)
{
	int		flag;
	vector	v;
	vector	temp;
	int		x;
	int		y;

	flag = 0;
	y = 0;
	while (y < this.y)
	{
		x = 0;
		while (x < this.x)
		{
			v.x = x * 10;
			v.y = y * 10;
			v.z = this.int_map[y][x] * -10;
			v = rotationdriver(v, radx, rady, radx);
			v.x += 750;
			v.y += 750;
			v.z += 750;
			if (flag == 1)
				draw_line6(temp, v, mlx_ptr, win_ptr);
			temp.x = v.x;
			temp.y = v.y;
			temp.z = v.z;
			flag = 1;
			x++;
		}
		y++;
	}
}



void	render(map this, void *mlx_ptr, void *win_ptr, float angle)
{
	float	radx;
	float	rady;

	radx = angle * 3.14 / 180;
	rady = angle * 3.14 / 180;
	draw_horizontal(this, mlx_ptr, win_ptr, radx, rady);
	draw_verticle(this, mlx_ptr, win_ptr, radx, rady);
}
