/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 10:05:20 by yinzhang          #+#    #+#             */
/*   Updated: 2020/01/12 10:05:21 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


vector iso(vector v)
{
    int x, y;

    x = v.x;
    y = v.y;
    v.x = (x - y) * cos(.523599);
    v.y = v.z + (x + y) * sin(.523599);
    return(v);
}


float  projection[2][3] = {
    {1,0,0},
    {0,1,0}
};

vector rotate_test(vector v, float radx, float rady)
{
    float x, y;

    x = v.x;
    y = v.y;
    v.x = (x * cos(radx)) - (y * sin(radx));
    v.y = (x * sin(rady)) + (y *cos(rady));
    return(v);
}


//vector rotation(vector point, float angle_x, float angle_y, float angle_z)

void	rotate_x(float *y, float *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

/*
** Rotate coordinate by y axis
*/

void	rotate_y(float *x, float *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

/*
** Rotate coordinate by z axis
*/

void	rotate_z(float *x, float *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}







/* 
void	rotate_x(float *y, float *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
} */
vector rotatex(vector point, float angle_x, float angle_y, float angle_z)
{
    vector ret;

    ret.x = point.x;
    ret.y = point.y;
    ret.z = point.z;

    float rotatex[3][3] = {
        {1, 0, 0},
        {0, cos(angle_x), sin(angle_x)},
        {0, -sin(angle_x), cos(angle_x)}
    };

    ret.x = point.x * rotatex[0][0] + point.y * rotatex[0][1] + point.z * rotatex[0][2];
    //ret.x = x
    ret.y = point.x * rotatex[1][0] + point.y * rotatex[1][1] + point.z * rotatex[1][2];
    //ret.y = y * cos(theat) + z * -sin(theta) COMEBACK TO THIS
    ret.z = point.x * rotatex[2][0] + point.y * rotatex[2][1] + point.z * rotatex[2][2];
    //ret.z = y * sin(theat) + z * cos(theta)
    
    printf("x %f y %f z %f \n", ret.x, ret.y, ret.z);

    return(ret);
}
/* 
void	rotate_y(float *x, float *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
} */

vector rotatey(vector point, float angle_x, float angle_y, float angle_z)
{
        vector ret;

    ret.x = point.x;
    ret.y = point.y;
    ret.z = point.z;
    float rotatey[3][3] = {
        {cos(angle_y), 0, sin(angle_y)},
        {0, 1, 0},
        {-sin(angle_y), 0, cos(angle_y)}
    };
    ret.x = point.x * rotatey[0][0] + point.y * rotatey[0][1] + point.z * rotatey[0][2];
    // ret.x = x * cos(theta) + y * 0 + z * sin(theta);
    ret.y = point.x * rotatey[1][0] + point.y * rotatey[1][1] + point.z * rotatey[1][2];
    // ret.y = y * 1
    ret.z = point.x * rotatey[2][0] + point.y * rotatey[2][1] + point.z * rotatey[2][2];
    // ret.z = -sin(theta) * x + z * cos(=theta)
    return(ret);
}

/*
void	rotate_z(float *x, float *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
} */


vector rotatez(vector point, float angle_x, float angle_y, float angle_z)
{    
    vector ret;

    ret.x = point.x;
    ret.y = point.y;
    ret.z = point.z;
    float rotatez[3][3] = {
        {cos(angle_z), -sin(angle_z), 0},
        {sin(angle_z), cos(angle_z), 0},
        {0, 0, 1}
    };
    ret.x = point.x * rotatez[0][0] + point.y * rotatez[0][1] + point.z * rotatez[0][2];
    // ret.x = cos(a) * x + - sin(a) * y
    ret.y = point.x * rotatez[1][0] + point.y * rotatez[1][1] + point.z * rotatez[1][2];
    // ret.y = sin(a) * x + cos(a) * cos(a)
    ret.z = point.x * rotatez[2][0] + point.y * rotatez[2][1] + point.z * rotatez[2][2];
    // ret.z = z
    return(ret);
}
vector rotationdriver(vector point, float angle_x, float angle_y, float angle_z)
{
    vector ret;

    ret.x = point.x; 
    ret.y = point.y;
    ret.z = point.z;

    ret = rotatex(point, angle_x, angle_y, angle_z);
    ret = rotatey(ret, angle_x, angle_y, angle_z);
    ret = rotatez(ret, angle_x, angle_y, angle_z);
    return(ret);
}




vector rotation(vector point, float angle_x, float angle_y, float angle_z)
{
    vector ret;
    
    ret.x = point.x;
    ret.y = point.y;
    ret.z = point.z;

    int ary[3];

    float rotatex[3][3] = {
        {1, 0, 0},
        {0, cos(angle_x), sin(angle_x)},
        {0, -sin(angle_x), cos(angle_x)}
    };

    ret.x = ret.x * rotatex[0][0] + ret.y * rotatex[0][1] + ret.z * rotatex[0][2];
    ret.y = ret.x * rotatex[1][0] + ret.y * rotatex[1][1] + ret.z * rotatex[1][2];
    ret.z = ret.x * rotatex[2][0] + ret.y * rotatex[2][1] + ret.z * rotatex[2][2];

    float rotatey[3][3] = {
        {cos(angle_y), 0, -sin(angle_y)},
        {0, 1, 0},
        {sin(angle_y), 0, cos(angle_y)}
    };
    ret.x = ret.x * rotatey[0][0] + ret.y * rotatey[0][1] + ret.z * rotatey[0][2];
    ret.y = ret.x * rotatey[1][0] + ret.y * rotatey[1][1] + ret.z * rotatey[1][2];
    ret.z = ret.x * rotatey[2][0] + ret.y * rotatey[2][1] + ret.z * rotatey[2][2];


    float rotatez[3][3] = {
        {cos(angle_z), sin(angle_z), 0},
        {-sin(angle_z), cos(angle_z), 0},
        {0, 0, 1}
    };
    ret.y = ret.x * rotatez[1][0] + ret.y * rotatez[1][1] + ret.z * rotatez[1][2];
    ret.x = ret.x * rotatez[0][0] + ret.y * rotatez[0][1] + ret.z * rotatez[0][2];
    ret.z = ret.x * rotatez[2][0] + ret.y * rotatez[2][1] + ret.z * rotatez[2][2];

    return(ret);
}

vector iso_rotation(vector point, float angle_x, float angle_y)
{
    vector ret;

    ret.x = point.x; 
    ret.y = point.y;
    ret.z = point.z;



    float rotatex[3][3] = {
        {1, 0, 0},
        {0, cos(angle_x), sin(angle_x)},
        {0, -sin(angle_x), cos(angle_x)}
    };
    ret.x = point.x * rotatex[0][0] + point.y * rotatex[0][1] + point.z * rotatex[0][2];
    ret.y = point.x * rotatex[1][0] + point.y * rotatex[1][1] + point.z * rotatex[1][2];
    ret.z = point.x * rotatex[2][0] + point.y * rotatex[2][1] + point.z * rotatex[2][2];
 /* 
    float rotatey[3][3] = {
        {cos(angle_y), 0, -sin(angle_y)},
        {0, 1, 0},
        {sin(angle_y), 0, cos(angle_y)}
    };
    ret.x = ret.x * rotatey[0][0] + ret.y * rotatey[0][1] + ret.z * rotatey[0][2];
    ret.y = ret.x * rotatey[1][0] + ret.y * rotatey[1][1] + ret.z * rotatey[1][2];
    ret.z = ret.x * rotatey[2][0] + ret.y * rotatey[2][1] + ret.z * rotatey[2][2];
*/
    return(ret);
}







//float rotation[2][3] ={
//    {cos(angle), -sin(angle)},
//    {sin(angle), cos(angle)}
//};


//vector, takes a vector and a projection thing to do stuff
vector mathmult_universal(vector point, float **projection)
{
    vector ret;

    ret.x = projection[0][0] * point.x + projection[0][1] * point.y + projection[0][2] * point.z;
    ret.y = projection[1][0] * point.x + projection[1][1] * point.y + projection[1][2] * point.z;

    return(ret);
}




vector mathmult(vector point)
{
    vector ret;
    int x = 0;
    int y = 0;
    int i = 0;

    ret.x = projection[0][0] * point.x + projection[0][1] * point.y + projection[0][2] * point.z;
    ret.y = projection[1][0] * point.x + projection[1][1] * point.y + projection[1][2] * point.z;
    //ret.z = projection[1][0] * point.x + projection[1][1] * point.x + projecction[1][2] * point.x;
    return(ret);
}

vector mathmult2(vector point, float angle)
{
    vector ret;
    int x = 0;
    int y = 0;
    int i = 0;

    float rotation[2][3] ={
    {   cos(angle), -sin(angle)},
        {sin(angle), cos(angle)}
    };

    ret.x = rotation[0][0] * point.x + rotation[0][1] * point.y + rotation[0][2] * point.z;
    ret.y = rotation[1][0] * point.x + rotation[1][1] * point.y + rotation[1][2] * point.z;

    
    
    //ret.z = projection[1][0] * point.x + projection[1][1] * point.x + projecction[1][2] * point.x;
    return(ret);
}
