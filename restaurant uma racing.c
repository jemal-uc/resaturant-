#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

void gotoxy (int x, int y) // Tempat pemangilan - menaruh output/text sesuai kordinasi sumbu X & Y
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
char str [] = "x+";
        gotoxy(52, 10);
        system("color e1");
        system("color e1");
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
}
