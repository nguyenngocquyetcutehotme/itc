#include<iostream>
#include<cstring>
using namespace std;
class hocsinh{
	private:
		char ten[30];
		int tuoi;
		float diemtb;
	public:
		nhap(){
			cout<<" \nnhap ten ";
			fflush(stdin);
			cin.getline(ten,30);
			cout<<"\nnhap tuoi ";
			cin>>tuoi;
			cout<<"\nnhap diem trung binh ";
			cin>>diemtb;
		}
		xuat(){
			cout<<" ho va ten "<<ten
			    <<" tuoi "<<tuoi
			    <<" diem trung binh la "<<diemtb<<endl; 
		}
		 float getdiemtb() {
          return diemtb;
      }
      char* getten(){
      	return ten; 
	  } 
	   void setdiemtb(float diem) {
        diemtb = diem;
    }
};  
void nhaphs(hocsinh a[],int &n){
	for(int i=0;i<n;i++){
		cout<<"\nnhap hoc sinh thu "<<i+1<<endl;
		a[i].nhap();
	}
}
void xuaths(hocsinh a[],int &n){
	for(int i=0;i<n;i++ ){
		cout<<" hoc sinh thu "<<i+1<<endl;
		a[i].xuat();
	}
}
void xeploai(hocsinh a[], int& n) {
	
	 cout << "==================Xep loai hoc sinh: =========================="<<endl; 
    for (int i = 0; i < n; i++) {
    	a[i].xuat(); 
        if (a[i].getdiemtb() >= 8) {
            cout << "Gioi" << endl;
        }
        else if (a[i].getdiemtb() >= 7) {
            cout << "Kha" << endl;
        }
        else if (a[i].getdiemtb() >= 5) {
            cout << "Trung binh" << endl;
        }
        else {
            cout << "Kem" << endl; 
        }
         
    }
   
}
void sapxep(hocsinh a[], int n) {
    cout << "Danh sach giang vien theo thu tu tu a->z " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].getten() < a[j].getten()) {
                swap(a[i], a[j]);
            }
        }
        
    }
    xuaths(a,n); 
}
void capNhatDiemTB(hocsinh a[], int n, const char* tenTimKiem, float diemMoi) {
    bool daTimThay = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].getten(), tenTimKiem) == 0) {
            a[i].setdiemtb(diemMoi);
            daTimThay = true;
            break;
        }
    }

    if (daTimThay) {
        cout << "Da cap nhat diem trung binh cho sinh vien " << tenTimKiem << " thanh " << diemMoi << "." << endl;
    }
    else {
        cout << "Khong tim thay sinh vien co ten " << tenTimKiem << " trong danh sach." << endl;
    }
}
int main() {
    int n;
    cout << "Nhap so hoc sinh: ";
    cin >> n;
    hocsinh* a = new hocsinh[n];
    nhaphs(a, n);
    xuaths(a, n);
    xeploai(a,n);
    sapxep(a,n);
     capNhatDiemTB(a, n, "Nguyen Van A", 10.0);
    xuaths(a, n);
    delete[] a;
    return 0;
}
