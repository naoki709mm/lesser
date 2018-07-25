#include<stdio.h>

#define N 10
#define M 100
#define L 100

void intlz_lu(int n ,double a[][N] ,double l[][N] ,double u[][N]){
  int i,j;
  
  for(i=0 ;i<n ;i++){
    for(j=0 ;j<n ;j++){
      u[i][j]=a[i][j];
    }
  }
  
  for(i=0 ;i<n ;i++){
    for(j=0 ;j<n ;j++){
      if(i == j)
	l[i][j]=1.0;
      else
	l[i][j]=0.0;
    }
  }
}

void lu(int n ,double a[][N] ,double l[][N] ,double u[][N]){
  int i,j,k;
  double mik;
  
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

int main(int argc ,char *argv[]){
  int i,j;
  int sum=0;
  int x_n=0;
  double a[N][N];
  double l[N][N],u[N][N];
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
	  fscanf(fr,"%lf",&a[i][j]);
	else
	  fscanf(fr,"%lf\n",&a[i][j]);
      }
      i++;
    }
    fclose(fr);
  }
  
  sum=i;
  printf("A=\n");
  for(i=0 ;i<sum ;i++){
    for(j=0 ;j<x_n ;j++){
      printf(" %5.2f ",a[i][j]);
    }
    printf("\n");
  }
  
  intlz_lu(sum,a,l,u);
  lu(sum,a,l,u);
  
  printf("\nL=\n");
  for(i=0 ;i<sum ;i++){
    for(j=0 ;j<x_n ;j++){
      printf(" %5.2f ",l[i][j]);
    }
    printf("\n");
  }
  
  printf("\nU=\n");
  for(i=0 ;i<sum ;i++){
    for(j=0 ;j<x_n ;j++){
      printf(" %5.2f ",u[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
