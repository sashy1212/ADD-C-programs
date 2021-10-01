#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node *newNode(int data) 
{
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int tocountNodes(struct Node *root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    return (1 + tocountNodes(root->left) + tocountNodes(root->right));
}


int countEdges(struct Node *root) 
{
    return (tocountNodes(root) - 1); //We know that, for a binary tree number of edges = number of nodes - 1
}

int maxHeight(struct Node *root) 
{
    if (root == NULL) {
        return 0;
    }
    return (1 + __max(maxHeight(root->left), maxHeight(root->right)));
}

int main() {
    struct Node *root = newNode(11); 
    root->left = newNode(12);
    root->right = newNode(13);

    root->left->left = newNode(14);
    root->left->right = newNode(15);

    root->right->left = newNode(16);

    root->right->left->left = newNode(17);
    root->right->left->right = newNode(18);

    root->left->left->left = newNode(19);
    root->left->left->left -> right = newNode(20); //Arbitrary nodes are added to the root

    printf("There are %d nodes, and %d edges in the tree\n\n", tocountNodes(root), countEdges(root));

    printf("There are %d nodes, and %d edges in the left subtree\n\n", tocountNodes(root->left), countEdges(root->left));

    printf("There are %d nodes, and %d edges in the right subtree\n\n", tocountNodes(root->right), countEdges(root->right));

    printf("Maximum height of the tree is %d\n\n", maxHeight(root));

    printf("Maximum height of the left subtree is %d\n\n", maxHeight(root -> left));

    printf("Maximum height of the right subtree is %d\n\n", maxHeight(root -> right));

    return 0;
}
