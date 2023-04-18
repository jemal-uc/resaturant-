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
    dataBarang();
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


void urutData() {
    int temp;
    char temps[30];

    FILE *file = fopen("data_makanan.txt", "r");
    if (file == NULL) {
    printf("  Gagal membuka file\n ");
    return;
    }
    while(fscanf(file, "%s %s %d %s", dat[tot].stok, dat[tot].nama, &dat[tot].kode, dat[tot].harga) != EOF) {

        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->barang = &dat[tot];

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
        tot++;
    }
    fclose(file);

    for (int i = 0; i < tot -1; i++) {
        for (int j = 0; j < tot -i -1; j++) {
            if (dat[j].kode > dat[j+1].kode) {
                temp = dat[j].kode;
                dat[j].kode = dat[j+1].kode;
                dat[j+1].kode = temp;

                strcpy(temps, dat[j].nama);
                strcpy(dat[j].nama, dat[j+1].nama);
                strcpy(dat[j+1].nama, temps);

                strcpy(temps, dat[j].stok);
                strcpy(dat[j].stok, dat[j+1].stok);
                strcpy(dat[j+1].stok, temps);

                strcpy(temps, dat[j].harga);
                strcpy(dat[j].harga, dat[j+1].harga);
                strcpy(dat[j+1].harga, temps);

                strcpy(temps, dat[j].telp);
                strcpy(dat[j].telp, dat[j+1].telp);
                strcpy(dat[j+1].telp, temps);
            }
        }
    }

    file = fopen("data_makanan.txt", "w");
    if (file == NULL) {
        printf(" Gagal membuka file\n ");
        return;
    }
    struct node* temp_node = head;
    while(temp_node != NULL) {
        fprintf(file, "%s %s %d %s\n", temp_node->barang->stok, temp_node->barang->nama, temp_node->barang->kode, temp_node->barang->harga);
        temp_node = temp_node->next;
    }
    fclose(file);

    printf(" \t\t\tData berhasil diurutkan berdasarkan Kode Barang\n ");
    system("pause");
    system("cls");
}

void mencariData(){
    system ("cls");
    int oy;
    gotoxy(26,13);
    printf("   Pencarian Data Barang   ");
    gotoxy (26,15);
    printf("Masukkan Kode Barang: ");
    scanf("%d", &oy);

    char filename[] = "data_makanan.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf(" Gagal membuka file\n ");
        return;
    }
    struct node* head = NULL;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        struct barang* new_data = malloc(sizeof(struct barang));
        sscanf(line, "%s %s %d %s", new_data->stok, new_data->nama, &new_data->kode, new_data->harga);
        struct node* new_node = malloc(sizeof(struct node));
        new_node->barang = new_data;
        if (head == NULL) {
            head = new_node;
            head->next = NULL;
        } else {
            struct node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = NULL;
        }
    }
    fclose(file);

    struct node* temp = head;
    while (temp != NULL) {
        if (temp->barang->kode == oy) {

            gotoxy (26,17);
            printf("    Data Tersedia    ");
            gotoxy (26,19);
            printf(" Stok           : %s", temp->barang->stok);
            gotoxy (26,20);
            printf(" Nama Barang    : %s", temp->barang->nama);
            gotoxy (26,21);
            printf(" Kode           : %d", temp->barang->kode);
            gotoxy (26,22);
            printf(" Harga          : %s", temp->barang->harga);
            getch();
            dataBarang();
            return;
        }
        temp = temp->next;
    }

    gotoxy (26,24);
    printf("   Data tidak ditemukan   ");
    getch();
    dataBarang();
}


