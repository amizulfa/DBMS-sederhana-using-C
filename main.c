/*
    Saya Amida Zulfa Laila NIM 2101147 mengerjakan evaluasi Tugas
    Masa Depan dalam mata kuliah Algoritma dan Pemrograman II untuk
    keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah
    dispesifikasikan. Aamiin.
*/
#include "header.h"

int main()
{
    // membersihkan terminal/cmd
    system("cls");
    // deklarasi variabel
    char pita[500];
    int i;

    printf("Selamat Datang di DBMS Koreksian Amida\nVersi 1.0\n\n");
    while (strcmp(pita, "jangan lupa bahagia hari ini;") != 0 || strcmp(pita, "exit;") != 0) // selama bukan kalimat untuk keluar program
    {
        printf("DBMS Amida > ");
        input(pita); // memanggil prosedur input

        if (strcmp(pita, "jangan lupa bahagia hari ini;") == 0 || strcmp(pita, "exit;") == 0) // jika pita berisi string perintah keluar program
        {
            printf("Dadah Kakak, Terima Kasih sudah memakai DBMS Koreksian Amida!\n");
            exit(0); // keluar program
        }
        else
        {
            if (strcmp(query[0], "ENTRI") == 0 || strcmp(query[0], "entri") == 0) // jika query indeks ke 0 nya adalah ENTRI
            {
                // jika query indeks ke 1 nya adalah UBAH
                if (((strcmp(query[1], "UBAH") == 0 || strcmp(query[1], "ubah") == 0) && idxQuery <= 7) || ((strcmp(query[1], "Ubah") != 0 || strcmp(query[1], "UBah") != 0) && idxQuery <= 6))
                {
                    entriData(); // panggil prosedur Entri data
                }
                // jika query indeks ke 1 nya adalah HAPUS
                else if (((strcmp(query[1], "HAPUS") == 0 || strcmp(query[1], "hapus") == 0) && idxQuery <= 7) || ((strcmp(query[1], "Hapus") != 0 || strcmp(query[1], "HApus") != 0) && idxQuery <= 6))
                {
                    entriData(); // memanggil prosedur detail query
                }
                // jika masukan kolomnya berlebihan maka tampilkan error
                else
                {
                    printf("Error\nPesan Error : Maaf Kakak Kolom yang anda masukan lebih!\n\n"); // tampilkan pesan error
                }
            }
            else if (strcmp(query[0], "ENTRI") == 0 || strcmp(query[0], "entri") == 0) // jika query indeks ke 0 nya adalah ENTRI
            {
                entriData();
            }
            else if (strcmp(query[0], "HAPUS") == 0 || strcmp(query[0], "hapus") == 0) // jika query indeks ke 0 nya adalah HAPUS
            {
                hapusData(); // panggil prosedur hapus data
            }
            else if (strcmp(query[0], "UBAH") == 0 || strcmp(query[0], "ubah") == 0) // jika query indeks ke 0 nya adalah UBAH
            {
                ubahData(); // panggil prosedur Ubah data
            }
            else if (strcmp(query[0], "TAMPIL") == 0 || strcmp(query[0], "tampil") == 0) // jika query indeks ke 0 nya adalah TAMPIL
            {
                tampilData(); // panggil prosedur Tampil data
            }
            else // jika query nya bukanlah query yang sudah ditentukan
            {
                printf("Error\nPesan Error : Maaf Kakak Query '%s' tidak dikenali.\n\n", query[0]); // tampilkan pesan error
            }
        }
    }
    return 0;
}