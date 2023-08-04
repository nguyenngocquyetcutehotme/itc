#include<iostream>
#include<string.h>
using namespace std;
class GIAOVIEN{
	private:
	    char ten[30];
	    int tuoi;
	    char bangcap[15];
	    char chuyennganh[20];
	    float bl;
	public:
		friend istream&operator>>(istream&in,GIAOVIEN &gv){
			cout<<"\tnhap ho va ten ";
			fflush(stdin);
			in.getline(gv.ten,30);
			cout<<"\tnhap tuoi ";
			in>>gv.tuoi;
			cout<<"\tnhap bang cap ";
			fflush(stdin);
			in.getline(gv.bangcap,15);
			cout<<"\tnhap chuyen nganh ";
			fflush(stdin);
			in.getline(gv.chuyennganh,20);
			cout<<"\tnhap bac luong cua giang vien ";
			in>>gv.bl;
			
			return in;
		}
		friend ostream&operator<<(ostream&out,GIAOVIEN gv){
			out<<" Ho Ten "<<gv.ten
			   <<" Tuoi "<<gv.tuoi
			   <<" Bang Cap "<<gv.bangcap
			   <<" Chuyen Nganh "<<gv.chuyennganh
			   <<" Bac Luong "<<gv.bl
			   <<" Luong Co ban "<<gv.luongcoban()<<endl;
		}
		float luongcoban(){
			return bl*610;
		}
		bool operator ==(GIAOVIEN gv){
			return strcmp(this->bangcap,gv.bangcap)==0;
		}
		bool operator >(GIAOVIEN gv){
			return strcmp(this->bangcap,gv.bangcap)==1;
		}
	 
}; 
void nhap(GIAOVIEN *gv,int n){
	for(int i=0;i<n;i++){
		cout<<"\nnhap giao vien thu "<<i+1<<endl;
		cin>>gv[i];
		
	}
}
void xuat(GIAOVIEN *gv,int n){
	for(int i=0;i<n;i++){
		cout<<" thong tin giao vien thu "<<i+1<<endl;
		cout<<gv[i];
	}
}
void sapxep(GIAOVIEN *gv,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(gv[i]>gv[j]){
				swap(gv[i],gv[j]);
			}
		}
	}
	xuat(gv, n);
}
int main(){
    int n;
    cout << "NHAP SO LUONG GIAO VIEN: ";
    cin >> n;

  GIAOVIEN* gv = new GIAOVIEN[n];
    nhap(gv, n);

    cout << "DANH SACH GIANG VIEN:" << endl;
    xuat(gv, n);
    cout<<"\n"; 

    cout << "DANH SACH GIANG VIEN SAU KHI SAP XEP THEO BANG CAP:" << endl;
    sapxep(gv, n);
 
}

