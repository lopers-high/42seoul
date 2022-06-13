/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_x_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/05/24 18:03:57 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list ap, t_info info)
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
	str = ft_modify_unsigned_number(str, info);
	len += write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_print_hex(va_list ap, t_info info)
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
		hex = ft_hex_to_str(n, size, "0123456789ABCDEF");
	hex = ft_modify_unsigned_number(hex, info);
	len += write(1, hex, ft_strlen(hex));
	free(hex);
	return (len);
}

int	ft_print_hex_lower(va_list ap, t_info info)
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
		hex = ft_hex_to_str(n, size, "0123456789abcdef");
	hex = ft_modify_unsigned_number(hex, info);
	len += write(1, hex, ft_strlen(hex));
	free(hex);
	return (len);
}

int	ft_print_pointer(va_list ap, t_info info)
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
	hex = ft_modify_unsigned_number(hex, info);
	len += write(1, hex, ft_strlen(hex));
	free(hex);
	return (len);
}