#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1556 - Συγκούνας Ιωάννης
//1573 - Χανός Στέφανος

int WoodenTable[57][31];

void Initialization()
{
    int i , j;
    for(i=0; i<57; i++)
    {
        for(j=0; j<31; j++)
        {
            WoodenTable[i][j]= -1;
        }
    }
}

int permutationCoeff1(int n, int k) // recursive
{
    if(k == 0)
    {
        return 1;
    }
    else if(k > n)
    {
        return 0;
    }
    else
    {
        return permutationCoeff1(n-1,k)+k*permutationCoeff1(n-1,k-1);
    }
}

int permutationCoeff2(int n, int k) //bottom-up
{
    int i , j;
    int MarbleTable[n+1][k+1];
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=k; j++)
        {
            if(j == 0)
            {
                MarbleTable[i][j] = 1;
            }
            else if(j > i)
            {
                MarbleTable[i][j] = 0;
            }
            else
            {
                MarbleTable[i][j] = MarbleTable[i-1][j] + (j*MarbleTable[i-1][j-1]);
            }
        }
    }
    return MarbleTable[n][k];
}

int permutationCoeff3(int n, int k) //top-down
{
    if(WoodenTable[n][k] == -1)
    {
        if(k == 0)
        {
            WoodenTable[n][k] = 1;
        }
        else if(k > n)
        {
            WoodenTable[n][k] = 0;
        }
        else
        {
            WoodenTable[n][k] = permutationCoeff3(n-1,k)+k*permutationCoeff3(n-1,k-1);
        }
    }
    return WoodenTable[n][k];
}

int main ()
{
    clock_t start , end;
    double time[10];
    double totaltime = 0;
    double average = 0;
    int i , x , answer;
    int n[10] = {4 , 25 , 36 ,5 , 31 , 3 , 41 , 37 , 56 , 49};
    int k[10] = {1 , 11 , 9 , 30 , 13 , 0 , 9 ,  11 , 8 , 10};
    
    printf("Would you like to use the recursive function (1) , the Bottom-Up function (2) or the Top-Down one (3) ?? \n");
    scanf("%d" , &answer);
    while(answer<1 || answer>3)
    {
        printf("Please choose a valid option (1 , 2 or 3) \n");
        scanf("%d" , &answer);
    }

    if(answer == 1)
    {
        printf("Recursive \n");
        for(i=0; i<10; i++)
        {
            start = clock();
                x = permutationCoeff1(n[i],k[i]);
            end = clock();
            time[i] = ((double)(end - start))/CLOCKS_PER_SEC;

            printf("If you have %d elements and you want to arrange %d of them , there are %d possible ways \nTime needed [%lf] \n", n[i] , k[i] , x , time[i]);
        }
        for(i=0; i<10; i++)
        {
        totaltime = totaltime + time[i];
        }
        average = totaltime/10;
        printf("Average time for the [RECURSIVE] function is: %lf" , average);
    }
    else if(answer == 2)
    {
        printf("Bottom-Up \n");
        for(i=0; i<10; i++)
        {
            start = clock();
                x = permutationCoeff2(n[i],k[i]);
            end = clock();
            time[i] = ((double)(end - start))/CLOCKS_PER_SEC;

            printf("If you have %d elements and you want to arrange %d of them , there are %d possible ways \nTime needed [%lf] \n", n[i] , k[i] , x , time[i]);
        }
        for(i=0; i<10; i++)
        {
        totaltime = totaltime + time[i];
        }
        average = totaltime/10;
        printf("Average time for the [Bottom-Up] function is: %lf" , average);
    }
    else
    {
        printf("Top-Down \n");
        for(i=0; i<10; i++)
        {
            Initialization();
            start = clock();
                x = permutationCoeff3(n[i],k[i]);
            end = clock();
            time[i] = ((double)(end - start))/CLOCKS_PER_SEC;

            printf("If you have %d elements and you want to arrange %d of them , there are %d possible ways \nTime needed [%lf] \n", n[i] , k[i] , x , time[i]);
        }
        for(i=0; i<10; i++)
        {
        totaltime = totaltime + time[i];
        }
        average = totaltime/10;
        printf("Average time for the [Top-Down] function is: %lf" , average);
    }
    return 0;
}