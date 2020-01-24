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
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == RIGHT)
	{
		maps.rightshift += 15;
		((t_map *)map)->rightshift += 15;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == DOWN)
	{
		maps.downshift += 15;
		((t_map *)map)->downshift += 15;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == LEFT)
	{
		maps.leftshift -= 15;
		((t_map *)map)->leftshift -= 15;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
}

void	key_2(int key, void *map, t_map maps)
{
	if (key == OKEY)
	{
		maps.scale += 5;
		((t_map *)map)->scale += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == PKEY)
	{
		maps.scale -= 5;
		((t_map *)map)->scale -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == RKEY)
	{
		maps.anglex -= 5;
		((t_map *)map)->anglex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == TKEY)
	{
		maps.angley -= 5;
		((t_map *)map)->angley -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
}

void	key_3(int key, void *map, t_map maps)
{
	if (key == YKEY)
	{
		maps.anglez -= 5;
		((t_map *)map)->anglez -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == FKEY)
	{
		maps.anglex += 5;
		((t_map *)map)->anglex += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == GKEY)
	{
		maps.angley += 5;
		((t_map *)map)->angley += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
	if (key == HKEY)
	{
		maps.anglez += 5;
		((t_map *)map)->anglez += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr);
	}
}

int		keys(int key, void *map)
{
	t_map maps;

	maps = copymapfrompointer(map);
	key_1(key, map, maps);
	key_2(key, map, maps);
	key_3(key, map, maps);
	key_4(key, map, maps);
	key_5(key, map, maps);
	key_6(key, map, maps);
	return (1);
}
