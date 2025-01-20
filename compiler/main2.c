#include "ast.h"

int main() {
    // Define a function "sum" with body: x + y
    ASTNode* x = createNode(NODE_TYPE_IDENTIFIER, "x", NULL, NULL);
    ASTNode* y = createNode(NODE_TYPE_IDENTIFIER, "y", NULL, NULL);
    ASTNode* sum_body = createNode(NODE_TYPE_OPERATOR, "+", x, y);
    ASTNode* sum_function = createFunctionDefNode("sum", sum_body);

    // Call the function "sum(3, 5)"
    ASTNode* three = createNode(NODE_TYPE_NUMBER, "3", NULL, NULL);
    ASTNode* five = createNode(NODE_TYPE_NUMBER, "5", NULL, NULL);
    ASTNode* params[] = {three, five};
    ASTNode* sum_call = createFunctionCallNode("sum", params, 2);

    // Print details
    printf("Function defined: %s\n", sum_function->value);
    printf("Function called: %s(%s, %s)\n",
           sum_call->value,
           sum_call->params[0]->value,
           sum_call->params[1]->value);

    // Pre-order traversal
    printf("Pre-order traversal of function body: ");
    printPreOrder(sum_function->body);
    printf("\n");

    // Free memory
    freeNode(sum_function);
    freeNode(sum_call);

    return 0;
}

