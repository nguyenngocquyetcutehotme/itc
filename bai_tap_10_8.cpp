#include<iostream>
#include<string.h>
using namespace std; 
class NGUOI{
	protected:
	    char hoten[30];
       	struct ngaysinh{
    		int ngay;
	    	int thang;
		    int nam;
	    }ngayS;
	public:
		NGUOI(){
			strcpy(hoten,"");
			ngayS.ngay=0;
			ngayS.thang=0;
			ngayS.nam=0;
		}
		NGUOI(char *hoten,int ngay,int thang,int nam){
			strcpy(this->hoten,hoten);
			this->ngayS.ngay;
			this->ngayS.thang;
			this->ngayS.thang;
		}
		~NGUOI(){}
		void nhap(){
			cout<<"\tNhap Ho va Ten: ";
			fflush(stdin);
			cin.getline(hoten,30);
			
			cout<<"\t nhap Ngay Sinh: "<<endl;
			cout<<"\t\tnhap ngay sinh ";
			cin>>ngayS.ngay ;
			cout<<"\t\tnhap thang sinh ";
			cin>>ngayS.thang ;
	    	cout<<"\t\tnhap nam sinh ";
			cin>>ngayS.nam ;
		}
		void xuat(){
			cout<<"Ho va Ten "<<hoten
			    <<" Ngay Sinh "<<ngayS.ngay<<" / "<<ngayS.thang<<" / "<<ngayS.nam<<endl; 
		} 		
};
class THISINH:public NGUOI{
	char sobaodanh[15];
	float toan,ly,hoa;
	public:
	    THISINH(): NGUOI(){
	    	strcpy(sobaodanh,"");
			toan=0;
			ly=0;
			hoa=0; 
		}
		THISINH(char*hoten,int ngay,int thang,int nam,float toan,float ly,float hoa,char*sobaodanh):NGUOI(hoten,ngay,thang,nam){
			strcpy(this->sobaodanh,sobaodanh) ;
			this->toan=toan;
			this->ly=ly;
			this->hoa=hoa; 
		}
		~THISINH(){}
		nhap(){
			this->NGUOI::nhap();
			
			cout<<"\t nhap so bao danh ";
			fflush(stdin);
			cin.getline(sobaodanh,15);
			
			cout<<"\t nhap diem Toan: ";
			cin>>toan;
			cout<<"\t nhap diem Ly: ";
			cin>>ly;
			cout<<"\t nhap diem Hoa: ";
			cin>>hoa; 
		} 
		void xuat(){
			this->NGUOI::xuat();
			
			cout<<" So Bao Danh "<<sobaodanh 
			    <<" Diem Toan "<<toan
				<<" Diem Ly "<<ly
				<<" Diem Hoa "<<hoa
				<<" Tong Diem "<<tongdiem()<<endl; 
		} 
		float tongdiem(){
			return toan+ly+hoa; 
		} 
		char* getsobaodanh(){
			return sobaodanh; 
		} 
		float gettoan(){
			return toan; 
		} 
		float getly(){
			return ly; 
		} 
		float gethoa(){
			return hoa; 
		} 
};
void nhapds(THISINH *ts,int n){
	for(int i=0;i<n;i++){
		cout<<"\nnhap thi sinh thu: "<<i+1<<endl;
		ts[i].nhap(); 
	} 
} 
void xuatds(THISINH *ts,int n ){
	for(int i=0;i<n;i++){
		cout<< "danh sach thu sinh tu: "<<i+1<<endl;
		ts[i].xuat(); 
	} 
} 
void sapxep(THISINH *ts,int n ){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ts[i].tongdiem()>ts[j]. tongdiem()){
				swap(ts[i],ts[j]); 
			} 
		} 
	} 
	cout<<" ===== /t danh sach sau khi sap xep theo thu tu tang dan cua tong diem la "<<endl; 
	xuatds(ts, n); 
}
void timkiem(THISINH *ts, int n, char *sobaodanh_tim_kiem) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(ts[i].getsobaodanh(), sobaodanh_tim_kiem) == 0) {
            found = true;
            cout << "Thong tin cua thi sinh can tim kiem:" << endl;
            ts[i].xuat();
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay thi sinh voi so bao danh da nhap" << endl;
    }
}
void tsdatyc(THISINH *ts,int n){
		int ts_dat_yc=0; 
	for(int i=0;i<n;i++){
		if(ts[i].gettoan() >= 5 && ts[i].getly() >= 5 && ts[i].gethoa() >=5  ){
			ts_dat_yc++;
		} 
	}  
	float phan_tram_dat_yeu_cau = (float) (ts_dat_yc)/n*100; 
	cout<<"****== phan tram thi sinh dat yeu cau la ****== "<< phan_tram_dat_yeu_cau<<"%"<<endl; 
} 
int main(){
	int n;
	cout<<"\nnhap so luong thi sinh ";cin>>n;
	THISINH ts[n];
	nhapds(ts, n);
	cout<<" danh sach cac thi sinh la "<<endl;
	xuatds(ts, n );
	cout<<endl; 
	sapxep(ts, n);
	
	char  sobaodanh_tim_kiem[15]; 
	cout<<"\nnhap so bao danh can tim kiem ";
	fflush(stdin); 
	cin.getline(sobaodanh_tim_kiem,15);
	timkiem(ts, n,sobaodanh_tim_kiem); 
	cout<<endl; 
	 tsdatyc(ts, n);
}
   
