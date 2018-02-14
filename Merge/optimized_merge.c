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

void display(struct node *head){
	struct node *p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");

}

struct node* merge(struct node *head1,struct node *head2){
	struct node *p=head1;
	struct node *q=head2;
	struct node *cur=head1;
	if(head2->data >= tail1->data){
		tail1->next=head2;
		head2->prev=tail1;
		return head1;
	}
	if(q->data < p->data){
		printf("Hello");
		p->prev=q;
		q->next=p;
		p=q;
		q=q->next;
		p->prev=NULL;
		head1=p;
		
	}

	while(q!=NULL){
		if(q->data >= p->data){
			if(p->next!=NULL)
				p=p->next;
			else
				break;
		}
		else{
			struct node *node=(struct node*) malloc(sizeof(struct node));
			node->data=q->data;
			p->prev->next=node;
			node->prev=p->prev;
			p->prev=node;
			node->next=p;
			q=q->next;
		}
	}
	if(q!=NULL){

		p->next=q;
		q->prev=p;
	}
	return head1;
}

int main(){
	int n,m,i,a;
	//struct node *head1, *tail1, *head2, *tail2;
	printf("Enter size and elements of set1\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		head1=insert(head1,a,tail1);
	}
	printf("Enter size and elements of set2\n");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&a);
		head2=insert(head2,a,tail2);
	}
	if(n>m){
		head1=merge(head1,head2);
		display(head1);
	}
	else{
		head2=merge(head2,head1);
		display(head2);
	}
	//display(head1);
	//display(head2);
	return 0;
}
