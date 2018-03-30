#include <stdio.h>
#include <stdlib.h>
int a[10000];
int min_f,max_f,n,min=1000000,max=-10000000;
int t;
int min_range(int l,int r)
{	
	if(l==r)
	{
		t+=1;
		if(a[l]<min){
			t+=2;
			min=a[l];
			min_f=l;
			t+=3;
		}
		return a[l];
	}
	else if(l==r-1)
	{	
		t+=1;
		if(a[l]<a[r])
		{
			t+=3;
			if(a[l]<min){
				t+=2;
				min=a[l];
				min_f=l;
				t+=3;
			}
			return a[l];
		}
		if(a[r]<min){
			t+=2;
			min=a[r];
			min_f=r;
			t+=3;
		}
		return a[r];
	}
	int mid=(l+r)/2;
	t+=2; 
	int x=min_range(l,mid);
	int y=min_range(mid+1,r);
	if(x<y)
	{
		t+=1;
		return x;
	}
	return y;
}
int max_range(int l,int r)
{
	if(l==r)
	{
		t+=1;
		if(a[l]>max){
			t+=2;
			max=a[l];
			max_f=l;
			t+=3;
		}
		return a[l];
	}
	else if(l==r-1)
	{
		t+=1;
		if(a[l]>a[r])
		{
			t+=3;
			if(a[l]>max){
				t+=2;
				max=a[l];
				max_f=l;
				t+=3;
			}
			return a[l];
		}
		if(a[r]>max){
			t+=2;
			max=a[r];
			max_f=r;
			t+=3;
		}
		return a[r];
	}
	int mid=(l+r)/2;
	t+=2; 
	int x=max_range(l,mid);
	int y=max_range(mid+1,r);
	if(x>y)
	{
		t+=1;
		return x;
	}
	return y;
}
int main()
{	
	int ctr=18;
	FILE *f1,*f2,*f3,*f4;
	f1=fopen("input.txt","r");f2=fopen("best.txt","w");f3=fopen("average.txt","w");f4=fopen("worst.txt","w");
	while(ctr>0){
	fscanf(f1,"%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		fscanf(f1,"%d",&a[i]);
	}
 	int l=0,r=n-1;
 	while(l<r)
 	{
 		t+=1;
 		min_range(l,r);
 		max_range(l,r);
 		min=1000000;
 		max=-10000000;
 		if(min_f!=l){
 			t+=1;
 			int x=a[min_f];
 			a[min_f]=a[l];
 			a[l]=x;
 			t+=7;
 			if(l==max_f){
 				t+=1;
 				max_f=min_f;
 				t+=1;
 			}
		}
		if(max_f!=r){
			t+=1;
			int x=a[max_f];
 			a[max_f]=a[r];
 			a[r]=x;
 			t+=7;
		}
		l++;
		r--;
		t+=2;
 	}
 	for(i=0;i<n;i++){
 		printf("%d ",a[i]);
 	}
	printf("\n");
	if(ctr%3==0)
		fprintf(f2,"%d	%d\n",n,t);
	if(ctr%3==2)
		fprintf(f3,"%d	%d\n",n,t);
	if(ctr%3==1)
		fprintf(f4,"%d	%d\n",n,t);
	ctr--;t=0;
	}
	fclose(f1);fclose(f2);fclose(f3);fclose(f4);
	return 0;
}
