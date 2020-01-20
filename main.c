/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:35:07 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/08 12:25:45 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line.h"
#include "fdf.h"

void	freestuff(int y_size, map main_map, int i)
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

map		map_populate(int x_size, int y_size, char *s, map main_map)
{
	int		fd;
	int		i;
	char	*line;

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
	return (main_map);
}

map		int_map_extraction(map main_map, int x_size, int y_size)
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

int		main(int argc, char **argv)
{
	int		x_size;
	int		y_size;
	void	*mlx_ptr;
	void	*win_ptr;
	map		main_map;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1500, "FDF_BETA");
	if (argc == 2 || argc == 4)
	{
		if (argc == 2)
		{
			if (gather_size(&x_size, &y_size, argv[1]) == 0)
				return (1);
			main_map = map_populate(x_size, y_size, argv[1], main_map);
			main_map = int_map_extraction(main_map, x_size, y_size);
			render(main_map, mlx_ptr, win_ptr);
			freestuff(y_size, main_map, 0);
			mlx_loop(mlx_ptr);
			free(win_ptr);
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
