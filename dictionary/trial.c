#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

struct node{
    char tar[50];
    int len;
}arr[500005];

long long int t=0;
int length=0;

int compare(const void *a, const void * b)
{
    t=t+4;
    return ( *(char *)a - *(char *)b );
}

int nextPermutation(char array[600006],int l) {
    int i = l - 1;
    t=t+1;
    t=t+5;
    while (i > 0 && array[i - 1] >= array[i]){
        t=t+5;
        i--;
        t=t+1;
    }
    t=t+1;
    if (i <= 0){
        return 0;
        t=t+1;
    }

    int j = l - 1;
    t=t+4;
    while (array[j] <= array[i - 1]){
        t=t+3;
        j--;
        t=t+1;
    }
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    t=t+7;
    // Reverse the suffix
    j = l - 1;
    t=t+1;
    t=t+1;
    while (i < j) {
        t=t+1;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
        t=t+9;
    }
    t=t+1;
    // Successfully computed the next permutation
    return 1;
}

void Search(char data[]){
    CURL *curl;
	CURLcode res;
	curl = curl_easy_init();
	char s[]="https://owlbot.info/api/v2/dictionary/";
	char * str;
	str=malloc(strlen(s)+strlen(data)+1);
	str[0]='\0';
	strcat(str,s);
    strcat(str,data);
	if(curl) {
    	    curl_easy_setopt(curl, CURLOPT_URL, str);
    
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_NOBODY,1L);
    	    res = curl_easy_perform(curl);
            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
  
    curl_easy_cleanup(curl);
    }
}

int main()
{
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("input.txt","r");
    f2=fopen("best.txt","w");
    f3=fopen("average.txt","w");
    f4=fopen("worst.txt","w");
    int i,j;
    char str[8];
    //srand(time(0));
    //const char* const a_to_z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    /*for(i=0;i<7;i++)
    {
        int x=rand()%26;
        t=t+3;
        str[i]=a_to_z[x];
        t=t+3;
    }*/
    int ctr=15,count;
    int n;
    while(ctr>0){
    fscanf(f1,"%d",&n);
    fscanf(f1,"%s",str);
    
    t=t+2;
    count=0;
    for(i=1;i<n;i++)
    {
    
    	if(str[i]==str[i-1])
    	{
    		count++;
    		t+=1;
    	}
    	t+=5;
    }
    t+=2;
    if(count==(n-1))
    {
    	//printf("No Possible Valid Word\n");
    	t+=2;
    	fprintf(f2,"%d    %lld\n",n,t);
    	t=0;
	ctr--;
    	continue;
    }
    t+=1;
    int k=0,l,h;
    char data[10];
    int x=1<<n;
    t=t+n+1;
    for(i=1;i<x;i++)
    {
        k=0;
        t=t+1;
        for(j=0;j<n;j++)
        {   
            t=t+j+2;
            if((i>>j)&(1))
            {
                data[k]=str[j];
                t=t+3;
                k++;
                t=t+1;
            }
        }
        data[k]='\0';
        t=t+1;
        l=strlen(data);
    	if(l!=1)
    	{    
        	t=t+1;
        	qsort(data, l, sizeof( data[0] ), compare);
        	t=t+1;
        	int j;
       		do{
        		int f=0;
        		t=t+1;
        		t=t+1;
        		if(length==0){
            		arr[length].len=l;
            		t=t+3;
            		for(j=0;j<l;j++){
                		arr[length].tar[j]=data[j];
                		t=t+5;
            		}
            		length++;
            		t=t+1;
        		}
        		else{
            		int e=0;
            		t=t+1;
            		for(j=0;j<length;j++){
            			t=t+3;
                		if(arr[j].len!=l){     	
                    		continue;
                    		t=t+1;
                		}
                		int fl=0;
                		t=t+1;
                		for(e=0;e<arr[j].len;e++){
                			t=t+5;
                    		if(data[e]!=arr[j].tar[e]){
                       			break;
                        		t=t+1;
                    		}
                    		fl+=1;
                    		t=t+1;
                		}
                		t=t+1;
                		if(fl==l){
                    		f=1;
                    		break;
                    		t=t+2;
                		}
            		}
        		}
				t=t+1;
        		if(!f){
        			for(j=0;j<l;j++)
        			{
            			arr[length].tar[j]=data[j];
            			t=t+5;
            			//printf("%c", data[j]);
        				t=t+2;
        			}
					//Search(data);
        			arr[length].len = l;
        			t=t+3;
        			length++;
        			t=t+1;
        			//printf("\n");
        			t=t+1;
    			}
   				t=t+1;     
   			}while(nextPermutation(data,l));
    	}
    }
    if(ctr>5 && ctr<11)
    {
        fprintf(f3,"%d    %lld\n",n,t);
    }
    else if(ctr<6)
    {
        fprintf(f4,"%d    %lld\n",n,t);
    }
    ctr--;
    t=0;
    } 
    printf("Done........");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);  
    return 0;
}
