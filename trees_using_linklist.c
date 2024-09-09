#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* create_trees(int data)
{
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}
struct node* traverse_preOrder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        traverse_preOrder(root->left);
        traverse_preOrder(root->right);
    }
}
struct node* traverse_postOrder(struct node* root)
{
    if(root!=NULL)
    {
        traverse_postOrder(root->left);
        traverse_postOrder(root->right);
        printf("%d ",root->data);
    }
}
struct node* traverse_inOrder(struct node* root)
{
    if(root!=NULL)
    {
        traverse_preOrder(root->left);
        printf("%d ",root->data);
        traverse_preOrder(root->right);
    }
   
}
int main()
{
	struct node* n1=create_trees(1);
	struct node* n2=create_trees(2);
	struct node* n3=create_trees(3);
    struct node* n4=create_trees(4);
    struct node* n5=create_trees(5);
    struct node* n6=create_trees('\0');
    struct node* n7=create_trees('\0');
	n1->left=n2;
	n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n7;
    printf("TRAVERSAL IN PRE-ORDER:\n");
    traverse_preOrder(n1);
    printf("\n");
    printf("TRAVERSAL IN POST-ORDER:\n");
    traverse_postOrder(n1);
    printf("\n");
    
    printf("TRAVERSAL IN IN-ORDER:\n");
    traverse_inOrder(n1);
    printf("\n");
	return 0;
}