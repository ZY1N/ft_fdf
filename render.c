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

	v.x = coord.x * map.scale;
	v.y = coord.y * map.scale;
	v.z = map.int_map[coord.y][coord.x] * -map.scalex;
	v = rotdriver(v, r.radx, r.rady, r.radz);
	v.x = v.x + map.leftshift + map.rightshift;
	v.y = v.y + map.upshift + map.downshift;
	v.z = v.z + map.elongate;

	//printf("upshift in rot %d\n", map.upshift);
	//v.x += map.leftshift + map.rightshift;
	//v.y += map.upshift + map.downshift;
	//v.z += ;
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
			v = rot_scale_projection(coord, this, this.scale, rad);
			if (flag == 1)
				drawl(temp, v, mlx_ptr, win_ptr, this);
			temp = v;
			flag = 1;
			if (coord.y + 1 == this.y)
				flag = 0;
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
			v = rot_scale_projection(coord, this, this.scale, rad);
			if (flag == 1)
				drawl(temp, v, mlx_ptr, win_ptr, this);
			temp = v;
			flag = 1;
			if (coord.x + 1 == this.x)
				flag = 0;
			coord.x++;
		}
		coord.y++;
	}
}

void	print_menu(void *mlx_ptr, void *win_ptr, int color)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char *str5;
	char *str6;
	char *str7;

	str1 = "Menu Controls";
	str2 = "Shift: Arrow Keys: < ^ v >";
	str3 = "Rotate: R T Y F G H";
	str4 = "Zoom: O P";
	str5 = "Protusion 1 2";
	str6 = "ISO U Topdown I";
	str7 = "Color C Gradient V";
	mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0xffffff, str1);
	mlx_string_put(mlx_ptr, win_ptr, 10, 40, 0xadadad, str2);
	mlx_string_put(mlx_ptr, win_ptr, 10, 60, 0xadadad, str3);
	mlx_string_put(mlx_ptr, win_ptr, 10, 80, 0xadadad, str4);
	mlx_string_put(mlx_ptr, win_ptr, 10, 100, 0xadadad, str5);
	mlx_string_put(mlx_ptr, win_ptr, 10, 120, 0xadadad, str6);
	mlx_string_put(mlx_ptr, win_ptr, 10, 140, 0xadadad, str7);
}

void		render(t_map this, void *mlx_ptr, void *win_ptr, double angle)
{
	t_rad rad;

	mlx_clear_window(this.mlx_ptr, this.win_ptr);
	rad.radx = this.anglex * 3.14 / 180;
	rad.rady = this.angley * 3.14 / 180;
	rad.radz = this.anglez * 3.14 / 180;
	draw_horizontal(this, mlx_ptr, win_ptr, rad);
	draw_verticle(this, mlx_ptr, win_ptr, rad);
	print_menu(mlx_ptr, win_ptr, 1);
}
