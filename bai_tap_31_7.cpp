#include<iostream>
#include<string.h>
#include <algorithm>
using namespace std;
class GiaoVien {
	private:
		char ht[30];
		int t;
		char bc[15];
		char chuyennganh[20];
		float bl;
	public:
		friend istream& operator>>(istream&in,GiaoVien &gv){
			cout<< "nhap ho ten: ";
			fflush(stdin);
			in.getline(gv.ht,30);
			
			cout<< "nhap tuoi: ";
			in>>gv.t;
			
			cout<< "nhap bang cap: ";
			fflush(stdin);
			in.getline(gv.bc,15);
			
			cout<< "nhap chuyen nganh: ";
			fflush(stdin);
			in.getline(gv.chuyennganh,20);
			
			cout<< "nhap bac luong: ";
			in>>gv.bl;
			
			return in;
		}
		friend ostream& operator<<(ostream&out,GiaoVien gv){
			out<<" Ho ten "<<gv.ht
			   <<" Tuoi "<<gv.t
			   <<" Bang cap "<<gv.bc
			   <<" Chuyen nganh "<<gv.chuyennganh
			   <<" luong co ban "<<gv.tinhTienLuong() 
			   <<" Bac luong "<<gv.bl<<endl; 
			  
			
			return out;
		}
		float tinhTienLuong(){
			return bl*610;
		}
		bool operator==( GiaoVien& gv){
			return strcmp(this->bc ,gv.bc)==0;
		} 
		char*getbc(){
			return bc;
		}
    
};
bool compareBangCap( GiaoVien& gv1,  GiaoVien& gv2) {
    return strcmp(gv1.getbc(), gv2.getbc()) < 0;
}
	

int main(){

	int n;
	cout<<"\nnhap so luong giao vien ";
	cin>>n;
	
		GiaoVien danhsach[n]; 
	for(int i=0;i<n;i++){
		cout<<" \nnhap thong tin cua giao vien thu "<<i+1<<endl;
		cin>>danhsach[i]; 
	} 
	cout<<"\nDanh sach "<< n <<" giao vien "<<endl;
	for(int i=0;i<n;i++){
		cout<<danhsach[i];
	}
	 sort(danhsach, danhsach + n, compareBangCap);
    cout << "Danh sach giao vien sau khi sap xep theo bang cap:" << endl;
    for (int i = 0; i < n; i++) {
        cout<<danhsach[i];
    }

    return 0;
}


 
