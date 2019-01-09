#include <stdio.h>

void createmap(char const *pargv, int *pMapArray);
void printmap(char const *pargv, int *pMapArray);

int main(int argc, char const *argv[])
{
    char const *pargv = &argv[1][0]; //start from second argv
    int MapArray[8][8]; // our game map 2d-array
    int i,j; // counters;
<<<<<<< HEAD
    int* pMapArray = &MapArray[0][0]; //sending 2d-array to showmap function as a pointer
    showmap(pargv,pMapArray); // puts argvs in 2d-array and prints the array
    // nested for to print the array
    for(j = 0; j < 8; j++)
    {
        for(i = 0; i < 8; i++)
        {
            printf("%d ",MapArray[i][j]);
        }
        printf("\n");
    }
=======
    //int* pMapArray = &MapArray[0][0]; //sending 2d-array to showmap function as a pointer
    createmap(pargv,&MapArray[0][0]); // puts argvs in 2d-array
    printmap(pargv,&MapArray[0][0]); //  prints the array
>>>>>>> putInput2array
    return 0;
}

void createmap(char const *pargv, int *pMapArray)
{
    int i,j; 
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
}

void printmap(char const *pargv, int *pMapArray)
{
    int i,j;
    // nested for to print the array
    for(j = 0; j < 8; j++)
    {
        for(i = 0; i < 8; i++)
        {
            printf("%d ",*pMapArray);
            *pMapArray++;
        }
        printf("\n");
    }
}