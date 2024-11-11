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
Node *buildTree(const string &inorder, const string &preorder, int start, int end,
                int &preorderIndex)
{
    if (start > end)
        return nullptr;
    // Get the current root from preorder
    char current = preorder[preorderIndex++];
    Node *node = new Node(current);
    // If this node has no children, return it
    if (start == end)
        return node;
    // Find the index of this node in inorder
    int inorderIndex = search(inorder, start, end, current);
    // Recursively construct the left and right subtrees
    node->left = buildTree(inorder, preorder, start, inorderIndex - 1, preorderIndex);
    node->right = buildTree(inorder, preorder, inorderIndex + 1, end, preorderIndex);
    return node;
}
// Function to perform postorder traversal
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data;
}
int main()
{
    string inorder = "DBEACF";
    string preorder = "ABDECF";
    int preorderIndex = 0;
    // Build the tree
    Node *root = buildTree(inorder, preorder, 0, inorder.size() - 1, preorderIndex);
    // Print the postorder traversal
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
    return 0;
