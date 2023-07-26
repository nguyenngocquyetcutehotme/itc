#include <iostream>
using namespace std;

class RealNumber {
private:
    float numerator;
    float denominator;

public:
    void nhap() {
        do {
            cout << "Nhap tu so: ";
            cin >> numerator;
            cout << "Nhap mau so: ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "Mau so khong duoc bang 0. Vui long nhap lai!" << endl;
            }
        } while (denominator == 0);
    }

    void xuat() {
        cout << "Tu so: " << numerator << endl;
        cout << "Mau so: " << denominator << endl;
        cout<<" phan so nhan duoc la "<<numerator <<" / "<<denominator ;
    }
};

int main() {
    RealNumber soThuc;
    soThuc.nhap();
    cout << "Thong tin so thuc: " << endl;
    soThuc.xuat();

    return 0;
}
