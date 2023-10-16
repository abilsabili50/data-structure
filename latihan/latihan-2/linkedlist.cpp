#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
  int data;
  struct node *next;
};
typedef struct node node;

// function declaration
void tambah_awal(node **pHead);
void tambah_sisipan(node **pHead);
void tambah_akhir(node **pHead);
void transversing(node **pHead);
void list_command();
void length_list(node **pHead);

int main()
{
  node *pHead;
  pHead = NULL;

  while (true)
  {
    int cmd = 0;
    list_command();
    length_list(&pHead);

    printf("Masukkan menu yang akan anda pilih: ");
    scanf("%d", &cmd);

    switch (cmd)
    {
    case 1:
      tambah_awal(&pHead);
      continue;
    case 2:
      tambah_sisipan(&pHead);
      continue;
    case 3:
      tambah_akhir(&pHead);
      continue;
    case 4:
      transversing(&pHead);
      continue;
    case 0:
      break;

    default:
      printf("nomor perintah tidak dikenali\n");
      system("pause");
      continue;
    }

    break;
  }
  printf("========== Terima Kasih ===========");
}

void tambah_awal(node **pHead)
{
  int bil;
  node *pNew;
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL)
  {
    printf("Masukkan bilangan untuk awal node: ");
    scanf("%d", &bil);
    pNew->data = bil;
    pNew->next = *pHead;
    *pHead = pNew;
  }
  else
  {
    printf("Alokasi memori gagal");
  }
}

void tambah_sisipan(node **pHead)
{
  int bil, pos;
  node *pNew, *pCur;

  // penentuan posisi yg dicari
  printf("Masukkan posisi yang akan dicari: ");
  scanf("%d", &pos);

  // cari data
  pCur = *pHead;
  while (pCur != NULL && pCur->data != pos)
  {
    pCur = pCur->next;
  }

  // membuat data baru
  if (pCur == NULL)
  {
    printf("Data tidak ditemukan");
  }
  else
  {
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL)
    {
      printf("Masukkan bilangan untuk list setelah %d: ", pCur->data);
      scanf("%d", &pNew->data);

      pNew->next = pCur->next;
      pCur->next = pNew;
    }
    else
    {
      printf("Alokasi memori gagal");
    }
  }
}

void tambah_akhir(node **pHead)
{
  node *pNew, *pCur;
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL)
  {
    printf("Masukkan bilangan untuk akhir node: ");
    scanf("%d", &pNew->data);
    pCur = *pHead;
    while (pCur->next != NULL)
    {
      pCur = pCur->next;
    }

    pNew->next = NULL;
    pCur->next = pNew;
  }
  else
  {
    printf("Alokasi memori gagal");
  }
}

void transversing(node **pHead)
{
  system("cls");
  printf("=============== Data Pada Node ===============\n");
  node *pCur = *pHead;
  while (pCur != NULL)
  {
    printf("data : %d \n", pCur->data);
    pCur = pCur->next;
  }

  if (pCur == NULL)
  {
    printf("Tidak ada data pada node\n");
  }

  system("pause");
}

void list_command()
{
  system("cls");
  printf("=============== Menu ===============\n");
  printf("1.\tTambah Data Di Awal Node\n");
  printf("2.\tTambah Data Di Tengah Node\n");
  printf("3.\tTambah Data Di Akhir Node\n");
  printf("4.\tTampilkan Data Pada Node\n");
  printf("0.\tKeluar\n");
}

void length_list(node **pHead)
{
  printf("======== Jumlah Data Pada Node ========\n");
  int length = 0;
  node *pCur = *pHead;
  while (pCur != NULL)
  {
    pCur = pCur->next;
    length++;
  }

  if (length == 0)
  {
    printf("Tidak ada data pada node / 0\n");
  }
  else
  {
    printf("terdapat %d data pada node\n", length);
  }

  printf("=========== Perintah ===========\n");
}