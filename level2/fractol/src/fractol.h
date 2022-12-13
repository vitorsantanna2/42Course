/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:44:40 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 19:27:45 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct s_complexnumber
{
	double	f;
	double	i;
}	t_complex;

typedef struct s_data
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			vertical;
	int			horizont;
	int			iterations;
	t_complex	z;
	t_complex	c;
	t_complex	j;
	double		minre;
	double		maxre;
	double		minim;
	double		maxim;
	double		zoom;
	double		re_factor;
	double		im_factor;
}	t_data;

int			reset_hook(t_data *img);
int			key_hook(int keycode, t_data *img);
void		initializable_vars(t_data *img);
int			close_hook(t_data *img);
int			mouse_hook(int keycode, int x, int y, t_data *img);
double		absolute_complex(t_complex z);
t_complex	sum_complex(t_complex first, t_complex second);
t_complex	pow_complex(t_complex z);
t_complex	julia_complex(t_complex first, t_data *img);
int			ft_rgb(int transparency, int red, int green, int blue);
int			mandelbrot_escape(t_complex x);
int			color_by_iterations(int iterations);
void		my_mlx_pixel_insert(t_data *data, int x, int y, int color);
void		draw_mandelbrot(t_data *img);
void		draw_julia(t_data *img);
void		argument_invalid(void);
void		validations(int argc, char **argv, t_data *img);
void		start_mandelbrot(t_data *img);
void		start_julie(t_data *img, double x, double y);
#endif
