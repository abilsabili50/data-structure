#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Struktur stack
struct Stack
{
  int items[MAX_SIZE];
  int top;
};

// Inisialisasi stack
void initialize(struct Stack *stack)
{
  stack->top = -1;
}

// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty(struct Stack *stack)
{
  return stack->top == -1;
}

// Fungsi untuk memeriksa apakah stack penuh
bool isFull(struct Stack *stack)
{
  return stack->top == MAX_SIZE - 1;
}

// Fungsi untuk menambahkan elemen ke stack (push)
void push(struct Stack *stack, int value)
{
  if (isFull(stack))
  {
    printf("Stack penuh, tidak dapat menambahkan elemen.\n");
  }
  else
  {
    stack->items[++stack->top] = value;
    printf("%d ditambahkan ke stack.\n", value);
  }
}

// Fungsi untuk mengeluarkan elemen dari stack (pop)
void pop(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack kosong, tidak dapat mengeluarkan elemen.\n");
  }
  else
  {
    printf("%d dihapus dari stack.\n", stack->items[stack->top--]);
  }
}

// Fungsi untuk menampilkan elemen teratas dari stack (pop)
void peek(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack kosong, tidak ada elemen untuk ditampilkan.\n");
  }
  else
  {
    printf("Elemen teratas: %d\n", stack->items[stack->top]);
  }
}

// Fungsi untuk menampilkan semua elemen dalam stack
void display(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack kosong, tidak ada elemen untuk ditampilkan.\n");
  }
  else
  {
    printf("Isi stack:\n");
    for (int i = 0; i <= stack->top; ++i)
    {
      printf("%d\n", stack->items[i]);
    }
  }
}

// Fungsi main untuk menguji implementasi stack
int main()
{
  struct Stack stack;
  initialize(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  display(&stack);

  pop(&stack);
  display(&stack);

  peek(&stack);

  // implementasi stack
  int nilai = 1234;
  struct Stack s;
  initialize(&s);

  while (nilai != 0)
  {
    int sisa = nilai % 2;
    push(&s, sisa);
    nilai = nilai / 2;
  }

  while (!isEmpty(&s))
  {
    printf("%d", pop(&s));
  }

  return 0;
}