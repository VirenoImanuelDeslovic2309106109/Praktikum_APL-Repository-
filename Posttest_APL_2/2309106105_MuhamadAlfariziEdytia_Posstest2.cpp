#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

unordered_map<string, unordered_map<string, vector<string>>> database;

string registerUser(const string& username, const string& password, bool isAdmin = false) {
    if (database.find(username) != database.end()) {
        return "Username sudah terdaftar.";
    }
    unordered_map<string, vector<string>> user = {{"password", {password}}, {"pesawat", {}}};
    database[username] = user;
    return "Registrasi berhasil.";
}

unordered_map<string, vector<string>>* loginUser(const string& username, const string& password, int& loginAttempt) {
    auto it = database.find(username);
    if (it != database.end()) {
        if (it->second["password"][0] == password) {
            return &(it->second);
        }
    }
    loginAttempt++;
    return nullptr;
}

string menambahkan(unordered_map<string, vector<string>>& user, const string& pesawat) {
    user["pesawat"].push_back(pesawat);
    return "Pesawat tempur berhasil ditambahkan.";
}

vector<string> lihat(const unordered_map<string, vector<string>>& user) {
    return user.at("pesawat");
}

string perbarui(unordered_map<string, vector<string>>& user, int index, const string& pesawat_baru) {
    if (index >= 0 && index < user["pesawat"].size()) {
        user["pesawat"][index] = pesawat_baru;
        return "Pesawat tempur berhasil diperbarui.";
    } else {
        return "Indeks tidak valid.";
    }
}

string hapus(unordered_map<string, vector<string>>& user, int index) {
    if (index >= 0 && index < user["pesawat"].size()) {
        user["pesawat"].erase(user["pesawat"].begin() + index);
        return "Pesawat tempur berhasil dihapus.";
    } else {
        return "Indeks tidak valid.";
    }
}

int main() {
    string username, password, pilihan, pilih_menu, pesawat, pesawat_baru;
    int index;
    int loginAttempt = 0; 

    do {
        cout << "Selamat datang! Silakan pilih tindakan:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;
            cout << registerUser(username, password) << endl;
        } else if (pilihan == "2") {
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
                    cout << "Menu:" << endl;
                    cout << "1. Tambahkan pesawat tempur" << endl;
                    cout << "2. Lihat daftar pesawat" << endl;
                    cout << "3. Perbarui pesawat" << endl;
                    cout << "4. Hapus pesawat" << endl;
                    cout << "5. Logout" << endl;
                    cout << "Pilihan: ";
                    cin >> pilih_menu;

                    switch (stoi(pilih_menu)) {
                        case 1: {
                            cout << "Masukkan jenis pesawat: ";
                            cin.ignore();
                            getline(cin, pesawat);
                            cout << menambahkan(*user, pesawat) << endl;
                            break;
                        }
                        case 2: {
                            auto pesawatList = lihat(*user);
                            cout << "Daftar Pesawat:" << endl;
                            for (int i = 0; i < pesawatList.size(); ++i) {
                                cout << i << ": " << pesawatList[i] << endl;
                            }
                            break;
                        }
                        case 3: {
                            cout << "Masukkan indeks pesawat yang ingin diperbarui: ";
                            cin >> index;
                            string newPesawat;
                            cout << "Masukkan jenis pesawat baru: ";
                            cin.ignore();
                            getline(cin, newPesawat);
                            cout << perbarui(*user, index, newPesawat) << endl;
                            break;
                        }
                        case 4: {
                            cout << "Masukkan indeks pesawat yang ingin dihapus: ";
                            cin >> index;
                            cout << hapus(*user, index) << endl;
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
                } while (pilih_menu != "5");
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

