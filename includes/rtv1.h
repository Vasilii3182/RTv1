/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:39:53 by ofranco           #+#    #+#             */
/*   Updated: 2017/12/19 14:15:55 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "./../libft/libft.h"
# include "./../minilibx_macos/mlx.h"
# include <math.h>

# define S_WIDTH 1080
# define S_HEIGHT 800

typedef struct	s_point {

	double		x;
	double		y;
	double		z;

}				t_point;

typedef struct	s_sphere {

	double		radius;
	t_point		center;
	int			color;
	void		*next;

}				t_sphere;

typedef	struct	s_plane	{

	t_point		pos;
	double		dist;
	int			color;
	void		*next;

}				t_plane;

typedef	struct	s_cone	{

	t_point		center;
	double		open;
	int			color;
	void		*next;

}				t_cone;

typedef	struct	s_spot	{

	t_point		pos;
	int			color;
	void		*next;

}				t_spot;

typedef struct	s_image {

    void		*image;
    char		*ptr;
    int			bpp;
    int			stride;
    int			endian;

}				t_image;

typedef	struct	s_scene {

	t_point		cam_pos;
	t_point		cam_dir;
	t_sphere	*spheres;
	t_cone		*cones;
	t_plane		*planes;
	t_spot		*spots;
	
}				t_scene;

typedef	struct	s_mlx {

	t_scene		*scene;
	void		*win;
	void		*mlx;
	t_image		*image;

}				t_mlx;

int	get_file_nblines(char *filename);

#endif
