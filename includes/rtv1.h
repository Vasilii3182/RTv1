/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:39:53 by ofranco           #+#    #+#             */
/*   Updated: 2018/01/11 13:19:21 by ofranco          ###   ########.fr       */
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
	t_point		*center;
	int			color;
	struct s_sphere		*next;

}				t_sphere;

typedef	struct	s_plane	{

	t_point		*pos;
	double		dist;
	int			color;
	struct s_plane		*next;

}				t_plane;

typedef	struct	s_cone	{

	t_point		*center;
	double		open;
	int			color;
	struct s_cone		*next;

}				t_cone;

typedef	struct	s_spot	{

	t_point		*pos;
	int			color;
	struct s_spot		*next;

}				t_spot;

typedef	struct	s_cylinder	{

	t_point		*center;
	double		radius;
	int			color;
	struct s_cylinder	*next;

}				t_cylinder;

typedef	struct	s_cam	{

	t_point		*cam_pos;
	t_point		*cam_dir;

}				t_cam;

typedef struct	s_image {

    void		*image;
    char		*ptr;
    int			bpp;
    int			stride;
    int			endian;

}				t_image;

typedef	struct	s_scene {

	t_cam		*camera;
	t_sphere	*spheres;
	t_cone		*cones;
	t_plane		*planes;
	t_spot		*spots;
	t_cylinder	*cylinders;
	
}				t_scene;

typedef	struct	s_mlx {

	t_scene		*scene;
	void		*win;
	void		*mlx;
	t_image		*image;

}				t_mlx;

int	get_file_nblines(char *filename);

#endif
