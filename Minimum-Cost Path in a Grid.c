#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1556 - Συγκούνας Ιωάννης
//1573 - Χανός Στέφανος

int M , N;

int minimum(int x , int y)
{
    if(x<y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int fun(int Table[M][N]) // Bottom Up
{
    int MinCost[M][N];
    int Position[M][N];
    int Path[M+N-1][2];
    int i , j;
    MinCost[0][0] = Table[0][0];
    Position[0][0] = (char) 'S';

    for(i=1; i<N; i++)
    {
        MinCost[0][i] = Table[0][i] + MinCost[0][i-1];
        Position[0][i] = (char) 'L';
    }

    for(i=1; i<M; i++)
    {
        MinCost[i][0] = Table[i][0] + MinCost[i-1][0];
        Position[i][0] = (char) 'U';
    }

    for (i=1; i<M; i++) 
    {
        for (j=1; j<N; j++) 
        {
            MinCost[i][j] = Table[i][j] + minimum(MinCost[i-1][j] , MinCost[i][j-1]);
            if(MinCost[i-1][j] < MinCost[i][j-1])
            {
                Position[i][j] = (char) 'U';
            }
            else
            {
                Position[i][j] = (char) 'L';
            }
        }
    }
    
    int k=1;
    int l=1;
    i=M+N-2;
    while(i>=0)
    {
        Path[i][0] = M-k;
        Path[i][1] = N-l;

        if(Position[Path[i][0]][Path[i][1]] == 'U')
        {
            k++;
        }
        else
        {
            l++;
        }
        i--;
    }
    
    printf("The minimum-cost path is:\n");
    for(i=0; i<M+N-1; i++)
    {
        printf("(%d,%d) \n" , Path[i][0] , Path[i][1]);
    }
    return MinCost[M-1][N-1];
}

int main ()
{
    int i,j;
    srand(time(NULL));
    printf("Please enter the Width of the table \n");
    scanf("%d" , &M);
    printf("Please enter the Height of the table \n");
    scanf("%d" , &N);
    
    int Table[M][N];
    
    printf("-----------------------------\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            Table[i][j] = rand() % 10;
            printf("[%d]" , Table[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
    printf("The cost is: [%d] \n" , fun(Table));
    return 0;
}