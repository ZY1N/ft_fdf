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

void draw_verticle(map this, void *mlx_ptr, void *win_ptr)
{
	int flag = 0;
	vector v;
	vector2 temp;
	vector2 v2;

	for(int x = 0; x < this.x; x++)
	{
		for(int y = 0; y < this.y; y++)
		{
			v.x = x * 10;
			v.y = y * 10;
			v.z = this.int_map[y][x] * -10;
			float radx = 30 * 3.14/180;
			float rady = 30 * 3.14/180;
			v = rotationdriver(v, radx, rady, radx);
			v.x += 750;
			v.y += 750;
			v.z += 750;
			v2.x = v.x;
			v2.y = v.y;
			v2.z = v.z;			
			if(flag == 1)
				draw_line6(temp, v2, mlx_ptr, win_ptr);
			temp.x = v.x;
			temp.y = v.y;
			temp.z = v.z;
			flag = 1;
		}
	}

}

void render(map this, void *mlx_ptr, void *win_ptr)
{
	vector v;
	vector2 temp;
	vector2 v2;

	int flag = 0;

	for(int y = 0; y < this.y; y++)
	{
		for(int x = 0; x < this.x; x++)
		{
			v.x = x * 10;
			v.y = y * 10;
			v.z = this.int_map[y][x] * -10;
			float radx = 30 * 3.14/180;
			float rady = 30 * 3.14/180;
			v = rotationdriver(v, radx, rady, radx);
			v.x += 750;
			v.y += 750;
			v.z += 750;
			v2.x = v.x;
			v2.y = v.y;
			v2.z = v.z;
			if(flag == 1)
				draw_line6(temp, v2, mlx_ptr, win_ptr);
			temp.x = v.x;
			temp.y = v.y;
			temp.z = v.z;
			flag = 1;
		}
	}
	draw_verticle(this, mlx_ptr, win_ptr);
}

