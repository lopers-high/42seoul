/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_x_p_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:57 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/14 16:49:10 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_unum_precision(char *str, t_info info, int len)
{
	int		i;
	char	*space;
	char	*ret;

	i = 0;
	space = (char *)ft_calloc(info.precision - len + 1, sizeof(char));
	if (space == NULL)
		return (NULL);
	while (i < info.precision - len)
		space[i++] = '0';
	space[i] = '\0';
	ret = ft_strjoin(space, str);
	free(str);
	free(space);
	return (ret);
}

static char	*ft_unum_width(char *str, t_info info, int len)
{
	int		i;
	char	*space;
	char	*ret;

	i = 0;
	space = (char *)ft_calloc(info.width - len + 1, sizeof(char));
	if (space == NULL)
		return (NULL);
	while (i < info.width - len)
	{
		if (info.flag & 2 && info.precision == -2)
			space[i++] = '0';
		else
			space[i++] = ' ';
	}
	space[i] = '\0';
	if (info.flag & 1)
		ret = ft_strjoin(str, space);
	else
		ret = ft_strjoin(space, str);
	free(str);
	free(space);
	return (ret);
}

char	*ft_modify_unsigned_number(char *str, t_info info)
{
	int		len;
	char	*tmp;

	if (info.sign != 0 && info.flag & 4 && info.type == 'X')
	{
		tmp = str;
		str = ft_strjoin("0X", str);
		free(tmp);
	}
	else if (info.sign != 0 && (info.type == 'p' || \
	(info.flag & 4 && info.type == 'x')))
	{
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	len = ft_strlen(str);
	if (info.precision > 0 && info.precision > len)
		str = ft_unum_precision(str, info, len);
	len = ft_strlen(str);
	if (info.width > 0 && info.width > len)
		str = ft_unum_width(str, info, len);
	return (str);
}

int	ft_get_hex_size(unsigned long n)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	else
	{
		while (n != 0)
		{
			n /= 16;
			size++;
		}
	}
	return (size);
}

char	*ft_hex_to_str(unsigned long n, int size, char *base)
{
	char	*hex;

	hex = (char *)ft_calloc(size + 1, sizeof(char));
	if (hex == NULL)
		return (NULL);
	hex[0] = '0';
	while (n > 0)
	{
		hex[size - 1] = base[n % 16];
		n /= 16;
		--size;
	}
	return (hex);
}
