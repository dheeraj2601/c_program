// minimum distance between a and b
#include<stdio.h> 
#include<stdlib.h> 
#define COUNT 5
  
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 

// lookup node with min value
struct node *max_val (struct node *root)
{
  struct node *max_node, *sec_max_node;
  max_node = root;

  while (max_node->right != NULL)
    {
      sec_max_node = max_node;
      max_node = max_node->right;
    }

  return sec_max_node;
}

 
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
    int dist;
    
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

    printf("\nSecond Largest\n"); 
    temp = max_val(root) ; 
    printf ("\n Second Largest : %d \n\n", temp->data); 
   
    return 0; 
} 
