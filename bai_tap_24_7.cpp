#include<iostream>
#include<string>
using namespace std;
class giangvien{
	private:
	   char ten[30];
	   int tuoi;
	   char bc;
	   char chuyennganh[15];
	   float bl ;
	public:
	    nhap(){
	    	cout<<"\n nhap ten giang vien ";
	    	fflush(stdin); 
			cin.getline(ten,30);
			cout<<"\nnhap tuoi giang vien " ;
			cin>>tuoi;
			cout<<"\n nhap bang cap";
			cin>>bc; 
			cout<<" \nnhap chuyen nganh ";
			fflush(stdin); 
			cin.getline(chuyennganh,15);
			cout<<" \nnhap bac luong ";
			cin>>bl;			 
		} 
		xuat(){
		   cout<<" ho ten: "<<ten
		       <<" tuoi: "<<tuoi
			   <<" bac luong "<<bl
			   <<" bang cap "<<bc
			   <<" luong co ban "<<this->tinhlcb()
			   <<" chuyen nganh "<<chuyennganh<<endl;			
		}
		float tinhlcb(){
			return bl*610;
		}
	
       char* getchuyenNganh() {
          return chuyennganh;
      }
}; 
void nhap(giangvien a[],int &n){
	for(int i=0;i<n;i++){
		cout<<" nhap giang vien thu "<<i+1<<endl;
		a[i].nhap();
	}
}
void xuat(giangvien a[], int &n){
	for(int i=0;i<n;i++){
		cout<<" giang vien thu: "<<i+1<<endl;
		a[i].xuat();
	}
}
void luonggiangvien(giangvien a[],int n){
	cout<<" danh sach giang vien co luong nho hon  2000 la "<<endl;
	bool found=false;
	for(int i=0;i<n;i++){
		if(a[i].tinhlcb()<2000){
			a[i].xuat(); 
			found= true;
		}
		
	}
	if(!found){
		cout<<" khong co giang vien nao co luong tren 2000"<<endl;
	}
}

void sapxepchuyennganh(giangvien a[], int n) {
    cout << "Danh sach giang vien theo thu tu tu a->z " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].getchuyenNganh() < a[j].getchuyenNganh()) {
                swap(a[i], a[j]);
            }
        }
        
    }
    xuat(a,n); 
}

int main() {
    int n;
    cout << "Nhap so luong Giang Vien: ";
    cin >> n;
    giangvien a[n];
    nhap(a, n);
    xuat(a, n);
    luonggiangvien(a, n);
    sapxepchuyennganh(a, n);
    return 0;
}
