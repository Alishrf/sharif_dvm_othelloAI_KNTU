#include <stdio.h>

void createmap(char const *pargv[], int MapArray[][8]);
void printmap(int pMapArray[][8]);
void checkvalidcell(int MapArray[][8],int validcell [][60],int bead);
void checkdown(int MapArray[][8],int validcell [][60],int bead,int x,int y);
void checkdownright(int MapArray[][8],int validcell [][60],int bead,int x,int y);
void checkdownleft(int MapArray[][8],int validcell [][60],int bead,int x,int y);
void checkup(int MapArray[][8],int validcell [][60],int bead,int x,int y);
void checkupleft(int MapArray[][8],int validcell [][60],int bead,int x,int y);
void checkright(int MapArray[][8],int validcell [][60],int bead,int x,int y);
void checkupright(int MapArray[][8],int validcell [][60],int bead,int x,int y);
void checkleft(int MapArray[][8],int validcell [][60],int bead,int x,int y);
int main(int argc, char const *argv[])
{
    int bead;
    int MapArray[8][8]; // our game map 2d-array
    //int* pMapArray = &MapArray[0][0]; //sending 2d-array to showmap function as a pointer
    int validcell[3][60];//shows valid cell
    for(int i=0;i<60;i++){
        validcell[0][i]=-1;
    }
    
    bead=*argv[9]-48; //bead var shows our bead color
    printf("b=%d\n",bead);
    createmap(argv,MapArray); // puts argvs in 2d-array
    printmap(MapArray); //  prints the array
    checkvalidcell(MapArray,validcell,bead);
    for(int i=0;validcell[0][i]!=-1;i++){
        printf("x=%d\n",validcell[0][i]);
        printf("y=%d\n",validcell[1][i]);
        printf("counter=%d\n",validcell[2][i]);
    }
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
void checkvalidcell(int MapArray[][8],int validcell [][60],int bead){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(MapArray[i][j]==0){
                if((i+1)<8 && MapArray[i+1][j]!=bead && MapArray[i+1][j]!=0 ) checkdown(MapArray,validcell,bead,i,j);
                if((i-1)>0 && MapArray[i-1][j]!=bead && MapArray[i-1][j]!=0 ) checkup(MapArray,validcell,bead,i,j);
                if((j+1)<8 && MapArray[i][j+1]!=bead && MapArray[i][j+1]!=0 ) checkright(MapArray,validcell,bead,i,j);
                if((j-1)>0 && MapArray[i][j-1]!=bead && MapArray[i][j-1]!=0 ) checkleft(MapArray,validcell,bead,i,j);
                if((j+1)<8 && (i-1)>0 && MapArray[i-1][j+1]!=bead && MapArray[i-1][j+1]!=0 ) checkupright(MapArray,validcell,bead,i,j);
                if((j+1)<8 && (i+1)<8 && MapArray[i+1][j+1]!=bead && MapArray[i+1][j+1]!=0 ) checkdownright(MapArray,validcell,bead,i,j);
                if((j-1)>0 && (i-1)>0 && MapArray[i-1][j-1]!=bead && MapArray[i-1][j-1]!=0 ) checkupleft(MapArray,validcell,bead,i,j);
                if((j-1)>0 && (i+1)<8 && MapArray[i+1][j-1]!=bead && MapArray[i+1][j-1]!=0 ) checkdownleft(MapArray,validcell,bead,i,j);
            }
        }
    }

}
void checkdown(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;x+i<8;i++){
        if(MapArray[x+i][y]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x+i][y]==0)
        break;
    }
}
void checkup(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;x-i>0;i++){
        if(MapArray[x][y-i]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x-i][y]==0)
        break;
    }
}
void checkleft(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;y-i>0;i++){
        if(MapArray[x][y-i]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x][y-i]==0)
        break;
    }
}
void checkright(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;y+i<8;i++){
        if(MapArray[x][y+i]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x][y+i]==0)
        break;
    }
}
void checkdownright(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;y+i<8 && x+i<8;i++){
        if(MapArray[x+i][y+i]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x+i][y+i]==0)
        break;
    }
}
void checkupright(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;y+i<8 && x-i>0;i++){
        if(MapArray[x-i][y+i]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x-i][y+i]==0)
        break;
    }
}
void checkupleft(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;y-i>0 && x-i>0;i++){
        if(MapArray[x-i][y-i]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x-i][y-i]==0)
        break;
    }
}
void checkdownleft(int MapArray[][8],int validcell [][60],int bead,int x,int y){
    int i,j;
    for(i=1;y-i>0 && x+i<8;i++){
        if(MapArray[x+i][y-i]==bead){
            for(j=0;validcell[0][j]!=-1;j++);
            validcell[0][j]=x;
            validcell[1][j]=y;
            validcell[2][j]=i-1;
            break;
        }
        if(MapArray[x+i][y-i]==0)
        break;
    }
}
