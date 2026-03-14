#include <stdio.h>
#include <string.h>

#define MAX_MENU 10
#define MAX_PESANAN 20

struct Menu {
    char nama[50];
    int harga;
    int tersedia; // 1 = tersedia, 0 = tidak
};

struct Pesanan {
    char namaMenu[50];
    int harga;
    int jumlah;
    int subtotal;
};

int main() {
    struct Menu menu[MAX_MENU] = {
        {"Nasi Goreng", 15000, 1},
        {"Mie Goreng", 13000, 1},
        {"Ayam Geprek", 18000, 1},
        {"Es Teh", 5000, 1},
        {"Kopi", 7000, 1},
        {"Jus Alpukat", 12000, 0}
    };

    struct Pesanan pesanan[MAX_PESANAN];

    int jumlahMenu = 6;
    int jumlahPesanan = 0;
    int pilihan, jumlah;
    int totalBayar = 0;
    int totalTransaksiHarian = 0;

    printf("=====================================\n");
    printf(" SISTEM OPERASIONAL KAFETARIA IT DEL \n");
    printf("=====================================\n\n");

    printf("Daftar Menu:\n");
    for (int i = 0; i < jumlahMenu; i++) {
        printf("%d. %-15s Rp%-6d [%s]\n",
               i + 1,
               menu[i].nama,
               menu[i].harga,
               menu[i].tersedia ? "Tersedia" : "Habis");
    }
    printf("0. Selesai memesan\n");

    while (1) {
        printf("\nPilih menu (0 untuk selesai): ");
        scanf("%d", &pilihan);

        if (pilihan == 0) {
            break;
        }

        if (pilihan < 1 || pilihan > jumlahMenu) {
            printf("Pilihan tidak valid.\n");
            continue;
        }

        if (menu[pilihan - 1].tersedia == 0) {
            printf("Maaf, menu %s sedang tidak tersedia.\n", menu[pilihan - 1].nama);
            continue;
        }

        printf("Masukkan jumlah pesanan: ");
        scanf("%d", &jumlah);

        if (jumlah <= 0) {
            printf("Jumlah pesanan harus lebih dari 0.\n");
            continue;
        }

        strcpy(pesanan[jumlahPesanan].namaMenu, menu[pilihan - 1].nama);
        pesanan[jumlahPesanan].harga = menu[pilihan - 1].harga;
        pesanan[jumlahPesanan].jumlah = jumlah;
        pesanan[jumlahPesanan].subtotal = menu[pilihan - 1].harga * jumlah;

        totalBayar += pesanan[jumlahPesanan].subtotal;
        jumlahPesanan++;

        printf("Pesanan ditambahkan.\n");
    }

    printf("\n=========== DAFTAR PESANAN ===========\n");
    if (jumlahPesanan == 0) {
        printf("Tidak ada pesanan.\n");
    } else {
        for (int i = 0; i < jumlahPesanan; i++) {
            printf("%d. %-15s x%d = Rp%d\n",
                   i + 1,
                   pesanan[i].namaMenu,
                   pesanan[i].jumlah,
                   pesanan[i].subtotal);
        }
        printf("-------------------------------------\n");
        printf("Total yang harus dibayar : Rp%d\n", totalBayar);
    }

    totalTransaksiHarian += totalBayar;

    printf("\n========= RINGKASAN TRANSAKSI ========\n");
    printf("Jumlah item dipesan      : %d\n", jumlahPesanan);
    printf("Total transaksi          : Rp%d\n", totalBayar);
    printf("Total transaksi harian   : Rp%d\n", totalTransaksiHarian);
    printf("=====================================\n");

    return 0;
}