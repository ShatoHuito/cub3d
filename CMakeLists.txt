cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3d main.c libft/libft.a get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_lstadd_back.c
        libft/ft_lstlast.c libft/ft_lstnew.c libft/ft_lstsize.c
        libft/ft_calloc.c libft/ft_memset.c libft/ft_putendl_fd.c libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c cub3d.h draw.c)
target_link_libraries(cub3d /Users/gbrittan/CLionProjects/cub3d/libmlx.dylib)
target_link_libraries(cub3d /Users/gbrittan/CLionProjects/cub3d/libft/libft.a)
target_link_libraries(cub3d "-framework OpenGL")
target_link_libraries(cub3d "-framework AppKit")