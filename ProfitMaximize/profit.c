#include <stdio.h>
#include <math.h>
#define max(x,y) x>y?x:y
int n,p;
int profit[100][100];
int t=0;
int func(int id,int mask){
	t=t+5;
	if(mask==(1<<p)-1 || id>n){
		t+=1;		
		return 0;
	}
	int i,ans=0;
    //func(id+1,mask);
	t+=2;
	for(i=0;i<p;i++){
		t+=2;
		if(mask&(1<<i)){
			t+=1;			
			continue;
		}	
		ans=max(ans,profit[i][id-1]+func(id+1,mask|(1<<i)));
		t+=6;
	}
	t+=1;
	return ans;
}
int main() {

    int i,j;
    scanf("%d%d",&n,&p);
    float x;
    for(i=0;i<p;i++){
        for(j=0;j<n;j++){
            scanf("%d",&profit[i][j]);
        }
    }
    t+=2;
    for(i=0;i<p;i++){
	t+=2;
        for(j=0;j<n;j++){
            scanf("%f",&x);
	    t+=2;
            int y=ceil(1.0/x);
            profit[i][j]=profit[i][j]*y;
	    t+=6;
         }
    }
    printf("%d\n",func(1,0));
    t+=3;
    return 0;
}
