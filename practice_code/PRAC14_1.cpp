#include <iostream>
#include <string>
using namespace std;

// Definition of a binary tree node
struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Function to search for a character in inorder traversal and return its index
int search(const string &inorder, int start, int end, char value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build the binary tree
Node* buildTree(const string &inorder, const string &preorder, int inStart, int inEnd, int &preIndex)
{
    if (inStart > inEnd)
        return nullptr;

    char curr = preorder[preIndex++];
    Node* tNode = new Node(curr);

    if (inStart == inEnd)
        return tNode;

    int inIndex = search(inorder, inStart, inEnd, curr);

    tNode->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    tNode->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return tNode;
}

// Function to perform postorder traversal and collect the result in a string
void postOrderTraversal(Node* node, string &result)
{
    if (node == nullptr)
        return;

    postOrderTraversal(node->left, result);
    postOrderTraversal(node->right, result);
    result += node->data;
}

int main()
{
    string inorder = "DBEACF";
    string preorder = "ABDECF";
    int len = inorder.length();
    int preIndex = 0;

    Node* root = buildTree(inorder, preorder, 0, len - 1, preIndex);

    string postorder;
    postOrderTraversal(root, postorder);

    cout << "Postorder traversal: " << postorder << endl;

    return 0;
}