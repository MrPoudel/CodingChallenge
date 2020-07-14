#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

// get the max of two no.s
int max(int a, int b) {
   return ((a > b) ? a : b);
}

/* Print nodes at a given level */
void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

// compute height of the tree
int getHeight(Node *root) {
   if (root == NULL)
         return 0;

      // find the height of each subtree
      int lh = getHeight(root->left);
      int rh = getHeight(root->right);

      return 1 + max(lh,rh);
}

void printLevelOrder(Node* root)
{
    int h = getHeight(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    // At this point root points to the root of the Binary Search Tree (BST)

    int height=getHeight(root);
    printf("height is: %d\n",height);

    printLevelOrder(root);

    return 0;

}
