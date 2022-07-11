/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:32:07 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/07 14:32:10 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "fdf.h"

void	ft_isometric(double *x, double *y, double z)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI / 6);
	*y = (prev_x + prev_y) * sin(M_PI / 6) - z;
}
