#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
	long long n,i,k,flag=0,j;
	int a=1;
	FILE *fp;
	fp = fopen("data2.csv","w");
	clock_t start,end;
	float time_taken;
	srand(time(0));
	for(j=0;j<50;j++){
		n = rand()%(1000001);
		int rec[n][2];
		for(i=0;i<n;i++){
			rec[i][0]=rand();
			rec[i][1]=rand();
		}
		k=rand()%(n+1);
		printf("Searching for a Random key %lld\n",k);
		start = clock();
		for(i=0;i<n;i++){
			if(rec[i][1]==k){
				flag=1;
				printf("Record Found\nRecord: %d\n",rec[i][0]);
				end = clock();
				time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
				double nanotime = time_taken*1000000;
				fprintf(fp, "%lld %f\n",n,nanotime);
			}
		}
		if(!flag){
			printf("Record Not Found!!\n");
			end = clock();
			time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
			double nanotime = time_taken*1000000;
			fprintf(fp, "%lld %f\n",n,nanotime);
		}
	}
	fclose(fp);
	printf("Search Time: %fs\n",time_taken);
	return 0;
}