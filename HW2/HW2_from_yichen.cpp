#include<iostream>
using namespace std;

// Node class to represent link list
struct Node
{
    int row;
    int column;
    struct Node* next;
    struct Node* prev;
};

void creat(struct Node** head, struct Node** final_l, int x, int y){

    struct Node* newNode = new Node;

    //assign data to new node
    newNode->row = x;
    newNode->column = y;

    newNode->next = NULL;
    newNode->prev = NULL;

    //change the position at first and last node
    (*head) = newNode;
    (*final_l) = (*head);

    //cout<<"head = "<< *head<<"\n";
    //cout<<"end = "<< *final_l<<"\n";
}

void insert_front(struct Node** head, int x, int y)
{
   //allocate memory for New node
    struct Node* newNode = new Node;

   //assign data to new node
    newNode->row = x;
    newNode->column = y;

   //new node is head and previous is null, since we are adding at the front
    newNode->next = (*head);
    newNode->prev = NULL;
    newNode->next->prev = newNode;

   //head points to new node
   (*head) = newNode;

   //cout<<"head = "<< *head<<"\n";
   //cout<<"end = "<< *final_l<<"\n";
}

void insert_end(struct Node** final_l, int x, int y)
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

void insert_after(struct Node* prev_node, int x, int y)//why we only need a star
{
   //allocate memory for new node
   struct Node* newNode = new Node;

   //assign data to new node
   newNode->row = x;
   newNode->column = y;

   //set next of newnode to next of prev node
   newNode->next = prev_node->next;

   //set next of prev node to newnode
   prev_node->next = newNode;

   //now set prev of newnode to prev node
   newNode->prev = prev_node;

   //set prev of new node's next to newnode
   newNode->next->prev = newNode;
}

void printfront(struct Node* node) {
   //struct Node* last;
    cout<<"PrintFront\n";
    while (node != NULL) {
        cout<<"("<<node->row<<","<<node->column<<")"<<"\n";
        node = node->next;
   }
}

void printend(struct Node* node) {
   //struct Node* last;
    cout<<"PrintEnd\n";
    while (node != NULL) {
        cout<<"("<<node->row<<","<<node->column<<")"<<"\n";
        node = node->prev;
    }

}

void delete_node(struct Node** node, struct Node** head, struct Node** final_l)
{
    //cout<<"PREV node "<< (*node)->prev->row<<(*node)->prev->column;
struct Node* del = (*node);
if (((*node)->prev == NULL) && ((*node)->next != NULL)){
    //cout<<"\nenter1";
    (*head) = (*node)->next;
    (*node)->next->prev=NULL;
    (*node) = (*node)->next;
    free(del);
}

else if (((*node)->prev != NULL) && ((*node)->next == NULL)){
    //cout<<"\nenter2";
    (*final_l) = (*node)->prev;
    (*node)->prev->next = NULL;
    (*node) = (*node)->prev;
    free(del);
}

else if (((*node)->prev == NULL) && ((*node)->next == NULL)){
    //cout<<"\nenter3";
    (*head) =NULL;
    (*final_l) = NULL;
    (*node) = NULL;
    free(del);
}

else if (((*node)->prev != NULL) && ((*node)->next != NULL)){
    //cout<<"\nenter4";
    (*node)->prev->next = (*node)->next;
    (*node)->next->prev = (*node)->prev;
    (*node) = (*node)->next;
    free(del);
}
}


int main()
{

    int i = 0,j,k = 0,c = 0,d = 0,z = 0;
    int x, y;
    cin >> k;
    string order;
    struct Node* head = NULL;
    struct Node* final_l = NULL;


    while(i < k){
        cin >> order;
        if( order == "House"){
            cin >> x >> y ;

            struct Node* node_check = head;
            for(j = 0; j < c; j++){
                if((x == node_check->row) && (y == node_check->column)){
                z = 1;
               // cout<<"enter";
                break;
                }
                node_check = node_check->next;
            }

            if(head == NULL && (z != 1) ){
                c++;
                creat(&head, &final_l, x, y);
            }
            else if((y > final_l->column) ||
                    ((y == final_l->column) && (x > final_l->row))
                    && (z != 1)){

                //cout<<"end\n";
                c++;
                insert_end(&final_l, x, y);
            }

            else if((y < head->column) ||
                    ((y == head->column) && (x < head->row)) &&
                    (z != 1)){
                //cout<<"front\n";
                c++;
                insert_front(&head, x, y);
            }
            else if(z != 1){
                //cout<<"enter";

                struct Node* node = head;
                for(j = 1; j < c; j++){

                    if( (node->column < y && y < node->next->column) ||
                       ( (node->column < y && y == node->next->column) &&
                        (x < node->next->row) ) ||
                       ( (node->column == y && y < node->next->column) &&
                        (node->row < x) ) ||
                       ( (node->column == y && y == node->next->column) &&
                        (node->row < x && x < node->next->row) )){//does()matters?
                        c++;
                        //cout<<"enter";
                        //cout<<" "<<node->row<<" "<<node->column;
                        //cout<<" "<<node->next->row<<" "<<node->next->column;
                        insert_after(node, x, y);
                        //cout<<"head = "<< head<<"\n";
                        //cout<<"end = "<< final_l<<"\n";
                        break;
                    }
                    node = node->next;
                }
            }
        }

        if( order == "Bomb"){//can we just check the place around the bomb?//use the data(x,y) to find the place??
            cin >> x >> y ;
            if(head != NULL){
                int target_x, target_y;
                struct Node* node = head;
                while(node != NULL){
                    //cout<<"node "<< (node)->row<<(node)->column;
                    target_x = node->row, target_y = node->column;//does it work???//can we find the last node //design a last
                    if(((target_x == x) && (target_y == (y - 1))) ||
                       ((target_x == (x - 1)) && (target_y == y))
                        || ((target_x == x) && (target_y == y)) ||
                       ((target_x == (x + 1)) && (target_y == y))||
                        ((target_x == x) && (target_y == (y + 1)))){
                        delete_node(&node, &head, &final_l);
                        //cout<<"enter delete";
                        d = 1;
                        z++;
                    }
                    //cout<<"node "<< (node)->row<<(node)->column;
                    //cout<<"NEXT node "<< (node)->next->row<<(node)->next->column;
                    //if(node == NULL){
                        //break;
                    //}
                    if(d == 0){
                    node = node->next;
                    }
                    d = 0;
                    //cout<<"NEXT node "<< (node)->row<<(node)->column;
                }

            }
            c = c - z;
        }


        if( order == "PrintFront"){//suggest us to use two linked list use array to store the output ant reverse? address?? two linked list?
            printfront(head);
        }

        if( order == "PrintEnd"){
            printend(final_l);
        }
        z = 0;
        i++;

    }
    return 0;
}
