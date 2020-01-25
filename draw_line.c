/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:23:14 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/10 11:23:15 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawl(t_vector f, t_vector s, t_map map)
{
	t_vector	delta;
	t_vector	sign;
	t_vector	cur;
	int			error1;
	int			error2;

	delta.x = abs(s.x - f.x);
	sign.x = f.x < s.x ? 1 : -1;
	delta.y = -abs(s.y - f.y);
	sign.y = f.y < s.y ? 1 : -1;
	error1 = delta.x + delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		error2 = 2 * error1;
		if (map.gradon == 1)
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, cur.x, cur.y,
				map.color + (map.coloradj * cur.x));
		else
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, cur.x, cur.y, map.color);
		if (error2 >= delta.y)
		{
			error1 += delta.y;
			cur.x += sign.x;
		}
		if (error2 <= delta.x)
		{
			error1 += delta.x;
			cur.y += sign.y;
		}
	}
}
