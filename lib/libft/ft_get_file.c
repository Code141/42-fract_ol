/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 03:40:10 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/22 13:30:29 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

static int	read_file(int fd, t_list **file)
{
	t_list	*new;
	char	*buf;
	size_t	ret;

	buf = (char*)malloc(BUFF_SIZE);
	if (!buf)
		return (0);
	new = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		ft_lst_push_back(&new, ft_lstnew(buf, ret));
	free(buf);
	*file = ft_lst_fold(new);
	ft_lstdel(&new, &ft_memdel);
	if (!*file)
		return (0);
	return (1);
}

char		*ft_get_file(char *file_name)
{
	char	*str;
	t_list	*file;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!read_file(fd, &file))
		return (NULL);
	close(fd);
	str = (char*)malloc(sizeof(char) * (file->content_size + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, file->content, file->content_size);
	str[file->content_size] = '\0';
	ft_lstdel(&file, &ft_memdel);
	return (str);
}
