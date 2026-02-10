#include <stdio.h>
#include <limits.h>

int n;
int graph[10][10];
int dist[10];
int visited[10];

int minDistance()
{
    int min = INT_MAX;
    int index = -1;
    int i;

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int src)
{
    int i, count, u, v;

    for (i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < n - 1; count++)
    {
        u = minDistance();
        visited[u] = 1;

        for (v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("%d %d\n", i, dist[i]);
}

int main()
{
    int i, j, src;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    scanf("%d", &src);

    dijkstra(src);

    return 0;
}
