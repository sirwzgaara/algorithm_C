
#ifdef _cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode * PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

/* 为了保证接口一致，使用这个方法 */
#define Insert(X, H) (H = Insert1((X), H))
#define DeleteMin(H) (H = DeleteMin1(H))
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int npl;
};

/* 交换H的左右子树 */
static void SwapChildren(PriorityQueue H)
{
    PriorityQueue Tmp;
    Tmp = H->Left;
    H->Left = H->Right;
    H->Right = Tmp;
}

/* 合并左式树核心例程 */
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    /* 递归终止条件，此时H1是一个没有儿子的节点 */
    if (!H1->Left)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->npl < H1->Right->npl)
            SwapChildren(H1);
        H1->npl = H1->Right->npl + 1;
    }

    return H1;
}

/* 左式树合并外部接口 */
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if (!H1)
        return H2;
    if (!H2)
        return H1;

    /* 用这个方法保证小的根在第一个参数 */
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}

/* 左式树插入，创建一个单节点和H合并，H可以是空 */
PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode));
    SingleNode->Element = X;
    SingleNode->Left = SingleNode->Right = NULL;
    SingleNode->npl = 0;
    H = Merge(SingleNode, H);
    return H;
}

/* 左式树合并，删除根，将左右子树合并 */
PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue Left, Right;

    if (!H)
        return NULL;

    Left = H->Left;
    Right = H->Right;
    free(H);
    return Merge(Left, Right);
}

void main()
{

}

#ifdef _cplusplus
}
#endif

