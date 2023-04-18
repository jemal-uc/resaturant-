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



