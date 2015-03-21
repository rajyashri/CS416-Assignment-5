#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_TOKENS 50

typedef struct{
        char* token;
        char* delim;
        int file_descriptor;
        }Token;
        
Token Token_List[MAX_TOKENS];

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tokenizer_T{
       char *token;
       char *delimiter;
       int *file_descriptor;
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
static bool Tokenizer (const char* data, const char** beginPtr, const char** endPtr) {
    static const char* nextStart;
    if (data) {
        nextStart = data;
        return true;
    }
    if (*nextStart == 0) return false;
    *beginPtr = nextStart;

    // Find next delimiter.
    do {
        nextStart++;
    } while (*nextStart != ' ' && *nextStart != '|' && *nextStart != 0);

    // Trim whitespace.
   *endPtr = nextStart - 1;
    while (isspace(**beginPtr) && *beginPtr < *endPtr)
        (*beginPtr)++;
    while (isspace(**endPtr) && *endPtr >= *beginPtr)
        (*endPtr)--;
    (*endPtr)++;

    return true;
}
int is_empty(char *s) {
    char* str;
    str = s ;
    int len = strlen(str);
    int i;
    for(i = 0; i < len ; i++){
          if(isspace(*str)){
             str++;
          } else
              return 1;
    }
    return 0;
}


int main(int argc, char *argv[])
{
   char* command;
   char token[50];
   char* ex = "exit";
   const char* begin;
   const char* end;
   
   int exit_status = 0;
   
   command = malloc(sizeof(command));   
  do {
    printf("Shell>> ");
    gets(command);
    
    if(is_empty(command)!= 0){
    printf("String is :\t");
    puts(command); 
    
    if((strcmp(command,ex)) == 0){
           exit_status = 1;
                   
    }else{ 
           printf("Tokens are :\n");      
          Tokenizer(command,0,0);
          
        while (Tokenizer(0, &begin, &end)) {
           printf("'%.*s'\n", end - begin, begin);
    }  
    }
   }
  } while( exit_status != 1 );
  
  return 0;
}
