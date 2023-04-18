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



