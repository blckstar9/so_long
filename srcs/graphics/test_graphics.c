#include "../../inc/so_long.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int close_window(t_map *map)
{
    mlx_destroy_window(map->mlx, map->win);
    exit(0);
    return (0);
}

void test_graphics()
{
    t_map map;

    // Initialize the map dimensions and player position for testing
    map.width = 13;
    map.height = 5;
    map.map = (char *[]) {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P0011E000001",
        "1111111111111",
        NULL
    };

    // Initialize the game window and images
    assert(init_window(&map) == 0);
    assert(init_images(&map) == 0);

    // Draw the map
    draw_floor(&map);
    draw_wnc(&map);
    draw_player(&map);
    draw_exit(&map);

    // Set up event handling to close the window
    mlx_hook(map.win, 17, 0, close_window, &map); // Handle window close event
    mlx_key_hook(map.win, close_window, &map); // Handle key press event

    // Display the window and wait for user input to close
    mlx_loop(map.mlx);
}

int main()
{
    test_graphics();
    printf("Graphics test passed\n");
    return 0;
}