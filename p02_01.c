#include <stdio.h>
#include <string.h>

int main() {

    char kode[4];
    char kota[20];
    char keterangan[20];
    char promo[50];

    float beratButet, beratUcok, totalBerat;
    float ongkirPerKg, totalOngkir, diskon, totalBayar;

    while (1) {

        printf("\nMasukkan kode kota (atau END untuk berhenti): ");
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            printf("Program selesai.\n");
            break;
        }

        printf("Masukkan berat paket Butet (kg): ");
        scanf("%f", &beratButet);

        if (strcmp(kode, "MDN") == 0) {
            strcpy(kota, "Medan");
            ongkirPerKg = 8000;
            strcpy(keterangan, "Dalam Pulau");
        }
        else if (strcmp(kode, "BLG") == 0) {
            strcpy(kota, "Balige");
            ongkirPerKg = 5000;
            strcpy(keterangan, "Dalam Pulau");
        }
        else if (strcmp(kode, "JKT") == 0) {
            strcpy(kota, "Jakarta");
            ongkirPerKg = 12000;
            strcpy(keterangan, "Luar Pulau");
        }
        else if (strcmp(kode, "SBY") == 0) {
            strcpy(kota, "Surabaya");
            ongkirPerKg = 13000;
            strcpy(keterangan, "Luar Pulau");
        }
        else {
            printf("Kode kota tidak valid!\n");
            continue;
        }

        beratUcok = 1.5 * beratButet;
        totalBerat = beratButet + beratUcok;

        totalOngkir = totalBerat * ongkirPerKg;

        diskon = 0;
        if (totalBerat > 10) {
            diskon = totalOngkir * 0.10;
        }

        totalBayar = totalOngkir - diskon;

        if (strcmp(keterangan, "Luar Pulau") == 0) {
            strcpy(promo, "Asuransi Gratis");
        } else {
            strcpy(promo, "Tidak Ada");
        }

        printf("\n===== STRUK DEL-EXPRESS =====\n");
        printf("Kota Tujuan       : %s\n", kota);
        printf("Berat Butet       : %.2f kg\n", beratButet);
        printf("Berat Ucok        : %.2f kg\n", beratUcok);
        printf("Total Berat       : %.2f kg\n", totalBerat);
        printf("Ongkir/kg         : %.0f\n", ongkirPerKg);
        printf("Total Ongkir      : %.0f\n", totalOngkir);
        printf("Diskon            : %.0f\n", diskon);
        printf("Total Bayar       : %.0f\n", totalBayar);
        printf("Promo             : %s\n", promo);
        printf("=============================\n");

    }

    return 0;
}