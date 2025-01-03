#include "../../inc/so_long.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void test_has_ber_extension()
{
    assert(has_ber_extension("valid_map.ber") == 1);
    assert(has_ber_extension("invalid_map.txt") == 0);
    printf("test_has_ber_extension passed\n");
}

void test_clear_newline()
{
    char line1[] = "Hello\n";
    char line2[] = "World";
    clear_newline(line1);
    clear_newline(line2);
    assert(strcmp(line1, "Hello") == 0);
    assert(strcmp(line2, "World") == 0);
    printf("test_clear_newline passed\n");
}

void test_get_matrix_dimensions()
{
    int width, height;
    assert(get_matrix_dimensions(&width, &height, "test_maps/valid_map.ber") == 0);
    assert(width == 13);
    assert(height == 5);
    assert(get_matrix_dimensions(&width, &height, "test_maps/invalid_map.ber") == -1);
    printf("test_get_matrix_dimensions passed\n");
}

void test_check_matrix_walls()
{
    char *valid_matrix[] = {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P0011E000001",
        "1111111111111",
        NULL
    };
    char *invalid_matrix[] = {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P0011E000001",
        "1111111111110",
        NULL
    };
    assert(check_matrix_walls(valid_matrix, 13, 5) == 0);
    assert(check_matrix_walls(invalid_matrix, 13, 5) == -1);
    printf("test_check_matrix_walls passed\n");
}

void test_check_matrix_interior()
{
    char *valid_matrix[] = {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P0011E000001",
        "1111111111111",
        NULL
    };
    char *invalid_matrix[] = {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P0011X000001",
        "1111111111111",
        NULL
    };
    assert(check_matrix_interior(valid_matrix, 13, 5) == 0);
    assert(check_matrix_interior(invalid_matrix, 13, 5) == -1);
    printf("test_check_matrix_interior passed\n");
}

void test_is_map_valid()
{
    char *valid_matrix[] = {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P0011E000001",
        "1111111111111",
        NULL
    };
    char *invalid_matrix[] = {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P00110000001",
        "1111111111111",
        NULL
    };
    assert(is_map_valid(valid_matrix, 13, 5) == 0);
    assert(is_map_valid(invalid_matrix, 13, 5) == -1);
    printf("test_is_map_valid passed\n");
}

void test_free_matrix()
{
    char **matrix = malloc(3 * sizeof(char *));
    matrix[0] = strdup("111");
    matrix[1] = strdup("1P1");
    matrix[2] = NULL;
    free_matrix(matrix);
    printf("test_free_matrix passed\n");
}

void test_free_map()
{
    t_map map;
    map.height = 2;
    map.map = malloc(2 * sizeof(char *));
    map.map[0] = strdup("111");
    map.map[1] = strdup("1P1");
    free_map(&map);
    printf("test_free_map passed\n");
}

void test_fill_map_struct()
{
    t_map map;
    map.width = 13;
    map.height = 5;
    map.fd = open("test_maps/valid_map.ber", O_RDONLY);
    char **matrix = ft_calloc(sizeof(char *), (map.height + 1));
    assert(fill_map_struct(&map, matrix) == 0);
    assert(map.map != NULL);
    free_map(&map);
    printf("test_fill_map_struct passed\n");
}

void test_map_init()
{
    t_map map;
    assert(map_init("test_maps/valid_map.ber", &map) == 0);
    assert(map.width == 13);
    assert(map.height == 5);
    assert(map.map != NULL);
    free_map(&map);
    printf("test_map_init passed\n");
}

int main()
{
    test_has_ber_extension();
    test_clear_newline();
    test_get_matrix_dimensions();
    test_check_matrix_walls();
    test_check_matrix_interior();
    test_is_map_valid();
    test_free_matrix();
    test_free_map();
    test_fill_map_struct();
    test_map_init();
    printf("All tests passed\n");
    return 0;
}
