/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_filelines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:57:15 by ofranco           #+#    #+#             */
/*   Updated: 2017/12/19 17:23:31 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	get_file_nblines(char *filename)
{
	int		fd;
	int		nb;
	int		ret;
	char	*buffer;

	if ((fd = open(filename, O_RDONLY, S_IREAD)) == -1)
		return (fd);
	nb = 0;
	while ((ret =get_next_line(fd, &buffer)) != 0)
	{
		if (ret < 0)
			return (-1);
		nb++;		
	}
	close(fd);
	return (nb);
}
