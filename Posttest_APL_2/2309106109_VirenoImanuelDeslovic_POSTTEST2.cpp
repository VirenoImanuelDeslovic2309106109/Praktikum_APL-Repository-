#include <iostream>
#include <string>
#include <limits>
using namespace std;

int login() {
    string username, password;
    int login = 0;
    cout<<"Selamat Datang Di Program Pendataan Item Mobile Legends: Bang Bang\n";
    while (login < 3) {
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
            login++;
        }
    }
    if (login == 3) {
        cout << "Anda Telah Mencapai Batas, Progam Di Berhentikan";
        return 0;
    }
    return 0;
}

struct itemgame {
    string nama_item;
    string fungsi_item;
    string jenis_item;
    int harga_item;
};

void menampilkan_data_item(itemgame mobile_legends[],int jumlah_item){
    if (jumlah_item == 0){
        cout<<"Tidak ada item yang tersedia\n"<<endl;
    } else {
        for(int i = 0;  i < jumlah_item; ++i){
            cout<<"\n"<<endl;
            cout<< i + 1<<". Nama item: "<< mobile_legends[i].nama_item<<endl;
            cout<<"Fungsi Item: "<< mobile_legends[i].fungsi_item<<endl;
            cout<<"Jenis Item: "<< mobile_legends[i].jenis_item<<endl;;
            cout<<"Harga item: "<< mobile_legends[i].harga_item <<" Gold"<<endl;
        }
    }
}

void merubah_data_item(itemgame mobile_legends[],int jumlah_item,int index_item){
    if (jumlah_item == 0) {
        cout<<"Tidak ada item yang tersedia\n"<<endl;
    }  else {
        cout<<"Masukkan index item yang ingin diubah: \n";
        cin>>index_item;
        if (index_item >= 0 && index_item <= jumlah_item){
            cout<<"Masukkan Nama Baru Item: ";
            cin.ignore();
            getline (cin, mobile_legends[index_item-1].nama_item);
            cout<<"Masukkan Fungsi Baru Item: ";
            getline(cin,mobile_legends[index_item-1].fungsi_item);
            cout<<"Masukkan Jenis Item Baru:";
            cout<<"Attack/Magic/Defense/Movement\n";
            cin>>mobile_legends[index_item-1].fungsi_item;
            do {
                cout << "Masukkan Harga Baru Item: ";
                if (cin >> mobile_legends[index_item-1].harga_item) {
                    break;
                } else {
                    cout << "Harga Harus Berupa Bilangan Bulat. Silakan Coba Lagi." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (true);
            cout<<"Item Telah Di Ubah"<<endl;
        } else{
            cout<<"Index Yang Anda Input Tidak vValid"<<endl;
        }
    }    
}

int main (){
    if (!login()) {
        return 0;
    }
    itemgame mobile_legends[20]{
        {"Winter Truncheon","Tidak Bergerak Dan Tidak dapat Diserang","Magic" ,1910},
        {"Blade Of Despair","Meningkatkan Damage Jika Musuh Sekarat","Attack",3010},
        {"Immortality","Hidup Kembali Setelah Mati","Defense", 2120},
        {"Wind Of Nature","Kebal Dari Serangan Physical Damage","Attack",1910},
        {"Magic Boots","Mengurangi Cooldown Skill","Movement",710}
    };
    int index_item,pilih,jumlah_item = 5;
    do{
        cout<<"\n=====Menu Utama=====\n";
        cout<<"1. Tambahkan Data Item\n";
        cout<<"2. Tampilkan Data Item\n";
        cout<<"3. Update Data Item\n";
        cout<<"4. Hapus Data Item\n";
        cout<<"5. Log Out\n";
        cout<<"Silahkan Pilih Menu Yang Anda Inginkan(1/2/3/4/5): \n";
        cin>>pilih;
        switch (pilih){
            case 1:{
                if (jumlah_item < 6){
                cout<<"Masukkan Nama Item: ";
                cin.ignore();
                getline (cin, mobile_legends[jumlah_item].nama_item);
                cout<<"Masukkan Fungsi Item: ";
                getline(cin,mobile_legends[jumlah_item].fungsi_item);
                cout<<"Masukkan Jenis Item\n";
                cout<<"Attack/Magic/Defense/Movement\n";
                cin>>mobile_legends[jumlah_item].jenis_item;
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
                    jumlah_item++;
                    cout<<"Data Item Berhasil Ditambahkan\n"<<endl;
                } else {
                    cout<<"Penyimpanan Telah Penuh, Tidak Dapat Menambahkan Data Item!!!"<<endl;
                }
                break;
            }
            case 2:{
                menampilkan_data_item(mobile_legends, jumlah_item);
                break;
            }
            case 3:{
                merubah_data_item(mobile_legends,jumlah_item, index_item);
                break;    
            }
            case 4:{
                if (jumlah_item == 0){
                    cout<<"Tidak ada item yang tersedia!\n"<<endl;
                } else {
                    cout<<"Masukkan Index Item Yang Ingin Dihapus: ";
                    cin>>index_item;
                    if (index_item >= 0 && index_item <= jumlah_item){
                        for (int i = index_item - 1; i < jumlah_item -1; ++i){
                        mobile_legends[i] = mobile_legends[i+1];
                        }
                        jumlah_item--;
                        cout<<"Data Item Telah Berhasil Dihapus."<<endl;
                    } else{
                        cout<<"Index Yang Anda Input Tidak Valid"<<endl;
                    }
                }   
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