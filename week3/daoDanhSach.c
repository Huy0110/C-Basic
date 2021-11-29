#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct _PointerType{
  ElementType Inf;
  struct _PointerType *Next;
};
typedef struct _PointerType PointerType;

PointerType *InsertMiddle(PointerType *Prev, ElementType X)
{
  PointerType *TempNode;
  
  TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = Prev->Next;
  Prev->Next = TempNode;
  
  return TempNode;
}

ElementType Delete(PointerType *Prev){
  ElementType X;
  PointerType *TempNode;
  
  TempNode = Prev->Next; Prev->Next = Prev->Next->Next;
  X = TempNode->Inf;
  free(TempNode);
  
  return X;
}

PointerType *InsertToHead(PointerType *First, ElementType X){
  PointerType *TempNode;
  
  TempNode = (PointerType *) malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = First;
  First = TempNode;
  
  return First;
}

PointerType *InsertToLast(PointerType *First, ElementType X){
  PointerType *NewNode; PointerType *TempNode;

  NewNode = (PointerType *)malloc(sizeof(PointerType));
  NewNode->Inf = X;NewNode->Next = NULL; 
  TempNode = First;
  
  while(TempNode->Next!=NULL)
    TempNode = TempNode->Next;
  
  TempNode->Next = NewNode;
  return First;
}

PointerType *DeleteHead(PointerType *First){
  PointerType *TempNode;
  
  TempNode = First->Next;
  free(First);
  
  return TempNode;
}

PointerType *DeleteLast(PointerType *First){
  PointerType *Temp1,*Temp2;
  Temp1 = First; Temp2 = First;
  
  while(Temp1->Next != NULL){
   Temp2 = Temp1;
   Temp1 = Temp1->Next;}
  
  Temp2->Next = NULL;
  free(Temp1);
  return First;
}

int IsEmpty(PointerType *First)
{
  return !First;
}

PointerType *MakeNull(PointerType *First)
{
  while(!IsEmpty(First))
   First=DeleteHead(First);
  return First;
}

void Print(PointerType *First){
  PointerType *TempNode;
  
  printf("%p ",First);
  TempNode = First;
  while(TempNode!=NULL){
   printf("%d:%p ",TempNode->Inf,TempNode->Next);
   TempNode = TempNode->Next;
  }
  printf("\n");
}

// Than chuong trinh chinh
int main(){
  PointerType *ds=NULL,*pv1=NULL,*pv2=NULL,*pv3=NULL;
    int i,p;
    for(i=0;i<10;i++)
      {
	ds=InsertToHead(ds,i);
      }
    pv1=ds;
    pv2=pv1->Next;
    pv1->Next=NULL;
    pv3=pv1;
    while(pv2->Next!=NULL)
      {
	pv1=pv2;
	pv2=pv2->Next;
	pv1->Next=pv3;
	pv3=pv1;
      }
    pv2->Next=pv3;
    ds=pv2;

    Print(ds);
    return 0;
}
