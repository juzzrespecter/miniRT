/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:26:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 16:47:24 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H
#include "../libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_res
{
	int x_res;
	int y_res;
} t_res;

typedef struct s_amb
{
	float light;
	unsigned char color;
} t_amb;

typedef struct s_cam
{
	float coord[3];
	float vector[3];
	int fov;
	struct s_cam *next;
} t_cam;

typedef struct s_light
{
	float coord[3];
	float light;
	unsigned char color;
	struct s_light *next;
} t_light;

typedef struct s_sp
{
	float coord[3];
	float d;
	unsigned char color;
	struct s_sp *next;
} t_sp;

typedef struct s_pl
{
	float coord[3];
	float vector[3];
	unsigned char color;
	struct s_pl *next;
} t_pl;

typedef struct s_sq
{
	float coord[3];
	float vector[3];
	float side;
	unsigned char color;
	struct s_sq *next;
} t_sq;

typedef struct s_cy
{
	float coord[3];
	float vector[3];
	float d;
	float h;
	unsigned char color;
	struct s_cy *next;
} t_cy;

typedef struct s_tr
{
	float first_coord[3];
	float second_coord[3];
	float third_coord[3];
	unsigned char color;
	struct s_tr *next;
} t_tr;

typedef struct s_objlst
{
	t_res *res;
	t_amb *amb;
	t_cam *cam;
	t_light *light;
	t_sp *sp;
	t_pl *pl;
	t_sq *sq;
	t_cy *cy;
	t_tr *tr;
} t_objlst;

bool check_syntax_scene(char *scene_file);
int greater_length(char *s1, char *s2);
bool check_scene_array(char **scene_line, int n_lines);
bool res_error_check(char **scene_line);
bool light_check(char *light);
bool color_check(char *color);
bool coord_check(char *coord);
bool vector_check(char *vector);
bool dim_check(char *dim);
bool res_error_check(char **scene_line);
bool a_error_check(char **scene_line);
bool c_error_check(char **scene_line);
bool l_error_check(char **scene_line);
bool sp_error_check(char **scene_line);
bool pl_error_check(char **scene_line);
bool sq_error_check(char **scene_line);
bool cy_error_check(char **scene_line);
bool tr_error_check(char **scene_line);

#endif
