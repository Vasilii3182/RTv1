/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:08:31 by ofranco           #+#    #+#             */
/*   Updated: 2017/12/18 10:40:02 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putstr("Usage: ./rtv1 [filename]\n")
		return (0);
	}
	if ((mlx = initialize()) == NULL)
	{
		ft_putstr("Window creation failed.Exiting.\n");
		return (-1);
	}
	if ((mlx->scene = parsing_file(argv[1])) == NULL)
		mlx_free(mlx);
	if ((mlx->image = new_image(mlx)) == NULL)
		mlx_free(mlx);
	raytracing(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
