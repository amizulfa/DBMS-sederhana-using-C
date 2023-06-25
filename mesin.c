/*
    Saya Amida Zulfa Laila NIM 2101147 mengerjakan evaluasi Tugas
    Masa Depan dalam mata kuliah Algoritma dan Pemrograman II untuk
    keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah
    dispesifikasikan. Aamiin.
*/
#include "header.h"
// prosedur untuk memulai mesin kata
void startKata(char pita[])
{
    // inisialisasi indeks dan panjang kata
    idx = 0;
    wlen = 0;
    // jika karakter dalam pita adalah spasi, indeks terus maju
    while (pita[idx] == ' ')
    {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((pita[idx] != ' ') && (EOP(pita) == 0))
    {
        cw[wlen] = pita[idx];
        idx++;
        wlen++;
    }
    // mengatur agar kata saat ini indeks terkahirnya menjadi NULL
    cw[wlen] = '\0';
}

// prosedur unutk mengosongkan kata yag dibaca dalam mesin kata
void resetKata()
{
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// prosedur untuk memajukan kata
void inc(char pita[])
{
    // inisialisasi ulang panjang kata
    wlen = 0;
    // jika karakter dalam pita adalah spasi, indeks terus maju
    while (pita[idx] == ' ')
    {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while (pita[idx] != ' ' && EOP(pita) == 0)
    {
        cw[wlen] = pita[idx];
        idx++;
        wlen++;
    }
    // mengatur agar kata saat ini indeks terkahirnya menjadi NULL
    cw[wlen] = '\0';
}

// fungsi untuk mendapatka kata saat ini
char *getcw()
{
    return cw;
}

// fungsi untuk endapatkan panjang kata saat ini
int getwlen()
{
    return wlen;
}

// fungsi untuk memeriksa akhir dari proses (end of process)
int EOP(char pita[])
{
    // memeriksa apakah karakter saat in merupakan simbol akhir pita
    if (pita[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void input(char pita[])
{                               // prosedur input
    resetQuery();               // memanggil prosedur reset query
    scanf(" %499[^\n]s", pita); // input pita

    // start mesin kata
    idxQuery = 0;
    startKata(pita);                  // memulai mesin kata
    strcpy(query[idxQuery], getcw()); // memasukan kata saat ini(cw)
    idxQuery++;                       // idxQuery nya bertambah 1
    while (EOP(pita) == 0)            // selama EOP nya bernilai 0
    {
        inc(pita);                        // memajukan kata
        strcpy(query[idxQuery], getcw()); // memasukan kata saat ini(cw) kedalam query
        idxQuery++;                       // idxQuery bertambah 1
    }
}

void resetQuery()
{ // prosedur reset query
    int i;
    for (i = 0; i < idxQuery; i++)
    {
        strcpy(query[i], "\0"); // setiap query menjadi null
    }
}

void loadData()
{                                       // prosedur load data atau mode read
    idxProduct = 0, idxBrand = 0;       // inisialisasi index product dan index brand nya =0
    fdata = fopen("fproduct.dat", "r"); // membuka file fproduct.dat dengan mode read
    fscanf(fdata, "%s %s %s %s", tProduct[idxProduct].pk, tProduct[idxProduct].value1, tProduct[idxProduct].value2, tProduct[idxProduct].value3);
    while (strcmp(tProduct[idxProduct].pk, "#####") != 0)
    {
        idxProduct++;
        fscanf(fdata, "%s %s %s %s", tProduct[idxProduct].pk, tProduct[idxProduct].value1, tProduct[idxProduct].value2, tProduct[idxProduct].value3);
    }
    fclose(fdata); // menutup file

    fdata = fopen("fbrand.dat", "r"); // membuka file fbrand.dat dengan mode read
    fscanf(fdata, "%s %s %s %s", tBrand[idxBrand].pk, tBrand[idxBrand].value1, tBrand[idxBrand].value2, tBrand[idxBrand].value3);
    while (strcmp(tBrand[idxBrand].pk, "#####") != 0)
    {
        idxBrand++;
        fscanf(fdata, "%s %s %s %s", tBrand[idxBrand].pk, tBrand[idxBrand].value1, tBrand[idxBrand].value2, tBrand[idxBrand].value3);
    }
    fclose(fdata); // menutup file
}

void saveData() // prosedur untuk menulis data ke dalam file.dat dengan mode write
{
    int i;

    fdata = fopen("fproduct.dat", "w"); // membuka file fproduct.dat dengan mode write
    for (i = 0; i < idxProduct; i++)
    {
        fprintf(fdata, "%s %s %s %s\n", tProduct[i].pk, tProduct[i].value1, tProduct[i].value2, tProduct[i].value3);
    }
    fprintf(fdata, "##### ##### ##### #####\n"); // end of file
    fclose(fdata);                               // menutup file

    fdata = fopen("fbrand.dat", "w"); // membuka file fbrand.dat dengan mode write
    for (i = 0; i < idxBrand; i++)
    {
        fprintf(fdata, "%s %s %s %s\n", tBrand[i].pk, tBrand[i].value1, tBrand[i].value2, tBrand[i].value3);
    }
    fprintf(fdata, "##### ##### ##### #####\n"); // end of file
    fclose(fdata);                               // menutup file
}

int seqSearch(structGlobal arr[], int n, char search[]) // fungsi sequential search
{
    int i = 0, found = 0;

    while (i < n && found == 0)
    {
        if (strcmp(arr[i].pk, search) == 0) // jika primary key ketemu
        {
            found = 1; // found menjadi 1
        }
        else // jika belum ketemu
        {
            i++; // i bertambah 1
        }
    }
    if (found == 1) // jika primary key ketemu
    {
        return i; // akan mereturn nilai i (indexnya)
    }
    else // jika tidak ketemu
    {
        return -1; // mereturn nilai -1
    }
}

void entriData()
{ // prosedur entri data
    int index, i;
    loadData();                                                         // menjalankan prosedur load data
    if (strcmp(query[1], "UBAH") == 0 || strcmp(query[1], "ubah") == 0) // jika query setelah entri adalah ubah
    {
        if (strcmp(query[2], "tproduct") == 0 || strcmp(query[2], "tProduct") == 0 || strcmp(query[2], "TPRODUCT") == 0) // jika input tabel tproduct
        {
            index = seqSearch(tProduct, idxProduct, query[3]); // mencari index primary key yang di input di dalam tabel
            if (index == -1)                                   // jika index primary key tidak ketemu
            {
                // maka jalankan query ENTRI
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
                // memasukan data kode produk sebagai primary key, nama produk, jenis produk, dan harga
                strcpy(tProduct[idxProduct].pk, query[3]);
                strcpy(tProduct[idxProduct].value1, query[4]);
                strcpy(tProduct[idxProduct].value2, query[5]);
                strcpy(tProduct[idxProduct].value3, query[6]);
                idxProduct++;
            }
            else // jika index primary key nya ketemu
            {
                // maka jalankan QUERY UBAH
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[1]);
                // maka mengupdate kolom nama produk, jenis produk, dan dan harga sesuai index primary key
                strcpy(tProduct[index].value1, query[4]);
                strcpy(tProduct[index].value2, query[5]);
                strcpy(tProduct[index].value3, query[6]);
            }
        }
        else if (strcmp(query[2], "tbrand") == 0 || strcmp(query[2], "tBrand") == 0 || strcmp(query[2], "TBRAND") == 0) // jika input tabel tbrand
        {
            index = seqSearch(tBrand, idxBrand, query[3]); // mencari index primary key yang di input di dalam tabel
            if (index == -1)                               // jika index primary key tidak ketemu
            {
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
                // memasukan data kode brand sebagai primary key, nama brand, asal brand, dan pendiri brand
                strcpy(tBrand[idxBrand].pk, query[3]);
                strcpy(tBrand[idxBrand].value1, query[4]);
                strcpy(tBrand[idxBrand].value2, query[5]);
                strcpy(tBrand[idxBrand].value3, query[6]);
                idxBrand++;
            }
            else // jika index primary key nya ketemu
            {
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[1]);
                // maka mengupdate kolom nama brand, asal brand, dan pendiri brand sesuai index primary key
                strcpy(tBrand[index].value1, query[4]);
                strcpy(tBrand[index].value2, query[5]);
                strcpy(tBrand[index].value3, query[6]);
            }
        }
        else // jika input tabel selain tabel yang tersedia
        {
            printf("[ERROR]\nPesan Error : Maaf Kakak Tabel '%s' tidak ada.", query[1]);
            printf("\nMasukan Format yang benar ya Kakak!\n"); // pesan error
        }
    }
    else if (strcmp(query[1], "HAPUS") == 0 || strcmp(query[1], "hapus") == 0) // jika query setelah entri adalah hapus
    {
        if (strcmp(query[2], "tproduct") == 0 || strcmp(query[2], "tProduct") == 0 || strcmp(query[2], "TPRODUCT") == 0) // jika input tabel tproduct
        {
            index = seqSearch(tProduct, idxProduct, query[3]); // mencari index primary key yang di input di dalam tabel
            if (index == -1)                                   // jika index primary key tidak ketemu
            {
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
                // memasukan data kode produk sebagai primary key, nama produk, jenis produk, dan harga
                strcpy(tProduct[idxProduct].pk, query[3]);
                strcpy(tProduct[idxProduct].value1, query[4]);
                strcpy(tProduct[idxProduct].value2, query[5]);
                strcpy(tProduct[idxProduct].value3, query[6]);
                idxProduct++;
            }
            else
            {
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[1]);
                // maka akan menghapus data pada tabel product
                for (i = index; i < idxProduct; i++)
                {
                    strcpy(tProduct[i].pk, tProduct[i + 1].pk);
                    strcpy(tProduct[i].value1, tProduct[i + 1].value1);
                    strcpy(tProduct[i].value2, tProduct[i + 1].value2);
                    strcpy(tProduct[i].value3, tProduct[i + 1].value3);
                }
                idxProduct--;
            }
        }
        else if (strcmp(query[2], "tbrand") == 0 || strcmp(query[2], "tBrand") == 0 || strcmp(query[2], "TBRAND") == 0) // jika input tabel tproduct
        {
            index = seqSearch(tBrand, idxBrand, query[3]); // mencari index primary key yang di input di dalam tabel
            if (index == -1)                               // jika index primary key tidak ketemu
            {
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
                // memasukan data kode produk sebagai primary key, nama produk, jenis produk, dan harga
                strcpy(tBrand[idxBrand].pk, query[3]);
                strcpy(tBrand[idxBrand].value1, query[4]);
                strcpy(tBrand[idxBrand].value2, query[5]);
                strcpy(tBrand[idxBrand].value3, query[6]);
                idxBrand++;
            }
            else
            { // jika index primary key nya ketemu, maka jalankan query hapus
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[1]);
                // maka akan menghapus data pada tabel product
                for (i = index; i < idxBrand; i++)
                {
                    strcpy(tBrand[i].pk, tBrand[i + 1].pk);
                    strcpy(tBrand[i].value1, tBrand[i + 1].value1);
                    strcpy(tBrand[i].value2, tBrand[i + 1].value2);
                    strcpy(tBrand[i].value3, tBrand[i + 1].value3);
                }
                idxBrand--;
            }
        }
        else // jika input tabel selain tabel yang tersedia
        {
            printf("[ERROR]\nPesan Error : Maaf Kakak Tabel '%s' tidak ada.", query[1]);
            printf("\nMasukan Format yang benar ya Kakak!\n\n"); // pesan error
        }
    }
    else // jika tidak ada query ubah dan hapus setelah entri
    {
        if (strcmp(query[1], "tproduct") == 0 || strcmp(query[1], "tProduct") == 0 || strcmp(query[1], "TPRODUCT") == 0) // jika tabelnya tproduct
        {
            index = seqSearch(tProduct, idxProduct, query[2]); // periksa indeks primary key nya
            if (index == -1)                                   // jika primary nya tidak ada atau belum ada
            {
                // maka dapat menjalankan perintah ENTRI
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
                // memasukan data kode produk sebagai primary key, nama produk, jenis produk, dan harga
                strcpy(tProduct[idxProduct].pk, query[2]);
                strcpy(tProduct[idxProduct].value1, query[3]);
                strcpy(tProduct[idxProduct].value2, query[4]);
                strcpy(tProduct[idxProduct].value3, query[5]);
                idxProduct++;
            }
            else // jika primary key nya sudah ada, maka tampilkan pesan eror bahwa primary key nya sudah ada atau sama
            {
                printf("[ERROR]\nPesan Error : Maaf Kakak Primary key '%s' sudah ada, silahkan ganti primary key nya ya Kakak!\n\n", query[2]);
            }
        }
        else if (strcmp(query[1], "tbrand") == 0 || strcmp(query[1], "tBrand") == 0 || strcmp(query[1], "TBRAND") == 0) // jika input tabel brand
        {
            index = seqSearch(tBrand, idxBrand, query[2]); // periksa indeks primary key nya
            if (index == -1)                               // jika primary nya tidak ada atau belum ada
            {
                // maka dapat menjalankan perintah ENTRI
                printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
                // memasukan data kode brand sebagai primary key, nama brand, asal brand, dan pendiri brand
                strcpy(tBrand[idxBrand].pk, query[2]);
                strcpy(tBrand[idxBrand].value1, query[3]);
                strcpy(tBrand[idxBrand].value2, query[4]);
                strcpy(tBrand[idxBrand].value3, query[5]);
                idxBrand++;
            }
            else // jika primary key nya sudah ada, maka tampilkan pesan eror bahwa primary key nya sudah ada atau sama
            {
                printf("[ERROR]\nPesan Error : Maaf Kakak Primary key '%s' sudah ada, silahkan ganti primary key nya ya Kakak!\n\n", query[2]);
            }
        }
        else // jika input tabel selain tabel yang tersedia
        {
            printf("[ERROR]\nPesan Error : Maaf Kakak Tabel '%s' tidak ada.", query[1]);
            printf("\nMasukan Format yang benar ya Kakak!\n\n"); // pesan error
        }
    }

    saveData(); // menjalankan prosedur save data
}

void ubahData()
{ // prosedur ubah data
    int i, index;
    loadData(); // menjalankan prosedur load data

    if (strcmp(query[1], "tproduct") == 0 || strcmp(query[1], "tProduct") == 0 || strcmp(query[1], "TPRODUCT") == 0) // jika input tabel produk
    {
        index = seqSearch(tProduct, idxProduct, query[2]); // mencari index primary key yang di input di dalam tabel
        if (index == -1)                                   // jika index primary key tidak ketemu
        {
            printf("[ERROR]\nPesan Error : Maaf Kakak Primary key tidak ditemukan.\n\n"); // tampilkan pesan error
        }
        else // jika index primary key nya ketemu
        {
            printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
            // mengupdate nama produk, jenis produk, dan dan harga sesuai index primary key
            strcpy(tProduct[index].value1, query[3]);
            strcpy(tProduct[index].value2, query[4]);
            strcpy(tProduct[index].value3, query[5]);
        }
    }
    else if (strcmp(query[1], "tbrand") == 0 || strcmp(query[1], "tBrand") == 0 || strcmp(query[1], "TBRAND") == 0) // jika input tabel brand
    {
        index = seqSearch(tBrand, idxBrand, query[2]); // mencari index primary key yang di input di dalam tabel
        if (index == -1)                               // jika index primary key tidak ketemu
        {
            printf("[ERROR]\nPesan Error : Maaf Kakak Primary key tidak ditemukan.\n\n"); // tampilkan pesan error
        }
        else // jika index primary key nya ketemu
        {
            printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
            // mengupdate nama brand, asal brand, dan pendiri brand sesuai index primary key
            strcpy(tBrand[index].value1, query[3]);
            strcpy(tBrand[index].value2, query[4]);
            strcpy(tBrand[index].value3, query[5]);
        }
    }
    else // jika input tabel selain tabel yang tersedia
    {
        printf("[ERROR]\nPesan Error : Maaf Kakak Tabel '%s' tidak ada.", query[1]);
        printf("\nMasukan Format yang benar ya Kakak!\n\n"); // pesan error
    }
    saveData(); // menjalankan prosedur save data
}

void tampilData()
{ // prosedur tampil data
    int i, j;
    loadData(); // menjalankan prosedur load data

    if ((strcmp(query[1], "tbrand") == 0 || strcmp(query[1], "tBrand") == 0 || strcmp(query[1], "TBRAND") == 0))
    { // jika input adalah tabel brand
        printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
        printf("Silahkan Kakak ini data nya!\n");
        printf("+-----------------------------------------------------+\n");
        printf("|                      Daftar Brand                   |\n");
        printf("+------------+------------+------------+--------------+\n");
        printf("| Kode Brand | Nama Brand | Asal Brand | Nama Pendiri |\n");
        printf("+------------+------------+------------+--------------+\n");
        for (i = 0; i < idxBrand; i++)
        {
            printf("|%12s|", tBrand[i].pk);    // print kode brand sebagai primary key dari tabel brand
            printf("%12s|", tBrand[i].value1); // print nama brand dari tabel brand
            printf("%12s|", tBrand[i].value2); // print asal brand dari tabel brand
            printf("%14s|", tBrand[i].value3); // print nama pendiri brand dari tabel brand
            printf("\n");
        }
        printf("+------------+------------+------------+--------------+\n");
        printf("%d rows in set.\n\n", idxBrand); // print output banyaknya baris
    }
    else if ((strcmp(query[1], "tproduct") == 0 || strcmp(query[1], "tProduct") == 0 || strcmp(query[1], "TPRODUCT") == 0))
    { // jika input adalah tabel produk
        printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
        printf("Silahkan Kakak ini data nya!\n");
        printf("+--------------------------------------------------------------------+\n");
        printf("|                            Daftar Product                          |\n");
        printf("+--------------+--------------+---------------+----------------------+\n");
        printf("| Kode Product | Nama Product | Jenis Product |          Harga       |\n");
        printf("+--------------+--------------+---------------+----------------------+\n");
        for (i = 0; i < idxProduct; i++)
        {
            printf("|%14s", tProduct[i].pk);        // print kode product sebagai primary key dari tabel product
            printf("|%14s", tProduct[i].value1);    // print nama product dari tabel product
            printf("|%15s", tProduct[i].value2);    // print jenis produk dari tabel product
            printf("|RP.%19s", tProduct[i].value3); // print dan harga dari tabel product
            printf("|\n");
        }
        printf("+--------------+--------------+---------------+----------------------+\n");
        printf("%d rows in set.\n\n", idxProduct); // print output banyaknya baris
    }
    else if ((strcmp(query[1], "tbrand") != 0 || strcmp(query[1], "tBrand") != 0 || strcmp(query[1], "TBRAND") != 0) && (strcmp(query[1], "tproduct") != 0 || strcmp(query[1], "tProduct") != 0 || strcmp(query[1], "TPRODUCT") != 0))
    { // jika input bukanlah tabel yang telah disediakan
        printf("[ERROR]\nPesan Error : Maaf Kakak Tabel '%s' tidak ada.", query[1]);
        printf("\nMasukan Format yang benar ya Kakak!\n"); // tampilkan pesan error
    }
}

void hapusData()
{ // prosedur hapus data
    int index, i;
    loadData(); // menjalankan prosedur load data

    if (strcmp(query[1], "tproduct") == 0 || strcmp(query[1], "tProduct") == 0 || strcmp(query[1], "TPRODUCT") == 0)
    {                                                      // jika input adalah tabel produk
        index = seqSearch(tProduct, idxProduct, query[2]); // mencari index primary key
        if (index == -1)                                   // jika primary key nya tidak ketemu
        {
            printf("[ERROR]\nPesan Error : Maaf Kakak Primary key tidak ditemukan.\n\n"); // tampilkan pesan error
        }
        else // jika primary key nya ketemu
        {
            printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
            // maka akan menghapus data pada tabel product
            for (i = index; i < idxProduct; i++)
            {
                strcpy(tProduct[i].pk, tProduct[i + 1].pk);
                strcpy(tProduct[i].value1, tProduct[i + 1].value1);
                strcpy(tProduct[i].value2, tProduct[i + 1].value2);
                strcpy(tProduct[i].value3, tProduct[i + 1].value3);
            }
            idxProduct--;
        }
    }
    else if (strcmp(query[1], "tbrand") == 0 || strcmp(query[1], "tBrand") == 0 || strcmp(query[1], "TBRAND") == 0)
    {                                                  // jika input adalah tabel brand
        index = seqSearch(tBrand, idxBrand, query[2]); // mencari index primary key
        if (index == -1)                               // jika index primary key nya tidak ketemu
        {
            printf("[ERROR]\nPesan Error : Maaf Kakak Primary key tidak ditemukan.\n\n"); // tampilkan pesan error
        }
        else // jika index primary key nya ketemu
        {
            printf("Perintah %s berhasil dijalankan Kakak!\n\n", query[0]);
            // maka akan menghapus data pada tabel brand
            for (i = index; i < idxBrand; i++)
            {
                strcpy(tBrand[i].pk, tBrand[i + 1].pk);
                strcpy(tBrand[i].value1, tBrand[i + 1].value1);
                strcpy(tBrand[i].value2, tBrand[i + 1].value2);
                strcpy(tBrand[i].value3, tBrand[i + 1].value3);
            }
            idxBrand--;
        }
    }
    else // jika input bukanlah tabel yang sudah disediakan
    {
        printf("[ERROR]\nPesan Error : Maaf Kakak Tabel '%s' tidak ada.", query[1]);
        printf("\nMasukan Format yang benar ya Kakak!\n\n"); // tampilkan pesan error
    }
    saveData(); // menjalankan prosedur save data
}