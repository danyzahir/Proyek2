#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Data {
    string nama;
    string tempatTanggalLahir;
    int usia;
    string jenisKelamin;
    string agama;
    string statusPerkawinan;
    string riwayatPekerjaan;
    string partai;
};

vector<Data> database;

void inputData() {
    Data newData;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nama: ";
    getline(cin, newData.nama);

    cout << "Tempat Tanggal Lahir: ";
    getline(cin, newData.tempatTanggalLahir);

    cout << "Usia: ";
    cin >> newData.usia;

    cin.ignore();
    cout << "Jenis Kelamin: ";
    getline(cin, newData.jenisKelamin);

    cout << "Agama: ";
    getline(cin, newData.agama);

    cout << "Status Perkawinan: ";
    getline(cin, newData.statusPerkawinan);

    cout << "Riwayat Pekerjaan: ";
    getline(cin, newData.riwayatPekerjaan);

    cout << "Partai: ";
    getline(cin, newData.partai);

    database.push_back(newData);

    // Menambahkan pembatas
    cout << "\n----------------------------------------\n";
}

void updateData() {
    string searchName;
    cout << "Masukkan nama untuk update data: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchName);

    auto it = find_if(database.begin(), database.end(), [searchName](const Data &d) { return d.nama == searchName; });

    if (it != database.end()) {
        cout << "Update data untuk " << searchName << ":\n";
        // Implement update logic here
        cout << "Nama: ";
        getline(cin, it->nama);

        cout << "Tempat Tanggal Lahir: ";
        getline(cin, it->tempatTanggalLahir);

        cout << "Usia: ";
        cin >> it->usia;

        cin.ignore();
        cout << "Jenis Kelamin: ";
        getline(cin, it->jenisKelamin);

        cout << "Agama: ";
        getline(cin, it->agama);

        cout << "Status Perkawinan: ";
        getline(cin, it->statusPerkawinan);

        cout << "Riwayat Pekerjaan: ";
        getline(cin, it->riwayatPekerjaan);

        cout << "Partai: ";
        getline(cin, it->partai);

        cout << "Data berhasil diupdate.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }
}

void removeData() {
    string searchName;
    cout << "Masukkan nama untuk menghapus data: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchName);

    auto it = remove_if(database.begin(), database.end(), [searchName](const Data &d) { return d.nama == searchName; });

    if (it != database.end()) {
        database.erase(it, database.end());
        cout << "Data untuk " << searchName << " berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }
}

void viewData() {
    if (database.empty()) {
        cout << "Belum ada data yang disimpan.\n";
        return;
    }

    cout << "\nData yang disimpan:\n";
    for (const auto &data : database) {
        cout << "\n----------------------------------------\n";
        cout << "Nama: " << data.nama << '\n';
        cout << "Tempat Tanggal Lahir: " << data.tempatTanggalLahir << '\n';
        cout << "Usia: " << data.usia << '\n';
        cout << "Jenis Kelamin: " << data.jenisKelamin << '\n';
        cout << "Agama: " << data.agama << '\n';
        cout << "Status Perkawinan: " << data.statusPerkawinan << '\n';
        cout << "Riwayat Pekerjaan: " << data.riwayatPekerjaan << '\n';
        cout << "Partai: " << data.partai << '\n';
    }

    // Menambahkan pembatas setelah setiap entri data
    cout << "\n----------------------------------------\n";
}

int main() {
    cout << "[===========Data Pemilihan Caleg============]\n";

    char choice;
    do {
        cout << "Silakan Pilih Menu:\n";
        cout << "1. Input Data\n";
        cout << "2. Update Data\n";
        cout << "3. Remove Data\n";
        cout << "4. View Data\n";
        cout << "5. Exit\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case '1':
                inputData();
                break;
            case '2':
                updateData();
                break;
            case '3':
                removeData();
                break;
            case '4':
                viewData();
                break;
            case '5':
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != '5');

    return 0;
}
