// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *lc, *rc;
};

// Create a node
struct node *newNode(int data) {
  struct node *temp = new node;
  temp->data = data;
  temp->lc = temp->rc = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->lc);

    // Traverse root
    cout << root->data << " -> ";

    // Traverse right
    inorder(root->rc);
  }
}

// Insert a node
struct node *insert(struct node *node, int data) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(data);

  // Traverse to the right place and insert the node
  if (data < node->data)
    node->lc = insert(node->lc, data);
  else
    node->rc = insert(node->rc, data);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->lc != NULL)
    current = current->lc;

  return current;
  cout << current->data ;
  
}




// Driver code
int main() {
  struct node *root = NULL;
 int data;
  cout << ".......................BINARY SEARCH TREE.........................."<<endl;

 cout<<"how many elements you want to enter?"<<endl;
 int n;
 cin>>n;


 cout<<"......enter data......."<<endl;
 for (int i=0;i<n;i++){
 cin>>data;

  root = insert(root, data);}

  cout << "Inorder traversal: ";
  inorder(root);



}