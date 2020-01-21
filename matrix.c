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

vector	rotatex(vector point, float angle_x, float angle_y, float angle_z)
{
	vector	ret;
	float	rotx[3][3];

	rotx[0][0] = 1;
	rotx[0][1] = 0;
	rotx[0][2] = 0;
	rotx[1][0] = 0;
	rotx[1][1] = cos(angle_x);
	rotx[1][2] = sin(angle_x);
	rotx[2][0] = 0;
	rotx[2][1] = -sin(angle_x);
	rotx[2][2] = cos(angle_x);
	ret.x = point.x;
	ret.y = point.y;
	ret.z = point.z;
	ret.x = point.x * rotx[0][0] + point.y * rotx[0][1] + point.z * rotx[0][2];
	ret.y = point.x * rotx[1][0] + point.y * rotx[1][1] + point.z * rotx[1][2];
	ret.z = point.x * rotx[2][0] + point.y * rotx[2][1] + point.z * rotx[2][2];
	return (ret);
}

vector	rotatey(vector point, float angle_x, float angle_y, float angle_z)
{
	vector	ret;
	float	roty[3][3];

	roty[0][0] = cos(angle_y);
	roty[0][1] = 0;
	roty[0][2] = sin(angle_y);
	roty[1][0] = 0;
	roty[1][1] = 1;
	roty[1][2] = 0;
	roty[2][0] = -sin(angle_y);
	roty[2][1] = 0;
	roty[2][2] = cos(angle_y);
	ret.x = point.x;
	ret.y = point.y;
	ret.z = point.z;
	ret.x = point.x * roty[0][0] + point.y * roty[0][1] + point.z * roty[0][2];
	ret.y = point.x * roty[1][0] + point.y * roty[1][1] + point.z * roty[1][2];
	ret.z = point.x * roty[2][0] + point.y * roty[2][1] + point.z * roty[2][2];
	return (ret);
}

vector	rotatez(vector point, float angle_x, float angle_y, float angle_z)
{
	vector	ret;
	float	rotz[3][3];

	rotz[0][0] = cos(angle_z);
	rotz[0][1] = -sin(angle_z);
	rotz[0][2] = 0;
	rotz[1][0] = sin(angle_z);
	rotz[1][1] = cos(angle_z);
	rotz[1][2] = 0;
	rotz[2][0] = 0;
	rotz[2][1] = 0;
	rotz[2][2] = 1;
	ret.x = point.x;
	ret.y = point.y;
	ret.z = point.z;
	ret.x = point.x * rotz[0][0] + point.y * rotz[0][1] + point.z * rotz[0][2];
	ret.y = point.x * rotz[1][0] + point.y * rotz[1][1] + point.z * rotz[1][2];
	ret.z = point.x * rotz[2][0] + point.y * rotz[2][1] + point.z * rotz[2][2];
	return (ret);
}

vector	rotationdriver(vector point, float a_x, float a_y, float a_z)
{
	vector ret;

	ret = rotatex(point, a_x, a_y, a_z);
	ret = rotatey(ret, a_x, a_y, a_z);
	ret = rotatez(ret, a_x, a_y, a_z);
	return (ret);
}
