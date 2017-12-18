#include <stdio.h>
#define N 50

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
  

doule energy(int x[N][N],double W[N][N][N][N],int n){
  double E=0.0;
