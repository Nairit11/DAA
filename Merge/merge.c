#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>


double CTimer() {
	struct timeval tm;

	gettimeofday(&tm,NULL);
	return((double)tm.tv_usec)/1000000.0;
}

int ans[10000000];
int merge1(int a[],int b[],int n,int m,int q1,int q2)//when one set is in increasing order and the other one being in decreasing order
{
	int i,j,k=0,h,t=0;
	if(q1==1 && q2==0)
	{
		i=0;
		j=m-1;
		t+=2;
		if(a[n-1]<=b[m-1])
		{
			t+=3;
			for(h=0;h<n;h++)
			{
				t+=2;
				ans[k]=a[h];
				k++;
				t+=4;
			}
			t+=2;
			for(h=m-1;h>=0;h--)
			{
				t+=2;
				ans[k]=b[h];
				k++;
				t+=4;
			}
			t+=2;
		}
		else if(b[0]<=a[0])
		{
			t+=3;
			for(h=m-1;h>=0;h--)
			{
				t+=2;
				ans[k]=b[h];
				k++;
				t+=4;
			}
			t+=2;
			for(h=0;h<n;h++)
			{
				t+=2;
				ans[k]=a[h];
				k++;
				t+=4;
			}
			t+=2;
		}
		else
		{
			while(i<n && j>=0)
			{
				t+=2;
				if(a[i]<b[j])
				{
					t+=3;
					ans[k]=a[i];
					i++;
					k++;
					t+=5;
				}
				else
				{
					ans[k]=b[j];
					j--;
					k++;
					t+=5;
				}
			}
			t+=1;
			if(i==n)
			{
				t+=1;
				for(h=j;h>=0;h--)
				{
					t+=2;
					ans[k]=b[h];
					k++;
					t+=4;
				}
				t+=2;
			}
			else if(j==-1)
			{
				t+=1;
				for(h=i;h<n;h++)
				{
					t+=2;
					ans[k]=a[h];
					k++;
					t+=4;
				}
				t+=2;
			}
		}
	}
	else if(q2==1 && q1==0)
	{
		j=0;
		i=n-1;
		t+=4;
		if(b[m-1]<=a[n-1])
		{
			t+=3;
			for(h=0;h<m;h++)
			{
				t+=2;
				ans[k]=b[h];
				k++;
				t+=4;
			}
			t+=2;
			for(h=n-1;h>=0;h--)
			{
				t+=2;
				ans[k]=a[h];
				k++;
				t+=4;
			}
			t+=2;
		}
		else if(a[0]<=b[0])
		{
			t+=3;
			for(h=n-1;h>=0;h--)
			{
				t+=2;
			    ans[k]=a[h];
				k++;
				t+=4;
			}
			t+=2;
			for(h=0;h<m;h++)
			{
				t+=2;
				ans[k]=b[h];
				k++;
				t+=4;
			}
			t+=2;
		}
		else
		{
			while(j<m && i>=0)
			{
				t+=2;
				if(a[i]<b[j])
				{
					t+=3;
					ans[k]=a[i];
					i--;
					k++;
					t+=5;
				}
				else
				{
					ans[k]=b[j];
					j++;
					k++;
					t+=5;
				}
			}
			t+=1;
			if(i==-1)
			{
				t+=1;
				for(h=j;h<m;h++)
				{
					t+=2;
					ans[k]=b[h];
					k++;
					t+=4;
				}
				t+=2;
			}
			else if(j==m)
			{
				t+=1;
				for(h=i;h>=0;h--)
				{
					t+=2;
					ans[k]=a[h];
					k++;
					t+=4;
				}
				t+=2;
			}
		}
	}
	return t;

}
int merge2(int a[],int b[],int n,int m)//when both sets are in increasing order
{
	int t=0;
	int i=0,j=0,k=0,h,y;
	t+=3;
	if(a[n-1]<=b[0])
	{
		t+=3;
		for(h=0;h<n;h++)
		{
			t+=2;
			ans[h]=a[h];
			t+=3;
		}
		t+=2;
		for(y=0;y<m;y++)
		{
			t+=2;
			ans[h]=b[y];
			h++;
			t+=4;
		}
		t+=2;
	}
	else if(b[m-1]<=a[0])
	{
		t+=3;
		for(h=0;h<m;h++)
		{
			t+=2;
			ans[h]=b[h];
			t+=3;
		}
		t+=2;
		for(y=0;y<n;y++)
		{
			t+=2;
			ans[h]=a[y];
			h++;
			t+=4;
		}
		t+=2;
	}
	else 
	{
		while(i<n && j<m) 
		{
			t+=2;
			if(a[i]<b[j])
			{
				t+=3;
				ans[k]=a[i];
				i++;
				k++;
				t+=5;
			}
			else
			{
				ans[k]=b[j];
				j++;
				k++;
				t+=5;
			}
		}
		t+=1;
		if(i==n)
		{
			t+=1;
			for(h=j;h<m;h++)
			{
				t+=2;
				ans[k]=b[h];
				k++;
				t+=4;
			}
			t+=2;
		}
		else if(j==m)
		{
			t+=1;
			for(h=i;h<n;h++)
			{
				t+=2;
				ans[k]=a[h];
				k++;
				t+=4;
			}	
			t+=2;
		}
	}
	return t;
}
int merge3(int a[],int b[],int n,int m)//when both the sets are in decreasing order
{
	int t=0;
	int i=n-1,j=m-1,k=0,h;
	t+=3;
	if(a[0]<=b[m-1])
	{
		t+=3;
		for(h=n-1;h>=0;h--)
		{
			t+=2;
			ans[k]=a[h];
			k++;
			t+=4;
		}
		t+=2;
		for(h=m-1;h>=0;h--)
		{
			t+=2;
			ans[k]=b[h];
			k++;
			t+=4;
		}
		t+=2;
	}
	else if(b[0]<=a[n-1])
	{
		t+=3;
		for(h=m-1;h>=0;h--)
		{
			t+=2;
			ans[k]=b[h];
			k++;
			t+=4;
		}
		t+=2;
		for(h=n-1;h>=0;h--)
		{
			t+=2;
			ans[k]=a[h];
			k++;
			t+=4;
		}
		t+=2;
	}
	else 
	{
		while(i>=0 && j>=0)
		{
			t+=2;
			if(a[i]<b[j])
			{
				t+=3;
				ans[k]=a[i];
				i--;
				k++;
				t+=5;
			}
			else
			{
				ans[k]=b[j];
				j--;
				k++;
				t+=5;
			}
		}
		t+=1;
		if(i==-1)
		{
			t+=1;
			for(h=j;h>=0;h--)
			{
				t+=2;
				ans[k]=b[h];
				k++;
				t+=4;
			}
			t+=2;
		}
		else if(j==-1)
		{
			t+=1;
			for(h=i;h>=0;h--)
			{
				t+=2;
				ans[k]=a[h];
				k++;
				t+=4;
			}
			t+=2;
		}
	}
return t;
}
int main()
{
	int t2=0,sum=0,tim,t1=0;
	int n,m,i,t=600,ctr=0;
	t1+=2;
	int a[1000],b[1000],q1=0,q2=0;//q1=0 implies first set is in decreasing order and similarly q2=0 implies second set is in decreasing order 
//q1=1 implies first set is in increasing order and q2=1 implies second set is in increasing order
	t1+=2;
	FILE *fd1,*fd2,*fd3,*fp;
	fd1=fopen("input1.txt","w");
	fd2=fopen("input2.txt","w");
	fd3=fopen("input3.txt","w");
	fp=fopen("input.txt","r");

	while(t>0 && feof(fp)!=-1){
		t2=0;
		q1=0;q2=0;
		t2+=2;	
		//printf("Enter the size of the two sets:\n");
		fscanf(fp,"%d%d",&n,&m);
		t2+=1;
		//printf("Enter the elements of first set:\n");
		int count=0;
		t2+=1;
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d",&a[i]);
			t2+=3;
			if(count<1 && i>0 && a[i]>a[i-1])
			{
				count++;
				q1=1;
				t2+=6;
			}
			t2+=1;
		}
		t2+=2;
		//printf("Enter the elements of first set:\n");
		count=0;
		t2+=1;
		for(i=0;i<m;i++)
		{
			fscanf(fp,"%d",&b[i]);
			t2+=3;
			if(count<1 && i>0 && b[i]>b[i-1])
			{
				count++;
				q2=1;
				t2+=6;
			}
			t2+=1;
		}
		t2+=2;
		if((q1==1 && q2==0)||(q1==0&&q2==1))
		{
			t2+=2;
			int x=merge1(a,b,n,m,q1,q2);
			t2+=x;
		}
		else if(q1==1 && q2==1)
		{
			t2+=2;
			int x=merge2(a,b,n,m);
			t2+=x;
		}
		else
		{
			int x=merge3(a,b,n,m);
			t2+=x;
		}
		tim=t2+t1;
		if(t<=400){
			sum+=tim;
			ctr++;
			if(ctr==4){
				ctr=0;
				tim=sum/4;
				sum=0;
				fprintf(fd3,"%d	%d\n",(n),tim);
			}
			
		}
		if(t>500)	
			fprintf(fd1,"%d    %d\n",(n),tim);
		else if(t>400 && t<=500)
			fprintf(fd2,"%d    %d\n",(n),tim);
		//printf("\nTime taken to print combined array = %d\n",t4-t3+t2-t1);
		t--;
	}
	fclose(fd1);
	fclose(fd2);
	fclose(fd3);
	fclose(fp);
	const char* script="~/myscript.sh";
	printf("Files input1.txt, input2.txt and input3.txt are created with data for plotting graphs for best, worst and average running time respectively\n");
	printf("Plotting the running time graphs.....\n");
	sleep(1);
	system(script);
	return 0;
}
