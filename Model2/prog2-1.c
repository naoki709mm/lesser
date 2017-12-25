#include <stdio.h>
#define N 20

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
	  W[i][j][k][l]=delta(i,k)*(1-delta(j,l))+delta(j,l)*(1-delta(i,k));
	  W[i][j][k][l]+=delta(i+j,k+l)*(1-delta(i,k));
	  W[i][j][k][l]+=delta(i-j,k-l)*(1-delta(i,k));
	}
      }
    }
  }
}

/*doule energy(int x[N][N],double W[N][N][N][N],int n){
  double E=0.0;
*/

int main(void){
  double W[N][N][N][N]={0};
  int x[N][N]
  
