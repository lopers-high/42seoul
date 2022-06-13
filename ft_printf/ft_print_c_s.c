/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:00:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/13 16:49:20 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_null_width(char *str, t_info info, int len)
{
	char	*space;
	int		i;
	char	*ret;

	i = 0;
	space = (char *)ft_calloc((info.width - len) + 1, sizeof(char));
	if (space == NULL)
		return (NULL);
	while (i < info.width - len)
	{
		space[i++] = ' ';
	}
	space[i] = '\0';
	if (info.flag & 1)
		ret = ft_strjoin(str, space);
	else
		ret = ft_strjoin(space, str);
	free(space);
	free(str);
	return (ret);
}

char	*ft_modify_null(t_info info)
{
	int		len;
	char	*tmp;
	char	*str;

	str = ft_strdup("!");
	len = ft_strlen(str);
	if (info.precision > 0 && info.precision < len)
	{
		tmp = (char *)ft_calloc(info.precision + 1, sizeof(char));
		if (tmp == NULL)
			return (NULL);
		ft_strlcpy(tmp, str, info.precision + 1);
		free(str);
	}
	else
		tmp = str;
	len = ft_strlen(tmp);
	if (info.width > 0 && info.width > len)
		tmp = ft_null_width(tmp, info, len);
	return (tmp);
}

int	ft_print_null(t_info info, int retlen)
{
	char	*str;
	char	*ret;
	int		len;

	len = 0;
	ret = ft_modify_null(info);
	str = ret;
	while (*ret)
	{
		if (retlen == INT_MAX)
		{
			free(str);
			return (-1);
		}
		if (*ret == '!')
			len += write(1, "\0", 1);
		else
			len += write(1, ret, 1);
		++retlen;
		++ret;
	}
	free(str);
	return (len);
}

int	ft_print_char(va_list ap, t_info info, int retlen)
{
	char	c;
	char	*str;
	char	*ret;
	int		len;

	len = 0;
	c = (char)va_arg(ap, int);
	if (c == '\0')
		return (ft_print_null(info, retlen));
	if (info.width > 0)
	{
		str = (char *)ft_calloc(2, sizeof(char));
		if (str == NULL)
			return (-1);
		*str = c;
		ret = ft_modify_string(str, info);
		return (ft_write(ret, retlen));
	}
	else
		return (write(1, &c, 1));
}

int	ft_print_str(va_list ap, t_info info, int retlen)
{
	char	*str;
	char	*ret;
	int		len;
	char	*tmp;

	len = 0;
	tmp = va_arg(ap, char *);
	if (info.precision == 0)
		str = ft_strdup("");
	else if (tmp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(tmp);
	ret = ft_modify_string(str, info);
	return (ft_write(ret, retlen));
}
