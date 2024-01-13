#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new node with a given key
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree
struct Node *insert(struct Node *node, int key)
{
    // Perform standard BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
    { // Equal keys are not allowed in AVL
        printf("\nSorry!!duplicate data");
        return node;
    }

    // Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Recursive function to delete a key in the subtree rooted with root and returns the new root of the subtree
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    // Perform standard BST delete
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        }
        else
        {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            struct Node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Recursive function to search for a key in the AVL tree
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Utility function to print the inorder traversal of the tree
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Utility function to print the preorder traversal of the tree
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Utility function to print the postorder traversal of the tree
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// Driver program to test above functions
int main()
{
    struct Node *root = NULL, *searchResult;
    int choice, n;
    do
    {
        printf("\n1. Exit  2. Insert a node  3. Preorder traversal  4. Inorder traversal");
        printf("\n5. Postorder traversal  6. Search  7. Delete\nGive choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            break;
        case 2:
            printf("\nEnter the data to be inserted = ");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 3:
            printf("\nPreorder traversal : ");
            preorder(root);
            break;
        case 4:
            printf("\nInorder traversal : ");
            inorder(root);
            break;
        case 5:
            printf("\nPostorder traversal : ");
            postorder(root);
            break;
        case 6:
            printf("\nEnter the data to be searched: ");
            scanf("%d", &n);
            searchResult = search(root, n);
            if (searchResult)
                printf("\n%d found ", n);
            else
                printf("\n%d not found ", n);
            break;
        case 7:
            printf("\nEnter the data to be deleted: ");
            scanf("%d", &n);
            root = deleteNode(root, n);
            if (root)
                printf("\n%d deleted ", n);
            else
                printf("\n%d not found ", n);
            break;
        default:
            printf("\nEnter valid choice!!");
            break;
        }
    } while (choice != 1);
    return 0;
}
