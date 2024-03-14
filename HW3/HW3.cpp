#include <iostream>
using namespace std;

int shortest_dist = 100000;
void check(int **maze, int i, int j, int m, int n, int dist, int path_counter, int sp_check, int **visited);
int main(void){
    int row, col;
    int **maze,**visited;
	int i, j;
    int x,y;



    cin >> row >> col;
    cin >> x>> y;



    maze = new int*[row];
    for (i = 0; i < row; i++) {
        maze[i] = new int[col];
    }
    visited = new int*[row];
    for (i = 0; i < row; i++) {
        visited[i] = new int[col];
    }
    for ( i = 0; i < row; i++)
    {
        for (j = 0; j< col; j++) {
            visited[i][j] = 0;
        }
    }
    

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> maze[i][j];
		}
	}
    visited[y][x] = 1;

	

	check(maze, y, x, row, col, 0, 0, 0, visited);
	cout << shortest_dist << "\n";

// output

	

  return 0;
}

void check(int **maze, int i, int j, int m, int n, int dist, int path_counter,int sp_check, int **visited)
{
	int x;
    path_counter = 1;
    if(maze[i][j] == -1) sp_check = 1;
    dist = dist + maze[i][j];
    
	//left
	if( (maze[i][j - 1] != 0) && (j - 1 >= 0) && (visited[i][j - 1] == 0)) {
        path_counter++;
        visited[i][j-1]=1;
 //       dist = x + maze[i][j-1];
     //   cout << maze[i][j-1] <<"\n";
       check(maze, i, (j - 1), m, n, dist, 2, sp_check, visited);
    }
	if( (maze[i + 1][j] != 0) && (i + 1 < m) && (visited[i + 1][j] == 0)) {
        path_counter++;
        visited[i + 1][j] = 1;
//        dist = x + maze[i+1][j];
    //    cout << maze[i+1][j] <<"\n";
       check(maze, i + 1, j, m, n, dist, 2, sp_check, visited);
    }
	//right
	if( (maze[i][j + 1] != 0) && ((j + 1) < n) && (visited[i][j + 1] == 0)) {
        path_counter++;
        visited[i][j + 1] = 1;
 //       dist = x + maze[i][j+1];
     //   cout << maze[i][j+1] <<"\n";
       check(maze, i, (j + 1), m, n, dist, 2, sp_check, visited);
    }
	// up
	if( (maze[i - 1][j] != 0) && (i - 1 >= 0) && (visited[i - 1][j] == 0)) {
        path_counter++;
        visited[i - 1][j] = 1;
 //       dist = x + maze[i-1][j];
     //   cout << maze[i-1][j] <<"\n";
      check(maze, i - 1, j, m, n, dist, 2, sp_check, visited);
    }
	
	else if((dist < shortest_dist) && (path_counter == 1) &&(sp_check == 0) && (visited[i][j] == 1)){
        shortest_dist = dist;
//        cout << shortest_dist << "\n";
	    sp_check = 0;
      //printf("special sum = %d\n", dist);
        path_counter = 0;
    }
    //printf("special check %d\n",sp_check);
    //printf("sum = %d\n", dist);
    sp_check = 0;
    path_counter = 0;
	return;
}