#include<bits/stdc++.h>
using namespace std;

#define INF 1000000

void dijkstra(vector<pair<int, int>> adj[], int src, int V)
{
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<> > pq;

    vector<int> dist(V, INF);

    pq.emplace(0, src);
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main()
{
    int V = 5;
    vector<pair<int, int>> adj[V];

    adj[0].emplace_back(1, 2);
    adj[1].emplace_back(0, 2);

    adj[1].emplace_back(2, 3);
    adj[2].emplace_back(1, 3);

    adj[0].emplace_back(3, 6);
    adj[3].emplace_back(0, 6);

    adj[1].emplace_back(3, 8);
    adj[3].emplace_back(1, 8);

    adj[1].emplace_back(4, 5);
    adj[4].emplace_back(1, 5);

    adj[2].emplace_back(4, 7);
    adj[4].emplace_back(2, 7);

    adj[3].emplace_back(4, 9);
    adj[4].emplace_back(3, 9);

    dijkstra(adj, 0, V);

    return 0;
}
