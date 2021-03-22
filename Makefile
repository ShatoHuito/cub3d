

NAME	= cub3D
CC		= gcc
CFLAGS			= -O3 -Wall -Wextra -Werror -I.

SRCS 	= main.c    \
            map_inic.c \
            map_parc.c \
            map_valid.c \
            ray_and_draw.c \
            spr_draw.c \
            spr_sort.c \
            textures.c \
            libft/ft_calloc.c \
            libft/ft_isdigit.c \
            libft/ft_lstadd_back.c \
            libft/ft_lstnew.c \
            libft/ft_lstlast.c \
            libft/ft_lstsize.c \
            libft/ft_memset.c \
            libft/ft_putchar_fd.c \
            libft/ft_putstr_fd.c \
            libft/ft_strncmp.c \
            get_next_line/get_next_line.c \
            get_next_line/get_next_line_utils.c \
            screenshot.c \
			key_hook.c \
			utils.c \
			resol_utils.c \
			floor_color.c \
			ceilling_color.c \
			ray_and_draw_2.c \
			textures_2.c \
			valid_color.c \



OBJS			= $(SRCS:.c=.o)

LIBS			= -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib


all:			$(NAME)

$(NAME):     $(OBJS)
			make -C ./minilibx_mms/
			cp ./minilibx_mms/libmlx.dylib .
			gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} ${MLX}




clean:
				rm -f $(OBJS) libmlx.dylib
				make clean -C ./minilibx_mms/

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
