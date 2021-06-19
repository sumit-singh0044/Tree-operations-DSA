#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

void creation(struct node* , struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search_BST(struct node* , int);

int main()
{
	int ch,n,k;
	struct node *root=NULL,*temp;
	while(1)
	{
		printf("\n1. Creation:");
		printf("\n2. Inorder traversal:");
		printf("\n3. Pre-order traversal:");
		printf("\n4. Post-order traversal:");
		printf("\n5. Search BST:");
		printf("\n0. Exit:");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter new node value:");
				scanf("%d",&n);
				temp=(struct node*)malloc(sizeof(struct node));
				temp->data=n;
				temp->left=NULL;
				temp->right=NULL;
				if(root==NULL)
				{
					root=temp;
				}
				else
				{
					creation(root,temp);
				}
				break;
		case 2: printf("\n\tInorder traversal\n");
				inorder(root); break;
		case 3: printf("\n\tPre-order Traversal:\n");
				preorder(root); break;
		case 4: printf("\n\tPost-order Traversal:\n");
				postorder(root); break;
		case 5: printf("Enter the elements to search:");
				scanf("%d",&k);
				search_BST(root,k); break;
		case 0: exit(0); break;
		default : printf("Invalid choice:");
	}
	}
}

void creation(struct node *root, struct node *temp)
{
	if(temp->data<root->data)
	{
		if(root->left==NULL)
		root->left=temp;
		else
		creation(root->left , temp);
	}
	else
	{
		if(root->right==NULL)
		root->right=temp;
		else
		creation(root->right,temp);
	}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\t%d",root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	
	if(root!=NULL)
	{
		printf("\t%d",root->data);
		inorder(root->left);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		printf("\t%d",root->data);
	}
}

void search_BST(struct node *root , int k)
{
	if(root==NULL)
	printf("\nTree doesnot exist:\n");
	else if(root->data==k)
	printf("\nElement Exist in BST:\n");
	else if(k<root->data)
	search_BST(root->left,k);
	else
	search_BST(root->right,k);
}
