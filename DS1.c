#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};
struct Node* insert(int data)
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=0;
    temp->right=0;
    return temp;
};
struct Node* create(struct Node *root,int data)
{
    if(root==0)
    {
        return insert(data);
    }
    else
    {
        if(data>root->data)
        {
            root->right=create(root->right,data);
        }
        else if(data<root->data)
        {
            root->left=create(root->left,data);
        }
    }
};
int h(struct Node *root)
{
    int l,r;
    if(root==0)
    {
        return 0;
    }
    l=h(root->left);
    r=h(root->right);
    if(l>r)
        return l+1;
    else
        return r+1;
}
void call(struct Node *root)
{
    int l,r;
    if(root==0)
    {
        return;
    }
    call(root->left);
    l=h(root->left);
    call(root->right);
    r=h(root->right);
    if((l-r)==1||(l-r)==0||(l-r)==-1)
    {
        printf("%d is a balanced node\n",root->data);
    }
    else if(l-r>1)
        printf("%d is a left unbalanced node\n",root->data);
    else if(l-r<-1)
         printf("%d is a right1 unbalanced node\n",root->data);
}
int main()
{
    struct Node *root=0;
    root=create(root,1);
    create(root,2);
    create(root,3);
    create(root,4);
    create(root,5);
    create(root,6);
    call(root);
}
