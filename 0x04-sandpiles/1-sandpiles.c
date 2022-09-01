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
            if (grid1[x][y] <= 3)
                return (0);   
        }
    }  
    return (1); 
}

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
            if (grid1[x][y] >= 4)
            {
                grid1[x][y] -= 4;

                if (grid1[x + 1][y])
                {
                    if (grid1[x + 1][y] >= 4)
                    {
                        zero_grid[x][y] += 1;
                        grid1[x + 1][y] -= 4;
                    }
                    int num_o = zero_grid[x + 1][y];
                    zero_grid[x + 1][y] = num_o++;
                }

                if (grid1[x][y + 1])
                {
                    if (grid1[x][y + 1] >= 4)
                    {
                        zero_grid[x][y] += 1;
                        grid1[x][y + 1] -= 4;
                    }
                    int num_t = zero_grid[x][y + 1];
                    zero_grid[x][y + 1] = num_t++;
                }

                /*if (grid1[x][y - 1])
                {
                    int check1 = grid1[x][y - 1];
                    if (check1 >= 4)
                    {
                        zero_grid[x][y] += 1;
                        grid1[x][y - 1] = check1 - 4;
                    }
                    int num_tr = zero_grid[x][y - 1];
                    zero_grid[x][y - 1] = num_tr++;
                }*/

                /*if (grid1[x - 1][y])
                {
                    int check2 = grid1[x - 1][y];
                    if (check2 >= 4)
                    {
                        zero_grid[x][y]++;
                        grid1[x - 1][y] = check2 - 4;
                    }
                    int num_f = zero_grid[x - 1][y];
                    zero_grid[x - 1][y] = num_f++;
                }*/
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
 * Return: grid1 stable
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int x, y;

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            grid1[x][y] = grid1[x][y] + grid2[x][y];

            if (test_stability(grid1) != 0)
                topple_grid(grid1);       
        }
    }
}
