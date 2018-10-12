
#include <stdio.h>

#ifdef persudo_code

typedef struct
{
    bool Known;
    int Dist;
    Vertex Path;
}Table;

/* 无权最短路径，简单的O(V^2)方法 */
void UnWeighted(Table T)
{
    int CurrDist;
    Vertex V, W;

    /* 遍历所有距离 */
    for (CurrDist = 0; CurrDist < NumVertex; CurrDist++)
        /* 遍历所有顶点 */
        for each vertex V
            /* 若一个顶点不是已经访问过的并且是当前距离 */
            if (!T[V].Known && T[V].Dist == CurrDist)
            {
                T[V].Known = True;
                /* 处理V的邻接顶点并记录路径 */
                for each W adjacent to V
                    if (T[W].Dist == Infinity)
                    {
                        T[W].Dist = CurrDist + 1;
                        T[W].Path = V;
                    }
            }
}

/* 使用队列改进的无权最短路径算法，时间是O(E+V) */
void Unweighted(Table T)
{
    Queue Q;
    Vertex V, W;

    /* 创建队列 */
    Q = CreateQueue(NumVertex);
    MakeEmpty(Q);

    /* 将单发点S入队 */
    Enqueue(S, Q);

    while (!IsEmpty(Q))
    {
        V = Dequeue(Q);
        T[V].Known = True;

        /* 遍历V的邻接顶点，根据距离判断之前是否访问过，若没有，那么入队列 */
        for each W adjacent to V
            if (T[W].Dist == Infinity)
            {
                T[W].Dist = T[V].Dist + 1;
                T[W].Path = V;
                Enqueue(W, Q);
            }
    }

    DisposeQueue(Q);
}

/* 赋值最短路径问题，dijkstra算法 */

typedef int Vertex;
struct TableEntry
{
    List Header;
    int Known;      //标记顶点是否已知
    DistType Dist;  //通过已知顶点从s到当前顶点的距离
    Vertex Path;
};

#define NotAVertex (-1)
typedef struct TableEntry Table[NumVertex];

/* 初始化表，Start是所求的源点 */
void InitTable(Vertex Start, Graph G, Table T)
{
    int i;
    /* 将图读入table中 */
    ReadGraph(G, T);
    for (i = 0; i < NumVertex; i++)
    {
        T[i].Known = False;
        T[i].Dist = Infinity;
        T[i].Path = NotAVertex;
    }
    T[Start].dist = 0;
}

/* 打印路径，是递归 */
void PrintPath(Vertex V, Table T)
{
    if (T[V].Path != NotAVertex)
    {
        PrintPath(T[V].Path, T);
        printf("to");
    }
    printf("%v", V);
}

/* dijkstra算法，使用优先队列，时间O(ElogV) */
void Dijkstra(Table T)
{
    Vertex V, W;

    for (;;)
    {
        /* 从未知顶点中选择一个路径最短的 */
        V = smallest unknown distance vertex;
        /* 没有这样的顶点，说明所有顶点都遍历到了，结束 */
        if (V == NotAVertex)
            break;
        /* 标记为已知 */
        T[V].Known = True;
        /* 遍历V的邻接顶点，更新距离信息 */
        for each W adjacent to V
            if (!T[W].Known)
                /* Cvw是从v到w的距离 */
                if (T[V].Dist + Cvw < T[W].Dist)
                {
                    Decrease(T[W].Dist to T[V].Dist + Cvw);
                    T[W].Path = V;
                }
    }
}

/* 有负值边的图，时间O(EV) */
void WeightedNegative(Table T)
{
    Queue Q;
    Vertex V, W;

    Q = CreateQueue(NumVertex);
    MakeEmpty(Q);
    Enqueue(S, Q);

    while (!IsEmpty(Q))
    {
        /* 每个顶点可以出队V次 */
        V = Dequeue(Q);
        for each W adjacent to V
            if (T[V].Dist + Cvw < T[W].Dist)
            {
                T[W].Dist = T[V].Dist + Cvw;
                T[W].Path = V;
                /* 这个可以用位图实现 */
                if (W is not already in Q)
                    Enqueue(W, Q);
            }
    }
    DisposeQueue(Q);
}

/* 无圈图，使用拓扑排序的思想，时间是O(E + V) */
void Acyclic(Table T)
{
    Queue Q;
    Vertex V, W;

    Q = CreateQueue(NumVertex);
    Q = MakeEmpty();

    Enqueue(S, Q);

    while (!IsEmpty(Q))
    {
        V = Dequeue(Q);
        for each W adjacent to V
            if (--Indegree[W] == 0)
            {
                Enqueue(W, Q);
                T[W].Path = V;
                T[W].Dist = T[V].Dist + Cvw;
            }
    }
    Dispose(Q);
}

#endif

void main()
{

}

