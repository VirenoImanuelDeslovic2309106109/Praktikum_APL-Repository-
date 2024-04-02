#include <iostream>
#include <string>
#include <limits>
using namespace std;

// fungsi login
int login(int batas_login = 0) {
    string username, password;
    cout<<"Selamat Datang Di Program Pendataan Item Mobile Legends: Bang Bang\n";
    while (batas_login < 3) {
        cout<<"Silahkan Login\n";
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == "vireno" && password == "109") {
            cout<<"Anda Berhasil Login\n";
            return true;
        } else {
            cout << "Username Atau Password Anda Tidak Valid!\n";
            return login(batas_login +1); // Rekursif
        }
    }
    if (batas_login == 3) {
        cout << "Anda Telah Mencapai Batas, Program Di Berhentikan";
        return 0;
    }
    return 0;
}

// struct karakteristik dan itemgame
struct Karakteristik {
    string tipe_item;
};
struct itemgame {
    string nama_item;
    string fungsi_item;
    int harga_item;
    Karakteristik karakteristik; // Nested struct karakteristik
};

void menambahkan_data_item(itemgame mobile_legends[], int& jumlah_item) {
    if (jumlah_item < 20) {
        cout << "Masukkan Nama Item: ";
        cin.ignore();
        getline(cin, mobile_legends[jumlah_item].nama_item);
        cout << "Masukkan Fungsi Item: ";
        getline(cin, mobile_legends[jumlah_item].fungsi_item);
        do {
            cout << "Masukkan Harga Item: ";
            if (cin >> mobile_legends[jumlah_item].harga_item) {
                break;
            } else {
                cout << "Harga harus berupa bilangan bulat. Silakan coba lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (true);
        cin.ignore();
        cout<<"Attack/Defense/Magic/Movement"<<endl;
        cout<< "Masukkan Tipe Item: ";
        getline(cin, mobile_legends[jumlah_item].karakteristik.tipe_item);
        jumlah_item++;
        cout << "Data Item Berhasil Ditambahkan\n" << endl;
    } else {
        cout << "Penyimpanan Telah Penuh, Tidak Dapat Menambahkan Data Item!!!" << endl;
    }
}

// prosedur menampilkan_data_item
void menampilkan_data_item(itemgame mobile_legends[], int jumlah_item){
    if (jumlah_item == 0){
        cout<<"Tidak ada item yang tersedia\n"<<endl;
    } else {
        for(int i = 0;  i < jumlah_item; ++i){
            cout<<"\n"<<endl;
            cout<< i + 1<<". Nama item: "<< mobile_legends[i].nama_item<<endl;
            cout<<"Fungsi Item: "<< mobile_legends[i].fungsi_item<<endl;
            cout<<"Harga item: "<< mobile_legends[i].harga_item <<" Gold"<<endl;
            cout<<"Tipe: "<< mobile_legends[i].karakteristik.tipe_item <<endl;
        }
    }
}

// prosedur merubah_data_item
void merubah_data_item(itemgame mobile_legends[], int jumlah_item, int index_item){
    if (jumlah_item == 0) {
        cout<<"Tidak ada item yang tersedia\n"<<endl;
    } else {
        cout<<"Masukkan index item yang ingin diubah: ";
        do {
            if (!(cin >> index_item)) {
                cout << "Inputan anda tidak valid, harus menggunakan angka : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                if (index_item >= 0 && index_item <= jumlah_item){
                    cout<<"Masukkan Nama Baru Item: ";
                    cin.ignore();
                    getline (cin, mobile_legends[index_item-1].nama_item);
                    cout<<"Masukkan Fungsi Baru Item: ";
                    getline(cin, mobile_legends[index_item-1].fungsi_item);
                    do {
                        cout << "Masukkan Harga Baru Item: ";
                        if (cin >> mobile_legends[index_item-1].harga_item) {
                            break;
                        } else {
                            cout << "Harga harus berupa bilangan bulat. Silakan coba lagi." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (true);
                    cin.ignore();
                    cout<<"Masukkan Tipe Baru Item: ";
                    getline(cin, mobile_legends[index_item-1].karakteristik.tipe_item);
                    cout<<"item telah diupdate"<<endl;
                    break; // Keluar dari loop setelah input valid
                } else{
                    cout<<"index yang anda input tidak valid"<<endl;
                }
            }
        } while (true);
    }    
}

// prosedur hapus_data_item
void hapus_data_item(itemgame mobile_legends[], int& jumlah_item, int index_item) {
    if (jumlah_item == 0) {
        cout << "Tidak ada item yang tersedia!" << endl;
    } else {
        do {
            cout << "Masukkan Index Item Yang Ingin Dihapus: ";
            if (!(cin >> index_item)) {
                cout << "Inputan anda tidak valid, harus menggunakan angka!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                if (index_item >= 1 && index_item <= jumlah_item) {
                    for (int i = index_item - 1; i < jumlah_item - 1; ++i) {
                        mobile_legends[i] = mobile_legends[i + 1];
                    }
                    jumlah_item--;
                    cout << "Data Item Telah Berhasil Dihapus." << endl;
                    break;
                } else {
                    cout << "Index Yang Anda Input Tidak Valid" << endl;
                }
            }
        } while (true);
    }
}

// fungsi main
int main (){
    if (!login()) {
        return 0;
    }
    itemgame mobile_legends[20]{
        {"Winter Truncheon", "Tidak Bergerak Dan Tidak dapat Diserang", 1910, {"Magic"}},
        {"Blade of despair", "Meningkatkan Damage Jika Musuh Sekarat",3010, {"Attack"}},
        {"Immortality", "Hidup Kembali Setelah Mati", 2120, {"Defense"}},
    };
    // Pointer Pada Array 
    itemgame *p_mobile_legends = mobile_legends;
    int index_item, pilih, jumlah_item = 3;
    int* p_jumlah_item = &jumlah_item; // Pointer yang menunjuk ke variabel jumlah_item
    int* p_index_item
     = &index_item; // Pointer yang menunjuk ke variabel index_item
    
    do {
        cout<<"\n===Menu Utama===\n";
        cout<<"1. Tambahkan Data Item\n";
        cout<<"2. Tampilkan Data Item\n";
        cout<<"3. Ubah Data Item\n";
        cout<<"4. Hapus Data Item\n";
        cout<<"5. Log Out\n";
        cout<<"Silahkan Pilih Menu Yang Anda Inginkan(1/2/3/4/5): ";
        if (!(cin>>pilih)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        switch (pilih){
            case 1:{
                menambahkan_data_item(p_mobile_legends, *p_jumlah_item);
                break;
            }
            case 2:{
                menampilkan_data_item(p_mobile_legends, *p_jumlah_item);
                break;
            }
            case 3:{
                merubah_data_item(p_mobile_legends, *p_jumlah_item, *p_index_item);
                break;    
            }
            case 4:{
                hapus_data_item(p_mobile_legends, *p_jumlah_item, *p_index_item);
                break;
            }
            case 5:{
                cout<<"Anda Berhasil Log Out."<<endl;
                cout<<"Terima Kasih Telah Berkunjung."<<endl;
                break;
            }
            default:{
                cout<<"Inputan Anda Tidak Valid!,Silahkan Pilih 1/2/3/4/5.\n";
            }
        }
    } while(pilih != 5);

    return 0;
}
