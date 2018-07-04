#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
  FILE *fr;
  FILE *fw;
  int i=0,j=0;
  double x=0;
  double y;
  char filename[100];

  if((fr=fopen(argv[1],"r"))==NULL)
    printf("エラー\n");
  else{
    sprintf(filename,"AVE-%s",argv[1]);
    if((fw=fopen(filename,"w"))==NULL)
      printf("エラー\n");
    else
      while(fscanf(fr,"%lf\n",&y)!=EOF){
	x+=y;
	j++;
	if(j==5){
	  x/=j+1;
	  fprintf(fw,"%lf\n",x);
	  i++;
	  j=0;
	  x=0;
	}
      }
  }
  return 0;
}
