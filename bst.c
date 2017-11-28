#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	struct tree *left;
	struct tree *right;
	int info;
}tree;
void preorder_traversal(tree *root)
{
	tree *temp;
	temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->info);
		preorder_traversal(temp->left);
		preorder_traversal(temp->right);
	}
}
void inorder_traversal(tree *root)
{
	tree *temp;
	temp=root;
	if(temp!=NULL)
	{
		inorder_traversal(temp->left);
		printf("%d\t",temp->info);
		inorder_traversal(temp->right);
	}
}
void postorder_traversal(tree *root)
{
	tree *temp;
	temp=root;
	if(temp!=NULL)
	{
		postorder_traversal(temp->left);
		postorder_traversal(temp->right);
		printf("%d\t",temp->info);
	}
}
void insert_bst(tree **root)
{
	tree *par,*loc,*new_node;
	int item;
	printf("Enter a number:");
	scanf("%d",&item);
	par=NULL;
	loc=*root;
	while(loc!=NULL)
	{
		if(item==loc->info)
		{
			printf("Duplicate item");
			return;
		}
		par=loc;
		if(item<loc->info)
		loc=loc->left;
		else
		loc=loc->right;
	}
	new_node=(tree*)malloc(sizeof(tree));
	new_node->info=item;
	new_node->left=NULL;
	new_node->right=NULL;
	if(par==NULL)
	*root=new_node;
	else if(item<par->info)
	par->left=new_node;
	else
	par->right=new_node;
}
void bst_search(tree *root)
{
	tree *par;
	int item,c=0;
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	printf("Input number:");
	scanf("%d",&item);
	while(root!=NULL && item!=root->info)
	{
		c++;
		if(item<root->info)
		root=root->left;
		else
		root=root->right;
	}
	if(root!=NULL)
	printf("Item present at level %d",c);
	else
	printf("Search is unsuccessfull");
	return;
}
void delete_caseAB(tree **root,tree *loc,tree *par)
{
	tree *child;
	if(loc->left==NULL && loc->right==NULL)
	child=NULL;
	else if(loc->left!=NULL)
	child=loc->left;
	else
	child=loc->right;
	if(par!=NULL)
	{
		if(loc==par->left)
		child=par->left;
		else
		child=par->right;
	}
	else
	*root=child;
	return;
}
void delete_caseC(tree **root,tree *loc,tree *par)
{
	tree *ptr,*suc,*par_suc,*save;
	ptr=loc->right;
	save=loc;
	while(ptr->left!=NULL)
	save=ptr;
	ptr=ptr->left;
	suc=ptr;
	par_suc=save;
	delete_caseAB(&(*root),suc,par_suc);
	if(par!=NULL)
	{
		if(loc=ptr->left)
		par->left=suc;
		else
		par->right=suc;
	}
	else
	*root=suc;
	suc->left=loc->left;
	suc->right=loc->right;
	return;
}
void bst_delete(tree **root)
{
	tree *loc,*par;
	int item;
	loc=*root;
	par=NULL;
	printf("Enter the number to be deleted:");
	scanf("%d",&item);
	while(loc!=NULL && item!=loc->info)
	{
		par=loc;
		if(item<loc->info)
		loc=loc->left;
		else
		loc=loc->right;
	}
	if(loc==NULL)
	{printf("Item not found");
	exit(0);}
	if(loc->left!=NULL && loc->right!=NULL)
	delete_caseC(&(*root),loc,par);
	else
	delete_caseAB(&(*root),loc,par);
	free(loc);
	return;
}
main()
{
	system("clear");
	tree *root=NULL;
	int ch,n;
	do
	{
		printf("1.Create\n2.Pre order traversal\n3.In order traversal\n4.Post order traversal\n5.Search\n6.Delete\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:insert_bst(&root);
				break;
			case 2:preorder_traversal(root);
				break;
			case 3:inorder_traversal(root);
				break;
			case 4:postorder_traversal(root);
				break;
			case 5:bst_search(root);
				break;
			case 6:bst_delete(&root);
				break;
			default:printf("Invalid option");
		}
		printf("\nDo you want to continue(0/1)?:");
		scanf("%d",&ch);
	}
	while(ch==1);
	return(0);
}
