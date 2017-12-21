/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:12:11 by ofranco           #+#    #+#             */
/*   Updated: 2017/12/19 13:53:25 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene	*scene_init(void)
{
	t_scene *scene;

	scene->spheres == NULL;
	scene->cones == NULL;
	scene->planes == NULL;
	scene->spot == NULL;
	return (scene);
}

t_mlx   *initialize(void)
{
    t_mlx *mlx;

    if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
        return (NULL);
    if ((mlx->mlx = mlx_init()) == NULL || 
			(mlx->scene = ft_memalloc(sizeof(t_scene))) == NULL)
        return (mlx_free(mlx));
	mlx->scene = scene_init();
    return (mlx);
}

t_mlx   *mlx_free(t_mlx *mlx)
{
    if (mlx->win != NULL)
        mlx_destroy_window(mlx->mlx, mlx->win);
    if (mlx->image != NULL)
        delete_image(mlx);
    if (mlx->scene != NULL)
		printf("scene a delete\n");
    ft_memdel((void **)&mlx);
    exit(0);
    return (NULL);
}
