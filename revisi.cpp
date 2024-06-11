#include <iostream>
#include <string>
#include <cstdlib>  // Untuk fungsi rand() dan srand()
#include <ctime>    // Untuk fungsi time()
#include <fstream>  // Untuk operasi file

using namespace std;

// Struktur untuk menyimpan informasi pengirim dan penerima
struct info {
    string namaPengirim;
    string alamatPengirim;
    string kontakPengirim;
    string namaPenerima;
    string alamatPenerima;
    string kontakPenerima;
    string nomorResi;
    string tglKirim;
    float beratBarang;
    float harga;    // Tambahkan harga
};

// Fungsi untuk meng-generate nomor resi random sebanyak 4 digit
string generateNomorResi() {
    srand(time(0)); // Menginisialisasi seed random dengan waktu sekarang
    int resi = rand() % 9000 + 1000; // Meng-generate nomor random 4 digit
    return to_string(resi);
}

// Fungsi untuk menyimpan nomor resi ke dalam file
void simpanNomorResiKeFile(const string& nomorResi) {
    ofstream file("resi.txt");
    if (file.is_open()) {
        file << "Nomor Resi: " << nomorResi << endl;
        file.close();
        cout << "Nomor resi telah disimpan ke dalam file resi.txt" << endl;
    } else {
        cout << "Gagal membuka file resi.txt" << endl;
    }
}

int main() {
    info informasi;

    // Input informasi pengirim
    cout << "Masukkan informasi pengirim:" << endl;
    cout << "Nama Lengkap: ";
    getline(cin, informasi.namaPengirim);
    cout << "Alamat: ";
    getline(cin, informasi.alamatPengirim);
    cout << "Nomor Handphone: ";
    getline(cin, informasi.kontakPengirim);

    // Input informasi penerima
    cout << "Masukkan informasi penerima:" << endl;
    cout << "Nama Lengkap: ";
    getline(cin, informasi.namaPenerima);
    cout << "Alamat: ";
    getline(cin, informasi.alamatPenerima);
    cout << "Nomor Handphone: ";
    getline(cin, informasi.kontakPenerima);

    // Generate nomor resi random
    informasi.nomorResi = generateNomorResi();

    // Simpan nomor resi ke dalam file
    simpanNomorResiKeFile(informasi.nomorResi);

    // Input tgl kirim
    cout << "Masukkan tanggal pengiriman (dd/mm/yyyy): ";
    cin >> informasi.tglKirim;

    // Input berat barang
    cout << "Masukkan berat barang (dalam gram): ";
    cin >> informasi.beratBarang;

    // Input harga
    cout << "Masukkan harga (dalam rupiah): ";
    cin >> informasi.harga;

    // Menampilkan resi barang
    cout << "\n=== Resi Barang ===" << endl;
    cout << "Informasi Pengirim:" << endl;
    cout << "Nama Lengkap: " << informasi.namaPengirim << endl;
    cout << "Alamat: " << informasi.alamatPengirim << endl;
    cout << "Nomor Handphone: " << informasi.kontakPengirim << endl;

    cout << "\nInformasi Penerima:" << endl;
    cout << "Nama Lengkap: " << informasi.namaPenerima << endl;
    cout << "Alamat: " << informasi.alamatPenerima << endl;
    cout << "Nomor Handphone: " << informasi.kontakPenerima << endl;

    cout << "\nNomor Resi: " << informasi.nomorResi << endl;
    cout << "Tanggal Pengiriman: " << informasi.tglKirim << endl;
    cout << "Berat Barang: " << informasi.beratBarang << " gram" << endl;
    cout << "Harga: " << informasi.harga << " rupiah" << endl;

    return 0;
}
