// FILE: srcs/parsing/test_map_init.c

#include <assert.h>
#include <stdio.h>
#include "../../inc/so_long.h"

void test_has_ber_extension()
{
	assert(has_ber_extension("map.ber") == 1);
	assert(has_ber_extension("map.txt") == 0);
	assert(has_ber_extension("map") == 0);
	printf("test_has_ber_extension passed\n");
}

void test_check_matrix_walls()
{
	char *valid_matrix[] = {
		"1111",
		"1001",
		"1111",
		NULL
	};
	char *invalid_matrix[] = {
		"1111",
		"1001",
		"1101",
		NULL
	};
	assert(check_matrix_walls(valid_matrix, 4, 3) == 0);
	assert(check_matrix_walls(invalid_matrix, 4, 3) == -1);
	printf("test_check_matrix_walls passed\n");
}

void test_get_matrix_dimensions()
{
	int width, height;
	assert(get_matrix_dimensions(&width, &height, "srcs/parsing/validmap.ber") == 0);
	assert(width == 13);
	assert(height == 5);
	printf("test_get_matrix_dimensions passed\n");
}

void test_fill_map_struct()
{
	t_map map;
	char *matrix[] = {
		"1111111111111\n",
		"10010000000C1\n",
		"1000011111001\n",
		"1P0011E000001\n",
		"1111111111111\n",
		NULL
	};
	int fd = open("srcs/parsing/validmap.ber", O_RDONLY);
	assert(fd >= 0);
	assert(fill_map_struct(&map, matrix, 13, 5, fd) == 0);
	assert(map.width == 13);
	assert(map.height == 5);
	close(fd);
	printf("test_fill_map_struct passed\n");
}

void test_map_init()
{
	t_map map;
	assert(map_init("srcs/parsing/validmap.ber", &map) == 0);
	assert(map.width == 13);
	assert(map.height == 5);
	for (int i = 0; i < map.height; i++)
	{
		free(map.map[i]);
	}
	free(map.map);
	printf("test_map_init passed\n");
}

int main()
{
	test_has_ber_extension();
	test_check_matrix_walls();
	test_get_matrix_dimensions();
	test_fill_map_struct();
	test_map_init();
	printf("All tests passed\n");
	return 0;
}
