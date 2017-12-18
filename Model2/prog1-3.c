#include<stdio.h>
#define N 30

static int C[N]={0};

void print_queens(int Q[N][N],int n){
  int x,y;
  for(x=0;x<n;x++){
    printf("|");
    for(y=0;y<n;y++){
      if(Q[y][x]==1)
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

  for(x=i;x>0;x--){
    if(Q[x][j]==1){
      sum++;
    }
  for
  return sum;
}

void format(int Q[N][N],int P[N],int n){
  int x,y;
  for(x=0;x<n;x++){
    for(y=0;y<n;y++){
      Q[x][y]=0;
    }
    P[x]=0;
  }
}

int success(int Q[N][N],int n){
  int done=0;
  int x,y;
  int s;
  for(x=0;x<n;x++){
    for(y=0;y<n;y++){
      if(Q[x][y]==1){
	s=check(x,y,Q,n);
	if(s!=0){
	  done=1;
	  return done;
	}
      }
    }
    return done;
  }
}

int main(void){
  int n,i;
  int x=0,y;
  int Q[N][N];
  int P[N];
  int sum,se=1,sc;
  
  printf("nをどこまでに設定しますか:");
  scanf("%d",&i);

  for(n=i;n<i+1;n++){
    format(Q,P,n);
    x=0;

    while(x<n){
      for(y=P[x];y<n;y++){
	sum=check(x,y,Q,N);
	if(sum==0){
	  Q[x][y]=1;
	  P[x]=y;
	  break;
	}
      }

      
      if(y==n && Q[x][n-1]==0){
	P[x]=0;
	y=P[--x];
	Q[x][y]=0;
	P[x]++;
      }
      else
	x++;
    }
    
    print_queens(Q,n);
    sc=success(Q,n);
    if(sc==0)
      printf("成功\n");
    else
      printf("失敗\n");
    printf("探索回数:%d\n",se);
    
  }
    
    return 0;
}
