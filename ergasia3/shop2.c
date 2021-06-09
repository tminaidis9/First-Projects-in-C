#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shopmem.h"

int minimum(int num,int* min){
      if(num < *min){
            *min = num;
            return 1;
      }
      else{
            return 0;
      }
}

int R(int** PinakasR,int* min,int i,int p,int m,int n, int* k, int** c){
      int R2;
      if(p < 0){
            return m;
      }
      else if(p >= 0 && i == n ){
            return p;
      }
      else {
            
            for(int j = 1; j <= k[i+1] ;j++){
                  if(PinakasR[i+1][p-c[i+1][j]] > 0){
                        minimum(PinakasR[i+1][p-c[i+1][j]],min);
                  }
                  else{
                        R2 = R(PinakasR,min,i+1,p-c[i+1][j],m,n,k,c);
                        minimum(R2,min);
                        if(p-c[i+1][j] >= 0)
                              PinakasR[i+1][p-c[i+1][j]] = R2;
                  }
            }
                  return *min;
      }                        
                  
}

int shop(int** PinakasR,int m, int n, int* k, int** c){
      
      int* min = malloc(sizeof(int));
      *min = INT_MAX;
      int RM1 = R(PinakasR,min,0,m,m,n,k,c);


      return m - RM1;
}