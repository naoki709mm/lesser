#include<stdio.h>
#include<stdlib.h>
#define N 10000
int main(int argc,char *argv[]){
  int i,j=0,k=0;
  int sample;
  int mark;
  int num=0;
  int dim;
  int sean;
  double s[10];
  double x[N][10]={},y[N][10]={};
  double time;
  FILE *fr;
  FILE *fw[10];
  char filename[100];
  char temp[100];
  sample=atoi(argv[1]);
  time=1/(float)sample;
  mark=atoi(argv[2]);
  if((fr=fopen(argv[3],"r"))==NULL){
    printf("ファイルを開けませんでした\n");
    return -1;
  }
  for(i=0;i<mark;i++){
    sprintf(filename,"%d-%s",i+1,argv[3]);
    if((fw[i]=fopen(filename,"w"))==NULL){
      printf("%d-%sを開けませんでした\n",i,argv[3]);
      return -1;
    }
  }
  
  fscanf(fr,"%s\n",temp);
  for(i=0;i<100;i++){
    if(temp[i]==',')
      num++;
  }
  
  dim=(num-1)/mark;
  
  rewind(fr);
  while(!feof(fr)){
    for(i=0;i<2+dim*mark;i++){
      if(i==0){
	fscanf(fr,"%d,",&sean);
      }
      else if(i==1){
	fscanf(fr,"%lf,",&s);
      }
      else if(i>=2 && i<2+mark){
	fscanf(fr,"%lf,",&x[j][i-2]);
      }
      else if(i>=2+mark && i<1+2*mark){
	fscanf(fr,"%lf,",&y[j][i-2-mark]);
      }
      else{
	fscanf(fr,"%lf\n",&y[j][i-2-mark]);
      }
    }
    j++;
  }
  
  for(j=0;j<sean;j++){
    for(i=0;i<mark;i++){
      fprintf(fw[i],"%6.3f,%6.2f,%6.2f\n",j*time,x[j][i],y[j][i]);
    }
  }
  
  fclose(fr);
  for(i=0;i<mark;i++){
    fclose(fw[i]);
  }
  
  return 0;
}
