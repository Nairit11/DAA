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
	FILE *f2,*f3,*f4,*f5;
	f2=fopen("input.txt","r");
    f3=fopen("best.txt","w");
    f4=fopen("average.txt","w");
    f5=fopen("worst.txt","w");
    while(ctr>0){
	    fscanf(f2,"%d%d",&n,&m);
	    t=t++;	
	    printf("GCD of %d and %d is %d\n",n,m,GCD(m,n));
	    ctr--;
	    if(ctr>10)
	    	fprintf(f3,"%d	%d\n",number_of_recursivecall,t);
	    else if(ctr>5 && ctr<11)
	    	fprintf(f4,"%d	%d\n",number_of_recursivecall,t);
	    else
	    	fprintf(f5,"%d	%d\n",number_of_recursivecall,t);
	    t=0;
	    number_of_recursivecall=0;
	}
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    return 0;
}
