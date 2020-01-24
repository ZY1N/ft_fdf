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

#include "fdf.h"

t_map	map_populate(int x_size, int y_size, char *s, int i)
{
	int		fd;
	char	*line;
	t_map	main_map;

	main_map.x = x_size / y_size;
	main_map.y = y_size;
	main_map.full_map = malloc(sizeof(char *) * x_size);
	fd = open(s, O_RDONLY);
	if (fd < 0)
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

void	fdf_driver(void *mlx_ptr, char *s)
{
	int		x_size;
	int		y_size;
	t_map	main_map;
	void	*win_ptr;

	if (gather_size(&x_size, &y_size, s) == 0)
		exit(1);
	main_map = map_populate(x_size, y_size, s, 0);
	main_map = int_map_extraction(main_map, x_size, y_size);
	win_ptr = mlx_new_window(mlx_ptr, 1000, 750, "FDF");
	main_map = standard_settings(mlx_ptr, win_ptr, main_map);
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
