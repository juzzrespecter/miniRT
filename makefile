#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 16:20:58 by danrodri          #+#    #+#              #
#    Updated: 2020/07/08 18:51:00 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean

SRCS		= main.c \
			check_syntax_scene.c \
			delete_obj_lst.c \
			setup_obj_lst.c \
			greater_length.c \
			check_scene_array.c \
			light_check.c \
			color_check.c \
			coord_check.c \
			vector_check.c \
			dim_check.c \
			array_char_to_float.c \
			char_to_color.c \
			res_build_obj.c \
			a_build_obj.c \
			c_build_obj.c \
			l_build_obj.c \
			sp_build_obj.c \
			pl_build_obj.c \
			sq_build_obj.c \
			cy_build_obj.c \
			tr_build_obj.c

NAME		= miniRT

SRCSDIR		= srcs/

OBJSDIR		= objs/

LIB		= ./libft/libft.a

MLXLIB		= -lmlx -framework OpenGL -framework AppKit -lz

OBJS		= $(patsubst %.c, $(OBJSDIR)%.o, $(SRCS))

GCC		= gcc -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		@make -C libft
		@$(GCC) -o $(NAME) $(OBJS) $(LIB) $(MLXLIB)

$(OBJSDIR)%.o:	$(SRCSDIR)%.c
		@$(GCC) -c $<
		@mkdir -p objs
		@mv $(@F) $(OBJSDIR)

clean:
		@rm -r $(OBJSDIR)
		@make clean -C libft

fclean:		clean
		@rm $(NAME)
		@make fclean -C libft

debug:
		@make -C libft
		$(GCC) -g -o $(NAME) $(addprefix $(SRCSDIR), $(SRCS)) $(LIB) $(MLXLIB)
