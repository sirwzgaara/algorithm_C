
#include <stdio.h>

#ifdef persudo_code

/* 有向图拓扑排序，简单方法，时间O(V^2) */
void TopSort(Graph G)
{
    int Counter;
    Vertex V, W;

    for (Counter = 0; Counter < NumVertex; Counter++)
    {
        /* 找一个入度为0的顶点 */
        V = FindNewVertexOfIndreeZero();
        if (NotAVertex == V)
            break;

        /* 计数，用于打印 */
        TopNum[V] = Counter;
        /* 所有邻接顶点入度要减少 */
        for each W adjacent to V
            Indegree[W]--;
    }

    if (Counter != NumVertex)
        error("Graph has a cycle");
}

/* 使用队列改进的拓扑排序，时间O(V+E) */
void TopSort(Graph G)
{
    Queue Q;
    int Counter = 0;
    Vertex V, W;

    /* 创建一个队列 */
    Q = CreateQueue(NumVertex);
    MakeEmpty(Q);

    /* 将所有入度为0的顶点入队列，时间O(V) */
    for each vertex V
        if (0 == Indegree[V])
            Enqueue(V, Q);

    /* 循环读取队列，时间O(V+E) */
    while (!IsEmpty(Q))
    {
        /* 每个顶点出队一次，时间一共是O(V) */
        V = Dequeue(Q);
        TopNum[V] = ++Counter;

        /* 每条边处理一次，时间一共是O(E) */
        for each W adjacent to V
            if (--Indegree[W] == 0)
                Enqueue(W, Q);
    }

    if (Counter != NumVertex)
        error("Graph has a cycle");
    DisposeQueue(Q);
}

#endif

void main()
{

}

