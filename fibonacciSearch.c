#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fibonacci_serch(int a[],int n,int key){
    int num1=0;
    int num2=1;
    int num=num1+num2;
    while(num<n){
        num1=num2;
        num2=num;
        num=num1+num2;
    }
    int offset=-1;
    while(num>1){
        int i;
        if(offset+1<n-1){
            i=offset+1;
        }
        else{
            i=n-1;
        }       
        if(a[i]<key){
            num=num2;
            num2=num1;
            num1=num-num2;
            offset=i;
        }
        else if(a[i]>key){
            num=num1;
            num2=num2-num1;
            num1=num-num2;
        }
        else{
            return a[i];
        }
    }
    if(num2 && a[offset+1]==key) {
        return a[offset+1];
    }
    else{
        return -1;
    }
    
}

int main(){
    FILE *fp;
    fp=fopen("fibo_data.csv","w");
    int t=100;
    srand(time(0));
    while(t--){
        clock_t start,end;
        start=clock();
        int n = random()%(100001);
        int a[n],i,key=random()%(100001);
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        printf("Searchong for random key: %d\n",key);
        int result=fibonacci_serch(a,n,key);
        if(result==key){
            printf("Found\n");
        }
        else{
            printf("Not found\n");
        }
        end=clock();
        double cpu_time_used=(((double)(end-start))/CLOCKS_PER_SEC)*1000000;
        fprintf(fp,"%d %f\n",n,cpu_time_used);
    }
}