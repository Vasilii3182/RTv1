/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:42:25 by ofranco           #+#    #+#             */
/*   Updated: 2018/01/11 13:49:13 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_point		*ft_getxyz(char *str, t_point *p)
{
	p->x = ft_doubleatoi(str);
	str = str + 2;
	p->y = ft_doubleatoi(str);
	str = str + 2;
	p->z = ft_doubleatoi(str);
	free(str);
	return (p);
}

t_point		*import_point(int fd)
{
	t_point	*p;
	char	*buffer;
	
	if (get_next_line(fd, &buffer) < 1)
	{	
		if ((p = (t_point*)malloc(sizeof(t_point))) == NULL)
			return (NULL);
		p = ft_getxyz(ft_strdup(buffer), p);
	}
	return (p);
}

t_camera	*import_cam(int fd)
{
	t_cam	*camera;
	int		read_ret;
	char	*buffer;

	if ((camera = ft_memalloc(sizeof(t_cam))) == NULL)
		return (NULL);
	while ((read_ret = get_next_line(fd, &buffer)) > 0 &&
				ft_strcmp(buffer, "----------"))
	{
		if	(ft_strcmp("pos:", buffer) == 0)
			camera->cam_pos = import_point(fd);
		if (ft_strcmp("dir:", buffer) == 0)
			camera->cam_dir = import_point(fd);	
	}
	if (read_ret == -1)
		return (-1);
	return (camera);
}
