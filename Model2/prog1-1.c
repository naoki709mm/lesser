#include<stdio.h>
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

int check(int i,int j,int Q[N][N],int n){/*マス(i,j)に対して縦、横、ななめに他のクイーンがいないか調べ、そのクイーンの数を返す関数*/
  int x,y;
  int sum=0; /*クイーンの数*/
  int P[N]={0}; /*クイーンが存在する列を保存*/

  for(x=0;x<i;x++){
    for(y=0;y<n;y++){
      if(P[y]==0){  /*クイーンが存在する列を除外*/
	if(x==i && y==j){} /*引数の(i,j)との重なりを除外*/
	else{
	  if(Q[x][y]==1){ /*クイーンを見つけた時に以下を実行*/
	    if(x==i || y==j) /*見つけたクイーンと(i,j)が同列、もしくは同行の場合重なっているクイーンの数をひとつ数える*/
	      sum++;
	    if(x+y==i+j || x-y==i-j) /*見つけたクイーンと(i,j)が斜めの関係にあるとき重なっているクイーンの数をひとつ数える*/
	      sum++;
	    P[y]=1; /*クイーンがいた列を保存*/
	    break; /*次の行へ*/
	  }
	}
      }
    }	  
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

int success(int Q[N][N],int n){ /*Nクイーン問題の解が求まったかを判定し求まっているなら0,求まっていないなら1を返す関数*/
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
  int x,y;
  int Q[N][N]; /*クイーンの配置を保存。あるなら1、ないなら2となる*/
  int P[N]; /*行でのクイーンの位置を保存*/
  int flag=1; /*探索が進んでいるか戻っているかを判定する*/
  int sum,sc;
  int se; /*探索回数を保存*/
  
  printf("nをどこまでに設定しますか:");
  scanf("%d",&i);

  for(n=4;n<i+1;n++){
    format(Q,P,n); /*配列Q、配列Pを0で初期化*/
    x=0; /*配列Qの行を示すxを0で初期化*/
    se=1; /*探索回数を1で初期化*/
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
	  se++;
	flag=-1; /*flagに-1を代入して探索が戻り中とする*/
      }
      else{
	x++;
	flag=1; /*flagに1を代入して探索が進み中とする*/
      }
    }

    print_queens(Q,n);
    sc=success(Q,n); /*success関数が0を返すと"成功"と表示、1を返すと"失敗と表示"*/
    printf("%d☓  %d ",n,n);
    if(sc==0)
      printf("成功\n");
    else
      printf("失敗\n");
    printf("探索回数:%d\n",se);
    
  }
    
    return 0;
}
