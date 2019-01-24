#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int Binary_search(int a[],int low,int high,int key){
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            return key;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    FILE *fp;
    fp=fopen("binSearch.csv","w");
    clock_t start,end;
    start=clock();
    int t = 10;
    srand(time(0));
    while(t--){
    int n = random()%(100001);
    int a[n],i;
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
    int key=a[random()%n];
    int result;
    result=Binary_search(a,0,n-1,key);
    if(result==key){
        printf("Key Found: %d \n",result);
    }
    else{
        printf("Not found\n");
    }
    end=clock();
    double cpu_cycle_time=(((double)(end-start))/CLOCKS_PER_SEC)*1000000;
    fprintf(fp,"%d %f %f\n",n,cpu_cycle_time,log2(n));
    }
    return 0;
}