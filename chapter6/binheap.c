
#ifdef _cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType * Elements;
};

int IsEmpty(PriorityQueue H)
{
    return 0 == H->Size;
}

int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

/* 初始化优先队列，特定是有一个哑头，是一个比所有元素都小的元素 */
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxElements + 1)* sizeof(ElementType));
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = 0x80000000;

    return H;
}

/* 空穴上冒法 */
void Insert(ElementType X, PriorityQueue H)
{
    int i;

    if (IsFull(H))
        return;

    for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}

/* 下滤法 */
ElementType DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;

    if (IsEmpty(H))
        return H->Elements[0];

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for (i = 1; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        /* 在两个儿子中找较小的 */
        if (Child < H->Size && H->Elements[Child] > H->Elements[Child + 1])
            ++Child;

        /* 若最后一个元素比较小的儿子都小，那么可以结束了，否则继续下滤 */
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;

    return MinElement;
}

/* 将位置为t的节点的值降低X */
void DecreaseKey(int t, ElementType X, PriorityQueue H)
{
    int i, newElement = H->Elements[t] - X;
    for (i = t; H->Elements[i / 2] > newElement; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = newElement;
}

/* 将位置为t的节点的值增加X */
void IncreaseKey(int t, ElementType X，PriorityQueue H)
{
    int i, Child;
    int newElement = H->Elements[t] - X;

    for (i = t; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child < H->Size && H->Elements[Child] > H->Elements[Child + 1])
            ++Child;
        if (newElement > H->Elements[Child])
            H->Elements[i]= H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = newElement;
}

/* 删除位置为t的节点，先上浮到跟，然后deletemin */
void Delete(int t, PriorityQueue H)
{
    DecreaseKey(t, 0x7fffffff, H);
    DeleteMin(H);
}

/* 将位置t的节点下滤到合适的位置，是BuildHeap的辅助函数 */
void PercolateDown(int t, PriorityQueue H)
{
    int i, Child;
    int Element = H->Elements[t];

    for (i = t; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child < H->Size && H->Elements[Child] > H->Elements[Child + 1])
            ++Child;
        if (Element > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = Element;
}

/* 将一个数组中的内容读取到优先队列 */
PriorityQueue BuildHeap(ElementType *a, int N)
{
    int i;
    PriorityQueue H = initialize(N);

    /* 将数字先全部插进去 */
    for (i = 0; i < N; i++)
        H->Elements[i + 1] = a[i];

    /* 从中间的位置开始下滤，也就是倒数第二层 */
    for (i = N / 2; i > 0; i /= 2)
        PercolateDown(i, H);
}

void main()
{

}

#ifdef _cplusplus
}
#endif

