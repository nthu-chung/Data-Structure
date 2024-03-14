#include <iostream>
#include <climits>
#include <iomanip> 
#include <stack>
using namespace std;

int V;
// Number of vertices in the graph
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  
// A utility function to print the constructed distance array
void printSolution(int dist[], int src, int path[])
{
    int j = 0;
    int i = 0;
    stack<int> q;


    for (int i = 0; i < V; i++) {
        j = i;
        while (path[j] != -1)
        {
            q.push(j);
            j = path[j];
        }
        q.push(j);
        if (dist[i] != 0) {
            cout << "Path(" << src <<","<< i << ")";
            cout << src;
            q.pop();
            while(!q.empty())
            {
                if (q.top() != src)
                 cout << "->"<< q.top();
                 q.pop();

            }
//            cout <<"->" << i <<"\n";
            cout << "\n";
            cout << "Difficulty:" << dist[i] <<"\n";
        }
       
    }
        
}
    
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int **graph, int src, double **cent)
{
    int i, j;
    int check = 1;
    int v = 0;
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    int path[V];
    
    for (i = 0; i < V; i++) {
        path[i] = -1;
    }
    
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                 dist[v] = dist[u] + graph[u][v];
                path[v] = u;     
            } 
            
        }
        
        
    }
/*    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            cout << path[i][j] <<" ";
        }
        cout <<"\n";
    }    */      
  
    // print the constructed distance array
 //   printSolution(dist, src, path);
    for (i = 0; i < V; i++) {
        cent[src][i] = dist[i];
    }
}
  
// driver program to test above function
int main()
{
    int N;
    int T;
    int Q;
    int x,y;
    int i, j;
    int k;
    int **A;
    int box[1000][2];
    double **cent;
    double *centnum;

    cin >> T;
    for (k = 1; k <= T; k++) {
        cin >> N;
        cin >> Q;
        
        V = N;
        A = new int*[N];
        cent = new double*[N];
        for (i = 0; i < N; i++) cent[i] = new double[N];
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cent[i][j] = 0.0;;
            }
        }
        for (i = 0; i < N; i++) {
            A[i] = new int[N];
        }

    
        
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
        for (j = 0; j < Q; j++) {
            for (i = 0; i < 2; i++) {
                cin >> box[j][i];
            }
        }
 /*       for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cout << A[i][j] <<" ";
            }
            cout <<"\n";
        }
       for (j = 0; j < Q; j++) {
            for (i = 0; i < 2; i++) {
                cout << box[j][i] <<" ";
            }
            cout <<"\n";
        }*/
        
        for (i = 0; i < N; i++) {
                dijkstra(A, i, cent);
        //       cout <<"\n";
        }
        cout << "Testcase" << k <<"\n";
        for (i = 0; i < Q; i++)
        {
            x = box[i][0];
            y = box[i][1];
            cout << "Cost(" << x <<"," << y << "):";
            if (cent[x][y] < INT_MAX) {
                cout << cent[x][y] <<"\n";
            } else {
                cout << "No Service" <<"\n";
            }
        }
        

        delete [] A;
        delete [] cent;
    }
    
    /* Let us create the example graph discussed above */
 /*   int graph[V][V] = { {0,4, 0, 9, 0}, 
                        {8, 0, 1, 5, 0}, 
                        {4, 2, 0, 0, 9}, 
                        {1, 0, 0, 0, 0}, 
                        {7, 8, 7, 5, 0}  };*/
                                                

  
    
    
/*    for (j = 0; j < V; j++) {
        for (i = 0; i < V; i++) {
            if (cent[i][j] != 0)
                centnum[j] = centnum[j] + double(1/cent[i][j]);
        }
    }*/

    return 0;
}