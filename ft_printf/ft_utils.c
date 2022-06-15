/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:08:38 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/15 14:13:27 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_free(char* str)
{
	free(str);
	return (NULL);
}

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

int	ft_handle_precision_error(unsigned long long precision, int len)
{
	if (precision > INT_MAX && precision - len <= INT_MAX)
		precision = precision - len;
	else if (precision == INT_MAX)
		return (-1);
	else
		precision = (int)precision;
	return (precision);
}
