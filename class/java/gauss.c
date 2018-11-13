#include<stdio.h>

#define N 10
#define M 100
#define L 100

//ガウス消去法の関数
void s_gauss(int n ,double x[] ,double a[][N] ,double b[]){
  int i,j,k;
  double mik;

  //ガウスの前進消去
  for(k=0 ;k<n-1 ;k++){
    for(i=k+1 ;i<n ;i++){
      mik=a[i][k]/a[k][k];
      for(j=k+1 ;j<n ;j++){
	a[i][j]-=mik*a[k][j];
      }
      b[i]-=mik*b[k];
    }
  }

  //ガウスの後退代入
  for(k=n-1 ;k>=0 ;k--){
    x[k]=b[k];
    for(i=k+1 ;i<n ;i++){
      x[k]-=a[k][i]*x[i];
    }
    x[k]/=a[k][k];
  }
}

int main(int argc ,char *argv[]){
  int i,j,k;
  int x_n=0;
  int sum;
  double a_b[N][N];
  double a[N][N];
  double x[N];
  double b[N];
  char f_name[M];
  char temp[L]={};
  FILE *fr;

  //引数から取ったファイル名をf_nameに代入
  //ファイルには行列Aとbを複合した物を書き込んでおく
  sprintf(f_name,"%s",argv[1]);
  
  if((fr=fopen(f_name,"r")) == NULL)
    printf("ファイルが開けません\n");
  else{
    fgets(temp,L,fr); //ファイルの1行目だけ読み込み、数字の数を数える
    for(i=0 ;i<L ;i++){
      if(temp[i]>='0' && temp[i]<='9'){
	x_n++;
      }
    }
    
    rewind(fr); //もう一度1行目から読み込む
    
    i=0;

    //ファイルから値を読み込みそれぞれを配列a_bに代入
    while(!feof(fr)){
      for(j=0 ;j<x_n ;j++){
	if(j < x_n-1)
	  fscanf(fr,"%lf",&a_b[i][j]);
	else
	  fscanf(fr,"%lf\n",&a_b[i][j]);
      }
      i++;
    }
    fclose(fr);
  }

  //iの値は行数となるのでそれを変数sumに代入
  sum=i;

  //ファイルから読み込んだ値を行列Aとbに分け、それぞれ配列a,bに代入
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
    printf(" %5.2f\n",b[i]);
  }
  
  s_gauss(sum,x,a,b);
  
  printf("\nx=\n");
  for(i=0 ;i<sum ;i++){
    printf(" %5.2f\n",x[i]);
  }

  return 0;
}
