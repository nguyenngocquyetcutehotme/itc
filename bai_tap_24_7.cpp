#include <iostream>
#include <string>
using namespace std;

class GiangVien {
private:
    string ten;
    int tuoi;
    char bc;
    string chuyennganh;
    float bl;

public:
    void nhap() {
        cout << "\nnhap ho ten  ";
        cin.ignore();
        getline(cin, ten);
        cout << "\n nhap tuoi ";
        cin >> tuoi;
        cout << "\n nhap bang cap ";
        cin >> bc;
        cout << " \nnhap chuyen nganh ";
        cin.ignore();
        getline(cin, chuyennganh);
        cout << " \nnhap bac luong ";
        cin >> bl;
    }

    void xuat() {
        cout << " ho va ten " << ten
             << " tuoi " << tuoi
             << " bang cap " << bc
             << " chuyen nganh " << chuyennganh
             << " bac luong " << bl << endl
             << " luong co ban " << this->tinhlcb() << endl;
    }

    float tinhlcb() {
        return bl * 610;
    }
};

void nhapdanhsach(GiangVien a[], int n) {
    cout << "Nhap danh sach " << n << " Giang Vien" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin giang vien thu " << i + 1 << endl;
        a[i].nhap();
    }
}

void xuatdanhsach(GiangVien a[], int n) {
    cout << "Xuat danh sach " << n << " Giang Vien" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Thong tin giang vien thu " << i + 1 << endl;
        a[i].xuat();
    }
}

void xuatluonggiangvien(GiangVien a[], int n) {
    bool found = false;
    cout << " Giang vien co luong nho hon 2000 : " << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].tinhlcb() < 2000) {
            a[i].xuat();
            found = true;
        }
    }
    if (!found) {
        cout << " Khong co giang vien co luong nho hon 2000 " << endl;
    }
}
void xuatGiangVienCungChuyenNganh(GiangVien a[], int n, const string& chuyennganh) {
    bool found = false;
    cout << "Danh sach giang vien co cung chuyen nganh '" << chuyennganh << "':" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].chuyennganh == chuyennganh) {
            a[i].xuat();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co giang vien co cung chuyen nganh '" << chuyennganh << "'" << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong Giang Vien: ";
    cin >> n;
    GiangVien a[n];
    nhapdanhsach(a, n);
    xuatdanhsach(a, n);
    xuatluonggiangvien(a, n);

    return 0;
}
