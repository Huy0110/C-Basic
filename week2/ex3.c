#include <stdio.h>

int main()
{
  FILE *fptr1,*fptr2;
  char str[100];
  fptr1=fopen("lab1.txt","r");
  fptr2=fopen("lab1a.txt","w+");
  while(!feof(fptr1))
    {
      fread(str,sizeof(char),100,fptr1);
      fwrite(str,sizeof(char),100,fptr2);
    }
  fclose(fptr1);
  fclose(fptr2);
}
