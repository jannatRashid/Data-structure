#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node *lc, *rc;
};

struct node *etroot(char data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->lc = temp->rc = NULL;
    return temp;
};

void inorder(struct node *root)
{
    if (root->lc != NULL)
    {
        inorder(root->lc);
    }
    cout << root->data;
    if (root->rc != NULL)
    {
        inorder(root->rc);
    }
}


void preorder(struct node *root)
{
    cout << root->data;
    if (root->lc != NULL)
    {
        preorder(root->lc);
    }
    if (root->rc != NULL)
    {
        preorder(root->rc);
    }
}




void postorder(struct node *root)
{
    if (root->lc != NULL)
    {
        postorder(root->lc);
    }
    if (root->rc != NULL)
    {
        postorder(root->rc);
    }
    cout << root->data;
}



int main()
{
    struct node *root = etroot('*');
    root->lc = etroot('a');
    root->rc = etroot('c');
    root->lc->lc = etroot('b');
    root->lc->rc = etroot('-');
    root->rc->lc = etroot('d');
    root->rc->rc = etroot('+');
    root->rc->rc->lc = etroot('e');
    cout << "\nInorder traversal of binary tree is \n";
    inorder(root);

     cout << "\npreorder traversal of binary tree is \n";
    preorder(root);

     cout << "\npostorder traversal of binary tree is \n";
    postorder(root);

    return 0;
}
