#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tokenizer_T{
       char *token;
       char *delimiter;
       };
typedef struct Tokenizer_T TokenizerT;

TokenizerT* TKCreate(char *ts,char * d){
           TokenizerT *tt1 = (TokenizerT*)malloc(sizeof(TokenizerT));
           char* delim = d;
           char *tok_string = ts;
           
           tt1->token = tok_string;
           tt1->delimiter = delim;
           
           if(tt1 != NULL)
                  return tt1;
           else
                  return NULL;          
}
char *Tokenizer(char *input_cmd,int len)
{
  char delim[] = {'|','.'};
  char* temp = (char *)malloc(50 * sizeof(char));
char* t = (char *)malloc(50 * sizeof(char));
//  char temp[50];
//  char t[44] = {'\0'};
  strcpy(temp,input_cmd);
  printf("You are in Tokenizer\n");
  puts(temp);
  puts(delim);
  int index = 0, j = 0;
  for(index = 0; index < len ; index++){
     for( j = 0; j < 2 ; j++){
            if(temp[index] == delim[j]){
               strncpy(t,temp,index);            
               printf("IF index = %d\t , val  %c\n",index, t[index]);                 
               //return t;
             TokenizerT *t =  TKCreate(t,delim[j]);
            } else{
               printf("ELSE index = %d\t , val  %c\n",index, temp[index]);                 
               continue;}
     }
  }
  return temp;
}

int main(int argc, char *argv[])
{
   char command[50];
   char token[50];
   char* ex = "exit";
   int exit_status = 0;
  do {
    printf("Shell>> ");
    gets(command);
  
    printf("String is :\t");
    puts(command); 
    if((strcmp(command,ex)) == 0)
      exit_status = 1;
     printf("String is :\t");  
    strcpy(token,Tokenizer(command,strlen(command)));  
      puts(token);
  } while( exit_status != 1 );
  
  return 0;
}
