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
void merge1(int a[],int b[],int n,int m,int q1,int q2)//when one set is in increasing order and the other one being in decreasing order
{
	int i,j,k=0,h;
	if(q1==1 && q2==0)
	{
		i=0;
		j=m-1;
		if(a[n-1]<=b[m-1])
		{
			for(h=0;h<n;h++)
			{
				ans[k]=a[h];
				k++;
			}
			for(h=m-1;h>=0;h--)
			{
				ans[k]=b[h];
				k++;
			}
		}
		else if(b[0]<=a[0])
		{
			for(h=m-1;h>=0;h--)
			{
				ans[k]=b[h];
				k++;
			}
			for(h=0;h<n;h++)
			{
				ans[k]=a[h];
				k++;
			}
		}
		else
		{
			while(i<n && j>=0)
			{
				if(a[i]<b[j])
				{
					ans[k]=a[i];
					i++;
					k++;
				}
				else
				{
					ans[k]=b[j];
					j--;
					k++;
				}
			}
			if(i==n)
			{
				for(h=j;h>=0;h--)
				{
					ans[k]=b[h];
					k++;
				}
			}
			else if(j==-1)
			{
				for(h=i;h<n;h++)
				{
					ans[k]=a[h];
					k++;
				}
			}
		}
	}
	else if(q2==1 && q1==0)
	{
		j=0;
		i=n-1;
		if(b[m-1]<=a[n-1])
		{
			for(h=0;h<m;h++)
			{
				ans[k]=b[h];
				k++;
			}
			for(h=n-1;h>=0;h--)
			{
				ans[k]=a[h];
				k++;
			}
		}
		else if(a[0]<=b[0])
		{
			for(h=n-1;h>=0;h--)
			{
			    ans[k]=a[h];
				k++;
			}
			for(h=0;h<m;h++)
			{
				ans[k]=b[h];
				k++;
			}
		}
		else
		{
			while(j<m && i>=0)
			{
				if(a[i]<b[j])
				{
					ans[k]=a[i];
					i--;
					k++;
				}
				else
				{
					ans[k]=b[j];
					j++;
					k++;
				}
			}
			if(i==-1)
			{
				for(h=j;h<m;h++)
				{
					ans[k]=b[h];
					k++;
				}
			}
			else if(j==m)
			{
				for(h=i;h>=0;h--)
				{
					ans[k]=a[h];
					k++;
				}
			}
		}
	}
	return;

}
void merge2(int a[],int b[],int n,int m)//when both sets are in increasing order
{
	int i=0,j=0,k=0,h,y;
	if(a[n-1]<=b[0])
	{
		for(h=0;h<n;h++)
		{
			ans[h]=a[h];
		}
		for(y=0;y<m;y++)
		{
			ans[h]=b[y];
			h++;
		}
	}
	else if(b[m-1]<=a[0])
	{
		for(h=0;h<m;h++)
		{
			ans[h]=b[h];
		}
		for(y=0;y<n;y++)
		{
			ans[h]=a[y];
			h++;
		}
	}
	else 
	{
		while(i<n && j<m) {
			
			if(a[i]<b[j])
			{
				ans[k]=a[i];
				i++;
				k++;
			}
			else
			{
				ans[k]=b[j];
				j++;
				k++;
			}
		}
		if(i==n)
		{
			for(h=j;h<m;h++)
			{
				ans[k]=b[h];
				k++;
			}
		}
		else if(j==m)
		{
			for(h=i;h<n;h++)
			{
				ans[k]=a[h];
				k++;
			}	
		}
	}
	return;
}
void merge3(int a[],int b[],int n,int m)//when both the sets are in decreasing order
{
	int i=n-1,j=m-1,k=0,h;
	if(a[0]<=b[m-1])
	{
		for(h=n-1;h>=0;h--)
		{
			ans[k]=a[h];
			k++;
		}
		for(h=m-1;h>=0;h--)
		{
			ans[k]=b[h];
			k++;
		}
	}
	else if(b[0]<=a[n-1])
	{
		for(h=m-1;h>=0;h--)
		{
			ans[k]=b[h];
			k++;
		}
		for(h=n-1;h>=0;h--)
		{
			ans[k]=a[h];
			k++;
		}
	}
	else 
	{
		while(i>=0 && j>=0)
		{
			if(a[i]<b[j])
			{
				ans[k]=a[i];
				i--;
				k++;
			}
			else
			{
				ans[k]=b[j];
				j--;
				k++;
			}
		}
		if(i==-1)
		{
			for(h=j;h>=0;h--)
			{
				ans[k]=b[h];
				k++;
			}
		}
		else if(j==-1)
		{
			for(h=i;h>=0;h--)
			{
				ans[k]=a[h];
				k++;
			}
		}
	}
return;
}
int main()
{
	double t1,t2,t3,t4,tim,sum=0;
	
	t1=CTimer();
	int n,m,i,t=24,ctr=0;
	int a[1000],b[1000],q1=0,q2=0;//q1=0 implies first set is in decreasing order and similarly q2=0 implies second set is in decreasing order 
//q1=1 implies first set is in increasing order and q2=1 implies second set is in increasing order
	t2=CTimer();
	FILE *fd1,*fd2,*fd3,*fp;
	fd1=fopen("input1.txt","w");
	fd2=fopen("input2.txt","w");
	fd3=fopen("input3.txt","w");
	fp=fopen("main_input.txt","r");

	while(t>0 && feof(fp)!=-1){
		q1=0;q2=0;	
		//printf("Enter the size of the two sets:\n");
		fscanf(fp,"%d%d",&n,&m);

		//printf("Enter the elements of first set:\n");
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d",&a[i]);
			if(i>0 && a[i]>a[i-1])
			{
				q1=1;
			}
		}
		//printf("Enter the elements of first set:\n");
		for(i=0;i<m;i++)
		{
			fscanf(fp,"%d",&b[i]);
			if(i>0 && b[i]>b[i-1])
			{
				q2=1;
			}
		}
		t3=CTimer();
		if((q1==1 && q2==0)||(q1==0&&q2==1))
		{
			merge1(a,b,n,m,q1,q2);
		}
		else if(q1==1 && q2==1)
		{
			merge2(a,b,n,m);
		}
		else
		{
			merge3(a,b,n,m);
		}
		
		t4=CTimer();
		tim=t4-t3+t2+t1;
		if(t<=16){
			sum+=tim;
			ctr++;
			if(ctr==4){
				ctr=0;
				tim=sum/4;
				sum=0;
				fprintf(fd3,"%d	%lf\n",(n+m),tim);
			}
			
		}
		if(t>20)	
			fprintf(fd1,"%d    %lf\n",(n+m),tim);
		else if(t>16 && t<=20)
			fprintf(fd2,"%d    %lf\n",(n+m),tim);
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
