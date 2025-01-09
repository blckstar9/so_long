#include "../../inc/so_long.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void test_is_path_valid()
{
    t_map map;
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
    // Test with valid map
    assert(is_path_valid(&map, 1, 3) == 1);
    printf("test_is_path_valid with valid map passed\n");

    map.map = (char *[]) {
        "1111111111111",
        "10010000000C1",
        "1000011111001",
        "1P00110000001",
        "1111111111111",
        NULL
    };
    // Test with invalid map
    assert(is_path_valid(&map, 1, 3) == 0);
    printf("test_is_path_valid with invalid map passed\n");
}

int main()
{
    test_is_path_valid();
    printf("All tests passed\n");
    return 0;
}