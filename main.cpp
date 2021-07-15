#include <bits/stdc++.h>
using namespace std;
#define MAX_CONTACT 1000

/*
    Dibuat oleh: Naufal Faadhilah
    NRP: 5025201221
    Struktur Data C
    Institut Teknologi Sepuluh Nopember
*/

struct kontak{ //struct kontak untuk menyimpan data nama dan nomor kontak
    string nama, nomor;
};

struct buku_telepon{ /*struct buku telepon untuk menyimpan sekumpulan 
                       kontak dan banyak kontak yang tersimpan*/
    vector<kontak> daftar;
    unsigned banyak_kontak=0;
};

buku_telepon buku;
kontak temp_kontak;
char temp_nama[100], temp_nomor[100];
FILE *fptr;

/* Daftar fungsi */

void logo(); //fungsi untuk menampilkan logo aplikasi
bool urut_nama_ascending(kontak a, kontak b); //fungsi komparasi untuk mengurutkan data
bool urut_nama_descending(kontak a, kontak b); //fungsi komparasi untuk mengurutkan data
bool urut_nomor_ascending(kontak a, kontak b); //fungsi komparasi untuk mengurutkan data
bool urut_nomor_descending(kontak a, kontak b); //fungsi komparasi untuk mengurutkan data
bool urut_acak(kontak a, kontak b); //fungsi komparasi untuk sortir secara acak
void mulai(); /*fungsi untuk membuka file, memindahkan data di dalam file ke dalam
                program dan mengurutkan data kontak*/
void print_kontak(); //fungsi untuk menampilkan kontak kepada pengguna
void tampilkan_data_terurut(); /*fungsi utama untuk menampilkan data terurut sesuai dengan yang
                                 diinginkan pengguna*/
void tambah_kontak(); //fungsi untuk menambah kontak ke dalam data
void hapus_kontak(); //fungsi untuk menghapus kontak yang sudah ada
void edit_kontak(); //fungsi untuk melakukan perubahan data pada kontak yang sudah ada
void modifikasi_data(); // fungsi utama untuk melakukan modifikasi terhadap data
void cari_data(); //fungsi untuk mencari data yang terdapat di dalam program
void tutup(); //fungsi untuk mengembalikan data pada file dalam keadaan acak

int main(){ //fungsi utama didalam program
    int perintah;
    mulai();
    logo();
    printf("\nSelamat datang\n");
    printf("Silahkan pilih perintah dibawah untuk menampilkan atau memodifikasi data\n");
    while(true){
        printf("0. Keluar\n");
        printf("1. Tampilkan data terurut\n");
        printf("2. Modifikasi data\n");
        printf("3. Cari data\n");
        scanf("%d", &perintah);
        if(perintah==0) break;
        else if(perintah==1) tampilkan_data_terurut();
        else if(perintah==2) modifikasi_data();
        else if(perintah==3) cari_data();
        else printf("\nMohon masukkan perintah yang valid \n");
        printf("\nSilahkan masukkan perintah kembali\n");
    }
    printf("\nTerimakasih telah menggunakan jasa kami\n");
    srand((unsigned)time(0));
    sort(buku.daftar.begin(), buku.daftar.end(), urut_acak);
    tutup();
    return 0;
}

void logo(){
    printf("\n\n");
    printf("     _______.   ___      .___  ___.      _______. __    __   __      \n");
    printf("    /       |  /   \\     |   \\/   |     /       ||  |  |  | |  |     \n");
    printf("   |   (----` /  ^  \\    |  \\  /  |    |   (----`|  |  |  | |  |     \n");
    printf("    \\   \\    /  /_\\  \\   |  |\\/|  |     \\   \\    |  |  |  | |  |     \n");
    printf(".----)   |  /  _____  \\  |  |  |  | .----)   |   |  `--'  | |  `----.\n");
    printf("|_______/  /__/     \\__\\ |__|  |__| |_______/     \\______/  |_______|\n");
}

bool urut_nama_ascending(kontak a, kontak b){
    return (a.nama.compare(b.nama)<0);
}

bool urut_nama_descending(kontak a, kontak b){
    return (a.nama.compare(b.nama)>0);
}

bool urut_nomor_ascending(kontak a, kontak b){
    return (a.nomor.compare(b.nomor)<0);
}

