/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:10:26 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/24 13:10:27 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	standard_settings(void *mlx_ptr, void *win_ptr, t_map main_map)
{
	main_map.scale = 600 / (main_map.x);
	main_map.mlx_ptr = mlx_ptr;
	main_map.win_ptr = win_ptr;
	main_map.anglex = 30;
	main_map.angley = 30;
	main_map.anglez = 30;
	main_map.scalex = 10;
	main_map.scaley = 10;
	main_map.scalez = 10;
	main_map.color = 123123312;
	main_map.coloradj = 100;
	main_map.rightshift = (1000 - main_map.x * main_map.scale);
	main_map.upshift = (750 - main_map.y * main_map.scale) / 2;
	return (main_map);
}

t_map	copymapfrompointer(t_map *map)
{
	t_map ret;

	ret.full_map = map->full_map;
	ret.int_map = map->int_map;
	ret.x = map->x;
	ret.y = map->y;
	ret.upshift = map->upshift;
	ret.downshift = map->downshift;
	ret.leftshift = map->leftshift;
	ret.rightshift = map->rightshift;
	ret.mlx_ptr = map->mlx_ptr;
	ret.win_ptr = map->win_ptr;
	ret.scale = map->scale;
	ret.anglex = map->anglex;
	ret.angley = map->angley;
	ret.anglez = map->anglez;
	ret.scalex = map->scalex;
	ret.scaley = map->scaley;
	ret.scalez = map->scalez;
	ret.color = map->color;
	ret.coloradj = map->coloradj;
	return (ret);
}

void	freestuff(int y_size, t_map main_map, int i)
{
	while (i < y_size)
	{
		free(main_map.int_map[i]);
		free(main_map.full_map[i]);
		i++;
	}
	free(main_map.full_map);
	free(main_map.int_map);
}

int		is_anum(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	gofindstuff(char *s, int *x_size, int *y_size)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] && s[i] != ' ')
				i++;
			(*x_size)++;
			continue;
		}
		i++;
	}
	(*y_size)++;
}