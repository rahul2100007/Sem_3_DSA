#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node
{
    char data;  
    struct Node *left;
    struct Node *right;
};

// Function to create a new tree node
struct Node *newNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if two trees are identical
int areIdentical(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

// Function to check if the department tree is a subtree of the organizational tree
int isSubtree(struct Node *orgTree, struct Node *deptTree)
{
    if (deptTree == NULL)
        return 1;
    if (orgTree == NULL)
        return 0;
    if (areIdentical(orgTree, deptTree))
        return 1;
    return isSubtree(orgTree->left, deptTree) || isSubtree(orgTree->right, deptTree);
}

int main()
{
    // Create the organizational tree
    struct Node *orgTree = newNode('A');
    orgTree->left = newNode('B');
    orgTree->right = newNode('C');
    orgTree->left->left = newNode('D');
    orgTree->left->right = newNode('E');
    orgTree->right->right = newNode('F');

    // Create the department tree
    struct Node *deptTree = newNode('B');
    deptTree->left = newNode('D');
    deptTree->right = newNode('E');

    if (isSubtree(orgTree, deptTree))
        printf("The department tree is a subtree of the organizational tree.\n");
    else
        printf("The department tree is NOT a subtree of the organizational tree.\n");

    return 0;
}