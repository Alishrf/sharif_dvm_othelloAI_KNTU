#include <stdio.h>

void showmap(char const *pargv, int *pMapArray);

int main(int argc, char const *argv[])
{
    char const *pargv = &argv[1][0]; //start from second argv
    int MapArray[8][8]; // our game map 2d-array
    int i,j; // counters;
    int* pMapArray = &MapArray[0][0]; //sending 2d-array to showmap function as a pointer
    showmap(pargv,pMapArray); // puts argvs in 2d-array and prints the array
    return 0;
}

void showmap(char const *pargv, int *pMapArray)
{
    int i; 
    // nested for to convert chars to ints and put in array
    for (i = 0; i < 8; ++i)
    {
        for (; *pargv != '\0'; pargv++)
        {
            *pMapArray = *pargv-48;
            pMapArray++;
        }
        ++pargv;
        ++pargv;
    }
    // nested for to print the array
    for(j = 0; j < 8; j++)
    {
        for(i = 0; i < 8; i++)
        {
            printf("%d ",MapArray[i][j]);
        }
        printf("\n");
    }
}