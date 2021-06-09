#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXNUM 2101000000
#define MINNUM 2100000000
#define MAXK 5
#define COMPUTATIONS 20

int main()
{
      long curtime;
      curtime = time(NULL);  
      srand((unsigned int) curtime); 
      int semiprimes = 0;
      int k_almost = 0;
      for(int i = MINNUM ; i <= MAXNUM ; i++){  // gia kathe arithmo toy sunolou [MINNUM,MAXNUM]           
            int x = 0;
            int y = 0;
            int num = i; 
            int k = 0;
            while(num % 2 == 0){
                  k++;
                  if(k == 1)
                        x = 2;
                  if(k == 2)
                        y = 2;
                  num = num / 2;
            }
            while(num % 3 == 0){
                  k++;
                  if(k == 1)
                        x = 3;
                  if(k == 2)
                        y = 3;
                  num = num / 3;
            }
            
            for(int j = 5 ; j*j <= i ; j+=6){  
                  while(num % j == 0){
                        k++;
                        if(k == 1)
                              x = j;
                        if(k == 2)
                              y = j;
                        num = num / j;
                  }
                  while(num % (j+2) == 0){
                        k++;
                        if(k == 1)
                              x = j+2;
                        if(k == 2)
                              y = j+2;
                        num = num / (j+2);
                  }
                  if(num == 1)
                        break;
            }

            if(num == 1){
                  num = i;
                  if ( k == 2){

                        semiprimes += 1;
                        k_almost += 1;
                              if((x < y) && ((y-x) <= (double)((0.01)* y))){
                                    printf(" %d * %d = %d is an interesting semiprime \n" ,x,y,i);
                              }
                              else if((y < x) && ((x-y) <= (double)((0.01) * x))){
                                    printf(" %d * %d = %d is an interesting semiprime \n" ,x,y,i);
                              }
                  }
                  else{
                        if ( k <= MAXK && k >= 2)
                              k_almost += 1;
                              

                  }
            }
            else{
                  k++;
                  if( k == 2)
                        y = num;
                  num = i;
                  
                  if ( k == 2){
                        
                        semiprimes += 1;
                        k_almost += 1;
                              if((x < y) && ((y-x) <= (double)((0.01)* y))){
                                    printf(" %d * %d = %d is an interesting semiprime \n" ,x,y,i);
                              }
                              else if((y < x) && ((x-y) <= (double)((0.01) * x))){
                                    printf(" %d * %d = %d is an interesting semiprime \n" ,x,y,i);
                              }
                  }
                  else{
                        if ( k <= MAXK && k >= 2)
                              k_almost += 1;
                              

                  }

            }
            
      }
      printf("Found %d k-almost semiprimes munbers   2<= k <= %d \n",k_almost,MAXK);
      printf("Found %d semiprimes munbers\n\n",semiprimes);
      printf("Current time is %ld\n\n", curtime);
      printf("Checking 20 random numbers\n");
      
      int first,second;
      for(int i = 1 ; i <= COMPUTATIONS ; i++){
            first = rand();
            second = rand();
            int new_x = (((first % 32768) + 1) * ((second % 32768) + 1)) + 1;
            int num2 = new_x;
            int k2 = 0;
            
            while(num2 % 2 == 0){
                  k2++;
                  num2 = num2 / 2;
            }
            while(num2 % 3 == 0){
                  k2++;
                  num2 = num2 / 3;
            }

            for(int s = 5 ; s*s <= i ; s+=6){

                  while(num2 % s == 0){
                        k2 += 1;
                        num2 = num2 / s;
                  }
                  while(num2 % (s+2) == 0){
                        k2 += 1;
                        num2 = num2 / (s+2);
                  }
                  if(num2 == 1)
                        break;
            }
            if (k2 == 0){
                  k2 = 1;
            }
            if (k2 == 1 && num2 != 1)
                  k2++;
            printf(" %d is a %d-almost prime number \n",new_x,k2);
      }

}