void hapusData() {
    system ("cls");
    int kodeBarang;
    struct node *temp_node = head, *prev_node;

    gotoxy(26,13);
    printf("    Hapus Data Barang   ");
    gotoxy(26,15);
    printf("Masukkan Kode Barang : ");
    scanf("%d", &kodeBarang);

    while (temp_node != NULL && temp_node->barang->kode != kodeBarang) {
        prev_node = temp_node;
        temp_node = temp_node->next;
    }

    if (temp_node == NULL) {
        printf("\n\t\t\t\tData tidak ditemukan.\n");
    } else {
        gotoxy(26,17);
        printf("Data Barang berikut akan dihapus :");
        gotoxy(26,19);
        printf(" Stok          : %s", temp_node->barang->stok);
        gotoxy(26,20);
        printf(" Nama          : %s", temp_node->barang->nama);
        gotoxy(26,21);
        printf(" Kode          : %d", temp_node->barang->kode);
        gotoxy(26,22);
        printf(" Harga         : %s", temp_node->barang->harga);

        char jawab;
        printf("\n\n\t\t\t Yakin ingin menghapus data ini? ");
        scanf(" %c", &jawab);

        if (jawab == 'Y' || jawab == 'y') {
            if (temp_node == head) {
                head = head->next;
            } else {
                prev_node->next = temp_node->next;
            }
            free(temp_node);

            FILE *file = fopen("data_makanan.txt", "w");
            if (file == NULL) {
                printf(" 31mGagal membuka file\n ");
                return;
            }
            temp_node = head;
            while (temp_node != NULL) {
                fprintf(file, "%s %s %d %s\n", temp_node->barang->stok, temp_node->barang->nama, temp_node->barang->kode, temp_node->barang->harga);
                temp_node = temp_node->next;
            }
            fclose(file);

            tot--;
            printf("\n\t\t\t\tData berhasil dihapus.\n");
        } else {
            printf("\n\t\t\t\tPenghapusan data dibatalkan.\n");
        }
    }
    system("pause");
    system("cls");
    dataBarang();
}



void edit() {
    system ("cls");
    char stemp[30], search[30], temps[100];
    int jaw = 0;
    gotoxy(26, 9);
    printf(" --- Ubah Data makanan --- ");
    gotoxy(26, 11);
    printf("Masukkan Kode  : ");
    scanf("%d", &oy);

    cari();

    result = 0;
    for (x = 0; x <= tot; x++) {
        if (oy == dat[x].kode) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        gotoxy(26, 13);
        printf("Data Barang berikut akan Diubah :");
        gotoxy(26, 15);
        printf(" Stok           : %s", dat[x].stok);
        gotoxy(26, 16);
        printf(" Nama           : %s", dat[x].nama);
        gotoxy(26, 17);
        printf(" Kode           : %d", dat[x].kode);
        gotoxy(26, 18);
        printf(" Harga          : %s", dat[x].harga);

        gotoxy(26, 20);
        printf("Pilih Data yang akan diganti ");
        gotoxy(26, 22);
        printf("1. Stok  ");
        gotoxy(26, 23);
        printf("2. Nama  ");
        gotoxy(26, 24);
        printf("3. Kode  ");
        gotoxy(26, 25);
        printf("4. Harga  ");
        gotoxy(26, 26);
        printf("5. kembali ");
        gotoxy(26, 28);
        printf("Pilihan : ");
        scanf("%d", &jaw);

        switch (jaw) {
            case 1:
                gotoxy(26, 31);
                printf("Masukkan Stok baru        : ");
                scanf(" %[^\n]%*c", &stemp);
                strcpy(dat[x].stok, stemp);
                break;
            case 2:
                gotoxy(26, 31);
                printf("Masukkan Nama Barang baru : ");
                scanf(" %[^\n]%*c", &stemp);
                strcpy(dat[x].nama, stemp);
                break;
            case 3:
                gotoxy(26, 31);
                printf("Masukkan Kode barang baru : ");
                scanf("%d", &temp);
                dat[x].kode = temp;
                break;
            case 4:
                gotoxy(26, 31);
                printf("Masukkan Harga Barang baru : ");
                scanf(" %[^\n]%*c", &stemp);
                            strcpy(dat[x].harga, stemp);
            break;
        case 5:
            return;
            dataBarang();
        default:
            gotoxy(26, 31);
            printf(" Input tidak valid, silakan coba lagi! ");
            dataBarang();
            break;
    }

    FILE *fp = fopen("data_makanan.txt", "w");
    if (fp == NULL) {
        printf(" Gagal membuka file\n ");
        return;
    }

    for (int i = 0; i < tot; i++) {
        fprintf(fp, "%s %s %d %s\n", dat[i].stok, dat[i].nama, dat[i].kode, dat[i].harga);
    }

    fclose(fp);

    printf(" Data berhasil diubah!\n ");
    system("pause");
} else {
    gotoxy(26, 17);
    printf(" Data tidak ditemukan!\n ");
    system("pause");
}
system("cls");
}

