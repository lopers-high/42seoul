/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:49:41 by jinypark          #+#    #+#             */
/*   Updated: 2022/05/24 18:04:19 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_specifier(const char **format, va_list ap, t_info *info, int ret)
{
	++*format;
	*info = ft_set_flag(format);
	info->type = **format;
	if (info->width == -1)
		return (-1);
	if (**format == 'c')
		return (ft_print_char(ap, *info));
	else if (**format == 's')
		return (ft_print_str(ap, *info));
	else if (**format == 'p')
		return (ft_print_pointer(ap, *info));
	else if (**format == 'd')
		return (ft_print_decimal(ap, *info, ret));
	else if (**format == 'i')
		return (ft_print_decimal(ap, *info, ret));
	else if (**format == 'u')
		return (ft_print_unsigned_decimal(ap, *info));
	else if (**format == 'X')
		return (ft_print_hex(ap, *info));
	else if (**format == 'x')
		return (ft_print_hex_lower(ap, *info));
	else if (**format == '%')
		return (ft_print_percent(*info));
	else
		return (write(1, *format, 1));
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
			len = ft_select_specifier(&format, ap, &info, ret);
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
