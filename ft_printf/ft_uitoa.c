/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:12:16 by jinypark          #+#    #+#             */
/*   Updated: 2022/05/24 18:12:21 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_uintlen(size_t n)
{
	int			len;
	long long	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(char *arr, size_t n, size_t len)
{
	if (n == 0)
		arr[0] = '0';
	while (n > 0)
	{
		arr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_uitoa(size_t n)
{
	size_t	len;
	char	*arr;

	len = ft_uintlen(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	ft_putnbr(arr, n, len);
	arr[len] = '\0';
	return (arr);
}
