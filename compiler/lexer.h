#ifndef LEXER_H
#define LEXER_H

#endif // !LEXER_H

typedef enum {
  T_ID,
  T_PLUS,
  T_MINUS,
  T_STAR,
  T_SLASH,
  T_INT,
  T_MAIN,
  T_OPEN_PAR,
  T_CLOSE_PAR,
  T_KEYWORD,
  T_OPEN_BRAC,
  T_CLOSE_BRAC,
  T_OPEN_SQUAR_BRAC,
  T_CLOSE_SQUAR_BRAC,
  T_SEMICOL,
  T_DOT,
  T_COMMA,
  T_COLON,
  T_ASSIGN,
}TokenType;

const char* TokenTypeNames[] = {
    "T_ID",
    "T_PLUS",
    "T_MINUS",
    "T_STAR",
    "T_SLASH",
    "T_INT",
    "T_MAIN",
    "T_OPEN_PAR",
    "T_CLOSE_PAR",
    "T_KEYWORD",
    "T_OPEN_BRAC",
    "T_CLOSE_BRAC",
    "T_OPEN_SQUAR_BRAC",
    "T_CLOSE_SQUAR_BRAC",
    "T_SEMICOL",
    "T_DOT",
    "T_COMMA",
    "T_COLON",
    "T_ASSIGN",
};
const char* keywords[]={"int","char","void","if","else","while"};

typedef struct {
  TokenType type;
  char lexem[255];
}Token;

void lexer(char *input);
