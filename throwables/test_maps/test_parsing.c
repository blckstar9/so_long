#include "../../inc/so_long.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_map_init_valid()
{
    t_map map;
    assert(map_init("test_maps/valid_map.ber", &map) == 0);
    printf("test_map_init_valid passed\n");
    free_map(&map);
}

void test_map_init_no_collectibles()
{
    t_map map;
    assert(map_init("test_maps/no_collectibles.ber", &map) == -1);
    printf("test_map_init_no_collectibles passed\n");
}

void test_map_init_no_exit()
{
    t_map map;
    assert(map_init("test_maps/no_exit.ber", &map) == -1);
    printf("test_map_init_no_exit passed\n");
}

void test_map_init_no_player()
{
    t_map map;
    assert(map_init("test_maps/no_player.ber", &map) == -1);
    printf("test_map_init_no_player passed\n");
}

void test_map_init_player_stuck()
{
    t_map map;
    assert(map_init("test_maps/player_stuck.ber", &map) == -1);
    printf("test_map_init_player_stuck passed\n");
}

void test_map_init_inaccessible_collectible()
{
    t_map map;
    assert(map_init("test_maps/inaccessible_collectible.ber", &map) == -1);
    printf("test_map_init_inaccessible_collectible passed\n");
}

void test_map_init_inaccessible_exit()
{
    t_map map;
    assert(map_init("test_maps/inaccessible_exit.ber", &map) == -1);
    printf("test_map_init_inaccessible_exit passed\n");
}

void test_map_init_non_rectangular()
{
    t_map map;
    assert(map_init("test_maps/non_rectangular_map.ber", &map) == -1);
    printf("test_map_init_non_rectangular passed\n");
}

void test_map_init_no_walls()
{
    t_map map;
    assert(map_init("test_maps/no_walls.ber", &map) == -1);
    printf("test_map_init_no_walls passed\n");
}

int main()
{
     test_map_init_valid();
    //  test_map_init_no_collectibles();
    //  test_map_init_no_exit();
    //  test_map_init_no_player();
    //  test_map_init_player_stuck();
    //  test_map_init_inaccessible_collectible();
    //  test_map_init_inaccessible_exit();
    //  test_map_init_non_rectangular();
    //  test_map_init_no_walls();
    printf("All tests passed\n");
    return 0;
}
