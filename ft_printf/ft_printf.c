/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:49:41 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/13 16:53:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(char *ret, int retlen)
{
	int		len;
	char	*str;

	str = ret;
	len = 0;
	while (*ret)
	{
		if (retlen == INT_MAX)
		{
			free(str);
			return (-1);
		}
		len += write(1, ret, 1);
		++retlen;
		++ret;
	}
	free(str);
	return (len);
}

int	ft_select_format(const char **fmt, va_list ap, t_info *info, int ret)
{
	++*fmt;
	*info = ft_set_flag(fmt);
	info->type = **fmt;
	if (info->width == -1)
		return (-1);
	if (**fmt == 'c')
		return (ft_print_char(ap, *info, ret));
	else if (**fmt == 's')
		return (ft_print_str(ap, *info, ret));
	else if (**fmt == 'p')
		return (ft_print_pointer(ap, *info, ret));
	else if (**fmt == 'd')
		return (ft_print_decimal(ap, *info, ret));
	else if (**fmt == 'i')
		return (ft_print_decimal(ap, *info, ret));
	else if (**fmt == 'u')
		return (ft_print_unsigned_decimal(ap, *info, ret));
	else if (**fmt == 'X')
		return (ft_print_hex(ap, *info, ret));
	else if (**fmt == 'x')
		return (ft_print_hex(ap, *info, ret));
	else if (**fmt == '%')
		return (ft_print_percent(*info, ret));
	else
		return (write(1, *fmt, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			ret;
	t_info		info;

	len = 0;
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len = ft_select_format(&format, ap, &info, ret);
		else
			len = write(1, format, 1);
		if (len == -1)
		{
			va_end(ap);
			return (-1);
		}
		else
			ret += len;
		++format;
	}
	va_end(ap);
	return (ret);
}
