#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){

      int M = atoi(argv[1]);

      int N;
      scanf("%d",&N);
      int** C = malloc((N+1) * sizeof(int*));
      int* K = malloc(N * sizeof(int));

      for(int i = 0 ; i < N ; i++){
            
            scanf("%d", &K[i]);
            C[i] = (int*)malloc((K[i]) * sizeof(int));
            for(int k = 0 ; k < K[i] ; k++){
                  scanf("%d",&C[i][k]);
            }
            
      }

      int num;
      
      int** P = malloc(N * sizeof(int*));
      for(int i = 0 ; i < N ; i++)
            P[i] = malloc((M+1) * sizeof(0));
      
      for(int j = 0; j < K[0]; j++){
            num = M - C[0][j];
            if(num > 0)
                  P[0][num] = 1;
      }
      
      for(int i = 1; i < N; i++){
            for(int j = 0; j < K[i]; j++){
                  for(int k = 1; k <= M; k++){
                        if(P[i-1][k] != 0){
                              num = k - C[i][j];
                              if(num >= 0){
                                    P[i][num] = 1;
                              }
                        }
                  }
            }
      }
      
      num = 0;
      for(int i = 0 ; i <= M ; i++)
            if(P[N-1][i] != 0){
                  num = M - i;
                  break;
            }

      if (num == 0)
            printf("No solution found\n");
      else
      printf("Maximum amount spent is: %d\n",num);

      free(K);
      for(int i = 0 ; i < N ; i++){
            free(C[i]);
      }
      free(C);

}
 