#include<iostream>
#include<string.h>
using namespace std;
 class HOSO{
 	protected:
 		string mahoso;
 		string hoten;
 		string ngaysinh;
 		string chuandoanbenh;
 	public: 
 	    HOSO(string &ma,string &ten,string &ngay,string &cd)
		   :mahoso(ma),hoten(ten),ngaysinh(ngay),chuandoanbenh(cd){} 
		 virtual void nhap(){
		 	cout<<"\t Nhap ma ho so :";
		 	fflush(stdin);
		 	getline(cin,mahoso);
		 	
		 	cout<<"\t Nhap ho va ten :";
		 	fflush(stdin);
		 	getline(cin,hoten);
		 	
		 	cout<<"\t Nhap ngay sinh : ";
		 	cin>>ngaysinh;
		 	
		 	cout<<"\t Nhap chuan doan benh: ";
		 	fflush(stdin);
		 	getline(cin,chuandoanbenh);
        }
        virtual void xuat(){
        	cout<<" Ma Ho So: "<<mahoso<<endl
        	    <<" Ho Ten: "<<hoten<<endl
        	    <<" Ngay Sinh: "<<ngaysinh<<endl
        	    <<" Chuan Doan benh: "<<chuandoanbenh<<endl;
		}
		virtual bool lonhonngaysinh(string & ngayX){
			return ngaysinh > ngayX;
		}
 };    
 class benhnhanhnoitru:public HOSO{
 	private:
 		string ngaynhapvien;
 		string ngayxuatvien;
 		string tenkhoa;
 		int sogiuong;
 	public:
 	     benhnhanhnoitru(string& ma, string& ten, string& ngay, string& cd, string& ngaynhap, string& ngayxuat, string& tenk, int sogiuong)
        : HOSO(ma, ten, ngay, cd), ngaynhapvien(ngaynhap), ngayxuatvien(ngayxuat), tenkhoa(tenk), sogiuong(sogiuong) {}
        
        void nhap(){
        	HOSO::nhap();
        	cout<<"\t Nhap ngay nhap vien: ";
        	cin>>ngaynhapvien;
        	
        	cout<<"\t nhap nhay xuat vien : ";
        	cin>>ngayxuatvien;
        	
        	cout<<"\t nhap ten khoa: ";
        	fflush(stdin);
        	getline(cin,tenkhoa);
        	
        	cout<<"\t nhap so giuong: ";
        	cin>>sogiuong;
		}
		void xuat(){
			HOSO::xuat();
			cout<<"Ngay nhap vien: "<<ngaynhapvien<<endl
			    <<" Ngay xuat vien: "<<ngayxuatvien<<endl
			    <<" Ten khoa: "<<tenkhoa<<endl
			    <<" So giuong: "<<sogiuong<<endl;
		}
		bool lonhonngaysinh(string & ngayX){
			return HOSO::lonhonngaysinh(ngayX)&&ngaynhapvien > ngayX;
		}
 };
 class benhnhanngoaitru:public HOSO{
 	private:
 		string ngaychuyen;
 		string noichuyen;
 	public:
 		benhnhanngoaitru(string &ma,string &ten,string &ngay,string &cd,string &ngayc,string noic):HOSO(ma, ten, ngay, cd),ngaychuyen(ngayc),noichuyen(noic){}
 	void nhap(){
 		HOSO::nhap();
 		cout<<"\t Nhap ngay chuyen: ";
 		cin>>ngaychuyen;
 		
 		cout<<"\t Nhap noi chuyen: ";
 		fflush(stdin);
 	    getline(cin,noichuyen);
	 }
	 void xuat(){
	 	HOSO::xuat();
	 	cout<<" Ngay chuyen: "<<ngaychuyen<<endl
	 	    <<" Noi chuyen: "<<noichuyen<<endl;
	 }
	 bool lonhonngaysinh(string &ngayX){
	 	return HOSO::lonhonngaysinh(ngayX);
	 }
 };
 int main(){
 	int  MAX_HO_SO = 100;
 	HOSO *danhsachhoso[ MAX_HO_SO];
 	
 	int n;
 	cout<<"\nNhap so luong ho so ";
 	cin>>n;
    
    int so_luong_benh_nhan_noi_tru = 0;
    int so_luong_benh_nhan_ngoai_tru = 0;
    int soluonghoso =0; 

 	for(int i=0;i<n;i++){
 		int loaihoso;
 		cout<<"Chon loai ho so (1: Noi tru ,2: Ngoai tru ): " ;
 		cin>>loaihoso;
 		
 		HOSO *hoso;
 		if (loaihoso == 1) {
            string ma, ten, ngay, cd, ngaynhap, ngayxuat, tenk;
            int sogiuong;
            cout << "\t Nhap thong tin benh nhan noi tru: " << endl;
            hoso = new benhnhanhnoitru(ma, ten, ngay, cd, ngaynhap, ngayxuat, tenk, sogiuong);
            so_luong_benh_nhan_noi_tru ++;
        } else if (loaihoso == 2) {
            string ma, ten, ngay, cd, ngaychuyen, noichuyen;
            cout << "\t Nhap thong tin benh nhan ngoai tru: " << endl;
            hoso = new benhnhanngoaitru(ma, ten, ngay, cd, ngaychuyen, noichuyen);
            so_luong_benh_nhan_ngoai_tru++;
        } else {
            cout << " loai ho so khong hop le ." << endl;
            continue;
        }

        hoso->nhap();
        danhsachhoso[i] = hoso;
        soluonghoso++;
    
    }
    cout<<" Danh sach ho so benh nhan Noi tru: "<<endl;
	for(int i=0;i< so_luong_benh_nhan_noi_tru ;i++){
		danhsachhoso[i]->xuat();
		cout<<endl;
	} 
	 cout<<" Danh sach ho so benh nhan Ngoai tru: "<<endl;
    for(int i=so_luong_benh_nhan_noi_tru;i<soluonghoso;i++){
    	danhsachhoso[i]->xuat();
		cout<<endl;
	} 
	string ngayX;
	cout<<"\nNHAP NGAY X: ";
	cin>>ngayX;
	
	cout<<" Danh sach ho so co ngay sinh lon hon ngay "<<ngayX<<":"<<endl;
	for(int i=0;i<soluonghoso;i++){
		if(	danhsachhoso[i]->lonhonngaysinh(ngayX)){
				danhsachhoso[i]->xuat();
				cout<<endl;
		}
	}
	return 0;
 }
 
 
