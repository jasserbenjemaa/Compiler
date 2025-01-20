#include "ast.h"

// Create a general AST node
ASTNode* createNode(NodeType type, const char* value, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = strdup(value);
    node->left = left;
    node->right = right;
    node->params = NULL;
    node->param_count = 0;
    node->body = NULL;
    return node;
}

// Create a function definition node
ASTNode* createFunctionDefNode(const char* name, ASTNode* body) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_FUNCTION_DEF;
    node->value = strdup(name);
    node->body = body;
    node->params = NULL;
    node->param_count = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a function call node
ASTNode* createFunctionCallNode(const char* name, ASTNode** params, int param_count) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_FUNCTION_CALL;
    node->value = strdup(name);
    node->params = params;
    node->param_count = param_count;
    node->body = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Free an AST node and its children
void freeNode(ASTNode* node) {
    if (node) {
        free(node->value);
        if (node->params) {
            for (int i = 0; i < node->param_count; i++) {
                freeNode(node->params[i]);
            }
            free(node->params);
        }
        freeNode(node->left);
        freeNode(node->right);
        freeNode(node->body);
        free(node);
    }
}

// Pre-order traversal (for testing or debugging)
void printPreOrder(ASTNode* node) {
    if (node) {
        printf("%s ", node->value);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

