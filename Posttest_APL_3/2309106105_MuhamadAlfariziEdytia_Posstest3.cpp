#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, unordered_map<string, vector<string>>> database;
void registerUser(const string& username, const string& password, bool isAdmin = false) {
    if (database.find(username) != database.end()) {
        cout << "Username sudah terdaftar." << endl;
    } else {
        unordered_map<string, vector<string>> user = {{"password", {password}}, {"pesawat", {}}};
        database[username] = user;
        cout << "Registrasi berhasil." << endl;
    }
}
unordered_map<string, vector<string>>* loginUser(const string& username, const string& password, int& loginAttempt) {
    auto it = database.find(username);
    if (it != database.end()) {
        // Periksa kecocokan kata sandi
        if (it->second["password"][0] == password) {
            return &(it->second);
        }
    }
    // Jika username atau password tidak cocok, tambahkan jumlah percobaan login yang gagal
    loginAttempt++;
    return nullptr;
}

// Fungsi untuk menambahkan pesawat ke daftar pengguna
void menambahkan(unordered_map<string, vector<string>>& user, const string& pesawat) {
    // Tambahkan pesawat ke daftar pengguna
    user["pesawat"].push_back(pesawat);
    cout << "Pesawat tempur berhasil ditambahkan." << endl;
}

// Fungsi untuk melihat daftar pesawat pengguna
void lihat(const unordered_map<string, vector<string>>& user) {
    // Ambil daftar pesawat dari database pengguna
    auto pesawatList = user.at("pesawat");
    cout << "Daftar Pesawat:" << endl;
    for (int i = 0; i < pesawatList.size(); ++i) {
        cout << i << ": " << pesawatList[i] << endl;
    }
}

// Fungsi untuk memperbarui pesawat dalam daftar pengguna
void perbarui(unordered_map<string, vector<string>>& user, int index, const string& pesawat_baru) {
    // Periksa apakah indeks yang dimasukkan valid
    if (index >= 0 && index < user["pesawat"].size()) {
        // Perbarui pesawat dengan indeks yang diberikan
        user["pesawat"][index] = pesawat_baru;
        cout << "Pesawat tempur berhasil diperbarui." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

// Fungsi untuk menghapus pesawat dari daftar pengguna
void hapus(unordered_map<string, vector<string>>& user, int index) {
    // Periksa apakah indeks yang dimasukkan valid
    if (index >= 0 && index < user["pesawat"].size()) {
        // Hapus pesawat dengan indeks yang diberikan
        user["pesawat"].erase(user["pesawat"].begin() + index);
        cout << "Pesawat tempur berhasil dihapus." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

// Fungsi utama program
int main() {
    int pilih_menu;
    string username, password, pilihan, pesawat, pesawat_baru;
    int index;
    int loginAttempt = 0; 

    // Loop utama program
    do {
        // Tampilkan menu utama
        cout << "Selamat datang! Silakan pilih tindakan:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            // Registrasi pengguna baru
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;
            registerUser(username, password);
        } else if (pilihan == "2") {
            // Login pengguna yang sudah terdaftar
            if (loginAttempt >= 3) {
                cout << "Anda telah mencapai batas percobaan login yang gagal. Program berhenti." << endl;
                break;
            }

            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            auto user = loginUser(username, password, loginAttempt);
            if (user != nullptr) {
                cout << "Selamat datang, " << username << "!" << endl;
                do {
                    // Tampilkan menu pengguna setelah login berhasil
                    cout << "Menu:" << endl;
                    cout << "1. Tambahkan pesawat tempur" << endl;
                    cout << "2. Lihat daftar pesawat" << endl;
                    cout << "3. Perbarui pesawat" << endl;
                    cout << "4. Hapus pesawat" << endl;
                    cout << "5. Logout" << endl;
                    cout << "Pilihan: ";
                    cin >> pilih_menu;

                    switch (pilih_menu){

    

                     
                        case 1: {
                            // Tambahkan pesawat ke daftar pengguna
                            cout << "Masukkan jenis pesawat: ";
                            cin.ignore();
                            getline(cin, pesawat);
                            menambahkan(*user, pesawat);
                            break;
                        }
                        case 2: {
                            // Tampilkan daftar pesawat pengguna
                            lihat(*user);
                            break;
                        }
                        case 3: {
                            // Perbarui pesawat dalam daftar pengguna
                            cout << "Masukkan indeks pesawat yang ingin diperbarui: ";
                            cin >> index;
                            string newPesawat;
                            cout << "Masukkan jenis pesawat baru: ";
                            cin.ignore();
                            getline(cin, newPesawat);
                            perbarui(*user, index, newPesawat);
                            break;
                        }
                        case 4: {
                            cout << "Masukkan indeks pesawat yang ingin dihapus: ";
                            cin >> index;
                            hapus(*user, index);
                            break;
                        }
                        case 5: {
                            cout << "Logout berhasil." << endl;
                            break;
                        }
                        default: {
                            cout << "Pilihan tidak valid." << endl;
                            break;
                        }
                    }
                } while (pilih_menu != 5);
            } else {
                cout << "Username atau password tidak valid." << endl;
            }
        } else if (pilihan == "3") {
            cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    } while (true);
    return 0;

}