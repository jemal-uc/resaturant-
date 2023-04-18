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



