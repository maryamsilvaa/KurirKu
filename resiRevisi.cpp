#include <iostream>
#include <string>
#include <cstdlib>  // Untuk fungsi rand() dan srand()
#include <ctime>    // Untuk fungsi time()
#include <fstream>  // Untuk operasi file
#include <iomanip>  // Untuk manipulasi output

using namespace std;

// Struktur untuk menyimpan informasi pengirim dan penerima
struct info {
    string namaPengirim;
    string kontakPengirim;
    string namaPenerima;
    string alamatPenerima;
    string kontakPenerima;
    string nomorResi;
    string tglKirim;
    float beratBarang;
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

// Fungsi untuk mencetak garis pemisah
void printSeparator() {
    cout << "+------------+-------------------+-------------------+-------------------+--------------------------+-----------------------+-------------+" << endl;
}

int main() {
    info informasi;

    // Input informasi pengirim
    cout << "Masukkan informasi pengirim:" << endl;
    cout << "Nama Lengkap: ";
    getline(cin, informasi.namaPengirim);
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

    // Menampilkan resi barang dalam bentuk tabel
    cout << "\n=== Resi Barang ===" << endl;
    printSeparator();
    cout << "| " << setw(10) << left << "No Resi"
         << " | " << setw(17) << left << "Tanggal Dikirim"
         << " | " << setw(17) << left << "Nama Pengirim"
         << " | " << setw(17) << left << "Nama Penerima"
         << " | " << setw(26) << left << "Alamat Penerima"
         << " | " << setw(21) << left << "No Handphone Penerima"
         << " | " << setw(11) << left << "Berat (g)"
         << " |" << endl;
    printSeparator();
    cout << "| " << setw(10) << left << informasi.nomorResi
         << " | " << setw(17) << left << informasi.tglKirim
         << " | " << setw(17) << left << informasi.namaPengirim
         << " | " << setw(17) << left << informasi.namaPenerima
         << " | " << setw(26) << left << informasi.alamatPenerima
         << " | " << setw(21) << left << informasi.kontakPenerima
         << " | " << setw(11) << left << informasi.beratBarang
         << " |" << endl;
    printSeparator();

    return 0;
}
