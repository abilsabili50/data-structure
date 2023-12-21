#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk double linked list
struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};

// Fungsi untuk membuat node baru
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
};

// Fungsi untuk menambahkan node di awal linked list
void insertAtBeginning(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head == newNode;
  }
  else
  {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
}

// Fungsi untuk menambahkan node di akhir linked list
void insertAtEnd(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head == newNode;
  }
  else
  {
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

// Fungsi untuk menambahkan node di tengah linked list setelah node tertentu
void insertAfter(struct Node *prevNode, int data)
{
  if (prevNode == NULL)
  {
    printf("Node sebelumnya tidak dapat NULL");
    return;
  }

  struct Node *newNode = createNode(data);
  // lengkapi bagian ini
  // lengkapi bagian ini
  if (prevNode->next != NULL)
  {
    // lengkapi bagian ini
  }
  // lengkapi bagian ini
}

// Fungsi untuk menghapus node dari linked list
void deleteNode(struct Node **head, struct Node *delNode)
{
  if (*head == NULL || delNode == NULL)
  {
    return;
  }
  if (*head == delNode)
  {
    *head = delNode->next;
  }
  if (delNode->next != NULL)
  {
    // lengkapi bagian ini
  }
  if (delNode->prev != NULL)
  {
    // lengkapi bagian ini
  }

  free(delNode);
}

// Fungsi untuk mencetak linked list dari depan ke belakang
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}

// Fungsi untuk mencetak linked list dari belakang ke depan
void printReverseList(struct Node *node)
{
  while (node->next != NULL)
  {
    node = node->next;
  }

  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}

// Fungsi main untuk menguji implementasi linked list
int main()
{
  struct Node *head = NULL;
  insertAtEnd(&head, 10);
  insertAtBeginning(&head, 5);
  insertAdter(head, 7);
  insertAtEnd(&head, 20);

  printf("Linked List dari depan ke belakang: ");
  printList(head);

  printf("Linked List dari belakang ke depan: ");
  printReverseList(head);

  struct Node *nodeToDelete = head->next; // Menghapus node kedua
  deleteNode(&head, nodeToDelete);

  printf("Linked List setelah menghapus node kedua");
  printList(head);

  return 0;
}