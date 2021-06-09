#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shoprec.h"

int minimum(int num,int* min){
      if(num < *min){
            *min = num;
            return 1;
      }
      else{
            return 0;
      }
}

int R(int* min,int i,int p,int m,int n, int* k, int** c){
      
      if(p < 0){
            return m;
      }
      else if(p >= 0 && i == n ){
            return p;
      }
      else {
            
            for(int j = 1; j <= k[i+1] ;j++){
                  minimum(R(min,i+1,p-c[i+1][j],m,n,k,c),min);
            }
                  return *min;
      }                        
                  
}

int shop(int m, int n, int* k, int** c){
      
      int* min = malloc(sizeof(int));
      *min = INT_MAX;
      int RM1 = R(min,0,m,m,n,k,c);
      return m - RM1;
}