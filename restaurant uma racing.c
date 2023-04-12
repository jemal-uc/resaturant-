#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

char user[10], pass[10];
int login_attempt = 1, max_login_attempt = 3;

void login() {
    // Isi fungsi menu di sini
}
void gotoxy (int x, int y) // Tempat pemangilan - menaruh output/text sesuai kordinasi sumbu X & Y
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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

    for(i=1; i <= 25; i++) // Perulangan kotak loading 25
    {
        printf("%c", 254); // Kode tampilan kotak
        Sleep (20);
    }
    for(i=1; i <= 15; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (300);
    }
    for(i=1; i <= 25; i++) // Perulangan kotak loading 25
    {
        printf("%c", 254);
        Sleep (50);
    }
    for(i=1; i <= 15; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (300);
    }
    for(i=1; i <= 37; i++) // Perulangan kotak loading 37
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
    system ("cls");
    gotoxy(52, 11);
    printf("masuk program  ketik 1 \n \t\t\t\t\t\t\tkeluar ketik 2");
    gotoxy(52, 13);
    printf ("input : ");
    scanf(" %i", &op);

    switch (op)
    {
    case 1:
        menu();
        break;
    case 2:
        exit(1);
        break;
        gotoxy(52, 14);
    default :
        printf("inputan tidak ada \n\n");
        break;
    }
    getch();
    system ("cls");
}



int menu()
{
    int beli;

    system("cls");
    system ("color e1");
    int ni, banyak_data;
    for (int i=0; ni !=4; i++)
    {
        gotoxy(52, 9);
        printf ("menu utama\n");
        gotoxy(51, 10);
        printf("==================\n");
        gotoxy(51, 11);
        printf ("1. data makanan \n");
        gotoxy(51, 12);
        printf ("2. riwayat transaksi \n");
        gotoxy(51, 13);
        printf ("3. keluar \n");
        gotoxy(51, 14);
        printf("==================\n");
        gotoxy(52, 15);
        printf ("input : ");
        scanf(" %i", &ni);
        switch (ni)
        {
        case 1:
            dataBarang();

        case 3:
            exit(1);
            break;
            gotoxy(51, 10);
        default :
            printf("inputan tidak ada \n\n");
            break;
        }
        getch();
        system ("cls");
    }
    return 0;
}

struct barang
{
    char nama_br[30], stok_br[30];
    int pil, kode;
    float harga;
    struct barang *next;

}*head, *tail, *current;

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

        printf ("2. menu \n");
        gotoxy(51, 13);

        printf ("3. Edit data menu \n");
        gotoxy(51, 14);

        printf ("4. Hapus data menu \n");
        gotoxy(51, 15);
        printf ("5. keluar \n");
        gotoxy(52, 16);
        printf ("------------------\n");
        gotoxy(52, 17);
        printf ("input : ");
        scanf(" %i", &pilih);
        switch (pilih)
        {
        case 5:
            menu();
            break;
            gotoxy(51, 12);
        default :
            printf("inputan tidak ada \n\n");
            break;
        }
        getch();
        system ("cls");
    }
    return 0;
}

