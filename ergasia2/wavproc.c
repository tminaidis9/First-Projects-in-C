// Τα mode 1,2,3,4 ειναι υλοποιημένα.
// στο mode 4 ειδα πως λειτουργει κανονικά το πρωτο αρχειο ρνω το δευτερο οχι.
// Όταν κρατούσα το size_of_file ίδιο,λειτουργούσε κανονικά απο την μέση και μετά.
// Στο υπόλοιπο κομμάτι ακούγονται μόνο παράσιτα ενώ δεν πιστέυω ότι υπάρχει κάποιο πρόβλημα.

#include <stdio.h>
#include <stdlib.h>

#define MODE 3

int main(){
      int end = 0;
      int x,y,k;

      int hex = 16;
      int f = 1;
      int s = 16;
      int krat = 0;
      int change = 0;
      int j = 0;
      int yes = 1;
      int ps1 = 0;
      int c2,c3,c4;
      int sof;
      int b;

      int size_of_file = 0, bps = 0,bts = 0;
      int format = 0,stereo = 0,block = 0;
      int wformat = 0, Srate = 0,dc = 0;
      int ch = getchar();
      while(ch != EOF){
            
            if(j == 0){
                  j = 1;
                  for(int i = 1 ; i <= 44 ; i++){
                        
                        int first = ch&0x0f;
                        int second  = ch&0xf0;
                        second = second / 16;
                        
                        if( end == 1)
                              break;

                        if(i <= 4){      // Έλεγξε ότι είναι αρχείο wav
                              if(i == 1){
                                    if(ch != 82){
                                          fprintf(stderr,"Error! 'RIFF' not found\n");
                                          end = 1;
                                          continue;
                                    }
                                    if(MODE == 2)
                                          putchar(ch);
                                    if(MODE == 3)
                                          putchar(ch);
                                    if(MODE == 4)
                                          putchar(ch);
                              }
                              if(i == 2){
                                    if(ch != 73){
                                          fprintf(stderr,"Error! 'RIFF' not found\n");
                                          end = 1;
                                          continue;
                                    }
                                    if(MODE == 2)
                                          putchar(ch);
                                    if(MODE == 3)
                                          putchar(ch);
                                    if(MODE == 4)
                                          putchar(ch);

                              }
                              if(i == 3){
                                    if(ch != 70){
                                          fprintf(stderr,"Error! 'RIFF' not found\n");
                                          end = 1;
                                          continue;
                                    }
                                    if(MODE == 2)
                                          putchar(ch);
                                    if(MODE == 3)
                                          putchar(ch);
                                    if(MODE == 4)
                                          putchar(ch);
                              }
                              if(i == 4){
                                    if(ch != 70){
                                          fprintf(stderr,"Error! 'RIFF' not found\n");
                                          end = 1;
                                          continue;
                                    }
                                    if(MODE == 2)
                                          putchar(ch);
                                    if(MODE == 3)
                                          putchar(ch);
                                    if(MODE == 4)
                                          putchar(ch);
                              }
                              
                        }
                        else if(i <= 8){
                                                
                              size_of_file = size_of_file + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;

                              if( i == 8){
                                    fprintf(stderr, "Size of File = %d \n",size_of_file);
                                    f = 1;
                                    s = 16;

                                    if(MODE == 4){
                                          b = size_of_file - 36;
                                          b /= 2;
                                          sof = b + 36;
                                          putchar((sof) & 0x000000FF);
                                          putchar(((sof) & 0x0000FF00)/256);
                                          putchar(((sof) & 0x00FF0000)/65536);
                                          putchar(((sof) & 0xFF000000)/16777216);
                                    }
                              }

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              // if(MODE == 4)
                              //             putchar(ch);

                        }
                        else if(i <= 12){
                              if(i == 9){
                                    if(ch != 87){
                                          fprintf(stderr,"Error! 'WAVE' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if(i == 10){
                                    if(ch != 65){
                                          fprintf(stderr,"Error! 'WAVE' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if(i == 11){
                                    if(ch != 86){
                                          fprintf(stderr,"Error! 'WAVE' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if(i == 12){
                                    if(ch != 69){
                                          fprintf(stderr,"Error! 'WAVE' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              if(MODE == 4)
                                          putchar(ch);

                        }
                        else if(i <= 16){
                              if(i == 13){
                                    if(ch != 102){
                                          fprintf(stderr,"ERROR! 'fmt' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if(i == 14){
                                    if(ch != 109){
                                          fprintf(stderr,"ERROR! 'fmt' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if(i == 15){
                                    if(ch != 116){
                                          fprintf(stderr,"ERROR! 'fmt' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if(i == 16){
                                    if(ch != 32){
                                          fprintf(stderr,"ERROR! 'fmt' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              if(MODE == 4)
                                    putchar(ch);
                        }
                        else if(i <= 20){

                              format = format + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;

                              if( i == 20){
                                    fprintf(stderr, "size of format chunck: %d \n",format);

                                    if(format != 16){
                                          fprintf(stderr,"Error! size of format chunck should be 16\n");
                                          end = 1;
                                          continue;
                                    }
                              
                                    f = 1;
                                    s = 16;
                              }

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              if(MODE == 4)
                                    putchar(ch);

                        }
                        else if(i <= 22){
                              
                              wformat = wformat + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;


                              if( i == 22){
                                    fprintf(stderr, "WAVE type format: %d \n",wformat);

                                    if(wformat != 1){
                                          fprintf(stderr,"Error! WAVE type format should be 1\n");
                                          end = 1;
                                          continue;
                                    }

                                    f = 1;
                                    s = 16;
                              }

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              if(MODE == 4)
                                    putchar(ch);
                        }
                        else if(i <= 24){

                              stereo = stereo + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;


                              if( i == 24){
                                    fprintf(stderr, "mono/stereo: %d \n",stereo);
                                    
                                    if(MODE == 4){
                                          if (stereo == 2){
                                                putchar(01);
                                                putchar(00);
                                                change = 1;
                                          }
                                    }

                                    if(stereo != 1 && stereo != 2){
                                          fprintf(stderr,"Error! mono/stereo should be 1 or 2\n");
                                          end = 1;
                                          continue;
                                    }

                                    f = 1;
                                    s = 16;
                              }

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                        }
                        else if(i <= 28){
                        
                              Srate = Srate + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;

                              
                              if( i == 28){
                                    fprintf(stderr, "sample rate: %d \n",Srate);
                                    f = 1;
                                    s = 16;
                                    if(MODE == 3){
                                          ps1 = Srate * 2;
                                          ch = (ps1 & 0x000000FF);
                                          c2 = (ps1 & 0x0000FF00)/256;
                                          c3 = (ps1 & 0x00FF0000)/65536;
                                          c4 = (ps1 & 0xFF000000)/16777216;
                                          putchar(ch);
                                          putchar(c2);
                                          putchar(c3);
                                          putchar(c4);
                                    }
                                    if(MODE == 2){
                                          ps1 = Srate/2;
                                          ch = (ps1 & 0x000000FF);
                                          c2 = (ps1 & 0x0000FF00)/256;
                                          c3 = (ps1 & 0x00FF0000)/65536;
                                          c4 = (ps1 & 0xFF000000)/16777216;
                                          putchar(ch);
                                          putchar(c2);
                                          putchar(c3);
                                          putchar(c4);
                                    }
                              }
                              
                              if(MODE == 4)
                                    putchar(ch);
                        }
                        else if(i <= 32){

                        
                              bps = bps + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;

                              // if(MODE == 4)
                              //       putchar(ch);
                              
                              if( i == 32){
                                    fprintf(stderr, "bytes/sec: %d \n",bps);

                                    f = 1;
                                    s = 16;

                                    if(MODE == 3){
                                                ps1 = bps * 2;
                                                ch = (ps1 & 0x000000FF);
                                                c2 = (ps1 & 0x0000FF00)/256;
                                                c3 = (ps1 & 0x00FF0000)/65536;
                                                c4 = (ps1 & 0xFF000000)/16777216;
                                                putchar(ch);
                                                putchar(c2);
                                                putchar(c3);
                                                putchar(c4);
                                    }
                                    if(MODE == 2 || (MODE == 4 && change == 1)){
                                          ps1 = bps / 2;
                                          ch = (ps1 & 0x000000FF);
                                          c2 = (ps1 & 0x0000FF00)/256;
                                          c3 = (ps1 & 0x00FF0000)/65536;
                                          c4 = (ps1 & 0xFF000000)/16777216;
                                          putchar(ch);
                                          putchar(c2);
                                          putchar(c3);
                                          putchar(c4);
                                    }
                                    if(MODE == 4 && change == 0){
                                          ps1 = bps;
                                          ch = (ps1 & 0x000000FF);
                                          c2 = (ps1 & 0x0000FF00)/256;
                                          c3 = (ps1 & 0x00FF0000)/65536;
                                          c4 = (ps1 & 0xFF000000)/16777216;
                                          putchar(ch);
                                          putchar(c2);
                                          putchar(c3);
                                          putchar(c4);
                                          
                                    }
                              }
                             
                        }
                        else if(i <= 34){
                              block = block + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              // if(MODE == 4)
                              //       putchar(ch);

                              if( i == 34){
                                    fprintf(stderr, "Block Align: %d \n",block);
                                    
                                    if ( bps != Srate * block){
                                          fprintf(stderr,"Error! bytes/second should be sample rate x block alignment\n");
                                          end = 1;
                                          continue;
                                    }

                                    if(MODE == 4 && change == 1){
                                          putchar((block / 2) & 0x000000FF);
                                          putchar(((block / 2) & 0x0000FF00)/256);
                                    }
                                    else if(MODE == 4){
                                          putchar(block & 0x000000FF);
                                          putchar((block & 0x0000FF00)/256);
                                    }

                                    f = 1;
                                    s = 16;
                              }
                        }
                        else if(i <= 36){

                              bts = bts + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              if(MODE == 4 /*&& change == 0*/)
                                    putchar(ch);
                                    
                              if( i == 36){
                                    fprintf(stderr, "Bits per Sample: %d \n",bts);
                                    
                                    if ( block != (bts/8)*stereo){
                                          fprintf(stderr,"Error! bits/sample should be 8 or 16\n");
                                          end = 1;
                                          continue;
                                    }     
                             
                                    f = 1;
                                    s = 16;
                              }
                        }
                        else if(i <= 40){
                              if (i == 37){
                                    if(ch != 100){
                                          fprintf(stderr,"Error! 'data' not found\n");
                                          end = 1;
                                          
                                          continue;
                                    }
                              }
                              if (i == 38){
                                    if(ch != 97){
                                          fprintf(stderr,"Error! 'data' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if (i == 39){
                                    if(ch != 116){
                                          fprintf(stderr,"Error! 'data' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              if (i == 40){
                                    if(ch != 97){
                                          fprintf(stderr,"Error! 'data' not found\n");
                                          end = 1;
                                          continue;
                                    }
                              }
                              
                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch);
                              if(MODE == 4)
                                    putchar(ch);
                        }
                        else if(i <= 44){
                              
                              dc = dc + (first * f) + (second * s);
                              f = s * 16;
                              s = f * 16;

                              if(MODE == 2)
                                    putchar(ch);
                              if(MODE == 3)
                                    putchar(ch); 
                             

                              if( i == 44){
                                    fprintf(stderr, "Size of data chunck: %d \n",dc);

                                    if(MODE == 4){
                                          putchar((dc / 2) & 0x000000FF);
                                          putchar(((dc / 2) & 0x0000FF00)/256);
                                          putchar(((dc / 2) & 0x00FF0000)/65536);
                                          putchar(((dc / 2) & 0xFF000000)/16777216);
                                    }
                                    // end = 1;
                                    continue;
                              }
                        }
                        ch = getchar();
                  
                  }
            }
            
            if(MODE == 1 && end == 1)
                  break;

            if( MODE == 1){
                  for(int i = 1 ; i <= size_of_file - 36 ; i++){
                        ch = getchar();
                  }
                  if ((ch = getchar()) != EOF){
                        fprintf(stderr,"ERROR bad file size\n");
                        end = 2;
                        break;
                  }
            }

            if (end == 2){
                  break;
            }

            if(MODE == 4 && change == 1){
                  for(int i = 1 ; i <= dc ; i++){
                        ch = getchar();
                        if(i % 2 == 0)
                        putchar(ch);
                  }
            }

            ch = getchar();
            if((MODE == 2 || MODE == 3 || MODE == 4)&& ch != EOF)
                  putchar(ch);
      }
}