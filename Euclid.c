#include <stdio.h>

int number_of_recursivecall,t=0;

int GCD(int A, int B) {
    t++;
    if(B==0){
		t++;
        return A;
    }
    else{
        t+=2;
    	number_of_recursivecall++;
        return GCD(B, A % B);
    }
}

int main()
{
	int n,m,ctr=15;
	FILE *f2,*f1;
	f2=fopen("input.txt","r");
    f1=fopen("output.txt","w");
    while(ctr>0){
	    fscanf(f2,"%d%d",&n,&m);
	    t=t++;	
	    printf("GCD of %d and %d is %d\n",n,m,GCD(m,n));
	    ctr--;
		fprintf(f1,"%d	%d\n",number_of_recursivecall,t);
	    t=0;
	    number_of_recursivecall=0;
	}
    fclose(f2);
    fclose(f1);
    return 0;
}
