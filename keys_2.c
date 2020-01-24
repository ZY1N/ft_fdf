/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:20:56 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/24 13:20:58 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_4(int key, void *map, t_map maps)
{
	if (key == ONEKEY)
	{
		maps.scalex += 5;
		((t_map *)map)->scalex += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == TWOKEY)
	{
		maps.scalex -= 5;
		((t_map *)map)->scalex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == ZKEY)
	{
		maps.scalex -= 5;
		((t_map *)map)->scalex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
}

void	key_5(int key, void *map, t_map maps)
{
	if (key == UKEY)
	{
		maps.anglex = 30;
		maps.angley = 30;
		maps.anglez = 30;
		((t_map *)map)->anglex = 30;
		((t_map *)map)->angley = 30;
		((t_map *)map)->anglez = 30;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == IKEY)
	{
		maps.anglex = 45;
		maps.angley = 45;
		maps.anglez = 45;
		((t_map *)map)->anglex = 45;
		((t_map *)map)->angley = 45;
		((t_map *)map)->anglez = 45;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
}

void	key_6(int key, void *map, t_map maps)
{
	if (key == CKEY)
	{
		maps.color = rand();
		((t_map *)map)->color = maps.color;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == VKEY)
	{
		maps.gradon = 1;
		((t_map *)map)->gradon = 1;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == ESC)
		exit(1);
}
