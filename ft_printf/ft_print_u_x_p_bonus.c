/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_x_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/15 15:23:45 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list ap, t_info info, int retlen)
{
	unsigned int	i;
	char			*str;
	int				len;

	len = 0;
	i = va_arg(ap, unsigned int);
	if (i == 0)
		info.sign = 0;
	if (info.precision == 0 && i == 0)
		str = ft_strdup("");
	else
		str = ft_uitoa(i);
	info.precision = ft_handle_precision_error(info.precision, ft_uintlen(i));
	if (info.precision == -1)
		return (-1);
	str = ft_modify_unsigned_number(str, info);
	return (ft_write(str, retlen));
}

int	ft_print_hex(va_list ap, t_info info, int retlen)
{
	unsigned long	n;
	int				size;
	int				len;
	char			*hex;

	len = 0;
	n = va_arg(ap, unsigned int);
	size = ft_get_hex_size(n);
	if (n == 0)
		info.sign = 0;
	if (info.precision == 0 && n == 0)
		hex = ft_strdup("");
	else
	{
		if (info.type == 'x')
			hex = ft_hex_to_str(n, size, "0123456789abcdef");
		else
			hex = ft_hex_to_str(n, size, "0123456789ABCDEF");
	}
	info.precision = ft_handle_precision_error(info.precision, size);
	if (info.precision == -1)
		return (-1);
	hex = ft_modify_unsigned_number(hex, info);
	return (ft_write(hex, retlen));
}

int	ft_print_pointer(va_list ap, t_info info, int retlen)
{
	unsigned long	n;
	int				size;
	char			*base;
	int				len;
	char			*hex;

	len = 0;
	n = va_arg(ap, unsigned long);
	base = "0123456789abcdef";
	size = ft_get_hex_size(n);
	hex = (char *)ft_calloc(size + 1, sizeof(char));
	if (hex == NULL)
		return (-1);
	hex[0] = '0';
	while (n > 0)
	{
		hex[size-- - 1] = base[n % 16];
		n /= 16;
	}
	info.precision = ft_handle_precision_error(info.precision, size);
	if (info.precision == -1)
		return (-1);
	hex = ft_modify_unsigned_number(hex, info);
	return (ft_write(hex, retlen));
}
