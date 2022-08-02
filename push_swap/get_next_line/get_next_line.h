/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:20:19 by hchang            #+#    #+#             */
/*   Updated: 2022/07/25 17:09:41 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}	t_lst;

char	*get_next_line(int fd);
char	*make_line(t_lst **res_lst, size_t res_len, char *res);
t_lst	*read_line(int fd, t_lst **t_back, ssize_t *rd);
size_t	check_line(int fd, t_lst **res_lst, size_t *res_len);
size_t	check_enter_len(const char *s, int c, size_t *len);
void	*ft_lstfclean_g(t_lst **lst);
char	*ft_strdup_g(const char *s1);
size_t	ft_strlcat_g(char *dst, const char *src, size_t dstsize);
t_lst	*ft_lstnew_add_back(t_lst **lst, void *content);
t_lst	*ft_lstnew_g(void *content);

#endif