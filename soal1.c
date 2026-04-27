/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 (Structures and Dynimic Arrays)
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : Davina Alya Shakira (13224081)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program untuk menerima data kecepatan angin sampai sinyal penghenti (-1) diterima, lalu menyimpan data dalam array dinamis, mengurutkan data, dan menghitung median kecepatan angin selama periode pengamatan.
 */

#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}

int main(){
    int *arr = NULL;
    int count = 0;
    int n;

    printf(""); /*Masukkan kecepatan angin hingga sinyal penghenti (-1)*/

    while (scanf("%d", &n) && n != -1) {
        arr = realloc(arr, (count + 1) * sizeof(int)); 
        if (arr == NULL) {
            return 1;
        }
        arr[count++] = n;
    }
    if (count == 0){
        return 1;
    }

    qsort(arr, count, sizeof(int), compare);

    printf("COUNT %d\n", count);
    printf("SORTED");
    for (int i = 0; i < count; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n"); 

    float median;
    if (count % 2 == 1){
        median = arr[count / 2];
    }
    else{
        median = (arr[count / 2 - 1] + arr[count / 2]) / 2.0;
    }

    printf("MEDIAN %.2f", median);

    free(arr);
    return 0;
}    