bool urut_nomor_descending(kontak a, kontak b){
    return (a.nomor.compare(b.nomor)>0);
}

bool urut_acak(kontak a, kontak b){
    return (rand()%2==1);
}

void mulai(){
    fptr=fopen("telepon.txt", "r+");
    int cek, i=0;
    rewind(fptr);
    while(true){
        cek=fscanf(fptr, "%[^\n]\n%s\n", temp_nama, temp_nomor);
        if(cek==EOF)break;
        temp_kontak.nama=temp_nama;
        temp_kontak.nomor=temp_nomor;
        if(buku.banyak_kontak<=MAX_CONTACT){
            buku.daftar.push_back(temp_kontak);
            buku.banyak_kontak++;
        }
    }
    buku.daftar.shrink_to_fit();
    sort(buku.daftar.begin(), buku.daftar.end(), urut_nama_ascending);
    fclose(fptr);
}

void print_kontak(){
    printf("\n\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("| NO.   | %-25s | %15s |\n", "N A M A", "N O.   T E L P");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	for(unsigned i=0; i<buku.banyak_kontak; i++){
        printf("|  %4u | %-25s | %15s |\n", i+1, buku.daftar[i].nama.c_str(), buku.daftar[i].nomor.c_str());
    	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    }
    printf("\n");
}

void tampilkan_data_terurut(){
    int perintah;
    bool cond=true;
    while(cond){
        printf("\nSilahkan pilih mode tampilan dibawah\n");
        printf("0. kembali\n");
        printf("1. Urut nama dari kecil ke besar\n");
        printf("2. Urut nama dari besar ke kecil\n");
        printf("3. Urut nomor dari kecil ke besar\n");
        printf("4. Urut nomor dari besar ke kecil\n");
        scanf("%d", &perintah);
        if(perintah==0) return;

        if(perintah==1){
            sort(buku.daftar.begin(), buku.daftar.end(), urut_nama_ascending);
            cond=false;
        }
        else if(perintah==2){
            sort(buku.daftar.begin(), buku.daftar.end(), urut_nama_descending);
            cond=false;
        }
        else if(perintah==3){
            sort(buku.daftar.begin(), buku.daftar.end(), urut_nomor_ascending);
            cond=false;
        }
        else if(perintah==4){
            sort(buku.daftar.begin(), buku.daftar.end(), urut_nomor_descending);
            cond=false;
        }
        else printf("\nMohon masukkan perintah yang valid\n\n");
    }
    print_kontak();
}

void tambah_kontak(){
    printf("Masukkan nama dan nomor yang ingin ditambahkan dengan dipisahkan oleh spasi\n");
    printf("Perlu diketahui, program hanya dapat membaca 1 kata nama saja\n");
    printf("Pastikan bahwa nama atau nomor yang ingin dimasukkan tidak ada di dalam data kontak\n");
    scanf("%s %s", temp_nama, temp_nomor);
    temp_kontak.nama=temp_nama;
    temp_kontak.nomor=temp_nomor;
    bool ada=false;
    for(int i=0; i<buku.banyak_kontak; i++){
        if(buku.daftar[i].nama==temp_kontak.nama or buku.daftar[i].nomor==temp_kontak.nomor){
            ada=true;
            break;
        }
    }
    if(ada) printf("Mohon maaf, nama atau nomor tersebut telah terdaftar di dalam data kontak\n");
    else{
        buku.daftar.push_back(temp_kontak);
        buku.banyak_kontak++;
        printf("Kontak baru telah berhasil ditambahkan!\n\n");
    }
}

void hapus_kontak(){
    printf("Masukkan nama dan nomor yang ingin dihapus dengan dipisahkan oleh spasi\n");
    printf("Perlu diketahui, program hanya dapat membaca 1 kata nama saja\n");
    printf("Pastikan bahwa nama atau nomor yang ingin dimasukkan terdaftar di dalam data kontak\n");
    scanf("%s %s", temp_nama, temp_nomor);
    temp_kontak.nama=temp_nama;
    temp_kontak.nomor=temp_nomor;
    for(auto it=buku.daftar.begin(); it!=buku.daftar.end(); ++it){
        if(it->nama==temp_kontak.nama and it->nomor==temp_kontak.nomor){
            printf("\nKontak tersebut berhasil ditemukan\n");
            buku.daftar.erase(it);
            buku.daftar.shrink_to_fit();
            buku.banyak_kontak--;
            printf("\nPenghapusan kontak berhasil dilakukan!\n");
            return;
        }
    }
    printf("\nMohon maaf, kontak yang dicari tidak ditemukan di dalam data\n");
}

