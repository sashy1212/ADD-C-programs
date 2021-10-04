/* 1. Write a C-program to concatenate two doubly linked linear lists.*/
#include<stdio.h>
#include<stdlib.h>
 
 struct Node
 {
 	int val;
 	struct Node *prev;
 	struct Node *next;

 } *head1, *head2 , *rear1, *rear2;

void create(int n, struct Node **head,struct Node **rear)
{
	int i=0;
	int element;
	struct Node *temp;
	scanf("%d",&element);
	*head=(struct Node*)malloc(sizeof(struct Node));
	(*head)->val=element;
	(*head)->next=NULL;
	(*head)->prev=NULL;
	temp=*head;
	for(i=1;i<n;i++)
	{
		scanf("%d",&element);
		temp->next=(struct Node*)malloc(sizeof(struct Node));
		temp->next->prev=temp;
		temp=temp->next;
		temp->val=element;
		temp->next=NULL;
	}
	*rear=temp;
}
void display(struct Node* List)
{
	while(List!=NULL)
	{
		printf("%d ",List->val);
		List=List->next;
	}
	printf("\n");
}

void concat()
{
	rear1->next=head2;
	head2->prev=rear1;
}
int main()
{
	int n1,n2;
	printf("Enter the number of elements in the two lists\n");
	scanf("%d %d",&n1,&n2);
	printf("enter elements of 1st list\n");
	create(n1,&head1,&rear1);
	printf("enter the elements of 2nd list \n");
	create(n2,&head2,&rear2);
	printf("Concatenated Lists: \n");
	concat();
	display(head1);
	return 0;
}
