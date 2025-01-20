#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Node types
typedef enum {
    NODE_TYPE_NUMBER,
    NODE_TYPE_OPERATOR,
    NODE_TYPE_IDENTIFIER,
    NODE_TYPE_STATEMENT,
    NODE_TYPE_FUNCTION_DEF,
    NODE_TYPE_FUNCTION_CALL
} NodeType;

// AST Node structure
typedef struct ASTNode {
    NodeType type;
    char *value;
    struct ASTNode **params;
    int param_count;
    struct ASTNode *body;
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

// Function declarations
ASTNode* createNode(NodeType type, const char* value, ASTNode* left, ASTNode* right);
ASTNode* createFunctionDefNode(const char* name, ASTNode* body);
ASTNode* createFunctionCallNode(const char* name, ASTNode** params, int param_count);
void freeNode(ASTNode* node);
void printPreOrder(ASTNode* node);

#endif // AST_H

