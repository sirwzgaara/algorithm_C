
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

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

/* 封装一个返回节点高度的函数，不用费心处理空指针的情况 */
static int Height(Position P)
{
	if (!P)
		return -1;
	else
		return P->Height;
}

static int Max(int a, int b)
{
	return a > b ? a : b;
}

static void updateHeight(Position P)
{
	P->Height = Max(Height(P->Left), Height(P->Right)) + 1;
}

/* 所有旋转函数中的空指针由外界保证 */
static Position SingleRotateWithLeft(Position K2)
{
	Position K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	updateHeight(K2);
	updateHeight(K1);
	return K1;
}

static Position SingleRotateWithRight(Position K1)
{
	Position K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;
	updateHeight(K2);
	updateHeight(K1);
	return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}

AvlTree Insert(ElementType X, AvlTree T)
{
	/* 递归终止条件，创建节点并返回 */
	if (!T)
	{
		T = malloc(sizeof(struct AvlNode));
		T->Left = T->Right = NULL;
		T->Element = X;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X < T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	else
	{
	}
	updateHeight(T);
	return T;
}


int main()
{
	return 1;
}
