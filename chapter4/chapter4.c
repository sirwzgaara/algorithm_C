#include <stdio.h>
#include <stdlib.h>

#ifdef pseudocode
/* 树的儿子兄弟表示法 */
typedef struct TreeNode *PtrToNode

struct TreeNode
{
	ElemenType Element;
	PtrToNode FirstChild;
	PtrToNode NextSibling;
};

/* 先序遍历打印目录树结构 */
static void ListDir(DirectoryOrFile D, int Depth)
{
	if (D is a legitimate entry)
	{
		PrintName(D, Depth);
		if (D is a directory)
			for each child, C of D
				ListDir(C, Depth + 1)
	}
}

void ListDirectory(DirectoryOrFile D)
{
	ListDir(D, 0);
}

/* 后序遍历获取目录文件大小 */
static void Sizedirectory(DirectoryOrFile D)
{
	int TotalSize;
	
	TotalSize = 0;
	if (D is a legitiate entry)
	{
		TotalSize = FileSize(D);
		if (D is a directory)
			for each child, C of D
				TotalSize += SizeDirectory(C);
	}
}

#endif

/* 二叉树 */
#ifdef BINARY_TREE

typedef struct TreeNode *PtrToNode;
typedef struct PtrToNode Tree;

struct TreeNode
{
	Element Element;
	Tree Left;
	Tree Right;
};

#endif

/* 二叉查找树 */
#ifdef BINARY_SEARCH_TREE

struct TreeNode;
typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

struct TreeNode
{
	ElementType X;
	Position Left;
	Position Right;
};

/* 销毁一个树中所有节点内存 */
SearchTree MakeEmpty(SearchTree T)
{
	if (T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (NULL == T)
		return NULL;
	else if (X < T->X)
		return Find(T->Left);
	else if (X > T->X)
		return Find(T->Right);
	else
		return T;
}

/* 递归实现查找最小值 */
Position FindMin(SearchTree T)
{
	/* 只有根需要判断本节点是否非空，这个判断可以优化 */
	if (NULL == T)
		return NULL;
	else if (NULL == T->Left)
		return T;
	else
		return FindMin(T->Left);
}

/* 非递归实现 */
Position FindMax(SearchTree T)
{
	if (T != NULL)
		while (T->Right)
			T = T->Right;

	return T;
}

/* 简单插入，不考虑重复的问题，实际应用中也不会重复 */
SearchTree Insert(ElementType X, SearchTree T)
{
	if (NULL == T)
	{
		T = malloc(sizeof(struct TreeNode));
		if (NULL == T)
			FatalError("Out of space");
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
		T->Left = Insert(X, T->Left);
	else if (X > T->Element)
		T->Right = Insert(X, T->Right);

	return T;
}

SearchTree Delete(Element X, SearchTree T)
{
	Position TmpCell;

	if (NULL == T)
		Error("Element not found");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else if (T->Left && T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (NULL == T->Left)
			T = T->Right;
		else if (NULL == T->Right)
			T = T->Left;
		free(TmpCell);
	}

	return T;
}

#endif
int main()
{
	return 1;
}
