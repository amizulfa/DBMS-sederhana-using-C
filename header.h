/*
    Saya Amida Zulfa Laila NIM 2101147 mengerjakan evaluasi Tugas
    Masa Depan dalam mata kuliah Algoritma dan Pemrograman II untuk
    keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah
    dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// bungkusan untuk menampung primary key, dan nilai dari kolom 2, 3, dan 4
typedef struct
{
    char pk[50];      // menampung primary key untuk kolom 1
    char value1[100]; // menampung suatu nilai untuk kolom 2
    char value2[100]; // menampung suatu nilai untuk kolom 3
    char value3[100]; // menampung suatu nilai untuk kolom 4
} structGlobal;

int idx, wlen, idxQuery, idxProduct, idxBrand; // variabel indeks mesin kata, panjang kata mesin kata, indeks query, indeks produk, dan indeks brand
char cw[50], query[100][100];                  // variabel untuk menampung string kata mesin kata dan query
FILE *fdata;                                   // variabel penampung sementara isi file
structGlobal tProduct[200];                    // struct untuk menampung tabel produk
structGlobal tBrand[200];                      // struct untuk menampung tabel brand

void input(char pita[]);                                 // prosedur memasukan inputan query
void resetQuery();                                       // prosedur untuk mereset query
void loadData();                                         // prosedur untuk membaca atau mode read file tabel brand dan tabel produk
void saveData();                                         // prosedur untuk menulis atau mode write ke dalam file tabel brand dan tabel produk
int seqSearch(structGlobal arr[], int n, char search[]); // fungsi sequential search untuk menemukan primary key suatu tabel
void entriData();                                        // prosedur untuk query ENTRI data
void tampilData();                                       // prosedur untuk query TAMPIL data
void hapusData();                                        // prosedur untuk query HAPUS data
void ubahData();                                         // prosedur untuk query UBAH data

//fungsi dan prosedur mesin kata
void startKata(char pita[]);                             // prosedur untuk memulai mesin kata
void resetKata();                                        // prosedur untuk mereset mesin kata
void inc(char pita[]);                                   // prosedur untuk memajukan kata
char *getcw();                                           // prosedur untu mendapatkan kata saat ini
int getwlen();                                           // fungsi untuk mendapatkan panjang kata saat ini
int EOP(char pita[]);                                    // fungsi untuk memeriksa akhir dari proses (end of processs)