void edit_kontak(){
    printf("Masukkan nama dan nomor yang ingin diedit dengan dipisahkan oleh spasi\n");
    printf("Perlu diketahui, program hanya dapat membaca 1 kata nama saja\n");
    printf("Pastikan bahwa nama dan nomor yang ingin dimasukkan terdaftar di dalam data kontak\n");
    scanf("%s %s", temp_nama, temp_nomor);
    temp_kontak.nama=temp_nama;
    temp_kontak.nomor=temp_nomor;
    for(int i=0; i<buku.banyak_kontak; i++){
        if(buku.daftar[i].nama==temp_kontak.nama and buku.daftar[i].nomor==temp_kontak.nomor){
            printf("\nKontak tersebut berhasil ditemukan\n");
            printf("Silahkan masukkan nama dan nomor kontak yang baru\n");
            scanf("%s %s", temp_nama, temp_nomor);
            buku.daftar[i].nama=temp_nama;
            buku.daftar[i].nomor=temp_nomor;
            printf("\nPengeditan kontak berhasil dilakukan!\n");
            return;
        }
    }
    printf("\nMohon maaf, kontak yang dicari tidak ditemukan di dalam data\n");
}

void modifikasi_data(){
    int perintah;
    bool cond=true;
    while(cond){
        printf("\nSilahkan pilih mode modifikasi dibawah\n");
        printf("0. kembali\n");
        printf("1. Tambah kontak\n");
        printf("2. Hapus kontak\n");
        printf("3. Edit kontak\n");
        scanf("%d", &perintah);
        if(perintah==0) return;

        if(perintah==1){
            cond=false;
            tambah_kontak();
        }
        else if(perintah==2){
            cond=false;
            hapus_kontak();
        }
        else if(perintah==3){
            cond=false;
            edit_kontak();
        }
        else printf("\nMohon masukkan perintah yang valid\n\n");
    }
}

void cari_data(){
    int perintah;
    bool cond=true;
    while(cond){
        temp_kontak.nama.clear();
        temp_kontak.nomor.clear();
        printf("\nSilahkan pilih mode pencarian dibawah\n");
        printf("0. kembali\n");
        printf("1. Cari nama\n");
        printf("2. cari nomor\n");
        scanf("%d", &perintah);
        if(perintah==0) return;

        if(perintah==1){
            printf("\nSilahkan masukkan nama kontak yang akan dicari\n");
            printf("Perlu diketahui bahwa program hanya dapat membaca 1 kata nama saja\n");
            scanf("%s", temp_nama);
            temp_kontak.nama=temp_nama;
            cond=false;
        }
        else if(perintah==2){
            printf("\nSilahkan masukkan nomor kontak yang akan dicari\n");
            scanf("%s", temp_nomor);
            temp_kontak.nomor=temp_nomor;
            cond=false;
        }
        else printf("\nMohon masukkan perintah yang valid\n\n");
    }
    for(int i=0; i<buku.banyak_kontak; i++){
        if(buku.daftar[i].nama==temp_kontak.nama or buku.daftar[i].nomor==temp_kontak.nomor){
            printf("\nKontak dengan nama atau nomor yang dicari telah ditemukan\n");
            printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
            printf("| %-25s | %15s |\n", buku.daftar[i].nama.c_str(), buku.daftar[i].nomor.c_str());
    	    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
            return;
        }
    }
    printf("\nKontak dengan nama atau nomor yang dicari tidak dapat ditemukan\n");
}

void tutup(){
    fptr=fopen("telepon.txt", "w+");
    rewind(fptr);
    for(int i=0; i<buku.banyak_kontak; i++){
        fprintf(fptr, "%s\n%s\n", buku.daftar[i].nama.c_str(), buku.daftar[i].nomor.c_str());
    }
    fclose(fptr);
}