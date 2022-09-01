#include "sandpiles.h"

/**
 * test_stability - Function to test stability
 * @grid1: 3x3 stable grid
 *
 * Return: 0 if stable or 1 if not
 */

int test_stability(int grid1[3][3])
{
    int x, y;

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            if (grid1[x][y] > 3)
                return (0);
        }
    }
    return (1);
}

/**
 * topple_grid - Function to topple grid accordingly to make it stable
 * @grid1: 3x3 grid
 */

void topple_grid(int grid1[3][3])
{
    int x, y;
    int zero_grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    printf("=\n");
    print_grid(grid1);
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            if (grid1[x][y] > 3)
            {
                grid1[x][y] -= 4;

                if (x >= 0 && x < 2)
                {
                    zero_grid[x + 1][y] += 1;
                }
                if (x > 0 && x <= 2)
                {
                    zero_grid[x - 1][y] += 1;
                }
                if (y >= 0 && y < 2)
                {
                    zero_grid[x][y + 1] += 1;
                }
                if (y > 0 && y <= 2)
                {
                    zero_grid[x][y - 1] += 1;
                }
            }
        }
    }

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            grid1[x][y] += zero_grid[x][y];
        }
    }
}

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: 3x3 stable grid
 * @grid2: 3x3 stable grif
 *
 * Return: grid1 sumed up by grid1 + grid2
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int x, y;

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            grid1[x][y] = grid1[x][y] + grid2[x][y];
        }
        while (test_stability(grid1) == 0)
            topple_grid(grid1);
    }
}
