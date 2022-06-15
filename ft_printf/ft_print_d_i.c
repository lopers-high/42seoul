/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:25 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/15 14:02:02 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_int_to_str(int i, t_info *info)
{
	char	*str;

	if (i == -2147483648)
	{
		str = ft_strdup("2147483648");
		info->sign *= -1;
	}
	else if (i < 0)
	{
		info->sign *= -1;
		i *= -1;
		str = ft_itoa(i);
	}
	else if (i == 0)
	{
		info->sign = 0;
		if (info->precision == 0)
			str = ft_strdup("");
		else
			str = ft_itoa(i);
	}
	else
		str = ft_itoa(i);
	return (str);
}

int	ft_print_decimal(va_list ap, t_info info, int retlen)
{
	int		i;
	char	*str;
	char	*ret;

	i = va_arg(ap, int);
	info.precision = ft_handle_precision_error(info.precision, ft_uintlen(i));
	if (info.precision == -1)
		return (-1);
	str = ft_int_to_str(i, &info);
	ret = ft_modify_signed_number(str, info);
	return (ft_write(ret, retlen));
}
