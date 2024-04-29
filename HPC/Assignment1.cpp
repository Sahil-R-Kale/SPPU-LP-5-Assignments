#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

const int MAX = 1000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) {
	stack<int> s;
	s.push(node);
	visited[node]=true;
	while (!s.empty()) {
    	int curr_node = s.top();
    	s.pop();
	    cout<<curr_node<<" ";
        #pragma omp parallel for
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int adj_node = graph[curr_node][i];
            if (!visited[adj_node]) {
            	s.push(adj_node);
				visited[adj_node]=true;
            }
        }
	}
}

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node]=true;
	while (!q.empty()) {
    	int curr_node = q.front();
    	q.pop();
	    cout<<curr_node<<" ";
        #pragma omp parallel for
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int adj_node = graph[curr_node][i];
            if (!visited[adj_node]) {
            	q.push(adj_node);
				visited[adj_node]=true;
            }
        }
	}
}

int main() {
	int n, m, start_node;
	cout<<"Enter no. of vertices in graph: ";
	cin >> n;
    cout<<"Enter no. of edges in graph: ";
	cin >> m;
	for (int i = 0; i < m; i++) {
    	int u, v;
        cout<<"Enter starting and ending vertex (0 to "<<n-1<<") of edge "<<i+1<<": ";
    	cin >> u >> v;
		while(u<0 || v<0 || u>n-1 || v>n-1){
			cout<<"Invalid input. Enter starting and ending vertex (0 to "<<n-1<<") of edge "<<i+1<<": ";
    		cin >> u >> v;
		}
    	graph[u].push_back(v);
    	graph[v].push_back(u);
	}
    while(true){
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                if(j!=i)
                    graph[i].push_back(j);
            }
        }
        for (int i = 0; i < 100; i++) {
                visited[i] = false;
            }
        dfs(0);
        bfs(0);
    //     cout<<"\n---------Menu----------\n1.DFS\n2.BFS\n3.Exit\nEnter choice: ";
    //     int cho;cin>>cho;
    //     switch(cho){
    //         case 1:
    //             #pragma omp parallel for
    //                 for (int i = 0; i < n; i++) {
    //                     visited[i] = false;
    //                 }
    //             cout<<"Enter starting node for DFS: ";cin>>start_node;
    //             dfs(start_node);
    //         break;
    //         case 2:
    //             #pragma omp parallel for
    //                 for (int i = 0; i < n; i++) {
    //                     visited[i] = false;
    //                 }
    //             cout<<"Enter starting node for BFS: ";cin>>start_node;
    //             bfs(start_node);
    //             break;
    //         case 3:
    //             cout<<"Thank you!";
    //             exit(0);
    //     }
    // }
	return 0;
}
