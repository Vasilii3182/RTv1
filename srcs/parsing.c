/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:15:31 by ofranco           #+#    #+#             */
/*   Updated: 2018/01/09 16:41:11 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene	*parsing_file(char *filename, t_scene *scene)
{
	int fd;
	int read_ret;
	char *buffer;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((read_ret = get_next_line(fd, &buffer)) > 0)
	{
		if (ft_strcmp("camera:", buffer) == 0)
			scene->camera = import_cam(fd);
		if (ft_strcmp("spheres:", buffer) == 0)
			scene->spheres = import_spheres(fd);
		if (ft_strcmp("planes:", buffer) == 0)
			scene->planes = import_planes(fd);
		if (ft_strcmp("spots:", buffer) == 0)
			scene->spots = import_spots(fd);
		if (ft_strcmp("cones:", buffer) == 0)
			scene->cones = import_cones(fd);
		if (ft_strcmp("cylinders:", buffer) == 0)
			scene->cylinders = import_cylinder(fd);
	}
	if (read_ret == -1)
		return (NULL);
	return (scene);
}
