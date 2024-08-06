#include<stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 20
int main(){
	int pages[MAX_PAGES];
	int frames[MAX_FRAMES];
	int n;
	int front=0, rear=0;
	int pagefaults=0;
	printf("Enter the no.of pages(max %d): ",MAX_PAGES);
	scanf("%d",&n);
	printf("Enter the page sequence: ");
	for(int i=0;i<n;i++){
		scanf("%d",&pages[i]);
	}
	for(int i=0;i<n;i++){
		frames[i]=-1;
	}
	printf("Page\tFrames\n");
	for(int i=0;i<n;i++){
		int page=pages[i];
		int found=0;
		for(int j=0;j<MAX_FRAMES;j++){
			if(frames[j]==page){
				found=1;
				break;
			}
		}
		if(!found){
			frames[rear]=page;
			rear=(rear+1)%MAX_FRAMES;
			pagefaults++;
		}
		printf("%d\t",page);
		for(int j=0;j<MAX_FRAMES;j++){
			if(frames[j]!=-1){
				printf("%d",frames[j]);
			} else{
				printf("- ");
			}
		}
		printf("\n");
	}
	printf("\nTotal page Faults: %d\n",pagefaults);
	return 0;
}
