#include "../../inc/so_long.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// ANSI color codes for colored output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Function to close the window and exit the program
// int close_window(t_map *map)
// {
//     mlx_destroy_window(map->mlx, map->win);
//     free_map(map);
//     exit(0);
//     return (0);
// }

// Function to handle key press events
// int handle_key(int key, t_map *map)
// {
//     int x;
//     int y;

//     if (key == XK_Escape)
//         close_window(map);

//     if (translate_key(key, &x, &y))
//     {
//         if (move_player(map, x, y))
//         {
//             draw_floor(map);
//             draw_wnc(map);
//             draw_player(map);
//             draw_exit(map); // Draw the exit only if all collectibles are collected
//         }
//     }

//     return (0);
// }

void test_graphics()
{
    t_map map;

    // Initialize the map from a file
    assert(map_init("test_maps/valid_map.ber", &map) == 0);

    // Initialize the game window and images
    assert(init_window(&map) == 0);
    assert(init_images(&map) == 0);

    // Draw the map
    draw_base(&map);
    draw_enc(&map);
    draw_player(&map);
    // Do not draw the exit initially

    // Set up event handling to close the window
    mlx_hook(map.win, 17, 0, close_window, &map); // Handle window close event
    mlx_key_hook(map.win, handle_key, &map); // Handle key press event

    // Display the window and wait for user input to close
    mlx_loop(map.mlx);
}

int main()
{
    printf(YELLOW "Starting graphics test...\n" RESET);
    test_graphics();
    printf(GREEN "Graphics test passed\n" RESET);
    return 0;
}