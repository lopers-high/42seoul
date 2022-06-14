/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:08:38 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/14 16:37:39 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_precision_error(unsigned long long precision, int len)
{
	if (precision > INT_MAX && precision - len <= INT_MAX)
		precision = precision - len;
	else if (precision == INT_MAX)
		return (-1);
	else
		precision = (int)precision;
	return (precision);
}
