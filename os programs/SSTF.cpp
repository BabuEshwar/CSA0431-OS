#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
	int n,i,total_hm=0,cp;
	printf("Enter the no.of disk requests: ");
	scanf("%d",&n);
	int req[n];
	int vis[n];
	printf("Enter the intial head pos: ");
	scanf("%d",&cp);
	printf("Enter the disk requests: ");
	for(i=0;i<n;i++){
		scanf("%d",&req[i]);
		vis[i]=0;
	}
	for(i=0;i<n;i++){
		int min_dis=INT_MAX;
		int min_index=-1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&abs(req[j]-cp)<min_dis){
				min_dis=abs(req[j]-cp);
				min_index=j;
			}
		}
		vis[min_index]=1;
		total_hm+=min_dis;
		cp=req[min_index];
	}
	printf("the total hp:%d\n",total_hm);
	return 0;
}
