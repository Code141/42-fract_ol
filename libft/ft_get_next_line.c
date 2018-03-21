/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:24:01 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 18:39:00 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static t_list	*get_dial(int fd, t_list **dial)
{
	t_file	file;
	t_list	*c_dial;
	t_list	*prev;
	t_list	*link;

	c_dial = *dial;
	prev = c_dial;
	while (c_dial)
		if (((t_file*)(c_dial->content))->fd == fd)
			return (c_dial);
		else
		{
			prev = c_dial;
			c_dial = c_dial->next;
		}
	file.fd = fd;
	file.save = NULL;
	link = ft_lstnew((void*)(&file), sizeof(file));
	if (!link)
		return (NULL);
	if (!*dial)
		*dial = link;
	else
		prev->next = link;
	return (link);
}

static int		read_more(t_file *file)
{
	int		ret;
	t_list	*new;
	char	*buf;

	buf = (char*)malloc(BUFF_SIZE);
	while ((ret = read(file->fd, buf, BUFF_SIZE)) > 0)
	{
		ft_lst_push_back(&file->save, ft_lstnew(buf, ret));
		if (ft_memchr(buf, '\n', ret))
			break ;
	}
	if (file->save)
	{
		new = ft_lst_fold(file->save);
		ft_lstdel(&file->save, &ft_memdel);
		file->save = new;
	}
	free(buf);
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	return (-1);
}

static int		send(t_file *file, char **line)
{
	size_t	i;
	char	*str;
	t_list	*new;

	str = ((char*)(file->save->content));
	i = 0;
	while (i < file->save->content_size && str[i] != '\n')
		i++;
	*line = ft_memalloc(i + 1);
	if (!line)
		return (-1);
	ft_memccpy(*line, str, '\n', i);
	(*line)[i] = '\0';
	if (i < file->save->content_size)
	{
		new = ft_lstnew(((char*)(file->save->content)) + i + 1,
						file->save->content_size - i - 1);
		ft_lstdelone(&file->save, &ft_memdel);
		file->save = new;
	}
	else
		ft_lstdelone(&file->save, &ft_memdel);
	if (!i && !file->status)
		return (0);
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*dial;
	t_list			*link_dial;
	t_file			*file;

	if (fd < 0)
		return (-1);
	link_dial = get_dial(fd, &dial);
	if (!link_dial)
		return (-1);
	file = link_dial->content;
	if (!file)
		return (-1);
	if (!file->save
		|| !ft_memchr(file->save->content, '\n', file->save->content_size))
		file->status = read_more(file);
	if (file->save && file->status != -1)
		file->status = send(file, line);
	if (file->status < 0)
	{
		ft_lstdel(&file->save, &ft_memdel);
		link_dial = ft_lst_remove(&dial, link_dial);
		ft_lstdel(&link_dial, &ft_memdel);
		return (-1);
	}
	return (file->status);
}
