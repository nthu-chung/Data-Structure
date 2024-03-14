#include <iostream>
#include <memory.h>
using namespace std;

int shortest_dist = 100000;
int m;
int n;
void check(int *maze, int i, int j, int dist, int path_counter, int *visited);
int main(void){
    int row, col;
    int *maze,*visited;
	int i, j;
    int x,y;



    cin >> row >> col;
    cin >> x>> y;



    maze = new int[row*col];
    visited = new int[row*col];
/*   for ( i = 0; i < row; i++)
    {
        for (j = 0; j< col; j++) {
            visited[i*col + j] = 0;
        }
    }*/
    memset(visited, false, sizeof visited);
    

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> maze[i*col+j];
		}
	}
    visited[y*col+x] = 1;
    m = row;
    n = col;
	

	check(maze, y, x, 0, 0, visited);
	cout << shortest_dist << "\n";

// output

	

  return 0;
}

void check(int *maze, int i, int j, int dist, int path_counter, int *visited)
{
	
    path_counter = 1;
    if(maze[i*n+j] == -1) return;
    dist = dist + maze[i*n+j];
    
	//left
	if( (maze[i*n +(j - 1)] != 0) && (j - 1 >= 0) && (visited[i*n +(j - 1)] == 0)) {
        path_counter++;
        visited[i*n +(j - 1)]=1;
 //       dist = x + maze[i][j-1];
     //   cout << maze[i][j-1] <<"\n";
       check(maze, i, (j - 1), dist, 2, visited);
    }
	if( (maze[(i + 1)*n+j] != 0) && (i + 1 < m) && (visited[(i + 1)*n+j] == 0)) {
        path_counter++;
        visited[(i + 1)*n+j] = 1;
//        dist = x + maze[i+1][j];
    //    cout << maze[i+1][j] <<"\n";
       check(maze, i + 1, j, dist, 2, visited);
    }
	//right
	if( (maze[i*n +(j + 1)] != 0) && ((j + 1) < n) && (visited[i*n +(j + 1)] == 0)) {
        path_counter++;
        visited[i*n +(j + 1)] = 1;
 //       dist = x + maze[i][j+1];
     //   cout << maze[i][j+1] <<"\n";
       check(maze, i, (j + 1),dist, 2, visited);
    }
	// up
	if( (maze[(i - 1)*n+j] != 0) && (i - 1 >= 0) && (visited[(i - 1)*n+j] == 0)) {
        path_counter++;
        visited[(i - 1)*n+j] = 1;
 //       dist = x + maze[i-1][j];
     //   cout << maze[i-1][j] <<"\n";
      check(maze, i - 1, j,dist, 2, visited);
    }
	
	else if((dist < shortest_dist) && (path_counter == 1) && (visited[i*n+j] == 1)){
        shortest_dist = dist;
//        cout << shortest_dist << "\n";
	    
      //printf("special sum = %d\n", dist);
        path_counter = 0;
    }
    //printf("special check %d\n",sp_check);
    //printf("sum = %d\n", dist);

    path_counter = 0;
	return;
}