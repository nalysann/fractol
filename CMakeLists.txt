# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/13 11:44:19 by nalysann          #+#    #+#              #
#    Updated: 2020/09/13 11:44:21 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.17)
project(fractol C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-O2 -march=native -pipe")

include_directories(include)
include_directories(libft/include)
include_directories(libmlx)

add_executable(fractol
        include/cl_data.h
        include/cl_funs.h
        include/error.h
        include/fractol.h
        include/hook.h
        include/image.h
        include/keyboard.h
        include/mouse.h
        include/palette.h
        include/utils.h
        src/cl_init.c
        src/cl_run.c
        src/fractol.c
        src/hook.c
        src/kernel.cl
        src/keyboard.c
        src/keyboard_utils.c
        src/mouse.c
        src/mouse_utils.c
        src/palette.c
        src/utils.c)
