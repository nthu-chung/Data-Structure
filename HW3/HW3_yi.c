#include <stdio.h>
#include <stdlib.h>

//void find_path(const char * const, int, int,char * const);
/* This is what you need to do. Your work is to implement this function */
int shortest_dist = 1000000;
//int sp_check = 0;
//int path_counter = 0;

void check(const int * const maze, int i, int j, int m, int n, int dist, int path_counter, int sp_check, int * const flag_maze)
{
   //printf("i = %d j = %d data = %d\n", i, j,  *(maze+i*n+j));
   path_counter = 1;
    *(flag_maze+i*n+j) = -2;
    if(*(maze+i*n+j) == -1){
      sp_check = 1;
    }
    dist = dist + *(maze+i*n+j);
   
    //left
    if( (*(flag_maze+i*n+(j-1)) != 0) && (*(flag_maze+i*n+(j-1)) != -2)){
        path_counter++;
        
      check(maze, i, (j - 1), m, n, dist, 2, sp_check, flag_maze);
    }
    //down
    if( (*(flag_maze+(i+1)*n+j) != 0) && (*(flag_maze+(i+1)*n+j) != -2)){
        path_counter++;
      check(maze, (i + 1), j, m, n, dist, 2, sp_check, flag_maze);
    }

    //right
    if( (*(flag_maze+i*n+(j+1)) != 0) && (*(flag_maze+i*n+(j+1)) != -2)){
     // printf("right\n");
     path_counter++;
      check(maze, i, (j + 1), m, n, dist, 2, sp_check, flag_maze);
    }

    //up

    if( (*(flag_maze+(i-1)*n+j) != 0) && (*(flag_maze+(i-1)*n+j) != -2) ){
        path_counter++;
      check(maze, (i - 1), j, m, n, dist, 2, sp_check, flag_maze);
    }
    //printf("sum = %d\n", dist + *(maze+i*n+j));
    /*
    if( (0 <= (i - 1)) && (*(flag_maze+(i-1)*n+j) == -2)){
        path_counter++;
    }
    if( (0 <= (j - 1)) && (*(flag_maze+i*n+(j-1)) == -2)){
        path_counter++;
    }
    if( (n > (j + 1)) && (*(flag_maze+i*n+(j+1)) == -2)){
        path_counter++;
    }
    if( (m > (i + 1)) && (*(flag_maze+(i+1)*n+j) == -2)){
        path_counter++;
    }
    */
    else if( (path_counter == 1) && (sp_check == 0) && (dist) < shortest_dist && *(flag_maze + (m*n))==1){
      shortest_dist = dist;
      //printf("special sum = %d\n", dist);
      sp_check = 0;
      path_counter = 0;
    }
    //printf("special check %d\n",sp_check);
    //printf("sum = %d\n", dist);
    sp_check = 0;
    path_counter = 0;
    
}

int main(void){
  int m, n;
  int x, y;

  x = 0;
  y = 0;
  scanf("%d %d", &m, &n); // Input maze size
  scanf("%d %d", &x, &y);\
  m = m + 2;
  n = n + 2;
  //printf("%d %d %d %d\n", m, n , x, y);


  
  int maze = (int)malloc(sizeof(int)*m*n);
  int flag_maze = (int)malloc(sizeof(int)*m*n);

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      *(maze+i*n+j) = 0;
      *(flag_maze+i*n+j) = 0;
    }
  }

  for(int i=1; i<(m-1); i++){
    for(int j=1; j<(n-1); j++){
      scanf(" %d", (maze+i*n+j));
      *(flag_maze+i*n+j) = *(maze+i*n+j);
    }
  }
/*
for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
          printf("%d",*(maze+i*n+j));
    }
    printf("\n");
  }
*/
 check(maze, y+1, x+1, m, n, 0, 0, 0, flag_maze);


//if(shortest_dist == 1000000){
  //  printf("0\n");
//}
//else{
  printf("%d\n", shortest_dist);
//}
  return 0;
}