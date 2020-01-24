/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:35:07 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/21 15:47:17 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line.h"
#include "fdf.h"

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

t_map	map_populate(int x_size, int y_size, char *s)
{
	int		fd;
	int		i;
	char	*line;
	t_map	main_map;

	i = 0;
	main_map.x = x_size / y_size;
	main_map.y = y_size;
	main_map.full_map = malloc(sizeof(char *) * x_size);
	fd = open(s, O_RDONLY);
	if(fd < 0)
	{
		printf("FAILURE\n");
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		main_map.full_map[i] = line;
		i++;
	}
	close(fd);
	main_map.upshift = 0; 
	main_map.downshift = 0;
	main_map.leftshift = 0;
	main_map.rightshift = 0;
	return (main_map);
}

t_map	int_map_extraction(t_map main_map, int x_size, int y_size)
{
	int		i;
	int		x;
	char	**split;

	i = 0;
	x = 0;
	main_map.int_map = malloc(sizeof(int *) * x_size);
	while (i < y_size)
	{
		main_map.int_map[i] = malloc(sizeof(int) * x_size);
		split = ft_strsplit(main_map.full_map[i], ' ');
		x = 0;
		while (split[x])
		{
			main_map.int_map[i][x] = ft_atoi(split[x]);
			free(split[x]);
			x++;
		}
		free(split);
		i++;
	}
	return (main_map);
}

int		gather_size(int *x_size, int *y_size, char *s)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		printf("Usage : ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		gofindstuff(line, x_size, y_size);
		free(line);
	}
	close(fd);
	return (1);
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

void	rerender(t_map map)
{
	mlx_clear_window(map.mlx_ptr, map.win_ptr);
	render(map, map.mlx_ptr, map.win_ptr, 30);
}

int 	keys(int key, void *map)
{
	t_map maps;

	maps = copymapfrompointer(map);
	if (key == ESC)
		exit(1);
	if (key == UP) //upkey
	{
		maps.upshift -= 15;
		((t_map *)map)->upshift -= 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == RIGHT) //leftkey
	{
		maps.rightshift += 15;
		((t_map *)map)->rightshift += 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == DOWN) //downkey
	{
		maps.downshift += 15;
		((t_map *)map)->downshift += 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}	
	if (key == LEFT) //leftkey
	{
		maps.leftshift -= 15;
		((t_map *)map)->leftshift -= 15;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}

	if (key == OKEY) //okey zoom in
	{
		maps.scale += 5;
		((t_map *)map)->scale += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	
	if (key == PKEY) //pkey zoom out
	{
		maps.scale -= 5;
		((t_map *)map)->scale -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}

	if (key == RKEY) //rkey
	{
		maps.anglex -= 5;
		((t_map *)map)->anglex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == TKEY) //tkey
	{
		maps.angley -= 5;
		((t_map *)map)->angley -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == YKEY) //ykey
	{
		maps.anglez -= 5;
		((t_map *)map)->anglez -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}

	if (key == FKEY) //fkey
	{
		maps.anglex += 5;
		((t_map *)map)->anglex += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == GKEY) //gkey
	{
		maps.angley += 5;
		((t_map *)map)->angley += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == HKEY) //hkey
	{
		maps.anglez += 5;
		((t_map *)map)->anglez += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
		if (key == ONEKEY) //1key
	{
		maps.scalex += 5;
		((t_map *)map)->scalex += 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == TWOKEY) //2key
	{
		maps.scalex -= 5;
		((t_map *)map)->scalex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == ZKEY) //zkey
	{
		maps.scalex -= 5;
		((t_map *)map)->scalex -= 5;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == UKEY) //ukey
	{
		maps.anglex = 30;
		maps.angley = 30;
		maps.anglez = 30;
		((t_map *)map)->anglex = 30;
		((t_map *)map)->angley = 30;
		((t_map *)map)->anglez = 30;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}	
	if (key == IKEY) //ikey
	{
		maps.anglex = 45;
		maps.angley = 45;
		maps.anglez = 45;
		((t_map *)map)->anglex = 45;
		((t_map *)map)->angley = 45;
		((t_map *)map)->anglez = 45;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == CKEY) //ckey
	{
		maps.color = rand();
		((t_map *)map)->color = maps.color;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	if (key == VKEY) //vkey
	{
		maps.gradon = 1;
		((t_map *)map)->gradon = 1;
		render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	return (1);
}

void	fdf_driver(void *mlx_ptr, char *s)
{
	int		x_size;
	int		y_size;
	t_map	main_map;
	void	*win_ptr;

	if (gather_size(&x_size, &y_size, s) == 0)
		exit (1);
	main_map = map_populate(x_size, y_size, s);
	main_map = int_map_extraction(main_map, x_size, y_size);
	main_map.scale = 600/(main_map.x);
	win_ptr = mlx_new_window(mlx_ptr, 1000, 750, "FDF");
	main_map.mlx_ptr = mlx_ptr;
	main_map.win_ptr = win_ptr;
	//main_map.scale = 20;
	main_map.anglex = 30;
	main_map.angley = 30;
	main_map.anglez = 30;
	main_map.scalex = 10;
	main_map.scaley = 10;
	main_map.scalez = 10;
	main_map.color = 123123312;
	main_map.coloradj = 100;
	main_map.rightshift = (1000 - main_map.x * main_map.scale);
	main_map.upshift = (750 - main_map.y * main_map.scale)/2;
	printf("y %d\n", main_map.y);
	printf("x %d\n", main_map.x);
	//(main_map.y * 50) - main_map.y * 20)/2;
	render(main_map, mlx_ptr, win_ptr, 30);
	mlx_hook(win_ptr, 2, 0, keys, &main_map);
	mlx_loop(mlx_ptr);
	free(win_ptr);
	freestuff(y_size, main_map, 0);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (argc == 2)
	{
		fdf_driver(mlx_ptr, argv[1]);
	}
	else
		printf("Usage : ./fdf <filename> [ case_size z_size ]");
}
