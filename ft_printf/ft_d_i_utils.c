/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:00:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/13 13:17:49 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_swap(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = '0';
			str[0] = c;
			break ;
		}
		i++;
	}
}

static char	*ft_num_precision(char *str, t_info info, int len)
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

static char	*ft_num_width(char *str, t_info info, int len)
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
		if (info.flag & 2 && info.precision == -1)
			space[i++] = '0';
		else
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

static char	*ft_num_plus_space(char *str, t_info info, int sign)
{
	char	*tmp;

	if (info.flag & 16 && sign >= 0)
	{
		tmp = ft_strjoin("+", str);
		free(str);
		str = tmp;
	}
	if (info.flag & 8 && sign >= 0)
	{
		tmp = ft_strjoin(" ", str);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_modify_signed_number(char *str, t_info info)
{
	int		len;
	char	*tmp;

	if ((info.flag & 16 || info.flag & 8) && info.sign >= 0)
		str = ft_num_plus_space(str, info, info.sign);
	len = ft_strlen(str);
	if (info.precision > 0 && info.precision > len)
		str = ft_num_precision(str, info, len);
	if (info.sign == -1)
	{
		tmp = str;
		str = ft_strjoin("-", str);
		free(tmp);
	}
	len = ft_strlen(str);
	if (info.width > 0 && info.width > len)
		str = ft_num_width(str, info, len);
	if (info.flag & 2 && info.sign == -1)
		ft_swap(str, '-');
	return (str);
}
