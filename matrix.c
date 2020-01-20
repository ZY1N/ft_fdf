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
    ret.y = point.x * rotatex[1][0] + point.y * rotatex[1][1] + point.z * rotatex[1][2];
    ret.z = point.x * rotatex[2][0] + point.y * rotatex[2][1] + point.z * rotatex[2][2];
    return(ret);
}

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
    ret.y = point.x * rotatey[1][0] + point.y * rotatey[1][1] + point.z * rotatey[1][2];
    ret.z = point.x * rotatey[2][0] + point.y * rotatey[2][1] + point.z * rotatey[2][2];
    return(ret);
}

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
    ret.y = point.x * rotatez[1][0] + point.y * rotatez[1][1] + point.z * rotatez[1][2];
    ret.z = point.x * rotatez[2][0] + point.y * rotatez[2][1] + point.z * rotatez[2][2];
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
