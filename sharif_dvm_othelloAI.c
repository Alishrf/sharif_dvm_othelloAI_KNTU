#include <stdio.h>

void createmap(char const *pargv[], int MapArray[][8]);
void printmap(int pMapArray[][8]);

int main(int argc, char const *argv[])
{
    int MapArray[8][8]; // our game map 2d-array
    //int* pMapArray = &MapArray[0][0]; //sending 2d-array to showmap function as a pointer
    createmap(argv,MapArray); // puts argvs in 2d-array
    printmap(MapArray); //  prints the array
    return 0;
}

void createmap(char const *pargv[], int MapArray[][8])
{
    int i,j; 
    // nested for to convert chars to ints and put in array
    for (i = 1; i <= 8; ++i)
    {
        for (j=0; pargv[i][j] != '\0'; j++)
        {
           MapArray[i-1][j]=pargv[i][j] - 48;
        }
    }
}

void printmap(int MapArray[][8])
{
    int i,j;
    // nested for to print the array
    for(j = 0; j < 8; j++)
    {
        for(i = 0; i < 8; i++)
        {
            printf("%d ",MapArray[j][i]);
        }
        printf("\n");
    }
}