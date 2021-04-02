#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void inputvisited(int upper,int visited[upper]);
void inputmatrix(int upper,int LEN,int arr[LEN][LEN],int coincidence[LEN][LEN],int visited[upper]);
void outputmatrix(int LEN,int arr[LEN][LEN]);
void outputhidden(int LEN);
int bingo(int LEN,int matrix[LEN][LEN],int coincidence[LEN][LEN]);
void printNumber(int LEN,int arr[LEN][LEN],int coincidence[LEN][LEN]);


int main()
{
    printf("\n");
    printf("               BINGO GAME              \n");


    int LEN = 10;
    int matrix[LEN][LEN];
    int coincidence[LEN][LEN];
    int upper = 100;
    int visited[upper];
    int i,j,num,foundNumber;

    srand(time(NULL));

    inputvisited(upper,visited);
    inputmatrix(upper,LEN,matrix,coincidence,visited);
   // outputmatrix(LEN,matrix);
    outputhidden(LEN);

    while(!bingo(LEN,matrix,coincidence))
    {
        printf("Input a number: ");
        scanf("%d",&num);
        for(i = 0; i < LEN; i++)
        {
            foundNumber = 0;
            for(j = 0; j < LEN; j++)
            {
                if(matrix[i][j] == num)
                {
                    coincidence[i][j] = 1;
                    foundNumber = 1;
                    printf("Coincidence! Number %d is at position: row %d, column %d.8\n\n", matrix[i][j], i+1 , j+1);
                   printNumber(LEN, matrix, coincidence);
                   printf("\n");
                    break;
                }
             }
            if(foundNumber == 1)
            {
                break;
            }
        }
    }

    printf("\nBINGO YOU WIN!\n");

    return 0;
}

void inputvisited(int upper,int visited[upper]) {
    for(int i = 0; i <= upper; i++)
    {
        visited[i] = 0;
    }
}

void inputmatrix(int upper,int LEN,int matrix[LEN][LEN],int coincidence[LEN][LEN],int visited[upper]) {
    int i,j,num;
    for(i = 0; i < LEN; i++)
    {
        for(j = 0; j < LEN; j++)
        {
            num = rand() % upper+1;
            while(visited[num] == 1) {
                num = (rand() % upper) +1;
            }
            visited[num] = 1;
            matrix[i][j] = num;
            coincidence[i][j] = 0;
        }
    }
}

void printNumber(int LEN,int matrix[LEN][LEN],int coincidence[LEN][LEN]) {
    int i,j;
    for(i = 0; i < LEN; i++)
    {
        for(j = 0; j < LEN; j++)
        {
            if(coincidence[i][j] == 1)
            {
                printf("%4d",matrix[i][j]);
            }else{
                printf("   *");
            }
        }
        printf("\n");
    }
}

void outputmatrix(int LEN,int matrix[LEN][LEN])
 {
    int i,j;
    for(i = 0; i < LEN; i++)
    {
        for(j = 0; j <LEN; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void outputhidden(int LEN)
{
    int i, j;
      printf(" \n");

       for(i = 0; i < LEN;i++)
     {
    	  for(j = 0; j < LEN; j++)
          {
            printf("   *");
    	  }
    	printf(" \n");
     }
    printf(" \n");
}

int bingo(int LEN,int matrix[LEN][LEN],int coincidence[LEN][LEN])
  {
    //check MD
    int i,j;
    int visited = 1;
    for(i = 0; i < LEN; i++)
    {
        if(coincidence[i][i] == 0)
        {
            visited = 0;
            break;
        }
    }

    if(visited == 1)
    {
        return 1;
    }

    //check SD
    visited = 1;
    for(i = 0; i < LEN; i++)
    {
        if(coincidence[i][LEN-i-1] == 0)
        {
            visited = 0;
            break;
        }
    }
    if(visited == 1)
    {
        return 1;
    }

    //check all rows
    for(j = 0; j < LEN; j++)
    {
        visited = 1;
        for(i = 0; i < LEN; i++)
        {
            if(coincidence[i][j] == 0)
            {
                visited = 0;
                break;
            }
        }
        if(visited == 1)
        {
            return 1;
        }
    }

    //check all cols
    for(i = 0; i < LEN; i++)
    {
        visited = 1;
        for(j = 0; j < LEN; j++)
        {
            if(coincidence[i][j] == 0)
            {
                visited = 0;
                break;
            }
        }
        if(visited == 1)
        {
            return 1;
        }
    }

    return 0;
}
