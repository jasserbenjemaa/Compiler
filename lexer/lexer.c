#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

void print_token(Token token){
  printf("token type %d token value %s",token.type,token.lexem);
}

Token checkPoint(char ptr){
  Token t;
  t.lexem[0]=ptr;
  switch (ptr) {
    case '.':
      t.type=T_DOT;
      break;
    case ',':
      t.type=T_COMMA;
      break;
    case ';':
      t.type=T_SEMICOL;
      break;
    case ':':
      t.type=T_COLON;
      break;
  }
  return t;
}
Token checkSymbol(char ptr){
  Token t;
  t.lexem[0]=ptr;
  switch (ptr) {
    case '{':
      t.type=T_OPEN_BRAC;
      break;
    case '}':
      t.type=T_CLOSE_BRAC;
      break;
    case '(':
      t.type=T_OPEN_PAR;
      break;
    case ')':
      t.type=T_CLOSE_PAR;
      break;
    case '[':
      t.type=T_OPEN_SQUAR_BRAC;
      break;
    case ']':
      t.type=T_CLOSE_SQUAR_BRAC;
      break;
  }
  return t;
}

Token checkSign(char ptr){
  Token t;
  t.lexem[0]=ptr;
  switch (ptr) {
    case '+':
      t.type=T_PLUS;
      break;
    case '-':
      t.type=T_MINUS;
      break;
    case '/':
      t.type=T_SLASH;
      break;
    case '*':
      t.type=T_STAR;
      break;
  }
  return t;
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
    
    strcpy(token.lexem,tokenValue);
    token.type=strcmp(tokenValue,"main")==0?T_MAIN:T_KEYWORD;
    print_token(token);
  }
  else if(isdigit(*ptr)) {
    int i=0;
    while (isdigit(*ptr)) tokenValue[i++]= *ptr++;
    token.type=T_INT;
    strcpy(token.lexem,tokenValue);
    print_token(token);
    }
    else if(*ptr=='+'||*ptr=='-'||*ptr=='*'||*ptr=='/'){
      print_token(checkSign(*ptr));
      ptr++;
    }
    else if(*ptr=='('||*ptr==')'||*ptr=='{'||*ptr=='}'||*ptr=='['||*ptr==']'){
      print_token(checkSymbol(*ptr));
      ptr++;
    }
    else if(*ptr==','||*ptr=='.'||*ptr==';'||*ptr==':'){
      print_token(checkPoint(*ptr));
      ptr++;
    }
    else {
      printf("undefind %c\n",*ptr);
      *ptr++;
    }
  }
}