//LOGIN
char user[10], pass[10];
int login_attempt = 1, max_login_attempt = 3;

int main() {
 char str [] = "x+";
        gotoxy(52, 10);
        system("color e1");
        int op;
        Sleep(100);printf(" U");Sleep(100);printf("M");Sleep(100);printf("A ");Sleep(100);printf("RESTAURANT");Sleep(100);
        {
    int i;
    gotoxy(51, 11);
    printf ("    Loading ");
    gotoxy(1, 12);

    for(i=1; i <= 25; i++)
    {
        printf("%c", 254);
        Sleep (20);
    }
    for(i=1; i <= 15; i++)
    {
        printf("%c", 254);
        Sleep (300);
    }
    for(i=1; i <= 25; i++)
    {
        printf("%c", 254);
        Sleep (50);
    }
    for(i=1; i <= 15; i++)
    {
        printf("%c", 254);
        Sleep (300);
    }
    for(i=1; i <= 37; i++)
    {
        printf("%c", 254);
        Sleep (10);
    }
}
system ("cls");
    system("color e1");
   gotoxy(51, 10);
    printf (" Selamat datang \n");
    gotoxy(52, 11);
    printf ("====================\n");


    do {
       gotoxy(51, 10);
    printf (" Selamat datang \n");
    gotoxy(52, 11);
    printf ("====================\n");
    gotoxy(52, 12);
    printf("Masukan Username : ");
    scanf("%s",&user);
    gotoxy(52, 13);
    printf("Masukan Password : ");
    scanf("%s",&pass);

        if ((strcmp(user, "admin") == 0 && strcmp(pass, "111") == 0)) {
                gotoxy(52, 14);
            printf("Akses diterima. Selamat Datang\n\n");
            break;
        } else {
            gotoxy(52, 14);
            system("cls");
            printf("Username dan Password tidak match. ");
            printf("Anda masih memiliki %d kesempatan login \n", max_login_attempt - login_attempt);
            login_attempt++;

        }
    } while (login_attempt <= max_login_attempt);

    if (login_attempt > max_login_attempt) {
            gotoxy(52, 10);
        printf("Anda sudah mencoba login sebanyak %d kali. Akun anda diblokir.\n", max_login_attempt);
        return 0;
    }
    dataBarang();
    getch();
    system ("cls");
}

int dataBarang()
{
    system("cls");
    system ("color e1");
    int pilih, banyak_data;
    for (int i=0; pilih !=5; i++)
    {
        gotoxy(52, 9);
        printf ("list \n");
        gotoxy(51, 10);
        printf ("------------------\n");
        gotoxy(51, 11);

        printf ("1. Tambahkan menu \n");
        gotoxy(51, 12);

        printf ("2. menu makanan \n");
        gotoxy(51, 13);

        printf ("3. Hapus data menu\n");
        gotoxy(51, 14);

        printf ("4. Edit data menu \n");
        gotoxy(51, 15);

        printf ("5. Mencari data menu \n");
        gotoxy(51, 16);

        printf ("6. Urutkan data menu \n");
        gotoxy(51, 17);

        printf ("7. keluar \n");
        gotoxy(52, 18);
        printf ("------------------\n");
        gotoxy(52, 19);
        printf ("input : ");
        scanf(" %i", &pilih);
        switch (pilih)
        {
        case 1:
            tambahData();
            break;
        case 2:
            tampilkan();
            break;
        case 3:
             hapusData();
            break;
        case 4:
            edit();
            break;
        case 5:
            mencariData();
            break;
        case 6:
            urutData();

            break;
        case 7:
            system("cls");
            gotoxy(51, 14);
            printf("KELUAR");
            system('cls');
            break;
        default :

            gotoxy(51, 12);
            printf("inputan tidak ada \n\n");
            break;
        }
        getch();
        system ("cls");
    }
    return 0;
}


