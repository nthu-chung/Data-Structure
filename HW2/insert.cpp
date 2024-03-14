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
void delete_node(struct Node** node, struct Node** head, struct Node** end)
{

}
/*
else if (command == "Bomb") {
            cin >> x >> y ;
            if(head != NULL){
                
                for(j = 0; j < node_num; j++){
                    target_x = node->data_x, target_y = node->data_y;//does it work???//can we find the last node //design a last
                    if (   (target_x == x && target_y == (y - 1)) 
                        || (target_x == (x - 1) && target_y == y)
                        || (target_x == x && target_y == y) 
                        || (target_x == (x + 1) && target_y == y)
                        || (target_x == x && target_y == (y + 1)) ) {

                        delete_node(&node, &head, &end);
                        c++;
                    } else {
                        node = node->next;
                    }
                }
                node_num = node_num - c;
            }
        } 
        */
void insert_end(struct Node** head, struct Node** final_l, int x, int y)
{
    //allocate memory for node
    struct Node* newNode = new Node;

    //set data for new node
    newNode->row = x;
    newNode->column = y;
    //new node is the last node , so set next of new node to null
    newNode->next = NULL;
    newNode->prev = *(final_l);
    newNode->prev->next = newNode;

    *final_l = newNode;

    //cout<<"head = "<< *head<<"\n";
    //cout<<"end = "<< *final_l<<"\n";
}