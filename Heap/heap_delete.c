#include <stdio.h>
#include <stdlib.h>

int t;
struct node{
    int data;
    struct node *next;
}* trace[1000];

struct node* insertnode(int n,struct node* trace,int value)
 {
     struct node* temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=value;
     temp->next=trace;
     trace=temp;
     return trace;
    
 }

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i;  
    int r = 2*i + 1;  
 
    
    if (l <= n && arr[l] > arr[largest])
        largest = l;
 
    
    if (r <= n && arr[r] >arr[largest])
        largest = r;
 
    
    if (largest != i)
    {
        int tmp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=tmp;
        trace[i]=insertnode(n,trace[i],arr[i]);
 		trace[largest]=insertnode(n,trace[largest],arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i)
{
    int smallest = i; 
    int l = 2*i;  
    int r = 2*i+1; 
 
    if (l <= n && arr[l] < arr[smallest])
        smallest = l;
 
    if (r <= n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        int tmp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=tmp;
 		trace[smallest]=insertnode(n,trace[smallest],arr[smallest]);
 		trace[i]=insertnode(n,trace[i],arr[i]);
        minHeapify(arr, n, smallest);
    }
}

int checkheap(int heap[], int n){
     int flag = 0;
     if(heap[1]>heap[2])
     {
     	flag=1;
     }
     return flag;
 }


int main(){
	int n,i,j,k,l,m,x,y,z,heap[1000];
    int flag=0;
	int ctr=12;
	FILE *f1=fopen("input.txt","r");
	FILE *f2=fopen("best.txt","w");
	FILE *f3=fopen("average.txt","w");
	FILE *f4=fopen("worst.txt","w");
	
	while(ctr>0){
	fscanf(f1,"%d",&n);
	t=t+2;
    for(i=1;i<=n;i++)
    {
        trace[i]=NULL;
		t=t+2;
    }
	t=t+2;
    for(i=1;i<=n;i++)
    {
		t=t+2;
        fscanf(f1,"%d",&heap[i]);
    }
	t=t+1;
    flag = checkheap(heap, n);
	t=t+2;
    for(i=1;i<=n;i++)
    {	
		t=t+4;
        trace[i]=insertnode(n,trace[i],heap[i]);
    }
    fscanf(f1,"%d",&k);
    l=heap[k];
    heap[k]=heap[n];
    heap[n]=l;
    trace[k]=insertnode(n,trace[k],heap[k]);
	t=t+11;
    if(flag==1)
    	maxHeapify(heap, n-1, k);
    else
    	minHeapify(heap, n-1, k);
	t=t+4;
    for(i=1;i<n;i++)
    {
		t=t+2;
        printf("%d ",heap[i]);
    }
    printf("\n");
	t=t+2;
    for(i=1;i<=n;i++)
    {
        printf("%d index -- ",i);
        struct node* p;
        p=trace[i];
		t=t+5;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
			t=t+4;
        }
        printf("\n");
		
    }

	if(ctr%3==0)
		fprintf(f2,"%d	%d\n",n,t);
	if(ctr%3==2)
		fprintf(f3,"%d	%d\n",n,t);
	if(ctr%3==1){
		fprintf(f4,"%d	%d\n",n,t);

	t=0;ctr--;flag=0;
	}
	fclose(f1);fclose(f2);fclose(f3);fclose(f4);
    return 0;
}
