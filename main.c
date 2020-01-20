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
//# include "./libft/libft.h"
#include "minilibx/mlx.h"
#include "get_next_line.h"
//#include <stdio.h>
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

			//splitary = ft_strsplit(main_)


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
					 //printf("%s\n", split[x]);
					main_map.int_map[i][x] = ft_atoi(split[x]);

					//printf("%d", main_map.int_map[i][x]);
					//printf("%s\n", split[x]);
					//free(split[x]);
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





/*
			//draw_line(, , , , mlx_ptr, win_ptr);

			//draw_line(0, 0, 500, 500, mlx_ptr, win_ptr);
			//draw_line(0, 500, 500, 0, mlx_ptr, win_ptr);
			//draw_line(1, 1, 500, 1, mlx_ptr, win_ptr);
			//draw_line(0, 499, 499, 499, mlx_ptr, win_ptr);
			//draw_line(0, 0, 0, 500, mlx_ptr, win_ptr);
			//draw_line(499, 0, 499, 500, mlx_ptr, win_ptr);

			//draw_line(, , , , mlx_ptr, win_ptr);
			//draw_line(, , , , mlx_ptr, win_ptr);
			//draw_line(, , , , mlx_ptr, win_ptr);
			//draw_line(, , , , mlx_ptr, win_ptr);

			vector points[4];

			vector one;
			one.x = 400;
			one.y = 400;
			one.z = 0;
			vector two;
			two.x = 700;
			two.y = 400;
			two.z = 0;
			vector three;
			three.x = 700;
			three.y = 700;
			three.z = 0;
			vector four;
			four.x = 400;
			four.y = 700;
			four.z = 0;
			points[0] = one;
			points[1] = two;
			points[2] = three;
			points[3] = four;

			vector tmp;
			vector tmp2;
			vector tmp3;

			float angle = .2;
			int flag = 0;


			for(int i = 0; i < 4; i++)
			{
				//tmp = mathmult(points[i]);
				//tmp = mathmult2(points[i], angle);
				//tmp = rotation(points[i], .3, .3, .3);

				tmp = rotation(points[i], 10, 10, 10);
				//tmp = mathmult(points[i]);
				
				if(flag == 1)
				{
					draw_line6(tmp, tmp2, mlx_ptr, win_ptr);
					//draw_line(tmp2.x, tmp2.y, tmp.x, tmp.y, mlx_ptr, win_ptr);
					//bresenham(tmp2.x, tmp2.y, tmp.x, tmp.y, mlx_ptr, win_ptr);
					printf("2x %d 2y%d 1x %d 1y %d\n", tmp2.x, tmp2.y, tmp.x, tmp.y);
				}
				else
					tmp3 = tmp;
				tmp2 = tmp;
//				mlx_pixel_put(mlx_ptr, win_ptr, tmp.x, tmp.y, 123123312);
				flag = 1;
			}
			printf("2x %d 2y%d 1x %d 1y %d\n", tmp3.x, tmp3.y, tmp.x, tmp.y);
			draw_line6(tmp3, tmp2, mlx_ptr, win_ptr);
			
			//bresenham(100, 200, 500, 200, mlx_ptr, win_ptr);
			//bresenham(100, 500, 150, 100, mlx_ptr, win_ptr);
			//bresenham(300, 100,500, 500, mlx_ptr, win_ptr);
			//bresenham(250, 0, 250, 500, mlx_ptr, win_ptr);


			//draw_line(358, 437, 656, 467, mlx_ptr, win_ptr);
			//bresenham(656, 467, 626, 766, mlx_ptr, win_ptr);

			//draw_line(656, 467, 626, 736, mlx_ptr, win_ptr);






			//points[0] = {100, 100, 0};
			//points[1] = {400, 100, 0};
			//points[2] = {400, 400, 0};
			//points[3] = {100, 400, 0};



//			mathmult(point1[0], point1[1]);
//			mathmult(point2[0], point2[1]);
//			mathmult(point3[0], point3[1]);
//			mathmult(point4[0], point4[1]);


	        mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 123123312);
	        mlx_pixel_put(mlx_ptr, win_ptr, 400, 100, 123123312);
			mlx_pixel_put(mlx_ptr, win_ptr, 400, 400, 123123312);
			mlx_pixel_put(mlx_ptr, win_ptr, 100, 400, 123123312);
*/





			//loop gets all values and plots them
		/*	while(get_next_line(fd, &line))
			{
				for(int i = 0; line[i]; i++)
				{
					if(line[i] > '0')
						mlx_pixel_put(mlx_ptr, win_ptr, i * 11, y * 11, 12312312);
				}
				y++;
			} */

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


/* 
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	ft_putchar('x');
	return 1;
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "I'm hungry ready for malatang");
	
	mlx_pixel_put(mlx_ptr, win_ptr, 0, 0, 12312312);
//	mlx_string_put(mlx_ptr, win_ptr, 0, 0, 12312312, "hello world ajsdjfasjkdflk asdfk asdf kajsdf lkasdj fklasdjf laksdfj kalsdjfklasdjfklasjdflkadsjfklads");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}

*/