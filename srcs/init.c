/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:12:11 by ofranco           #+#    #+#             */
/*   Updated: 2017/12/18 10:40:08 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mlx   *initialize(void)
{
    t_mlx *mlx;

    if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
        return (NULL);
    if ((mlx->mlx = mlx_init()) == NULL || 
			(mlx->scene = ft_memalloc(sizeof(t_scene))) == NULL)
        return (mlx_free(mlx));
	if ((mlx->scene = scene_init()) == NULL)
		return (mlx_free(mlx));
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
