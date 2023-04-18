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


