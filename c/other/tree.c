/*
 * Author: Szymon Kublin (szymonkublin@gmail.com)
 * Date: 18-12-2022
 *
 * 'Algorithm':
 *
 * ./choinka 8
 *
 *       *
 *      *#*
 *     *###*
 *    *#####*
 *   *#######*
 *  *#########*
 * *###########*
 *      ##
 *      ##
 *
 * levels = 8
 *
 * row - characters [total]
 * 0 - 8 x space, *             [9 + 1 = 10]
 * 1 - 6 x space, *, 1 x #, *   [6 + 1 + 1 + 1 + 1 = 10]
 * 2 - 5 x space, *, 3 x #, *   [5 + 1 + 3 + 1 + 1 = 10]
 * 3 - 4 x space, *, 5 x #, *   [4 + 1 + 5 + 1 + 1 = 12]
 * 4 - 3 x space, *, 7 x #, *
 * 5 - 2 x space, *, 9 x #, *
 * 6 - 1 x space, *, 11 x #, *  [1 + 1 + 11 + 1 + 1 = 15]
 * 7 - 6 x space, 2 x #         [6 + 2 + 1 = 9]
 * 8 - 6 x space, 2 x #         [9]
 *
 * for 0:levels+1
 * 
 * row 0 -> levels * space + '*'
 * row 1 -> (levels - row - 1) * space + '*' + (2*row - 1) * '#' + '*'
 * ...
 * row (levels - 1) -> (levels - 2) * space + '##'
 * row levels -> (levels - 2) * space + '##'
 *
 * (!) each line with \n (!)
 *
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void merry_christmas(int levels);

char* get_shape();

int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (argc == 2)
    {
        int lvl = atoi(argv[1]);
        if (lvl > 5)
            merry_christmas(lvl);
        else if (lvl == 0)
            printf("Wrong argument!\n");
        else
            printf("Levels number must be larger than 5!\n");
    }
    else if (argc > 2)
        printf("There are too many arguments!\n");
    else
        printf("Expected one argument (number of levels).\n");

    return 0;
}

void merry_christmas(int levels)
{
    char *tree, *str;
    int j = 1;

    tree = (char*)malloc(sizeof(char));
    str = (char*)malloc(sizeof(char));
    
    for (int row = 0; row < levels + 1; row++)
    {
        if (row == 0)
        {
            // top of the tree
            j += levels + 1;
            tree = (char*)realloc(tree, j * sizeof(char));
            sprintf(tree, "%s%*s*\n", tree, levels-1, "");
        }
        else if (row < levels - 1)
        {
           // middle of the tree
           // 1. prepare string with '#'s
           strcpy(str, "");
           str = (char*)realloc(str, (2*row - 1) * sizeof(char));
           for (int i = 0; i < 2*row - 1; i++)
           {
               char* c = get_shape();
               strcat(str, c);
           }
           // 2. append spaces, *, '#'s and *
           j += (levels - row - 1) + (2 * row - 1) + 3;
           tree = (char*)realloc(tree, j * sizeof(char));
           sprintf(tree, "%s%*s*%s*\n", tree, levels-row-1, "", str);
        }
        else 
        {
            // bottom of the tree
            j += levels + 1;
            tree = (char*)realloc(tree, j * sizeof(char));
            sprintf(tree, "%s%*s##\n", tree, levels-2, "");
        }

    }
    printf("\033[0;31m");
    printf("\nMerry Christmas!\n\n%s\n", tree);
    printf("\033[0m");
}

char* get_shape()
{
    int r = rand() % 10;
    
    if (r == 0 || r == 9)
        return "O";
    else
        return "#";
}

