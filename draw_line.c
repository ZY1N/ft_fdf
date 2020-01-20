/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:23:14 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/10 11:23:15 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//bresenham line algo

/*
void draw_line(int x_1, int y_1, int x_2, int y_2, void *mlx_ptr, void *win_ptr)
{
    //int x_to_plot;
    //int y_to_plot;
    int deltax = x_2 - x_1;
    int deltay = y_2 - y_1;
    int deltaerr = abs(deltay / deltax);

    float error = 0.0;

    int y = y_1;

    for(int x = x_1; x <= x_2; x++)
    {
        //plot(x, y);
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
        error = error + deltaerr;
        if (error >= .5)
        {
            //y = y + sign(deltay) * y;
            y = y + deltay * y;
            error = error - 1.0;
        }
    }
} */

/*
void draw_line(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr) 
{ 
   int m_new = 2 * (y2 - y1); 
   int slope_error_new = m_new - (x2 - x1); 

   for(int x = x1, y = y1; x <= x2; x++) 
   { 
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
  
      // Add slope to increment angle formed 
      slope_error_new += m_new; 
  
      // Slope error reached limit, time to 
      // increment y and update slope error. 
      if (slope_error_new >= 0) 
      { 
         y++; 
         slope_error_new  -= 2 * (x2 - x1); 
      } 
   }
} */

/*
void draw_line(int x0, int y0, int x1, int y1, void * mlx_ptr, void * win_ptr)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x != x1)
	{
		if(p>=0)
		{
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
			p=p+2*dy;
		}

        if(x < x1)
            x++;
        else if(x > x1)
            x--;
		//x=x+1;
	}

    while(y != y1)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
        if(y < y1)
            y++;
        else if (y > y1)
            y--;
    }

} */

void bresenham2(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr) 
{ 
   int m_new = 2 * (y2 - y1); 
   int slope_error_new = m_new - (x2 - x1); 
   for (int x = x1, y = y1; x <= x2; x++) 
   { 
        printf("x %d y %d \n", x, y);      
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
      // Add slope to increment angle formed 
      slope_error_new += m_new; 
  
      // Slope error reached limit, time to 
      // increment y and update slope error.

      printf("%d %d\n", y1, y2);
      if (slope_error_new >= 0) 
      { 
            y--; 
         slope_error_new  -= 2 * (x2 - x1); 
      }
   } 
} 


 void	draw_line6(vector2 f, vector2 s, void * mlx_ptr, void * win_ptr)
{
	vector2	delta;
	vector2	sign;
	vector2	cur;
	int		error[2];

	delta.x = abs(s.x - f.x);
	delta.y = abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, cur.x, cur.y, 123123312);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void blinealgo(vector2 f, vector s, void *mlx_ptr, void * win_ptr)
{
    vector2 delta;
    vector2 sign;
    vector2 cur;
    int error[2];

    delta.x = abs(s.x - f.x)
    delta.y = abs(s.y - f.y)
    sign.x = f.x < s.x ? 1 : -1;
    sign.y = f.y < s.y ? 1 : -1;
    error[0] = delta.x - delta.y;
    cur = f;

    while(cur.x != s.x || cur.y != s.y)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, cur.x, cur.y, 123123312);
        if((error[1] = error[0] * 2) > -delta.y)
    }
}




void draw_line_2(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr)
{
    int x, y, dx, dy, p;
    x = x1;
    y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    p = 2 * dy - dx;

    while(x <= x2)
    {
        printf("x %d y %d \n", x, y);
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
        if(p < 0)
        {
            p = p + 2*dy;
            if(y1 != y2)
                y++;
        }
        else if(p > 0)
        {
            p = p + 2*dy - 2*dx;
            y--;
        }
        x++;
    }
}

void draw_line_3(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr)
{
    int x, y, dx, dy, p;
    x = x1;
    y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    p = 2 * dy - dx;

    int increment_y = dy/dx; 

    while(y <= y2)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 123123312);
        if(p < 0)
        {
            p = p + 2*dy;
            if(x1 != x2)
                x--;
        }
        else if(p > 0)
        {
            p = p + 2*dy - 2*dx;
            x++;
        }
        y++;
    }
}

void draw_vertical(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr)
{
    while(y1 != y2)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 123123312);
        if(y1 < y2)
            y1++;
        else
            y1--;
    }
}

/*
void draw_line(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr)
{
    int xL;
    int yL;
    int xR;
    int yR;

    if(x1 < x2)
    {
        xL = x1;
        yL = y1;
        xR = x2;
        yR = y2;
    }
    else
    {
        xL = x2; 
        yL = y2;
        xR = x1;
        yR = y1;
    }
    if(x1 == x2)
    {
        draw_vertical(x1, y1, x2, y2, mlx_ptr, win_ptr);
    }
    else
        draw_line_2(xL, yL, xR, yR, mlx_ptr, win_ptr);
} */

void bresenham(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr) 
{
    if(x1 == x2)
        draw_vertical(x1, y1, x2, y2, mlx_ptr, win_ptr);
    else
    {
        if(x1 < x2)
            bresenham2(x1, y1, x2, y2, mlx_ptr, win_ptr);
        else if(x1 >= x2)
            bresenham2(x2, y2, x1, y1, mlx_ptr, win_ptr);
    }
}

void draw_line(int x1, int y1, int x2, int y2, void * mlx_ptr, void * win_ptr)
{
    int deltax;
    int deltay;

    if(x1 == x2)
        draw_vertical(x1, y1, x2, y2, mlx_ptr, win_ptr);
    else
    {
        deltax = x2 - x1;
        deltay = y2 - y1;

        if(deltax > deltay)
        {
            printf("here i am");
            if(x1 < x2)
                draw_line_2(x1, y1, x2, y2, mlx_ptr, win_ptr);
            else if(x1 >= x2)
                draw_line_2(x2, y2, x1, y1, mlx_ptr, win_ptr);
        }
        else
        {
            //draw_line_3(x1, y1, x2, y2, mlx_ptr, win_ptr);
            if(y1 < y2)
                draw_line_3(x1, y1, x2, y2, mlx_ptr, win_ptr);
            else if(y1 >= y2)
                draw_line_3(x2, y2, x1, y1, mlx_ptr, win_ptr);
        }
    }
}







/*
void draw_line(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
{
    int xstart = x1;
    int ystart = y1;
    int xend = x2;
    int yend = y2;

    float slope = (yend - ystart) / (xend - xstart);
    float b = -1* (slope * xstart) + ystart;

    float curr = 0;
    int y;

    while(xstart != xend)
    {
        //curr = slope * (xstart) + b;
        //if( (curr - (int)curr) >= .5)
        //    y = (int) curr + 1;
        //else
        //    y = (int) curr;

        mlx_pixel_put(mlx_ptr, win_ptr, xstart, y, 123123312);

        if(xstart > xend)
            xstart--;
        else if(xstart < xend)
            xstart++;
    }
} */
