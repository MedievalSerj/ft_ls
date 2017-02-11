cmake_minimum_required(VERSION 3.6)
project(ft_ls)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(SOURCE_FILES
		buble_sort.c
		ft_inspect_file.c
		ft_list_dir.c
		ft_ls.c
		get_info.c
		get_width.c
		initial_sort.c
		list_functions.c
		print_f.c
		print_f_dir.c
		proc_flags.c
		proc_input.c
		proc_links.c
		sort_string.c)

add_executable(ft_ls ${SOURCE_FILES})
target_link_libraries(ft_ls ${CMAKE_SOURCE_DIR}/libft.a)