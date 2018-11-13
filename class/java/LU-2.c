//LU分解からxを求める

#include<stdio.h>

#define N 10
#define M 100
#define L 100

//LU分解をするの関数
void lu(int n ,double a[][N] ,double l[][N] ,double u[][N]){
  int i,j,k;
  double mik;

  //U行列にA行列の値を代入
  for(i=0 ;i<n ;i++){
    for(j=0 ;j<n ;j++){
      u[i][j]=a[i][j];
    }
  }

  //L行列を単位行列で初期化
  for(i=0 ;i<n ;i++){
    for(j=0 ;j<n ;j++){
      if(i == j)
	l[i][j]=1.0;
      else
	l[i][j]=0.0;
    }
  }
  
  //LU分解
  for(k=0 ;k<n-1 ;k++){
    for(i=k+1 ;i<n ;i++){
      mik=u[i][k]/u[k][k];
      l[i][k]=mik;
      u[i][k]=0.0;
      for(j=k+1 ;j<n ;j++){
	u[i][j]-=mik*u[k][j];
      }
    }
  }
}

//LU分解後のLと行列bから行列yを求める
void f_gauss(int n ,double y[] ,double a[][N] ,double b[]){
  int i,j;

  //ガウスの前進代入
  for(i=0 ;i<n ;i++){
    y[i]=b[i];
    for(j=0 ;j<i ;j++){
      y[i]-=a[i][j]*y[j];
    }
    y[i]/=a[i][i];
  }
}

//LU分解後の行列Uと行列yから答えの行列xをもとめる
void r_gauss(int n ,double x[] ,double a[][N] ,double b[]){
  int i,j;

  //ガウスの後退代入
  for(i=n-1 ;i>=0 ;i--){
    x[i]=b[i];
    for(j=i+1 ;j<n ;j++){
      x[i]-=a[i][j]*x[j];
    }
    x[i]/=a[i][i];
  }
}

int main(int argc ,char *argv[]){
  int i,j;
  int sum=0;
  int x_n=0;
  double a_b[N][N];
  double a[N][N],b[N];
  double l[N][N],u[N][N];
  double x[N],y[N];
  char f_name[M];
  char temp[L]={};
  FILE *fr;

  sprintf(f_name,"%s",argv[1]);
  
  if((fr=fopen(f_name,"r")) == NULL)
    printf("ファイルが開けません\n");
  else{
    fgets(temp,L,fr); //一列目だけ読み込み、数字の数を数える
    for(i=0 ;i<L ;i++){
      if(temp[i]>='0' && temp[i]<='9'){
	x_n++;  //行列Aとbを並べた横の数字の数
      }
    }
    
    rewind(fr); //ファイルをもう一度最初から読み込む
    
    i=0;
    
    while(!feof(fr)){
      for(j=0 ;j<x_n ;j++){
	if(j < x_n-1)  //一列目の最後の値を読み込むときだけ改行も読み込む
	  fscanf(fr,"%lf",&a_b[i][j]);
	else
	  fscanf(fr,"%lf\n",&a_b[i][j]);
      }
      i++;
    }
    fclose(fr);
  }
  
  sum=i; //列数を格納

  //読み込んだ行列Aとbが複合された数列をaとbに分ける
  for(i=0 ;i<sum ;i++){
    for(j=0 ;j<x_n ;j++){
      if(j < x_n-1){
	a[i][j]=a_b[i][j];
      }
      else
	b[i]=a_b[i][j];
    }
  }
  
  printf("A=\n");
  for(i=0 ;i<sum ;i++){
    for(j=0 ;j<x_n-1 ;j++){
      printf(" %5.2f ",a[i][j]);
    }
    printf("\n");
  }
  
  printf("\nb=\n");
  for(i=0 ;i<sum ;i++){
    printf(" %5.2f \n",b[i]);
  }
  
  lu(sum,a,l,u);
  
  f_gauss(sum,y,l,b);
  
  r_gauss(sum,x,u,y);

  printf("\nx=\n");
  for(i=0 ;i<sum ;i++){
    printf(" %5.2f \n",x[i]);
  }
  
  return 0;
}
