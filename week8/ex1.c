#include <stdio.h>
#include <stdlib.h>

typedef int elmType;
typedef struct nodeType
{
  elmType element;
  struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

void MakeNullTree (treetype *T)
{
  (*T)=NULL;
}

int EmptyTree(treetype T)
{
  return T==NULL;
}

treetype LeftChild(treetype n)
{
  if(n!=NULL) return n->left;
  else return NULL;
}

treetype RightChild(treetype n)
{
  if(n!=NULL) return n->right;
  else return NULL;
}

node_Type *creat_node(elmType NewData)
{
  node_Type *N;
  N=(node_Type*)malloc(sizeof(node_Type));
  if(N!=NULL)
    {
      N->left = NULL;
      N->right = NULL;
      N->element = NewData;
    }
  return N;
}

int IsLeaf(treetype n)
{
  if(n!=NULL)
    return (LeftChild(n)==NULL)&&(RightChild(n)==NULL);
  else return -1;
}

int nb_nodes(treetype T)
{
  if(EmptyTree(T)) return 0;
  else return 1+nb_nodes(LeftChild(T))+nb_nodes(RightChild(T));
}

treetype creatfrom2( elmType v, treetype l,treetype r)
{
  treetype N;
  N=(node_Type*)malloc(sizeof(node_Type));
  N->element = v;
  N->left=l;
  N->right = r;
  return N;
}

treetype Add_Left(treetype *Tree, elmType NewData)
{
  node_Type *NewNode = creat_node(NewData);
  if(NewNode==NULL) return NewNode;
  if(*Tree == NULL)
    *Tree = NewNode;
  else
    {
      node_Type *Lnode=*Tree;
      while (Lnode->left != NULL)
	Lnode=Lnode->left;
      Lnode->left=NewNode;
    }
  return NewNode;
}

treetype Add_Right(treetype *Tree, elmType NewData)
{
  node_Type *NewNode = creat_node(NewData);
  if(NewNode==NULL) return NewNode;
  if(*Tree == NULL)
    *Tree = NewNode;
  else
    {
      node_Type *Rnode=*Tree;
      while (Rnode->right != NULL)
	Rnode=Rnode->right;
      Rnode->right=NewNode;
    }
  return NewNode;
}

int soLa(treetype Tree)
{
  if(Tree==NULL) return 0;
  else
    if(IsLeaf(Tree)==1) return 1;
    else
      return soLa(LeftChild(Tree))+soLa(RightChild(Tree));
}

elmType  max( elmType a, elmType b)
{
  if(a>b) return a;
  else return b;
}

int chieuCao(treetype Tree)
{
  if(Tree==NULL) return 0;
  else
    if(IsLeaf(Tree)==1) return 1;
    else return max(chieuCao(LeftChild(Tree))+1,1+chieuCao(RightChild(Tree)));
}

int main()
{
  int i,n,m;
  elmType Data;
  treetype T;
  MakeNullTree(&T);
  printf("Nhap vao so nguyen n:");
  scanf("%d",&n);
  printf("Nhap vao so nguyen m:");
  scanf("%d",&m);
  for(i=0;i<n;i++)
    {
      printf("Nhap du lieu ben trai:");
      scanf("%d",&Data);
      Add_Left(&T,Data);
    }
  for(i=0;i<m;i++)
    {
      printf("Nhap du lieu ben phai:");
      scanf("%d",&Data);
      Add_Right(&T,Data);
    }
  printf("So luong nut la:%d\n",nb_nodes(T));
  printf("So la cua cay la:%d\n",soLa(T));
  printf("Chieu cao cua cay la:%d\n",chieuCao(T));
}
