#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_SERVICE 10
#define NUMBERS_OF_TELLERS 2

struct Queue{
  int id_user[MAX_SIZE];
  int front, rear;
};

struct Tellers{
  struct Queue* queue[NUMBERS_OF_TELLERS];
};

void initialize(struct Tellers* tellers){
  for(int i=0; i<NUMBERS_OF_TELLERS; i++){
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    tellers->queue[i] = newQueue;
    tellers->queue[i]->front = -1;
    tellers->queue[i]->rear = -1;
  }
}

void resetQueue(struct Tellers* tellers, int teller_id){
  tellers->queue[teller_id]->front = -1;
  tellers->queue[teller_id]->rear = -1;
}

bool isEmpty(struct Tellers* tellers, int teller_id){
  return tellers->queue[teller_id]->front == -1;
}

bool isFull(struct Tellers* tellers, int teller_id){
  bool firstCondition = (tellers->queue[teller_id]->front == 0 && tellers->queue[teller_id]->rear == MAX_SERVICE - 1);
  bool secondCondition = (tellers->queue[teller_id]->front == tellers->queue[teller_id]->rear + 1);
  return firstCondition || secondCondition;
}

void enqueue(struct Tellers* tellers, int teller_id, int value){
  if(isFull(tellers, teller_id)){
    printf("Queue penuh, tidak dapat menambahkan elemen.\n");
  }else {
    if (isEmpty(tellers, teller_id)){
      tellers->queue[teller_id]->front = 0;
    }
    tellers->queue[teller_id]->rear = (tellers->queue[teller_id]->rear + 1) % MAX_SERVICE;
    tellers->queue[teller_id]->id_user[tellers->queue[teller_id]->rear] = value;
    printf("%d ditambahkan ke antrian.\n", value);
  }
}

void dequeue(struct Tellers* tellers, int teller_id){
  if(isEmpty(tellers, teller_id)){
    printf("Antrian kosong, tidak dapat mengeluarkan elemen.\n");
  }else {
    printf("%d dihapus dari queue.\n", tellers->queue[teller_id]->id_user[tellers->queue[teller_id]->front]);
    if(tellers->queue[teller_id]->front == tellers->queue[teller_id]->rear){
      resetQueue(tellers, teller_id);
    }else {
      tellers->queue[teller_id]->front = (tellers->queue[teller_id]->front + 1) % MAX_SERVICE;
    }
  }
}

void jockeying(struct Tellers* tellers){
  int length_of_teller1 = tellers->queue[0]->rear - tellers->queue[0]->front + 1;
  int length_of_teller2 = tellers->queue[1]->rear - tellers->queue[1]->front + 1;
  int gap = abs(length_of_teller1 - length_of_teller2);
  if(gap == 2 || (gap == 1 && (isEmpty(tellers, 0) || isEmpty(tellers, 1)))){
    printf("Terjadi jockeying\n");
    if(length_of_teller1 > length_of_teller2){
      int last_index = tellers->queue[0]->rear;
      int id_user = tellers->queue[0]->id_user[last_index];
      enqueue(tellers, 1, id_user);
      tellers->queue[0]->rear = (last_index - 1) % MAX_SERVICE;
    }else{
      int last_index = tellers->queue[1]->rear;
      int id_user = tellers->queue[1]->id_user[last_index];
      enqueue(tellers, 0, id_user);
      tellers->queue[1]->rear = (last_index - 1) % MAX_SERVICE;
    }
  }
}

void display(struct Queue* queue){
  int i = queue->front;
  while(i != queue->rear){
    printf("%d -> ", queue->id_user[i]);
    i = (i + 1) % MAX_SERVICE;
  }
  printf("%d", queue->id_user[i]);
  printf("\n");
}

void printQueue(struct Tellers* tellers){
  for (int i=0; i<NUMBERS_OF_TELLERS; i++){
    if(isEmpty(tellers, i)){
      printf("Antrian pada teller %d kosong\n", i+1);
    }else {
      printf("Isi antrian pada teller %d:\n", i+1);
      display(tellers->queue[i]);
    }
  }
}

void list_command()
{
  system("cls");
  printf("=============== Menu ===============\n");
  printf("1.\tEnqueue\n");
  printf("2.\tDequeue\n");
  printf("3.\tDisplay Queue\n");
  printf("0.\tExit\n");
  printf("============= Command =============\n");
  printf("Select the menu you want to go: ");
}

int main(){
  struct Tellers* tellers = (struct Tellers*)malloc(sizeof(struct Tellers));
  initialize(tellers);

  while(true){
    int cmd = 0;
    list_command();
    scanf("%d", &cmd);

    int teller_id = 0;
    switch(cmd){
    case 1:
      printQueue(tellers);
      printf("Pilih teller (1/2):");
      scanf("%d", &teller_id);
      if(teller_id == 1 || teller_id == 2){
        int id_user = 0;
        printf("masukkan id user:");
        scanf("%d", &id_user);
        enqueue(tellers, teller_id - 1, id_user);
      }else {
        printf("invalid teller id\n");
      }
      jockeying(tellers);
      system("pause");
      continue;
    case 2:
      printQueue(tellers);
      printf("Pilih teller (1/2):");
      scanf("%d", &teller_id);
      if(teller_id == 1 || teller_id == 2){
        dequeue(tellers, teller_id - 1);
      }else {
        printf("invalid teller id\n");
      }
      jockeying(tellers);
      system("pause");
      continue;
    case 3:
      printQueue(tellers);
      system("pause");
      continue;
    case 0:
      break;
    defaul:
      printf("invalid command\n");
      system("pause");
      continue;
    }
    break;
  }

}