#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max(x,y) x>y?x:y

long long int dp[100][100];
long long int profit[100][100];
long long int t=0,n,p;
long long int func(long long int id,long long int mask){
    t+=p+4;
    if(mask==(1<<p)-1 || id>n){
		t+=1;
        return 0;
    }
	t+=3;
    if(dp[id][mask]!=1000000000){
		t+=3;        
		return dp[id][mask];
    }
    long long int i,ans=0;
    //func(id+1,mask);
	t+=2;
    for(i=0;i<p;i++){
		t+=i+1;        
		if(mask&(1<<i)){
			t+=1;            
			continue;
        }   
        ans=max(ans,profit[i][id-1]+func(id+1,mask|(1<<i)));
        t+=6+i;
    }
    dp[id][mask]=ans;
	t+=3;
}
int main() {

    long long int i,j,z;
	FILE *f1,*f2;
	f1=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	for(z=5;z>0;z--){
    fscanf(f1,"%lld%lld",&n,&p);
    double x;
	
    for(i=0;i<p;i++){
        for(j=0;j<n;j++){
            fscanf(f1,"%lld",&profit[i][j]);
        }
    }
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            dp[i][j]=1000000000;
        }
    }
    for(i=0;i<p;i++){
        for(j=0;j<n;j++){
            fscanf(f1,"%lf",&x);
            long long int y=ceil(1.0/x);
            profit[i][j]=profit[i][j]*y;
			t=t+8;
         }
    }
    printf("%lld\n",func(1,0));
	fprintf(f2,"%lld	%lld\n",n,t);
	t=0;
	}
    return 0;
}
