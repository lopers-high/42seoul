/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:34:34 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/18 14:24:57 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_x(double y, double z, t_point *point, double angle)
{
	point->trans_y = y * cos(angle * M_PI / 180) + \
	(z) * sin(angle * M_PI / 180);
	point->trans_z = -y * sin(angle * M_PI / 180) \
	+ (z) * cos(angle * M_PI / 180);
}

void	rotate_y(double x, double z, t_point *point, double angle)
{
	point->trans_x = x * cos(angle * M_PI / 180) + \
	(z) * sin(angle * M_PI / 180);
	point->trans_z = -x * sin(angle * M_PI / 180) \
	+ (z) * cos(angle * M_PI / 180);
}

void	rotate_z(double x, double y, t_point *point, double angle)
{
	point->trans_x = x * cos(angle * M_PI / 180) - y * sin(angle * M_PI / 180);
	point->trans_y = x * sin(angle * M_PI / 180) + y * cos(angle * M_PI / 180);
}
