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

void	draw_line6(vector f, vector s, void *mlx_ptr, void *win_ptr)
{
	vector delta;
	vector sign;
	vector cur;
	int error[2];

	delta.x = abs(s.x - f.x);
	delta.y = abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, cur.x, cur.y, 123123312);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

/*
void blinealgo(vector f, vector s, void *mlx_ptr, void * win_ptr)
{
    vector delta;
    vector sign;
    vector cur;
    int error[2];

    delta.x = abs(s.x - f.x)
    delta.y = abs(s.y - f.y)
    sign.x = f.x < s.x ? 1 : -1;
    sign.y = f.y < s.y ? 1 : -1;
    error[0] = delta.x - delta.y;
    cur = f;

    while(cur.x != s.x || cur.y != s.y)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, cur.x, cur.y, 123123312);
        if((error[1] = error[0] * 2) > -delta.y)
    }
} */
