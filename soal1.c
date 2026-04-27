/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 (Structures and Dynimic Arrays)
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : Davina Alya Shakira (13224081)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program untuk menerima data kecepatan angin sampai sinyal penghenti (-1) diterima, lalu menyimpan data dalam array dinamis, mengurutkan data, dan menghitung median kecepatan angin selama periode pengamatan.
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float Median(int *arr, int n) {
    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}

int main() {
    int *arr = NULL;
    int count = 0;
    int n;

    printf("");
    while (1) {
        scanf("%d", &n);
        if (n == -1) {
            break;  
        }
        arr = realloc(arr, (count + 1) * sizeof(int));
        arr[count] = n;
        count++;
    }

    if (count == 0) {
        return 0;
    }

    sort(arr, count);

    printf("COUNT %d", count);
    printf(" SORTED");
    for (int i = 0; i < count; i++) {
        printf(" %d", arr[i]);
    }
    printf(" MEDIAN %.2f", Median(arr, count));

    free(arr);

    return 0;
}


