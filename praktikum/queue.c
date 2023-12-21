#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Struktur Queue
struct Queue
{
  int items[MAX_SIZE];
  int front, rear;
};

// Inisialisasi queue
void initialize(struct Queue *queue)
{
  queue->front = -1;
  queue->rear = -1;
}

// Fungsi untuk memeriksa apakah queue kosong
bool isEmpty(struct Queue *queue)
{
  return queue->front == -1;
}

// Fungsi untuk memeriksa apakah queue penuh
bool isFull(struct Queue *queue)
{
  bool firstCondition = (queue->front == 0 && queue->rear == MAX_SIZE - 1);

  bool secondCondition = (queue->front == queue->rear + 1);

  return firstCondition || secondCondition;
}

// Fungsi untuk menambahkan elemen ke queue (enqueue)
void enqueue(struct Queue *queue, int value)
{
  if (isFull(queue))
  {
    printf("Queue penuh, tidak dapat menambhkan elemen.\n");
  }
  else
  {
    if (isEmpty(queue))
    {
      queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("%d ditambahkan ke queue.\n", value);
  }
}

// Fungsi untuk mengeluarkan elemen dari queue (dequeue)
void dequeue(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue kosong, tidak dapat mengeluarkan elemen.\n");
  }
  else
  {
    printf("%d dihapus dari queue.\n", queue->items[queue->front]);
    if (queue->front == queue->rear)
    {
      initialize(queue);
    }
    else
    {
      queue->front = (queue->front + 1) % MAX_SIZE;
    }
  }
}

// Fungsi untuk menampilkan elemen-elemen dalam queue
void display(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    print("Queue kosong, tidak ada elemen untuk ditampilkan.\n");
  }
  else
  {
    printf("Isi queue:\n");
    int i = queue->front;
    while (i != queue->rear)
    {
      printf("%d\n", queue->items[i]);
      i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[i]);
  }
}

// Fungsi main untuk menguji implementasi queue
int main()
{
  struct Queue queue;
  initialize(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  display(&queue);

  dequeue(&queue);
  display(&queue);

  return 0;
}