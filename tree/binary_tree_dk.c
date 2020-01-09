
// C program to demonstrate delete operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
#define COUNT 5
  
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new BST node 
struct node *newNode (int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
  
/* A utility function to insert a new node with given data in BST */
void insert (struct node *root, struct node *temp)
{
  if (temp->data < root->data)
    {
      if (root->left != NULL)
        insert (root->left, temp);
      else
        root->left = temp;
    }

  if (temp->data > root->data)
    {
      if (root->right != NULL)
        insert (root->right, temp);
      else
        root->right = temp;
    }
}

/* Given a non-empty binary search tree, return the node with minimum 
   data value found in that tree. Note that the entire tree does not 
   need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Given a binary search tree and a data, this function deletes the data 
   and returns the new root */
struct node* deleteNode(struct node* root, int data) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the data to be deleted is smaller than the root's data, 
    // then it lies in left subtree 
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
  
    // If the data to be deleted is greater than the root's data, 
    // then it lies in right subtree 
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
  
    // if data is same as root's data, then This is the node 
    // to be deleted 
    else
    { 
        // node with no child 
        if (root->left == NULL && root->right == NULL) 
        { 
            free(root); 
            root = NULL;
        } 
 
        // node with only one child
        else if (root->left == NULL) 
        { 
            struct node *temp = root;
            root = root->right; 
            free(temp); 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root;
            root = root->left; 
            free(temp); 
        } 
  
        // node with two children 
        else
        { 
          // Get the inorder successor (smallest in the right subtree) 
          struct node* temp = minValueNode(root->right); 
  
          // Copy the inorder successor's content to this node 
          root->data = temp->data; 
  
          // Delete the inorder successor 
          root->right = deleteNode(root->right, temp->data); 
        }
    } 
    return root; 
} 

void print2DUtil(struct node *root, int space)
{
    int i;
    // Base case 
    if (root == NULL)
        return;

    // Increase distance between levels 
    space += COUNT;

    // Process right child first 
    print2DUtil(root->right, space);

    // Print current node after space 
    // count 
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child 
    print2DUtil(root->left, space);
}
  
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    struct node *temp = NULL; 
    
    temp = newNode (50);   
    if(root == NULL)
      root = temp;
    else
      insert (root, temp);

    temp = newNode (30);   
    insert(root, temp); 
    temp = newNode (20);   
    insert(root, temp); 
    temp = newNode (40);   
    insert(root, temp); 
    temp = newNode (70);   
    insert(root, temp); 
    temp = newNode (60);   
    insert(root, temp); 
    temp = newNode (80);   
    insert(root, temp); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
    printf("\n \n"); 
    print2DUtil(root, 0);

    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
    printf("\n \n"); 
    print2DUtil(root, 0);
  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
    printf("\n \n"); 
    print2DUtil(root, 0);
  
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
    printf("\n \n"); 
    print2DUtil(root, 0);
  
    return 0; 
} 
