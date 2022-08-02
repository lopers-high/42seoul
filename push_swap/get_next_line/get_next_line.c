/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/07/25 17:09:34 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_enter_len(const char *s, int c, size_t *len)
{
	int	idx;

	idx = 0;
	while (s[*len])
		(*len)++;
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return (idx);
		idx++;
	}
	return (-1);
}

size_t	check_line(int fd, t_lst **res_lst, size_t *res_len)
{
	t_lst	*curr;
	ssize_t	rd;
	size_t	enter_pos;
	size_t	content_len;

	curr = *res_lst;
	while (1)
	{
		content_len = 0;
		if (curr)
		{
			enter_pos = check_enter_len((curr)->content, '\n', &content_len);
			if (enter_pos != (size_t) - 1)
			{
				*res_len += (enter_pos + 1);
				return (rd);
			}
			*res_len += content_len;
		}
		curr = read_line(fd, res_lst, &rd);
		if (!curr)
			return (rd);
	}
	return (rd);
}

t_lst	*read_line(int fd, t_lst **t_back, ssize_t *rd)
{
	char		*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	*rd = read(fd, tmp, BUFFER_SIZE);
	if (*rd <= 0)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp[*rd] = '\0';
	return (ft_lstnew_add_back(t_back, tmp));
}

char	*make_line(t_lst **res_lst, size_t res_len, char *res)
{
	char	*save;
	size_t	tmp;
	size_t	enter_pos;
	t_lst	*clean_lst;

	tmp = 0;
	res[0] = 0;
	clean_lst = *res_lst;
	while (*res_lst)
	{
		ft_strlcat_g(res, (*res_lst)->content, res_len + 1);
		if ((*res_lst)->next == NULL)
			save = (*res_lst)->content;
		*res_lst = (*res_lst)->next;
	}
	enter_pos = check_enter_len(save, '\n', &tmp);
	if ((enter_pos != (size_t)-1) && *(save + enter_pos + 1) != '\0')
		*res_lst = ft_lstnew_g(ft_strdup_g(save + (enter_pos + 1)));
	ft_lstfclean_g(&clean_lst);
	return (res);
}

char	*get_next_line(int fd)
{
	char			*res;
	static t_lst	*res_lst;
	size_t			res_len;
	ssize_t			rd;

	res_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = check_line(fd, &res_lst, &res_len);
	if ((!rd && !res_len) || rd == -1)
		return ((char *)ft_lstfclean_g(&res_lst));
	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	res[res_len] = '\0';
	return (make_line(&res_lst, res_len, res));
}
