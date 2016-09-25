#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* head_addr = NULL;

void insert(int data) {
  Node* new_node_address = NULL;
  Node* current = head_addr;

  new_node_address = new Node();
  new_node_address -> data = data;
  new_node_address -> link = NULL;

  if (head_addr == NULL) {
    head_addr = new_node_address;
  }
  else {
    while(current -> link != NULL) {
      current = current -> link;
    }
    current -> link = new_node_address;
  }
}

void insert_at_position(int data, int position) {

  Node* new_node_address = NULL;
  Node* current = head_addr;
  int curr_pos = 1;

  new_node_address = new Node();
  new_node_address -> data = data;
  new_node_address -> link = NULL;

  if (position == 1) {
    new_node_address -> link = head_addr;
    head_addr = new_node_address;
  } else {

    while(curr_pos < position - 1) {
      current = current -> link;
      curr_pos++;
    }

    new_node_address -> link = current -> link;
    current -> link = new_node_address;

  }

}

void reverse_list() {
  Node* curr = head_addr;
  Node* prev = NULL;
  Node* next = NULL;

  while (curr != NULL) {
    next = curr -> link;
    curr -> link = prev;
    prev = curr;
    curr = next;
  }

  head_addr = prev;
}

void print_list() {

  Node* current = head_addr;

  while(current != NULL){
    cout << current ->data << " ";
    current = current -> link;
  }

}


int main() {

  int num_of_elements = 0;
  int data = 0;
  int pos = 0;

  cout << "How many elements you want to enter the list? ";
  cin >> num_of_elements;

  for (int i = 0; i < num_of_elements; i++) {
    cout << "Enter value # " << i+1 << " to insert in the list ";
    cin >> data;

    insert(data);
  }

  cout << endl;

  cout<< " The input list is: ";
  print_list();
  cout << endl;

  reverse_list() ;
  cout<< " The reverse list is: ";
  print_list();
  cout << endl << endl;

  reverse_list() ; // To revert to original list.

  cout << "*** Insert new node *** ";
  cout << endl;
  cout << "Enter data: ";
  cin >> data;
  cout << "Enter position: ";
  cin >> pos;

  insert_at_position(data, pos);

  cout<< "The new list is: ";
  print_list();
  cout << endl;

  return (0);
}

