#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define Max 100
#define MaxDanhBa 100
#define SoLuong 10

typedef struct DanhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;

void SapXep(address List[],int size)
{
  int i,j;
  int n;
  address tmp;
  n=size;
  for(i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
	{
	  if(strcmp(List[i].name,List[j].name)>0)
	    {
	      tmp=List[i];
	      List[i]=List[j];
	      List[j]=tmp;
	    }
	}
    }
}

int binSearch(address List[],char *Target,int Size)
{
  int Mid,Lo=0,Hi=Size-1;
  while(Lo<=Hi)
    {
      Mid=(Lo+Hi)/2;
      if(strcmp(List[Mid].name,Target)==0)
	return Mid;
      else if(strcmp(Target,List[Mid].name)<0)
	Hi=Mid-1;
      else Lo=Mid+1;
    }
  return -1;
}

int main()
{
  address danhBa[MaxDanhBa];
  int i;
  int ViTri;
  char str[Max],ten[Max];
  FILE *fptr;
  fptr=fopen("danhBa.txt","r");
  for(i=0;i<SoLuong;i++)
    {
      fgets(str,100,fptr);
      fgets(danhBa[i].name,100,fptr);
      danhBa[i].name[strlen(danhBa[i].name)-1]='\0';
      //printf("\n%s: %ld\n",danhBa[i].name,strlen(danhBa[i].name));
      fgets(danhBa[i].tel,100,fptr);
      danhBa[i].tel[strlen(danhBa[i].tel)-1]='\0';
      fgets(danhBa[i].mail,100,fptr);
      danhBa[i].mail[strlen(danhBa[i].mail)-1]='\0';
    }
  printf("Ban muon tim ten nao:");
  __fpurge(stdin);
  gets(ten);
  // printf("%s:%ld\n",ten,strlen(ten));
  __fpurge(stdin);
  SapXep(danhBa,SoLuong);
  // for(i=0;i<SoLuong;i++)
  //printf("\n%s: %ld\n",danhBa[i].name,strlen(danhBa[i].name));
  
  ViTri=binSearch(danhBa,ten,SoLuong);
  if(ViTri==-1)
    printf("Not found\n");
  else
    {
      //printf("Ten o phan tu (co chi so mang gan nhat) thu a[%d]\n",ViTri);
      printf("Ten:%s\n",danhBa[ViTri].name);
      printf("So dien thoai:%s\n",danhBa[ViTri].tel);
      printf("Email:%s\n",danhBa[ViTri].mail);
       
    }
  
  fclose(fptr);
}
