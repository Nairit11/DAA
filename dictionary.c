
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

int compare(const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}
 
void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
    return;
}
int length=0;
struct node{
    char tar[50];
    int len;
}arr[500005];
int findCeil(char str[], char first, int l, int h)
{
    int ceilIndex = l;
    for (int i = l+1; i <= h; i++)
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
 
    return ceilIndex;
}
bool NextPermutation(char elems[600006],int l) {
  int N = l;
  int i;
  int li = -1;  
  int next_candidate_index = li + 1;
  for (i = 0; i < N; ++i) {
    if ((i + 1 < N) && elems[i + 1] > elems[i]) {
      li = i;
      next_candidate_index = li + 1;
    }
    if (li >= 0 && elems[i] > elems[li] &&
        elems[i] < elems[next_candidate_index]) {
      next_candidate_index = i;
    }
  }
 
  if (li == -1) {
    return false;
  }
 char a = elems[li];
            elems[li]=elems[next_candidate_index];
            elems[next_candidate_index]=a;
  int u=1;
  for(i=li+1;i<(li+1)+((l-(li+1))/2);i++){
    char a = elems[i];
            elems[i]=elems[l-u];
            elems[l-u]=a;
            u++;
  }
  return true;
}
 
void sortedPermutations(char data[],int r)
{
    int size = r;
    qsort(data, r, sizeof( data[0] ), compare);
    int isFinished = 0,i,j;
    while (!isFinished)
    {
        for (i = size - 2; i >= 0; --i)
            if (data[i] < data[i+1])
                break;
        if (i == -1)
            isFinished = 1;
        else
        {
            int ceilIndex = findCeil(data, data[i], i + 1, size - 1);
            swap(&data[i], &data[ceilIndex]);
            qsort(data + i + 1, size - i - 1, sizeof(data[0]), compare);
        }
    }
}

void Search(){
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();
	if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://owlbot.info/api/v2/dictionary/nairit");
    
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
  
    curl_easy_cleanup(curl);
    }
}

int main()
{
    int i,j;
    char str[8];
    srand(time(0));
    const char* const a_to_z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    for(i=0;i<7;i++)
    {
        int x=rand()%26;
        str[i]=a_to_z[x];
    }
    str[7]='\0';

    int k=0,l,h;
    char data[10];
    for(i=1;i<(1<<7);i++)
    {
        k=0;
        for(j=0;j<7;j++)
        {   
            if((i>>j)&(1))
            {
                data[k]=str[j];
                k++;
            }
        }
        data[k]='\0';
         l=strlen(data);
      
        sortedPermutations(data,l);
        int j;
        for(j=0;j<l/2;j++){
            char a = data[j];
            data[j]=data[l-j-1];
            data[l-j-1]=a;
        }
       do{
        int f=0;
        if(length==0){
            arr[length].len=l;
            for(j=0;j<l;j++)
                arr[length].tar[j]=data[j];
            length++;
        }
        else{
            int e=0;
            for(j=0;j<length;j++){
                if(arr[j].len!=l)
                    continue;
                int fl=0;
                for(e=0;e<arr[j].len;e++){
                    if(data[e]!=arr[j].tar[e]){
                        break;
                    }
                    fl+=1;
                }
                if(fl==l){
                    f=1;
                    break;
                }
            }
        }

        if(!f){
         for(j=0;j<l;j++)
        {
            arr[length].tar[j]=data[j];
            printf("%c", data[j]);
        }
        arr[length].len = l;
        length++;
        printf("\n");
    }
        
   }while(NextPermutation(data,l));
    }
    return 0;
}
