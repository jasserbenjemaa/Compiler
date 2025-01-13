#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

void print_token(Token token){
  printf("token type %d token value %s",token.type,token.lexem);
}

void lexer(char *c){
  char *ptr=c;
  while (*ptr!='\0'){
  Token token;
  char tokenValue[255]={0};
  printf("%s\n",tokenValue);
  if(isspace(*ptr)){
    ptr++;
  }
  else if (isalpha(*ptr)) {
    int i=0;
    while (isalnum(*ptr)||*ptr=='_') tokenValue[i++]= *ptr++;
    token.type=T_KEYWORD;
    strcpy(token.lexem,tokenValue);
    print_token(token);
  }
  else if(isdigit(*ptr)) {
    int i=0;
    while (isdigit(*ptr)) tokenValue[i++]= *ptr++;
    token.type=T_INT;
    strcpy(token.lexem,tokenValue);
    print_token(token);
    }
    else {
      ptr++;
    }
  }
}
