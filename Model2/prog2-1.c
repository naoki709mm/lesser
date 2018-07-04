#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define N 30

void print_queens(int Q[N][N],int n){ /*配列Qを探索し1だと●、0だと空白を表示する関数*/
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

int delta(int x,int y){
  if(x==y)
    return 1;
  else
    return 0;
}

void make_W(double W[N][N][N][N],int n){
  int i,j,k,l;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	for(l=0;l<n;l++){
	  W[i][j][k][l]=delta(i,k)*(1-delta(j,l))+delta(j,l)*(1-delta(i,k))+delta(i+j,k+l)*(1-delta(i,k))+delta(i-j,k-l)*(1-delta(i,k));
	}
      }
    }
  }
}

double energy(int x[N][N],double W[N][N][N][N],int n){
  double E=0.0;
  int i,j,k,l;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	for(l=0;l<n;l++){
	  E+=W[i][j][k][l]*x[i][j]*x[k][l];
	}
      }
    }
  }
  return E;
}

void reset(double W[N][N][N][N],int x[N][N],int xd[N][N],int n){
  int i,j,k,l;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	for(l=0;l<n;l++){
	  W[i][j][k][l]=0;
	  x[i][j]=0;
	  xd[i][j]=0;
	}
      }
    }
  }
}

int main(void){
  int n,i,j,k,l;
  int x[N][N],xd[N][N];
  int P[N],r;
  double W[N][N][N][N]={0};
  double Ec,En,dE;
  time_t tp;
  time(&tp);
  srand48(tp);
  printf("nを入力:");scanf("%d",&n);
  reset(W,x,xd,n);
  make_W(W,n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==j){
	x[i][j]=1;
	break;
      }
    }
  }
  Ec=energy(x,W,n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(x[i][j]==1){
	P[i]=j;
	break;
      }
    }
  }
  
  while(En==0){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	xd[i][j]=x[i][j];
      }
    }
    i=rand()%n;
    k=rand()%n;
    xd[i][P[i]]=0;
    xd[i][P[k]]=1;
    xd[k][P[k]]=0;
    xs[k][P[i]]=1;
    En=(xd,W,n);
    dE=En-Ec;
    if(dE<=0)
 
  print_queens(x,n);
  return 0;
}
