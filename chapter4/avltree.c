
#include <stdio.h>

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

AvlTree MakeEmpty(AvlTree T)
{
	if (T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, AvlTree T)
{
	if (!T)
		return NULL;

	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

Position FindMin(AvlTree T)
{
	if (!T)
		return NULL;
	if (T->Left)
		return FindMin(T->Left);
	else
		return T;
}

Position FindMax(AvlTree T)
{
	if (T)
	{
		while (T->Right)
			T = T->Right;
	}
	return T;
}

static int Height(Position P)
{
	if (!P)
		return -1;
	else
		return P->Height;
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (!T)
	{
		T = malloc(sizeof(struct AvlNode));
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
		}
	}
	else if (X > T->Element)
	{
	}
}
