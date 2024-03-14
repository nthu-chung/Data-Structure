#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data_x;
    int data_y;
    struct Node *next;
    struct Node *prev;
};
void insert_front(struct Node** head, int x, int y);
void insert_after(struct Node* prev_node, int x, int y);
void insert_end(struct Node** end ,int x, int y);
void delete_node(struct Node** current, struct Node** head, struct Node** end);

int main(void) {
    int N;
    string command;
    int x,y;
    int i,j;
    int c = 0;
    int target_x, target_y; 
    struct Node* head = NULL;
    struct Node* end = NULL;
    struct Node* current = NULL;
  

    cin >> N ;
    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "House") {
            cin >> x >> y;
 //           cout << "House" << ' ' << x << ' ' << y <<"\n";
            if (head == NULL) {
                head = new Node;
                head->data_x = x;
                head->data_y = y;
                head->prev = NULL;
                head->next = NULL;
                current = head;
                end = head;
            } else {
                current = head;
                if (y < head->data_y) {
                    insert_front(&head, x, y);
                } else if (y == head->data_y) {
                    if (x < head->data_x) {
                        insert_front(&head, x, y);    
                    } else if (x > head->data_x) {
                        while (x > current->data_x && current->next != NULL) {
                                current = current->next; 
                        }
                        if (current->next == NULL) {
                            insert_end(&end, x, y);
                        } else {
                            insert_after(current->prev, x, y);
                            
                        }
                    }
                } 
                current = head;
                if (y > head->data_y) {
                    while (y > current->data_y && current->next != NULL) {
                        current = current->next; 
                    }
                    if (current->data_y < y && current->next == NULL) {
                        insert_end(&end, x, y);
                    }
                    if (current->data_y > y) {
                        insert_after(current->prev, x, y);
                    }
                    if (current->data_y == y) {
                        // y the same start to compare
                        if (current->data_x > x) {
                            insert_after(current->prev, x, y);
                        }
                        if (current->data_x < x) {
                            while (x > current->data_x && current->next != NULL) {
                                current = current->next; 
                            }
                            if (current->next == NULL) {
                                insert_end(&end, x, y);
                            }
                            if (current->data_x > x) {
                                insert_after(current->prev, x, y);
                            }
                        }
                    }
                    
                }
                
            }
            
        } 
        else if (command == "Bomb") {
            current = head;
            cin >> x >> y ;
//           cout << "Bomb " << x << ' ' << y << "\n";
            while (head != NULL && current != NULL)
            {
                target_x = current->data_x, target_y = current->data_y;//does it work???//can we find the last node //design a last
                if (   (target_x == x && target_y == (y - 1)) 
                    || (target_x == (x - 1) && target_y == y)
                    || (target_x == x && target_y == y) 
                    || (target_x == (x + 1) && target_y == y)
                    || (target_x == x && target_y == (y + 1)) ) {

                    delete_node(&current, &head, &end);
                } else {
                    current = current->next;
                }
            }
            
        } 
        else if (command == "PrintFront") {
            cout << "PrintFront" <<"\n";
            current = head;
            while (head != NULL && current != NULL) {
                cout << "(" << current->data_x <<',' <<current->data_y <<")" << "\n";
                current = current->next;
            }
             
        } 
        else if (command == "PrintEnd") {
            cout << "PrintEnd" <<"\n";
            current = end;
/*            if (head->prev == NULL)
            {
                cout << "head has NULL" <<"\n";
            }else{ cout << "head NO NULL" <<"\n";}
            cout << end->next <<"\n";
            if (end->next == NULL)
            {
                cout << "end has NULL" <<"\n";
            }else{ cout << "end NO NULL" <<"\n";}
 */
            while (end != NULL && current != NULL) {
                cout << "(" << current->data_x <<',' <<current->data_y <<")" << "\n";
                current = current->prev;
            }////////qqqqqqqqqqqqqq
        }
       
    }
    return 0;
}
void insert_front(struct Node** head, int x, int y)
{
   //allocate memory for New node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data_x = x;
   newNode->data_y = y;
   //new node is head and previous is null, since we are adding at the front
   newNode->next = (*head);
   newNode->prev = NULL;
   newNode->next->prev = newNode;
   
  
   //head points to new node
   (*head) = newNode;
}
/* Given a node as prev_node, insert a new node after the given node */
void insert_after(struct Node* prev_node, int x, int y)
{
   //check if prev node is null
   
   //allocate memory for new node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data_x = x;
   newNode->data_y = y;
   //set next of newnode to next of prev node
   newNode->next = prev_node->next;
  
   //set next of prev node to newnode
   prev_node->next = newNode;
  
   //now set prev of newnode to prev node
   newNode->prev = prev_node;
  
   //set prev of new node's next to newnode
   newNode->next->prev = newNode;
}
  
//insert a new node at the end of the list
void insert_end(struct Node** end ,int x, int y)
{
   //allocate memory for node
   struct Node* newNode = new Node;
  
  
   //set data for new node
   newNode->data_x = x;
   newNode->data_y = y;
   //new node is the last node , so set next of new node to null
   newNode->next = NULL;
   newNode->prev = (*end);
   newNode->prev->next = newNode;

   *end = newNode; 
   //check if list is empty, if yes make new node the head of list
  
  

   
}
void delete_node(struct Node** current, struct Node** head, struct Node** end)
{
    struct Node* pre = (*current)->prev;

    if ((*current)->prev == NULL && (*current)->next != NULL) {
        *head = (*current)->next;
        (*current)->next->prev = NULL;
        delete *current;
        *current = *head;

    } else if ((*current)->next == NULL && (*current)->prev != NULL) {
        *end = (*current)->prev;
        (*current)->prev->next = NULL;
        delete *current;
        *current = *end;
    } else if ((*current)->next == NULL && (*current)->prev == NULL) {
        delete *current;
        *head = NULL;
        *end = *head;
        *current = *head;
    } else {
        pre->next = (*current)->next;
        pre->next->prev = pre;
        delete *current;
        *current = pre->next;
    }
    
    
}
 /* 
// This function prints contents of linked list starting from the given node
void displayList(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
   }
   */
