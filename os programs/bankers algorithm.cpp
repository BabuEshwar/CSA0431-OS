#include<stdio.h>
#include<conio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avl[100];
int n,r;
void input();
void show();
void cal();
int main(){
    int i,j;
    printf("***************** Banker's algorithm ********************\n");
    input();
    show();
    cal();
    getch();
    return 0;
}
void input(){
    int i,j;
    printf("Enter no.of process: ");
    scanf("%d",&n);
    printf("Enter no.of resource instances\t");
    scanf("%d",&r);
    printf("Enter the max matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the allocation matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the avaliable resources\n");
    for(j=0;j<r;j++){
        scanf("%d",&avl[j]);
    }
}

void show(){
    int i,j;
    printf("process\tallocation\tMAx\tAvaliable\n");
    for(i=0;i<n;i++){
        printf("P%d\t",i+1);
        for(j=0;j<r;j++){
            printf("%d ",alloc[i][j]);
        }
        printf("\t");
        for(j=0;j<r;j++){
            printf("%d ",max[i][j]);
        }
        printf("\t");
        if(i==0){
            for(j=0;j<r;j++){
                printf("%d ",avl[j]);
            }
        }
        printf("\n");
    }
}

void cal(){
    int finish[100], temp, flag=1, k,cl=0;
    int safe[100];
    int i,j;
    for(i=0;i<n;i++){
        finish[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\n");
    while(flag){
        flag=0;
        for(i=0;i<n;i++){
            int c=0;
            for(j=0;j<r;j++){
                if((finish[i]==0)&&(need[i][j]<=avl[j])){
                    c++;
                    if(c==r){
                        for(k=0;k<r;k++){
                            avl[k]+=alloc[i][k];
                            finish[i]=1;
                            flag=1;
                        }
                        printf("P%d->",i);
                        if(finish[i]==1){
                            i=n;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(finish[i]==1){
            cl++;
        } else{
            printf("P%d->",i);
        }
    }
    if(cl==n){
        printf("\n the system is in safe state");
    } else{
        printf("\n process are in dead lock");
        printf("\n System is in unsafe state");
    }
}
