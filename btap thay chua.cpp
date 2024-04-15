#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/*hello*/
class NGUOI{
	private:
		string hoten;
	protected:
		string maso;
		float luong;
	public: 
		void nhap() {
			cout << endl << "Nhap ma so (BC: bien che; HD: hop dong): ";
			cin >> maso;
			cout << endl << "Nhap ho ten: ";
			cin.ignore(); getline(cin,hoten);
		}
		void in() {
			cout << endl << setw(10) << maso << setw(30)<< hoten << setw(20) <<setprecision(2) << fixed << luong;
		}
};

class BIENCHE : virtual public NGUOI {
	private:
		float hsl, phucap;
	public: 
		void nhapBC(){
			cout << endl << "Nhap he so luong: "; cin >> hsl;
			cout << endl << "Nhap phu cap: "; cin >> phucap;
			luong= hsl*1800000 + phucap;
		}
};

class HOPDONG : virtual public NGUOI {
	private:
		int ngaycong, tiencong, hsvg;
	public:
		void nhapHD() {
			cout << endl << "Nhap ngay cong: "; cin >> ngaycong;
			cout << endl << "Nhap tien cong: "; cin >> tiencong;
			cout << endl << "Nhap he so vuot gio: "; cin >> hsvg;
			luong= ngaycong<=26? ngaycong*tiencong: (26+(ngaycong-26)*hsvg)*tiencong;
		}
};

class VIENCHUC: public BIENCHE, public HOPDONG {
	private:
		static int tsvc;
		static float tsluong;
	public:
		VIENCHUC() {
			tsvc++;
		}
		~VIENCHUC() {
			tsvc--;
			tsluong -= luong;
		}
		
		void nhapVC() {
			nhap();		//gọi hàm nhập ở lớp NGUOI để nhập hồ sơ
			if(maso[0] == 'B' || maso[0] == 'b')
				nhapBC();
			else nhapHD();
			tsluong += luong;
		}
		
		VIENCHUC *next; //tao moc
};

int VIENCHUC::tsvc=0;
float VIENCHUC::tsluong=0.0;

int main() {
	int n;
	cout << "Nhap so vien chuc: "; cin >> n;
	VIENCHUC *list = new VIENCHUC[n];
	for(int i=0; i<n; i++) {
		list[i].nhapVC();
	}
	
	cout << "\nDanh sach vien chuc: ";
	for(int i=0; i<n; i++) {
		list[i].in();
	}
	
	
	//5 ý, mỗi ý 2 điểm, 90', form đề thi:

    //toán tử so sánh, toán tử cộng
    // Thuộc tính thống kê: tổng số viên chức, tổng số lượng, tổng số lượng biên chế,.....
    // Danh sách liên kết đơn
    // Sắp xếp danh sách liên kết đơn theo thứ tự giảm dần của lương
    // In ra biên chế có lương cao nhất, hợp đồng có lương cao nhất
    // Thêm, bớt viên chức
    
    delete[] list;
}
