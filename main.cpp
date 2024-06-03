#include <iostream>
#include <string>

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
};


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
    cout << "Masukkan nomor resi: ";
    cin >> informasi.nomorResi;

    // Input tgl kirim
    cout << "Masukkan tanggal pengiriman (dd/mm/yyyy): ";
    cin >> informasi.tglKirim;

    // Input berat barang
    cout << "Masukkan berat barang (dalam gram): ";
    cin >> informasi.beratBarang;

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

    return 0;
}
