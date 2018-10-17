#include<stdio.h>
#include<conio.h>
struct node 
{
    int data;
    struct node * left;
    struct node * right;
};
struct node* getnode()
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    return ptr;
}
struct node * root=NULL;
struct node* insertion(struct node* root, int data)
{
    if(root==NULL)
    {
        root=getnode();
        root->left=NULL;
        root->right=NULL;
        root->data=data;
    }
    else
    {
        if(root->data<data)
        {
            root->left=insertion(root->left,data);
        }
        else
        {
            root->right=insertion(root->right,data);
        }
    }
    return root;
}
void traverse(struct node * root)
{
    if(root!=NULL)
    {
        traverse(root->left);
        printf("%d ",root->data);
        traverse(root->right);
    }
}
int main()
{
    int number,i,info;
    printf("Enter the number of elements\n");
    scanf("%d",&number);
    for(i=0;i<number;i++)
    {
        printf("Enter the information\n");
        scanf("%d",&info);
        root=insertion(root,info);
    }
    traverse(root);
    getchar();
    return 0;
}
