#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shopmem.h"

int main(int argc,char* argv[]){

      int M = atoi(argv[1]);

      int N;
      scanf("%d",&N);
      int** C = malloc((N+1) * sizeof(int*));
      int* K = malloc((N+1) * sizeof(int));

      for(int i = 1 ; i <= N ; i++){
            
            scanf("%d", &K[i]);
            C[i] = (int*)malloc((K[i]+1) * sizeof(int));
            for(int k = 1 ; k <= K[i] ; k++){
                  scanf("%d",&C[i][k]);
            }
            
      }

      int** PinakasR = malloc((N+2) * sizeof(int*));
      for(int i = 0 ; i <= N+1 ; i++){
            PinakasR[i] = malloc((M+2) * sizeof(int));
            for(int j = 0; j <=(M+1); j++)
                  PinakasR[i][j] = -1;
      }

      int num = shop(PinakasR,M,N,K,C);
      
      if (num == 0)
            printf("No solution found\n");
      else
      printf("Maximum amount spent is: %d\n",num);
      
      free(K);
      for(int i = 0 ; i < N ; i++){
            free(C[i]);
      }
      free(C);

      for(int i = 0 ; i <= N+1 ; i++){
            free(PinakasR[i]);
      }
      free(PinakasR);
}

