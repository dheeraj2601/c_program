
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

 


#define MAX_Q_SIZE 500

/* frunction prototypes */
struct node** createQueue(int *, int *); 
void enQueue(struct node **, int *, struct node *); 
struct node *deQueue(struct node **, int *); 
 

/* Helper function for getLevel().  
It returns level of the data if data is 
present in tree, otherwise returns 0.*/
int getLevelUtil(struct node *node,  
                 int data, int level) 
{ 
    if (node == NULL) 
        return 0; 
  
    if (node -> data == data) 
        return level; 
  
    int downlevel = getLevelUtil(node -> left,  
                                 data, level + 1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(node->right,  
                             data, level + 1); 
    return downlevel; 
} 
 
/* Given a binary tree, print its nodes in level order 
   using array for implementing queue */
void printLevelOrder(struct node* root) 
{ 
    int rear, front; 
    struct node **queue = createQueue(&front, &rear); 
    struct node *temp_node = root; 
  
    printf("\n\n"); 
    while (temp_node) 
    { 
        printf("%d : %d\n", temp_node->data, getLevelUtil(root, temp_node->data, 1)); 
  
        /*Enqueue left child */
        if (temp_node->left) 
            enQueue(queue, &rear, temp_node->left); 
  
        /*Enqueue right child */
        if (temp_node->right) 
            enQueue(queue, &rear, temp_node->right); 
  
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front); 
    } 
} 

/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear) 
{ 
    struct node **queue = 
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE); 
  
    *front = *rear = 0; 
    return queue; 
} 
  
void enQueue(struct node **queue, int *rear, struct node *new_node) 
{ 
    queue[*rear] = new_node; 
    (*rear)++; 
} 
  
struct node *deQueue(struct node **queue, int *front) 
{ 
    (*front)++; 
    return queue[*front - 1]; 
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
    
    temp = newNode (50);   
    if(root == NULL)
      root = temp;
    else
      insert (root, temp);

    temp = newNode (32);   
    insert(root, temp); 

    temp = newNode (30);   
    insert(root, temp); 


    temp = newNode (20);   
    insert(root, temp); 
    temp = newNode (40);   
    insert(root, temp); 
    temp = newNode (45);   
    insert(root, temp); 
 
    temp = newNode (70);   
    insert(root, temp); 
    temp = newNode (60);   
    insert(root, temp); 
    temp = newNode (80);   
    insert(root, temp); 
    temp = newNode (80);   
    insert(root, temp); 
    temp = newNode (35);   
    insert(root, temp); 
    temp = newNode (25);   
    insert(root, temp); 
    temp = newNode (90);   
    insert(root, temp); 
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
    printf("\n \n"); 
    print2DUtil(root, 0);

    printLevelOrder(root); 
    printf("\n \n"); 
 
    return 0; 
} 
