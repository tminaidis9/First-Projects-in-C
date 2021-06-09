#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shoprec.h"


int main(int argc,char* argv[]){

      int M = atoi(argv[1]);
      // printf("M = %d \n",M);

      int N;
      scanf("%d",&N);
      int** C = malloc((N+1) * sizeof(int*));
      int* K = malloc(N * sizeof(int));

      for(int i = 1 ; i <= N ; i++){
            
            scanf("%d", &K[i]);
            C[i] = (int*)malloc((K[i]+1) * sizeof(int));
            for(int k = 1 ; k <= K[i] ; k++){
                  scanf("%d",&C[i][k]);
            }
            
      }
      int num = shop(M,N,K,C);
      
      if (num == 0)
            printf("No solution found\n");
      else
      printf("Maximum amount spent is: %d\n",num);
}

