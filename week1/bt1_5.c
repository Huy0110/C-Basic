#include <stdio.h>
#include <string.h>

void ham(char *str, char c1,char c2)
{
  int i;
  int n=strlen(str);
  for(i=0;i<n;i++)
    if(*(str+i)==c1)
      *(str+i)=c2;
}

int main()
{
  char a[100];
  strcpy(a,"papa");
  ham(a,'p','m');
  printf("%s\n",a);
}
