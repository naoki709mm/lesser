#include<stdio.h>

#define N 10
#define M 100
#define L 100

void s_gauss(double x[] ,double *a[] ,double b[] ,int n){
  int i,j,k;
  double mik;

  for(k=0 ;k<n-1 ;k++){
    for(i=k+1 ;i<n ;i++){
      mik=a[i][k]/a[k][k];
      for(j=k+1 ;j<n ;j++){
	a[i][j]-=mik*a[k][j];
      }
      b[i]-=mik*b[k];
    }
  }
  
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
  double a_b[N][N]={};
  double a[N][N]={};
  double x[N]={};
  double b[N]={};
  char f_name[M];
  char temp[L]={};
  FILE *fr;
  
  sprintf(f_name,"%s",argv[1]);
  
  if((fr=fopen(f_name,"r")) == NULL)
    printf("ファイルが開けません\n");
  else{
    fgets(temp,L,fr);
    for(i=0 ;i<L ;i++){
      if(temp[i]>='0' && temp[i]<='9'){
	x_n++;
      }
    }
    rewind(fr);
    
    i=0;
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

  sum=i;
  for(i=0 ;i<sum ;i++){
    for(j=0 ;j<x_n ;j++){
      if(j < x_n-1){
	a[i][j]=a_b[i][j];
      }
      else
	b[i]=a_b[i][j];
    }
  }
  
  for(i=0 ;i<sum ;i++){
    for(j=0 ;j<x_n ;j++){
      printf("%d ",a_b[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
