
#include<stdlib.h>
#include<stdio.h>
 typedef struct node{
int data;
struct node*left,*right;

};
 struct node* create(struct node*temp,int data)
{
if(temp==NULL)
{
     struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=i;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
else
{
    if((temp->data)>data)
    {

    temp->left=create(temp->left,data);

    }
    else
    temp->right=create(temp->right,data);

}

}
int height(struct node *temp,int i)
{ int j,k;
    if(temp==NULL)
        return 0;
    else
    { i++;
        j=height(temp->left,0);
        k=height(temp->right,0);
        if(j>k)
            return i+j;
        else
            return i+k;
    }}
    int main()
{ struct node *root=NULL;

int num[6]={1,2,3,4,5,6};
int n=0;
    while(n!=6)
    {
  int data=num[n];

    root=create(root,data);
    n++;

    }
      printf(" height of tree is %d\n",height(root,-1));
      postorder(root);
}

void postorder(struct node*temp)
{
    if(temp!=NULL){
    postorder(temp->left);
    postorder(temp->right);


        if(((height(temp->left,0))-(height(temp->right,0)))>1)
    {    printf("balance factor:%d\n",((height(temp->left,0))-(height(temp->right,0))));
        printf("%d node is not balanced right right rotation is needed\n",temp->data);
    }
    if(((height(temp->left,0))-(height(temp->right,0)))<-1)
        {    printf("balance factor:%d\n",((height(temp->left,0))-(height(temp->right,0))));
            printf("%d node is not balanced left left rotation is needed\n",temp->data);
        }
    }
}