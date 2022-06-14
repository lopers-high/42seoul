/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_s_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:59:51 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/14 10:51:07 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_str_width(char *tmp, t_info info, int len)
{
	char	*space;
	int		i;
	char	*ret;

	space = (char *)ft_calloc((info.width - len) + 1, sizeof(char));
	if (space == NULL)
		return (NULL);
	i = 0;
	while (i < info.width - len)
	{
		if (info.flag & 2)
			space[i++] = '0';
		else
			space[i++] = ' ';
	}
	space[i] = '\0';
	if (info.flag & 1)
		ret = ft_strjoin(tmp, space);
	else
		ret = ft_strjoin(space, tmp);
	free(space);
	free(tmp);
	return (ret);
}

char	*ft_modify_string(char *str, t_info info)
{
	int		len;
	char	*tmp;

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
		tmp = ft_str_width(tmp, info, len);
	return (tmp);
}

int	ft_print_percent(t_info info, int retlen)
{
	char	c;
	char	*str;
	char	*ret;

	c = '%';
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
