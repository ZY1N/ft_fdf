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
	return (ret);
}



void	print_struct(t_map map)
{
	/* char	**full_map;
	int		**int_map;
	int		x;
	int		y;
	int		upshift;
	int		downshift;
	int		leftshift;
	int		rightshift;
	void	*mlx_ptr;
	void	*win_ptr; */
	printf("x %d y %d up %d down %d left %d right %d\n", map.x, map.y, map.upshift, map.downshift, map.leftshift, map.rightshift);

	for(int y = 0; y < map.y; y++)
	{
		for(int x = 0; x < map.x; x++)
		{
			printf("%d", map.int_map[y][x]);
		}
		printf("\n");
	}
}
void	print_struct_ptr(t_map *map)
{
	/* char	**full_map;
	int		**int_map;
	int		x;
	int		y;
	int		upshift;
	int		downshift;
	int		leftshift;
	int		rightshift;
	void	*mlx_ptr;
	void	*win_ptr; */
	printf("x %d y %d up %d down %d left %d right %d\n", map->x, map->y, map->upshift, map->downshift, map->leftshift, map->rightshift);

	//for(int y = 0; y < map->y; y++)
//	{
//		for(int x = 0; x < map->x; x++)
		//{
			printf("%d", map->int_map[0][0]);
	//	}
	//	printf("\n");
	//}
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

	print_struct_ptr(map);
	if (key == 53)
		exit(1);
	if (key == 126) //upkey
	{
		maps.upshift += 5;
		((t_map *)map)->upshift += 5;
		//mlx_clear_window(((t_map *)map)->mlx_ptr, ((t_map *)map)->win_ptr);
		mlx_clear_window(maps.mlx_ptr, maps.win_ptr);
		//render(maps, maps.mlx_ptr, maps.win_ptr, 30);
	}
	//printf("upshift in keys function: %d\n", ((t_map *)map)->upshift);

	/*
	if (key == 124) //leftkey
		(t_map)map->rightshift += 5;
	if (key == 125) //downkey
		(t_map)map->downshift += 5;
	if (key == 123) //leftkey
		(t_map)map->leftshift += 5; */
	//printf("hello i waz here %d\n", key);
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
	win_ptr = mlx_new_window(mlx_ptr, main_map.x * 20, main_map.y * 20, "FDF");
	main_map.mlx_ptr = mlx_ptr;
	main_map.win_ptr = win_ptr;
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
	//win_ptr = mlx_new_window(mlx_ptr, 1500, 1500, "FDF_BETA");
	if (argc == 2 || argc == 4)
	{
		if (argc == 2)
		{
			fdf_driver(mlx_ptr, argv[1]);
		}
		//come back to finish this one
		if (argc == 4)
		{
			if (is_anum(argv[2]) && is_anum(argv[3]))
			{
//				case_size = ft_isdigit(3);
//				z_size = ft_atoi(argv[3]);
			}
		}
	}
	else
		printf("Usage : ./fdf <filename> [ case_size z_size ]");
}
