#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define T 400
#define X_START 0
#define X_END 20000
int main(int argc,char *argv[]){
  FILE *fr;
  FILE *fw;
  FILE *gp;
  int i=0,j,k;
  int delta_T=T;
  float x[20000]={};
  float a[20000]={};
  char y[20000]={};
  char filename[100];
  
  if((fr=fopen(argv[1],"r"))==NULL)
    printf("エラー\n");
  else{
    sprintf(filename,"EMG-%s",argv[1]);
    if((fw=fopen(filename,"w"))==NULL)
      printf("エラー\n");
    else{
      while(fscanf(fr,"%s",y)!=EOF){
	x[i]=fabsf(atof(y));
	i++;
      }
      fclose(fr);
      for(j=delta_T/2;j<i-(delta_T/2);j++){
	for(k=-delta_T/2;k<delta_T/2;k++){
	  a[j]+=x[j+k];
	}
	a[j]/=delta_T;
      }
      for(i=delta_T/2;i<j;i++){
	fprintf(fw,"%lf %lf\n",0.001*i,a[i]);
      }
      fclose(fw);
    }
  }
  return 0;
}
