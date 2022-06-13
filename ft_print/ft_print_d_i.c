/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:25 by jinypark          #+#    #+#             */
/*   Updated: 2022/05/24 18:01:32 by jinypark         ###   ########.fr       */
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
	else if (info->precision == 0 && i == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(i);
	return (str);
}

int	ft_print_decimal(va_list ap, t_info info, int retlen)
{
	int		i;
	char	*str;
	int		len;
	char	*ret;

	len = 0;
	i = va_arg(ap, int);
	if (info.precision > INT_MAX && info.precision - ft_uintlen(i) <= INT_MAX)
		info.precision = info.precision - ft_uintlen(i);
	else if (info.precision == INT_MAX)
		return (-1);
	str = ft_int_to_str(i, &info);
	if (i == 0)
		info.sign = 0;
	ret = ft_modify_signed_number(str, info);
	str = ret;
	while (*ret)
	{	
		if (retlen == INT_MAX)
			return (-1);
		len += 1;
		++retlen;
		++ret;
	}
	free(str);
	return (len);
}