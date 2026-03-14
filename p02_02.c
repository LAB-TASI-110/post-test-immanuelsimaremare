#include <stdio.h>

int main() {

    int n;
    
    printf("Masukkan jumlah data stok: ");
    scanf("%d", &n);

    int stok[n];
    int kategori[n];

    // Input stok dan kategori
    for(int i = 0; i < n; i++) {
        printf("Stok barang ke-%d: ", i+1);
        scanf("%d", &stok[i]);

        printf("Kategori barang ke-%d: ", i+1);
        scanf("%d", &kategori[i]);
    }

    int kategori_dicari;
    printf("Masukkan kategori yang ingin dihitung: ");
    scanf("%d", &kategori_dicari);

    int total = 0;

    // Menghitung total stok sesuai kategori
    for(int i = 0; i < n; i++) {
        if(kategori[i] == kategori_dicari) {
            total += stok[i];
        }
    }

    printf("Total stok untuk kategori %d adalah: %d\n", kategori_dicari, total);

    return 0;
}