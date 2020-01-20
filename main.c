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

int is_anum(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(!(s[i] >= '0' && s[i] <= '9'))
			return(0);
		i++;
	}
	return(1)                             ;
}

void gofindstuff(char *s, int *x_size, int *y_size)
{
	int i = 0;

	while(s[i])
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			
			while(s[i] && s[i] != ' ')
				i++;
			(*x_size)++;
			continue;
		}
		i++;  
	}
	(*y_size)++;
}

int main(int argc, char **argv)
{
	int case_size = 0;
	int z_size = 0;
	int fd;
	char *line;
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1500, "FDF_BETA");
	int y = 0;

	int x_size = 0;
	int y_size = 0;
	map main_map;
	int i = 0;
	

	if(argc == 2 || argc == 4)
	{
		if(argc == 2)
		{
			//open the file descriptor and check to see if it is valid
			fd = open(argv[1], O_RDONLY);
			if(fd < 0)
			{
				printf("Usage : ./fdf <filename> [ case_size z_size ]");
				return 1;
			}
			//here we need to do a parse between every get next line 
			while(get_next_line(fd, &line))
			{
				gofindstuff(line, &x_size, &y_size);
				free(line);
			}
			close(fd);
			//printf("x_size %d y_size %d", x_size, y_size);

			//now it is time to get the coordinates into a structure put it into 
			main_map.x = x_size/y_size;
			main_map.y = y_size;

			main_map.full_map = malloc(sizeof(char *) * x_size);

			fd = open(argv[1], O_RDONLY);

			//REMEBER TO FREE THIS
			while(get_next_line(fd, &line))
			{
				main_map.full_map[i] = line;
				//printf("%s\n", main_map.full_map[i]);
				//free(line);
				i++;
			}

			//mallocing for the int map and extracting the integers
			char **split;
			int x = 0;
			
			main_map.int_map = malloc(sizeof(int *) * x_size);
			for(int i = 0; i < y_size; i++)
			{
				main_map.int_map[i] = malloc(sizeof(int) * x_size);
				split = ft_strsplit(main_map.full_map[i], ' ');
				x = 0;
				while(split[x])
				{
					main_map.int_map[i][x] = ft_atoi(split[x]);
					x++;
				}
				x = 0;

				//figure out why i cant do it in the main loop
				while(split[x])
				{
					free(split[x]);
					x++;
				}
				free(split);
			}
			render(main_map, mlx_ptr, win_ptr);

			//for(int i = 0; i < y_size; i++)
			//{
				//printf("%s\n", main_map.full_map[i]);
			//}
			

			//freeing random stuff

			free(main_map.full_map);
			
			
			for(int i = 0; i < y_size; i++)
			{
				free(main_map.int_map[i]);
			}
			free(main_map.int_map);
			mlx_loop(mlx_ptr);
			free(win_ptr);
		}
		//come back to finish this one
		if(argc == 4)
		{
			if(is_anum(argv[2]) && is_anum(argv[3]))
			{
//				case_size = ft_isdigit(3);
//				z_size = ft_atoi(argv[3]);
			}
		}
	}
	else
		printf("Usage : ./fdf <filename> [ case_size z_size ]");
}
