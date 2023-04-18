    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <windows.h>
    #include <conio.h>

struct barang {
    int kode;
    char nama[30], stok[20], harga[30], telp[20];
}dat[15];

struct node {
char hist[100]; struct barang *barang; struct node *next;};

int jum=0, tot=0, temp, oy, result, x; char temps[100]; struct node*head = NULL;

void gotoxy();
void cari();

 void gotoxy (int x, int y){
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);}

void cari(){
    system ("cls");
    int i, j;
    struct barang temp;

    for(i=0; i<tot-1; i++){
    for(j=0; j<tot-i-1; j++){
    if(dat[j].kode > dat[j+1].kode){
        temp = dat[j];
        dat[j] = dat[j+1];
        dat[j+1] = temp;}
        }
    }
}

void tambahData() {
    system ("cls");
    gotoxy(51, 11);
    printf("Tambah Data Makanan");

    gotoxy(26, 14);
    printf(" Masukan Jumlah Data Buku Yang Dimasukan : ");
    scanf("%d", &jum);

    for(int i = 0; i < jum; i++) {
        system("cls");
        gotoxy(26, 13);
        printf("Tambah Data Makanan");

        gotoxy(26, 14);
        printf(" Masukan Jumlah Data Buku Yang Dimasukan : %d", jum);

        gotoxy(26, 16);
        printf(" Data ke %d", i + 1);
        gotoxy(26, 17);
        printf(" Stok           : ");
        gotoxy(26, 18);
        printf(" Nama           : ");
        gotoxy(26, 19);
        printf(" Kode           : ");
        gotoxy(26, 20);
        printf(" Harga          : ");

        gotoxy(43, 17);
        scanf(" %[^\n]%*c", &dat[i + tot].stok);
        gotoxy(43, 18);
        scanf(" %[^\n]%*c", &dat[i + tot].nama);
        gotoxy(43, 19);
        scanf(" %d", &dat[i + tot].kode);
        gotoxy(43, 20);
        scanf(" %[^\n]%*c", &dat[i + tot].harga);

        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->barang = &dat[i + tot];

        if(head == NULL) {
            head = new_node;
            new_node->next = NULL;
        }
        else {
            struct node* temp_node = head;
            while(temp_node->next != NULL) {
                temp_node = temp_node->next;
            }
            temp_node->next = new_node;
            new_node->next = NULL;
        }
    }

    tot += jum;

    FILE *file = fopen("data_makanan.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file ");
        return;
    }
    struct node* temp_node = head;
    while(temp_node != NULL) {
        fprintf(file, "%s %s %d %s\n", temp_node->barang->stok, temp_node->barang->nama, temp_node->barang->kode, temp_node->barang->harga);
        temp_node = temp_node->next;
    }
    fclose(file);

    printf(" \t\t\t Data berhasil ditambahkan\n\ ");
    system("pause");
    system("cls");
}

 void tampilkan() {
    FILE *file = fopen("data_makanan.txt", "r");
    if (file == NULL) {
    printf(" Gagal membuka file\n ");
    return;
    }

    struct node *head = NULL;

    struct barang *d = malloc(sizeof(struct barang));
    while (fscanf(file, "%s %s %d %s", d->stok, d->nama, &d->kode, d->harga) != EOF) {


        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->barang = d;
        new_node->next = NULL;


        if(head == NULL) {
            head = new_node;
        }
        else {
            struct node *temp_node = head;
            while(temp_node->next != NULL) {
                temp_node = temp_node->next;
            }
            temp_node->next = new_node;
        }

        d = malloc(sizeof(struct barang));
    }

    fclose(file);

    int i = 1;
    struct node *temp_node = head;
    while(temp_node != NULL) {
        system("cls");
        gotoxy(26, 13);
        printf("  Daftar Makanan   ");
        gotoxy(26, 15);
        printf(" Data ke %d", i);
        gotoxy(26, 16);
        printf(" Stok                    :%s", temp_node->barang->stok);
        gotoxy(26, 17);
        printf(" Nama Barang             :%s", temp_node->barang->nama);
        gotoxy(26, 18);
        printf(" Kode Barang             :%d", temp_node->barang->kode);
        gotoxy(26, 19);
        printf(" Harga Barang            :%s", temp_node->barang->harga);
        getch();
        i++;
        temp_node = temp_node->next;
    }


    struct node *curr_node = head;
    while(curr_node != NULL) {
        struct node *temp_node = curr_node;
        curr_node = curr_node->next;
        free(temp_node);}
    free(d);}


