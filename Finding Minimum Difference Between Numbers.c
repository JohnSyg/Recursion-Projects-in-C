#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Value 60000

//1556 - Συγκούνας Ιωάννης
//1573 - Χανός Στέφανος

//We used this quickshort code that we found online in order to improve our function
//------------------------------------------------
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot) 
    {
     
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
//------------------------------------------------

int Starter(int T[])
{
    int min = 1000000000;
    int i , j;

    for(i=0; i<Value; i++)
    {
        for(j=0; j<Value; j++)
        {
            if(i!=j && abs(T[i] - T[j])<min)
            {
                min = abs(T[i] - T[j]); // abs() , gives us the absolute value of a number
                //printf("T[i]= [%d] , T[j] = [%d] , min = [%d] \n" , T[i] , T[j] , min);   
            }
            //printf("T[i]= [%d] , T[j] = [%d] , min = [%d] \n" , T[i] , T[j] , min);
        }
    }
    //printf("------------------------ \n");
    return min;
}

int Better(int T[])
{
   quickSort(T , 0 , Value-1);
   int min = 1000000000;
   int i;
   
   for(i=0; i<Value-1; i++)
   {
       if(T[i+1] - T[i] < min)
        {
            min = T[i+1] - T[i];
            //printf("T[i+1]= [%d] , T[i] = [%d] , min = [%d] \n" , T[i+1] , T[i] , min);
        }
        //printf("T[i+1]= [%d] , T[i] = [%d] , min = [%d] \n" , T[i+1] , T[i] , min);
   }
   //printf("------------------------ \n");
   return min;
}

int main()
{
    clock_t start , end;
    double A_time , B_time , C_time , D_time , E_time , Average_time;
    srand(time(0));
    
    int i , a , b , c , d , e , answer;
    int A[Value] , B[Value] , C[Value] , D[Value] , E[Value];

    for(i=0; i<Value; i++)
    {
        A[i] = rand();
        B[i] = rand();
        C[i] = rand();
        D[i] = rand();
        E[i] = rand();
    }
    
    printf("Would you like to use the starting function (1) or the improved one (2) ?? \n");
    scanf("%d" , &answer);
    while(answer<1 || answer>2)
    {
        printf("Please choose a valid option (1 or 2) \n");
        scanf("%d" , &answer);
    }
    if(answer == 1)
    {
        start = clock();
            a = Starter(A);
        end = clock();
        A_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            b = Starter(B);
        end = clock();
        B_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            c = Starter(C);
        end = clock();
        C_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            d = Starter(D);
        end = clock();
        D_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            e = Starter(E);
        end = clock();
        E_time = ((double)(end - start))/CLOCKS_PER_SEC;

        Average_time = (A_time + B_time + C_time + D_time + E_time)/5;
            
        printf("For %d table elements \n" , Value);
        printf("The smallest difference of two numbers in table A is: [%d] , and it needed %lf seconds \n" , a , A_time);
        printf("The smallest difference of two numbers in table B is: [%d] , and it needed %lf seconds \n" , b , B_time);
        printf("The smallest difference of two numbers in table C is: [%d] , and it needed %lf seconds \n" , c , C_time);
        printf("The smallest difference of two numbers in table D is: [%d] , and it needed %lf seconds \n" , d , D_time);
        printf("The smallest difference of two numbers in table E is: [%d] , and it needed %lf seconds \n" , e , E_time);
        printf("The average run time of the the five tables is: %lf seconds \n" , Average_time);
    }
    else
    {
        start = clock();
            a = Better(A);
        end = clock();
        A_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            b = Better(B);
        end = clock();
        B_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            c = Better(C);
        end = clock();
        C_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            d = Better(D);
        end = clock();
        D_time = ((double)(end - start))/CLOCKS_PER_SEC;

        start = clock();
            e = Better(E);
        end = clock();
        E_time = ((double)(end - start))/CLOCKS_PER_SEC;

        Average_time = (A_time + B_time + C_time + D_time + E_time)/5;
            
        printf("For %d table elements \n" , Value);
        printf("The smallest difference of two numbers in table A is: [%d] , and it needed %lf seconds \n" , a , A_time);
        printf("The smallest difference of two numbers in table B is: [%d] , and it needed %lf seconds \n" , b , B_time);
        printf("The smallest difference of two numbers in table C is: [%d] , and it needed %lf seconds \n" , c , C_time);
        printf("The smallest difference of two numbers in table D is: [%d] , and it needed %lf seconds \n" , d , D_time);
        printf("The smallest difference of two numbers in table E is: [%d] , and it needed %lf seconds \n" , e , E_time);
        printf("The average run time of the the five tables is: %lf seconds \n" , Average_time);
        
    }
    return 0;
}