#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
} *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL;

struct node* insert(struct node *head, int data,struct node *tail){
	struct node *node=(struct node*) malloc(sizeof(struct node));
	struct node *p= head;
	node->data=data;
	tail=node;
	if(p==NULL){
		head=node;
		node->next=NULL;
		node->prev=NULL;
		return head;
	}
	else{
		while(p->next!=NULL)
			p=p->next;
		p->next=node;
		node->next=NULL;
		node->prev=p;
		return head;
	}
}

int main(){
	int n,m,i;
	//struct node *head1, *tail1, *head2, *tail2;
	printf("Enter size and elements of set1\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(%d,&a);
		head1=insert(head1,a,tail1);
	}
	printf("Enter size and elements of set2\n");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf(%d,&a);
		head2=insert(head2,a);
	}
	return 0;
}
