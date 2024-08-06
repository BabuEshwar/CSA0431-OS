#include<stdio.h>
#define MAX_BLOCKS 10
#define MAX_PROCESS 10
void firstfit(int blocksize[],int m,int processsize[], int n){
	int alloc[MAX_PROCESS];
	for(int i=0;i<n;i++){
		alloc[i]=-1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(blocksize[j]>=processsize[i]){
				alloc[i]=j;
				blocksize[j]-=processsize[i];
				break;
			}
		}
	}
	printf("Process no. \tProcess Size\tBlock no.\n");
	for(int i=0;i<n;i++){
		printf("%d\t\t%d\t\t",i+1,processsize[i]);
		if(alloc[i]!=-1){
			printf("%d\n",alloc[i]+1);
		} else{
			printf("not allowed\n");
		}
	}
}
	int main(){
		int blocksize[MAX_BLOCKS]={100,500,200,300,600};
		int processsize[MAX_PROCESS]={122,417,112,426};
		int m=5;
		int n=4;
		firstfit(blocksize,m,processsize,n);
		return 0;
	}

