
#ifdef _cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxTrees 16
#define Infinity 0x80000000

typedef int ElementType;

typedef struct BinNode * BinTree, * Position;
typedef struct Collection * BinQueue;

/* 二项队列单个节点，包含指向第一个儿子和兄弟的指针 */
struct BinNode
{
    ElementType Element;
    Position LeftChild;
    Position NextSibling;
};

/* 二项队列管理容器 */
struct Collection
{
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};

int IsEmpty(BinQueue H)
{
    return !(0 == H->CurrentSize);
}

BinQueue Initialize()
{
    BinQueue H = NULL;
    H = malloc(sizeof(struct Collection));
    memset(H, 0, sizeof(struct Collection));

    return H;
}

/* 合并两棵树，对于二项队列，T1和T2大小一定是一样的 */
BinTree CombineTrees(BinTree T1, BinTree T2)
{
    if (T1->Element > T2->Element)
        return CombineTrees(T2, T1);
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;

    return T1;
}

/* 合并两个二项队列,不能合并自己，否则还要处理 */
BinQueue Merge(BinQueue H1, BinQueue H2)
{
    BinTree T1, T2, Carry = NULL;
    int i, j;

    H1->CurrentSize += H2->CurrentSize;
    for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
    {
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];

        switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
        {
            /* 什么都没有或者只有T1，不用处理 */
            case 0:
            case 1:
                break;
            /* 只有T2，将T2移动到T1，清零T2 */
            case 2:
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 4:
                H1->TheTrees[i] = Carry;
                Carry = NULL;
                break;
            /* 若同时有T1和T2，进位到Carry */
            case 3:
                Carry = CombineTrees(T1, T2);
                H1->TheTrees[i] = NULL;
                H2->TheTrees[i] = NULL;
                break;
            case 5:
                Carry = CombineTrees(T1, Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6:
                Carry = CombineTrees(T2, Carry);
                H2->TheTrees[i] = NULL;
                break;
            /* 3个都有，保留Carry，再次将T1和T2进位 */
            case 7:
                H1->TheTrees[i] = Carry;
                Carry = CombineTrees(T1, T2);
                break;
        }
    }
}

/* 删除最小值并返回 */
ElementType DeleteMin(BinQueue H)
{
    int i, j;
    int MinTree;
    BinQueue DeletedQueue;
    Position DeletedTree, OldRoot;
    ElementType MinItem;

    /* 遍历所有格子找最小的根 */
    MinItem = Infinity;
    for (i = 0; i < MaxTrees; i++)
    {
        if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
        {
            MinItem = H->TheTrees[i]->Element;
            MinTree = i;
        }
    }

    /* 保存最小根的第一个左儿子并删除这个根 */
    DeletedTree = H->TheTrees[MinTree];
    OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free(OldRoot);

    /* 收集删除根后剩下的树，放到DeletedQueue中 */
    DeletedQueue = Initialize();
    DeletedQueue->CurrentSize = (1 << MinTree) - 1;
    for (j = MinTree - 1; j >= 0; j--)
    {
        DeletedQueue->TheTrees[j] = DeletedTree;
        DeletedTree = DeletedTree->NextSibling;
        DeletedQueue->TheTrees[j]->NextSibling = NULL;
    }

    H->TheTrees[MinTree] = NULL;
    H->CurrentSize -= DeletedQueue->CurrentSize + 1;

    /* 合并 */
    Merge(H, DeletedQueue);
    return MinItem;
}

void main()
{

}

#ifdef _cplusplus
}
#endif
