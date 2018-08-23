
#ifdef _cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

struct Node
{
	ElementType Element;
	Position Next;
};


int IsEmpty(List L)
{
	return NULL == L->Next;
}

int IsLast(Position P)
{
	return NULL == P->Next;
}

Position Find(ElementType X, List L)
{
	Position P = L->Next;

	while (P && P->Element != X)
		P = P->Next;

	return P;
}

Position FindPrevious(ElementType X, List L)
{
	Position P = L;

	while (P->Next && P->Next->Element != X)
		P = P->Next;

	return P;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);

	if (!IsLast(P))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void Insert(ElementType X, Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (NULL == TmpCell)
		return;

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;

	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}


void main()
{
}




#ifdef _cplusplus
}
#endif
