/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:49 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/14 16:38:52 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_info_width(const char **format)
{
	unsigned long long	width;

	width = 0;
	while (ft_isdigit(**format))
	{
		width = width * 10 + **format - '0';
		++(*format);
	}
	if (INT_MAX <= width && width <= LLONG_MAX)
		return (-1);
	--(*format);
	return ((int)width);
}

static long long	ft_get_info_precision(const char **format)
{
	long long	precision;

	precision = 0;
	++(*format);
	while (ft_isdigit(**format))
	{
		precision = precision * 10 + **format - '0';
		++(*format);
	}
	--(*format);
	return (precision);
}

static t_info	set_info(void)
{
	t_info	info;

	info.flag = 0;
	info.precision = -2;
	info.type = 0;
	info.width = 0;
	info.sign = 1;
	return (info);
}

t_info	ft_ignore_flag(t_info info)
{
	if ((info.flag & 1 && info.flag & 2) || \
	(info.precision > 0 && info.flag & 2))
		info.flag &= ~2;
	if (info.flag & 16 && info.flag & 8)
		info.flag &= ~8;
	return (info);
}

t_info	ft_set_flag(const char **format)
{
	t_info	info;

	info = set_info();
	while (!ft_isalpha(**format) && **format != '%')
	{
		if (**format == '-')
			info.flag |= 1;
		else if (**format == '0')
			info.flag |= 2;
		else if (**format == '#')
			info.flag |= 4;
		else if (**format == ' ')
			info.flag |= 8;
		else if (**format == '+')
			info.flag |= 16;
		else if (ft_isdigit(**format))
			info.width = ft_get_info_width(format);
		else if (**format == '.')
			info.precision = ft_get_info_precision(format);
		else
			break ;
		++(*format);
	}
	info = ft_ignore_flag(info);
	return (info);
}
