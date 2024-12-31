// #include <stdio.h>
// #include <stdlib.h>
// #include "../../inc/so_long.h"

// int main(int argc, char **argv)
// {
//     t_map map;

//     if (argc != 2)
//     {
//         fprintf(stderr, "Usage: %s <map_file.ber>\n", argv[0]);
//         return EXIT_FAILURE;
//     }

//     if (map_init(argv[1], &map) < 0)
//     {
//         fprintf(stderr, "Error initializing map\n");
//         return EXIT_FAILURE;
//     }

//     printf("Map initialized successfully:\n");
//     printf("Width: %d, Height: %d\n", map.width, map.height);
//     for (int i = 0; i < map.height; i++)
//     {
//         printf("%s", map.map[i]);
//     }

//     // Free allocated memory
//     for (int i = 0; i < map.height; i++)
//     {
//         free(map.map[i]);
//     }
//     free(map.map);

//     return EXIT_SUCCESS;
// }
