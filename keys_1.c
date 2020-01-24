/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:06:53 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/24 13:06:55 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_1(int key, void *map, t_map maps)
{
	if (key == UP)
	{
		maps.upshift -= 15;
		((t_map *)map)->upshift -= 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == RIGHT)
	{
		maps.rightshift += 15;
		((t_map *)map)->rightshift += 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == DOWN)
	{
		maps.downshift += 15;
		((t_map *)map)->downshift += 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == LEFT)
	{
		maps.leftshift -= 15;
		((t_map *)map)->leftshift -= 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
}

void	key_2(int key, void *map, t_map maps)
{
	if (key == OKEY)
	{
		maps.scale += 5;
		((t_map *)map)->scale += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == PKEY)
	{
		maps.scale -= 5;
		((t_map *)map)->scale -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == RKEY)
	{
		maps.anglex -= 5;
		((t_map *)map)->anglex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == TKEY)
	{
		maps.angley -= 5;
		((t_map *)map)->angley -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
}

void	key_3(int key, void *map, t_map maps)
{
	if (key == YKEY)
	{
		maps.anglez -= 5;
		((t_map *)map)->anglez -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == FKEY)
	{
		maps.anglex += 5;
		((t_map *)map)->anglex += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == GKEY)
	{
		maps.angley += 5;
		((t_map *)map)->angley += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == HKEY)
	{
		maps.anglez += 5;
		((t_map *)map)->anglez += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
}

void	key_4(int key, void *map, t_map maps)
{
	if (key == ONEKEY)
	{
		maps.scalex += 5;
		((t_map *)map)->scalex += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == TWOKEY)
	{
		maps.scalex -= 5;
		((t_map *)map)->scalex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == ZKEY)
	{
		maps.scalex -= 5;
		((t_map *)map)->scalex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
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
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == IKEY)
	{
		maps.anglex = 45;
		maps.angley = 45;
		maps.anglez = 45;
		((t_map *)map)->anglex = 45;
		((t_map *)map)->angley = 45;
		((t_map *)map)->anglez = 45;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
}

int		keys(int key, void *map)
{
	t_map maps;

	maps = copymapfrompointer(map);
	if (key == ESC)
		exit(1);
	key_1(key, map, maps);
	key_2(key, map, maps);
	key_3(key, map, maps);
	key_4(key, map, maps);
	key_5(key, map, maps);
	if (key == CKEY)
	{
		maps.color = rand();
		((t_map *)map)->color = maps.color;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == VKEY)
	{
		maps.gradon = 1;
		((t_map *)map)->gradon = 1;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	return (1);
}
