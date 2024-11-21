Q1 BFS
#include <bits/stdc++.h>
using namespace std;
 
void bfs(vector<vector<int>> &graph, int start) {
   int n = graph.size();
   vector<bool> visited(n, false);
   queue<int> q;
 
   q.push(start);
   visited[start] = true;
 
   cout << "BFS: ";
   while (!q.empty()) {
       int node = q.front();
       q.pop();
       cout << node << " ";
       for (int neighbor : graph[node]) {
           if (!visited[neighbor]) {
               visited[neighbor] = true;
               q.push(neighbor);
           }
       }
   }
   cout << endl;
}
 
int main() {
   int n, m;
   cout << "Enter the number of nodes and edges: ";
   cin >> n >> m;
 
   vector<vector<int>> graph(n);
   cout << "Enter edges (u v):\n";
   for (int i = 0; i < m; ++i) {
       int u, v;
       cin >> u >> v;
       graph[u].push_back(v);
       graph[v].push_back(u); // Remove for directed graph
   }
 
   int start;
   cout << "Enter the starting node for BFS: ";
   cin >> start;
 
   bfs(graph, start);
 
   return 0; }
Q2 DFS
#include <bits/stdc++.h>
using namespace std;
 
void dfsUtil(int node, vector<vector<int>> &graph, vector<bool> &visited) {
   visited[node] = true;
   cout << node << " ";
   for (int neighbor : graph[node]) {
       if (!visited[neighbor]) {
           dfsUtil(neighbor, graph, visited);
       }
   }
}
 
void dfs(vector<vector<int>> &graph, int start) {
   int n = graph.size();
   vector<bool> visited(n, false);
   cout << "DFS: ";
   dfsUtil(start, graph, visited);
   cout << endl;
}
 
int main() {
   int n, m;
   cout << "Enter the number of nodes and edges: ";
   cin >> n >> m;
 
   vector<vector<int>> graph(n);
   cout << "Enter edges (u v):\n";
   for (int i = 0; i < m; ++i) {
       int u, v;
       cin >> u >> v;
       graph[u].push_back(v);
       graph[v].push_back(u); // Remove for directed graph
   }
 
   int start;
   cout << "Enter the starting node for DFS: ";
   cin >> start;
 
   dfs(graph, start);
 
   return 0;
}
 
 
 
 
Q3 PRIM ALOG
#include <bits/stdc++.h>
using namespace std;
 
void primMST(vector<vector<pair<int, int>>> &graph) {
   int n = graph.size();
   vector<int> parent(n, -1), key(n, INT_MAX);
   vector<bool> inMST(n, false);
 
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
   pq.push({0, 0}); // Weight, Node
   key[0] = 0;
 
   while (!pq.empty()) {
       int u = pq.top().second;
       pq.pop();
 
       inMST[u] = true;
 
       for (auto &[v, weight] : graph[u]) {
           if (!inMST[v] && weight < key[v]) {
               key[v] = weight;
               pq.push({key[v], v});
               parent[v] = u;
           }
       }
   }
 
   cout << "Prim's MST:" << endl;
   for (int i = 1; i < n; ++i) {
       cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")" << endl;
   }
}
 
int main() {
   int n, m;
   cout << "Enter the number of nodes and edges: ";
   cin >> n >> m;
 
   vector<vector<pair<int, int>>> graph(n);
   cout << "Enter edges (u v w):\n";
   for (int i = 0; i < m; ++i) {
       int u, v, w;
       cin >> u >> v >> w;
       graph[u].emplace_back(v, w);
       graph[v].emplace_back(u, w); // Remove for directed graph
   }
 
   primMST(graph);
 
   return 0;
}
 
Q4 DIJKSTRA ALOG
#include <bits/stdc++.h>
using namespace std;
 
void dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
   int n = graph.size();
   vector<int> dist(n, INT_MAX);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
 
   dist[start] = 0;
   pq.push({0, start}); // Distance, Node
 
   while (!pq.empty()) {
       int u = pq.top().second;
       pq.pop();
 
       for (auto &[v, weight] : graph[u]) {
           if (dist[u] + weight < dist[v]) {
               dist[v] = dist[u] + weight;
               pq.push({dist[v], v});
           }
       }
   }
 
   cout << "Dijkstra's shortest paths from node " << start << ":\n";
   for (int i = 0; i < n; ++i) {
       cout << "Node " << i << " Distance: " << dist[i] << endl;
   }
}
 
