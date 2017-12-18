#include<stdio.h>
#define N 30

void print_queens(int Q[N][N],int n){
  int x,y;
  for(x=0;x<n;x++){
    printf("|");
    for(y=0;y<n;y++){
      if(Q[x][y]==1)
        printf("● |");
      else
        printf("  |");
    }
    printf("\n");
  }
}

int check(int i,int j,int Q[N][N],int n){
  int x,y;
  int sum=0;
  for(x=0;x<n;x++){
    for(y=0;y<n;y++){
      if(Q[x][y]==1){
	if(x==i||y==j||x+y==i+j||x-y==i-j)
	  sum++;
      }
    }
  }
  return sum;
}


int main(void){
  int Q[N][N]={1},P[N]={0},n;
  int x,y;
  int s=0;

  n=4;
  print_queens(Q,n);
  s=check(1,2,Q,n);

  printf("%d\n",s);
  return 0;
}
