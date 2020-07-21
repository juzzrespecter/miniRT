/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:26:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/21 17:44:56 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H
#include "../libft/libft.h"
#include "vector.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *img_ptr;
	int x_res;
	int y_res;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_data;

typedef struct s_res
{
	int x_res;
	int y_res;
} t_res;

typedef struct s_amb
{
	float light;
	unsigned char color[3];
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
	unsigned char color[3];
	struct s_light *next;
} t_light;

typedef struct s_sp
{
	float coord[3];
	float d;
	unsigned char color[3];
	struct s_sp *next;
} t_sp;

typedef struct s_pl
{
	float coord[3];
	float vector[3];
	unsigned char color[3];
	struct s_pl *next;
} t_pl;

typedef struct s_sq
{
	float coord[3];
	float vector[3];
	float side;
	unsigned char color[3];
	struct s_sq *next;
} t_sq;

typedef struct s_cy
{
	float coord[3];
	float vector[3];
	float d;
	float h;
	unsigned char color[3];
	struct s_cy *next;
} t_cy;

typedef struct s_tr
{
	float first_coord[3];
	float second_coord[3];
	float third_coord[3];
	unsigned char color[3];
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

t_objlst *check_syntax_scene(char *scene_file);
void setup_obj_lst(t_objlst *obj_lst);
void delete_obj_lst(t_objlst *obj_lst);
int greater_length(char *s1, char *s2);
bool check_scene_array(char **scene_line, int n_lines);
bool res_error_check(char **scene_line);
bool light_check(char *light);
bool color_check(char *color);
bool coord_check(char *coord);
bool vector_check(char *vector);
bool dim_check(char *dim);
float char_to_float(char *array);
void array_char_to_float(float *coord, char *array);
void char_to_color(unsigned char *color, char *array);
bool res_build_obj(char **scene_line, t_objlst *obj_lst);
bool a_build_obj(char **scene_line, t_objlst *obj_lst);
bool l_build_obj(char **scene_line, t_objlst *obj_lst);
bool c_build_obj(char **scene_line, t_objlst *obj_lst);
bool sp_build_obj(char **scene_line, t_objlst *obj_lst);
bool pl_build_obj(char **scene_line, t_objlst *obj_lst);
bool sq_build_obj(char **scene_line, t_objlst *obj_lst);
bool cy_build_obj(char **scene_line, t_objlst *obj_lst);
bool tr_build_obj(char **scene_line, t_objlst *obj_lst);
char *draw_image(t_objlst *obj_lst, t_data data, char *img);
void search_for_collision(t_objlst *obj_lst, t_3dvec *ray);
void sp_loop(t_sp *sp, t_cam *cam, t_3dvec *ray);
void pl_loop(t_pl *pl, t_cam *cam, t_3dvec *ray);
void sq_loop(t_sq *sq, t_cam *cam, t_3dvec *ray);
void cy_loop(t_cy *cy, t_cam *cam, t_3dvec *ray);
void tr_loop(t_tr *tr, t_cam *cam, t_3dvec *ray);
void sp_collision(t_sp *sp,  t_cam *cam, t_3dvec *ray);

#endif
