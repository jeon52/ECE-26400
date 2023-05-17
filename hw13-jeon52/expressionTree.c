#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) 
{
    Token first = nextToken(s); 
    if (first.type == T_VAL) //RULE 1
    {
        TreeNode * Node = buildTreeNode(first);
        return Node; //assume no children = NULL on each side
    }
    else //if (first.type == T_LPAREN) //RULE 2
    {
        TreeNode * FirstNode = buildExpressionTree(s); //recursive again! (gets first value)
        Token operand = nextToken(s); //this should be an operand...
        TreeNode * SecondNode = buildExpressionTree(s); //recursive again! (gets second value)
        TreeNode * Node = buildTreeNode(operand);
        Node -> left = FirstNode;
        Node -> right = SecondNode;
        
        Token check = nextToken(s);
        if (check.type == T_RPAREN)
        {
            return Node;
        }
        else //(check.type == T_EOF)
        {
            return Node;
        }
    }
}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) 
{
    if(t -> left != NULL)
    {
        makePostFix(t -> left, fptr);
    }
    if (t -> right != NULL)
    {
        makePostFix(t -> right, fptr);
    }

    if (t -> t.type == T_VAL)
    {
        fprintf(fptr, "%f ", t -> t.value);
    }
    else if (t -> t.type == T_ADD)
    {
        fprintf(fptr, "+ ");
    }
    else if (t -> t.type == T_SUB)
    {
        fprintf(fptr, "- ");
    }
    else if (t -> t.type == T_MUL)
    {
        fprintf(fptr, "* ");
    }
    else //divide
    {
        fprintf(fptr, "/ ");
    }
    return;
}
#endif
