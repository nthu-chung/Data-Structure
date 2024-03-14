#include<iostream>
using namespace std;

struct Node
{
    int data_x;
    struct Node *next;
    struct Node *prev;
};
void insert_front(struct Node** head, int x);
void insert_after(struct Node* prev_node, int x);
void insert_end(struct Node** end ,int x);
void delete_node(struct Node** current, struct Node** head, struct Node** end);
int main(void) {
    int N;
    string command;
    int x,y;
    int a,d;
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
            cin >> x ;
            if (head == NULL) {
                head = new Node;
                head->data_x = x;
                head->prev = NULL;
                head->next = NULL;
                current = head;
                end = head;
            } else {
                current = head;
                if (x < head->data_x) {
                    insert_front(&head, x);    
                } else if (x > head->data_x) {
                    while (x > current->data_x && current->next != NULL) {
                            current = current->next; 
                    }
                    if (current->next == NULL && x > current->data_x) {
                        insert_end(&end, x);
                    } else if (current->data_x != x) {
                        insert_after(current->prev, x);
                        
                    }
                }
                
            }
            
        } 
        else if (command == "Bomb") {
            current = head;
            cin >> a >> d;
//           cout << "Bomb " << x << ' ' << y << "\n";
            while (head != NULL && current != NULL)
            {
                //does it work???//can we find the last node //design a last
                if (a - d <= current->data_x && current->data_x <= a + d) {
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
                cout << current->data_x  << "\n";
                current = current->next;
            }
             
        } 
        else if (command == "PrintEnd") {
            cout << "PrintEnd" <<"\n";
            current = end;
            while (end != NULL && current != NULL) {
                cout << current->data_x << "\n";
                current = current->prev;
            }
        }
       
    }
    return 0;
}
void insert_front(struct Node** head, int x)
{
   //allocate memory for New node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data_x = x;

   //new node is head and previous is null, since we are adding at the front
   newNode->next = (*head);
   newNode->prev = NULL;
   newNode->next->prev = newNode;
   
  
   //head points to new node
   (*head) = newNode;
}
/* Given a node as prev_node, insert a new node after the given node */
void insert_after(struct Node* prev_node, int x)
{
   //check if prev node is null
   
   //allocate memory for new node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data_x = x;
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
void insert_end(struct Node** end ,int x)
{
   //allocate memory for node
   struct Node* newNode = new Node;
  
  
   //set data for new node
   newNode->data_x = x;
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