int main() {
   int n, m;
   cout << "Enter the number of nodes and edges: ";
   cin >> n >> m;
 
   vector<vector<pair<int, int>>> graph(n);
   cout << "Enter edges (u v w):\n";
   for (int i = 0; i < m; ++i) {
       int u, v, w;
       cin >> u >> v >> w;
       graph[u].emplace_back(v, w);
       graph[v].emplace_back(u, w); // Remove for directed graph
   }
 
   int start;
   cout << "Enter the starting node for Dijkstra: ";
   cin >> start;
 
   dijkstra(graph, start);
 
   return 0;
}
 
Q5 ALL IN ONE
#include <bits/stdc++.h>
using namespace std;
 
void bfs(vector<vector<pair<int, int>>> &graph, int start) {
   int n = graph.size();
   vector<bool> visited(n, false);
   queue<int> q;
 
   q.push(start);
   visited[start] = true;
 
   cout << "BFS: ";
   while (!q.empty()) {
       int node = q.front();
       q.pop();
       cout << node << " ";
       for (auto &[neighbor, weight] : graph[node]) {
           if (!visited[neighbor]) {
               visited[neighbor] = true;
               q.push(neighbor);
           }
       }
   }
   cout << endl;
}
 
void dfsUtil(int node, vector<vector<pair<int, int>>> &graph, vector<bool> &visited) {
   visited[node] = true;
   cout << node << " ";
   for (auto &[neighbor, weight] : graph[node]) {
       if (!visited[neighbor]) {
           dfsUtil(neighbor, graph, visited);
       }
   }
}
 
void dfs(vector<vector<pair<int, int>>> &graph, int start) {
   int n = graph.size();
   vector<bool> visited(n, false);
   cout << "DFS: ";
   dfsUtil(start, graph, visited);
   cout << endl;
}
 
void primMST(vector<vector<pair<int, int>>> &graph) {
   int n = graph.size();
   vector<int> parent(n, -1), key(n, INT_MAX);
   vector<bool> inMST(n, false);
 
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
   pq.push({0, 0}); // Weight, Node
   key[0] = 0;
 
   while (!pq.empty()) {
       int u = pq.top().second;
       pq.pop();
 
       inMST[u] = true;
 
       for (auto &[v, weight] : graph[u]) {
           if (!inMST[v] && weight < key[v]) {
               key[v] = weight;
               pq.push({key[v], v});
               parent[v] = u;
           }
       }
   }
 
   cout << "Prim's MST:" << endl;
   for (int i = 1; i < n; ++i) {
       cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")" << endl;
   }
}
 
void dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
   int n = graph.size();
   vector<int> dist(n, INT_MAX);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
 
   dist[start] = 0;
   pq.push({0, start}); // Distance, Node
 
   while (!pq.empty()) {
       int u = pq.top().second;
       pq.pop();
 
       for (auto &[v, weight] : graph[u]) {
           if (dist[u] + weight < dist[v]) {
               dist[v] = dist[u] + weight;
               pq.push({dist[v], v});
           }
       }
   }
 
   cout << "Dijkstra's shortest paths from node " << start << ":\n";
   for (int i = 0; i < n; ++i) {
       cout << "Node " << i << " Distance: " << dist[i] << endl;
   }
}
 
int main() {
   int n, m;
   cout << "Enter the number of nodes and edges: ";
   cin >> n >> m;
 
   vector<vector<pair<int, int>>> graph(n);
   cout << "Enter edges (u v w) (0-indexed):\n";
   for (int i = 0; i < m; ++i) {
       int u, v, w;
       cin >> u >> v >> w;
       graph[u].emplace_back(v, w);
       graph[v].emplace_back(u, w); // Remove for directed graph
   }
 
   int start;
   cout << "Enter the starting node for BFS, DFS, and Dijkstra: ";
   cin >> start;
 
   bfs(graph, start);
   dfs(graph, start);
   primMST(graph);
   dijkstra(graph, start);
 
   return 0;
}
 
 