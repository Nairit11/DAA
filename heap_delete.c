#include <stdio.h>
#include <stdlib.h>

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
    scanf("%d",&n);
    int flag=0;
    for(i=1;i<=n;i++)
    {
        trace[i]=NULL;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&heap[i]);
    }

    flag = checkheap(heap, n);

    for(i=1;i<=n;i++)
    {
        trace[i]=insertnode(n,trace[i],heap[i]);
    }
    scanf("%d",&k);
    l=heap[k];
    heap[k]=heap[n];
    heap[n]=l;
    trace[k]=insertnode(n,trace[k],heap[k]);
    if(flag==1)
    	maxHeapify(heap, n-1, k);
    else
    	minHeapify(heap, n-1, k);
    for(i=1;i<n;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d index -- ",i);
        struct node* p;
        p=trace[i];
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
    return 0;
}
