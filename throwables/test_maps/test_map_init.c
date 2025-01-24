#include "../../inc/so_long.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Helper function to create a temporary map file
void create_temp_map_file(const char *filename, const char *content)
{
    FILE *file = fopen(filename, "w");
    if (file)
    {
        fputs(content, file);
        fclose(file);
    }
}

void test_map_init_valid()
{
    t_map map;
    create_temp_map_file("test_maps/valid_map.ber",
        "1111111111111\n"
        "10010000000C1\n"
        "1000011111001\n"
        "1P0011E000001\n"
        "1111111111111\n");
    printf(CYAN "Testing valid map...\n" RESET);
    assert(map_init("test_maps/valid_map.ber", &map) == 0);
    printf(GREEN "test_map_init_valid passed\n" RESET);
    free_map(&map);
}

void test_map_init_no_collectibles()
{
    t_map map;
    create_temp_map_file("test_maps/no_collectibles.ber",
        "1111111111111\n"
        "1001000000001\n"
        "1000011111001\n"
        "1P0011E000001\n"
        "1111111111111\n");
    printf(CYAN "Testing map with no collectibles...\n" RESET);
    assert(map_init("test_maps/no_collectibles.ber", &map) == -1);
    printf(GREEN "test_map_init_no_collectibles passed\n" RESET);
}

void test_map_init_no_exit()
{
    t_map map;
    create_temp_map_file("test_maps/no_exit.ber",
        "1111111111111\n"
        "10010000000C1\n"
        "1000011111001\n"
        "1P00110000001\n"
        "1111111111111\n");
    printf(CYAN "Testing map with no exit...\n" RESET);
    assert(map_init("test_maps/no_exit.ber", &map) == -1);
    printf(GREEN "test_map_init_no_exit passed\n" RESET);
}

void test_map_init_no_player()
{
    t_map map;
    create_temp_map_file("test_maps/no_player.ber",
        "1111111111111\n"
        "10010000000C1\n"
        "1000011111001\n"
        "100011E000001\n"
        "1111111111111\n");
    printf(CYAN "Testing map with no player...\n" RESET);
    assert(map_init("test_maps/no_player.ber", &map) == -1);
    printf(GREEN "test_map_init_no_player passed\n" RESET);
}

void test_map_init_player_stuck()
{
    t_map map;
    create_temp_map_file("test_maps/player_stuck.ber",
        "1111111111111\n"
        "1P110000000C1\n"
        "1100011111001\n"
        "100011E000001\n"
        "1111111111111\n");
    printf(CYAN "Testing map with player stuck...\n" RESET);
    assert(map_init("test_maps/player_stuck.ber", &map) == -1);
    printf(GREEN "test_map_init_player_stuck passed\n" RESET);
}

void test_map_init_inaccessible_collectible()
{
    t_map map;
    create_temp_map_file("test_maps/inaccessible_collectible.ber",
        "1111111111111\n"
        "1001000000001\n"
        "1000011111001\n"
        "1P0011E000001\n"
        "1111111111C11\n");
    printf(CYAN "Testing map with inaccessible collectible...\n" RESET);
    assert(map_init("test_maps/inaccessible_collectible.ber", &map) == -1);
    printf(GREEN "test_map_init_inaccessible_collectible passed\n" RESET);
}

void test_map_init_inaccessible_exit()
{
    t_map map;
    create_temp_map_file("test_maps/inaccessible_exit.ber",
        "1111111111111\n"
        "10010000000C1\n"
        "1000011111001\n"
        "1P00110000001\n"
        "1111111111E11\n");
    printf(CYAN "Testing map with inaccessible exit...\n" RESET);
    assert(map_init("test_maps/inaccessible_exit.ber", &map) == -1);
    printf(GREEN "test_map_init_inaccessible_exit passed\n" RESET);
}

void test_map_init_non_rectangular()
{
    t_map map;
    create_temp_map_file("test_maps/non_rectangular_map.ber",
        "1111111111111\n"
        "10010000000C1\n"
        "1000011111001\n"
        "1P0011E000001\n"
        "1111111111\n");
    printf(CYAN "Testing non-rectangular map...\n" RESET);
    assert(map_init("test_maps/non_rectangular_map.ber", &map) == -1);
    printf(GREEN "test_map_init_non_rectangular passed\n" RESET);
}

void test_map_init_no_walls()
{
    t_map map;
    create_temp_map_file("test_maps/no_walls.ber",
        "10010000000C1\n"
        "1000011111001\n"
        "1P0011E000001\n"
        "10010000000C1\n"
        "1000011111001\n");
    printf(CYAN "Testing map with no walls...\n" RESET);
    assert(map_init("test_maps/no_walls.ber", &map) == -1);
    printf(GREEN "test_map_init_no_walls passed\n" RESET);
}

int main()
{
    printf(YELLOW "Starting map initialization tests...\n" RESET);
    test_map_init_valid();
    test_map_init_no_collectibles();
    test_map_init_no_exit();
    test_map_init_no_player();
    test_map_init_player_stuck();
    test_map_init_inaccessible_collectible();
    test_map_init_inaccessible_exit();
    test_map_init_non_rectangular();
    test_map_init_no_walls();
    printf(GREEN "All tests passed\n" RESET);
    return 0;
}
