/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:40:54 by ofranco           #+#    #+#             */
/*   Updated: 2017/12/18 10:41:24 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    image_set_pixel(t_mlx *mlx, int x, int y)
{
    if (x < 0 || x >= SCREEN_X || y < 0 || y >= SCREEN_Y)
        return ;
    *(int *)(mlx->image->ptr + ((x + y * SCREEN_X) * BPP)) = COLOR;
}

void    *delete_image(t_mlx *mlx)
{
    if (mlx->image != NULL)
    {
        if (mlx->image->image != NULL)
            mlx_destroy_image(mlx->mlx, mlx->image->image);
        ft_memdel((void **)&mlx->image);
    }
    return (NULL);
}

void    *new_image(t_mlx *mlx)
{
    if (mlx->image == NULL)
    {
        if ((mlx->image = ft_memalloc(sizeof(t_image))) == NULL)
            return (NULL);
    }
    if ((mlx->image->image = mlx_new_image(mlx->mlx, SCREEN_X, SCREEN_Y))
            == NULL)
        return (delete_image(mlx));
    mlx->image->ptr = mlx_get_data_addr(mlx->image->image, &mlx->image->bpp,
            &mlx->image->stride, &mlx->image->endian);
    mlx->image->bpp /= 8;
    return (mlx->image);
}
