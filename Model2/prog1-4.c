#include<stdio.h>
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

int check(int i,int j,int Q[N][N],int n){/*マス(i,j)に対して縦、横、ななめに他のクイーンがいないか調べ、そのクイーンの数を返す関数*/
  int x=i-1,y_up=j-1,y_down=j+1; /*xが左y_upが上をy_downが下を探索*/
  int sum=0; /*クイーンの数*/

  while(x>=0){  /*xが一番左に行くまで探索*/
    if(Q[x][j]==1) /*左にクイーンを見つけるとクイーンの数を増やす*/
      sum++;
    if(y_up>=0){
      if(Q[i][y_up]==1) /*上下にクイーンを見つけるとクイーンの数を増やす*/
	sum++;
      if(Q[x][y_up]==1){
	sum++;  /*左上にクイーンを見つけるとクイーンの数を増やす*/ 
      }
    }
    if(y_down<n){
      if(Q[i][y_down==1])
	sum++;
      if(Q[x][y_down]==1)
	sum++;  /*左下にクイーンを見つけるとクイーンの数を増やす*/
    }
    x--;
    y_up--;  /*それぞれの探索位置を１つ更新する*/
    y_down++;
  }
  return sum;
}

void format(int Q[N][N],int P[N],int n){ /*配列Qと配列Pの要素の初期化を行う関数*/
  int x,y;
  for(x=0;x<n;x++){
    for(y=0;y<n;y++){
      Q[x][y]=0;
    }
    P[x]=0;
  }
}

int main(void){
  int n,n_Max,n_min;
  int x,y;
  int Q[N][N]; /*クイーンの配置を保存。あるなら1、ないなら2となる*/
  int P[N]; /*行でのクイーンの位置を保存*/
  int flag=1; /*探索が進んでいるか戻っているかを判定する*/
  int sum;
  int SE[N]; /*探索回数を保存*/

  printf("nの初期値を入力:");
  scanf("%d",&n_min);
  printf("nをどこまでに設定しますか:");
  scanf("%d",&n_Max);

  for(n=n_min;n<n_Max+1;n++){
    format(Q,P,n); /*配列Q、配列Pを0で初期化*/
    x=0; /*配列Qの行を示すxを0で初期化*/
    SE[n]=1;
    while(x<n){ /*行xが指定した行nになるまでループ*/
      for(y=P[x];y<n;y++){ /*列yを配列Pの値から探索*/
	sum=check(x,y,Q,N);
	if(sum==0){ /*マス(x,y)が他のクイーンと重なっていない時、そこにクイーンを置く*/
	  Q[x][y]=1;
	  P[x]=y; /*クイーンをおいた位置を保存*/
	  break; /*次の行へ*/
	}
      }


      if(y==n && Q[x][n-1]==0){ /*その行にクイーンが置けない時以下を実行*/
	P[x]=0; /*その行の配列Pを初期化*/
	y=P[--x]; /*一つ前のクイーンがある列をyに代入*/
	Q[x][y]=0; /*一つ前のクイーンを除去*/
	P[x]++; /*一つ前のクイーンの探索開始位置を一つ上げる*/
	if(flag==1) /*探索が帰り始めると探索回数を１プラスする*/
	  SE[n]++;
	flag=-1; /*flagに-1を代入して探索が戻り中とする*/
      }
      else{
	x++;
	flag=1; /*flagに1を代入して探索が進み中とする*/
      }
    }

    print_queens(Q,n);
    printf("%d×　%d\n",n,n);
    
  }

  for(x=n_min;x<n;x++){
    printf("%d,%d \n",x,SE[x]);
  }
    
    return 0;
}
