#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk double linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di awal linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if(*head == NULL){
      *head = newNode;
    }else {
      newNode->next = *head;
      (*head)->prev = newNode;
      *head = newNode;
    }
}

// Fungsi untuk menambahkan node di akhir linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk menambahkan node di tengah linked list setelah node tertentu
void insertAfter(struct Node* prevNode, int data)
{
  if (prevNode == NULL)
  {
    printf("Node sebelumnya tidak dapat NULL");
    return;
  }

  struct Node* newNode = createNode(data);
  // lengkapi bagian ini
  newNode->prev = prevNode;
  // lengkapi bagian ini
  if (prevNode->next != NULL)
  {
    // lengkapi bagian ini
    struct Node* nextNode = prevNode->next;
    newNode->next = nextNode;
    nextNode->prev = newNode;
  }
  // lengkapi bagian ini
  prevNode->next = newNode;
}

// Fungsi untuk menghapus node dari linked list
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        return;
    }

    if (*head == delNode) {
        *head = delNode->next;
    } 
    
    if (delNode->next != NULL){
      //  lengkapi bagian ini
      struct Node* nextNode = delNode->next;
      nextNode->prev = delNode->prev;
    }

    if (delNode->prev != NULL){
      // lengkapi bagian ini
      struct Node* prevNode = delNode->prev;
      prevNode->next = delNode->next;
    }

    free(delNode);
}

// Fungsi untuk mencetak linked list dari depan ke belakang
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Fungsi untuk mencetak linked list dari belakang ke depan
void printReverseList(struct Node* node){
  while(node->next != NULL){
    node = node->next;
  }

  while(node != NULL){
    printf("%d ->", node->data);
    node = node->prev;
  }
  printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAfter(head, 7);
    insertAtEnd(&head, 20);

    printf("Linked List dari depan ke belakang: ");
    printList(head);

    printf("Linked List dari belakang ke depan: ");
    printReverseList(head);

    struct Node* nodeToDelete = head->next; // Menghapus node kedua
    deleteNode(&head, nodeToDelete);

    printf("Linked List setelah menghapus node kedua: ");
    printList(head);

    return 0;
}