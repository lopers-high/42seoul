/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:44 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/14 16:28:37 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_info
{
	unsigned char	flag;
	long long		width;
	long long		precision;
	char			type;
	int				sign;
}	t_info;

int		ft_printf(const char *format, ...);
int		ft_select_format(const char **fmt, va_list ap, t_info *info, int ret);
int		ft_write(char *ret, int retlen);
t_info	ft_set_flag(const char **format);
char	*ft_modify_unsigned_number(char *str, t_info info);
int		ft_get_hex_size(unsigned long n);
char	*ft_hex_to_str(unsigned long n, int size, char *base);
void	*ft_free(char* str);
size_t	ft_uintlen(size_t n);
char	*ft_uitoa(size_t n);
int		ft_handle_precision_error(unsigned long long precision, int len);
int		ft_print_pointer(va_list ap, t_info info, int retlen);
int		ft_print_hex(va_list ap, t_info info, int retlen);
int		ft_print_unsigned_decimal(va_list ap, t_info info, int retlen);
int		ft_print_decimal(va_list ap, t_info info, int retlen);
int		ft_print_str(va_list ap, t_info info, int retlen);
int		ft_print_char(va_list ap, t_info info, int retlen);
int		ft_print_percent(t_info info, int retlen);
char	*ft_modify_signed_number(char *str, t_info info);
char	*ft_modify_string(char *str, t_info info);




#endif
