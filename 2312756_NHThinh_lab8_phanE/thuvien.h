#pragma once
#define MAX 100


struct SinhVien {
	string MaSV="";
	string HovaTenLot="";
	string Ten="";
	string GioiTinh="";
	double DTB=0;
	string Lop="";
	string HocLuc ;
};
typedef SinhVien DSSinhVien[MAX];
DSSinhVien DSSV;
int mangsoluong[MAX];
void DuLieuMau(DSSinhVien DSSV) {
	DSSV[0] = { "2312571","Nguyen Minh","Anh","nu",8.5,"CTK47A"};
	DSSV[1] = { "2312756","Nguyen Hung","Thinh","nam",9,"CTK47A"};
	DSSV[2] = { "2312577","Tran Nguyen Tuan","Anh","nu",4, "CTK47B"};
	DSSV[3] = { "2312639","Phan Khanh","Vuong","nam",10,"CTK47B"},
		DSSV[4] = { "2312802","Phung Nguyen Hoai","Bo","nu",5,"CTK47C" };
}
bool KTMaSV(int n, SinhVien SV, DSSinhVien DSSV) {
	bool c=true;
	for (int i = 0; i < n; i++) {
		if (SV.MaSV!=DSSV[i].MaSV) {
			c= 0;
			
		}
	}
	return c;
}

void NhapSV(int n,SinhVien& SV, DSSinhVien DSSV) {
	system("cls");
	
	cout << "NHAP THIET BI " ;
	do {
		
		cout << "\nNhap vao ma sinh vien(max: 7): ";
		cin >> SV.MaSV; 

	} while (SV.MaSV.length() > 7 || KTMaSV(n, SV, DSSV));
	cin.ignore();
	do {
		cout << "\nNhap ho va ten lot sinh vien: "; getline(cin, SV.HovaTenLot);
	} while (SV.HovaTenLot.length() > 30 || SV.HovaTenLot.length() < 0);
	do {
		cout << "\nNhap ten sinh vien: "; cin >> SV.Ten;
	} while (SV.Ten.length() > 10 || SV.Ten.length() <= 0);
	do {
		cout << "\nNhap vao gioi tinh(nam/nu): "; cin >> SV.GioiTinh;
	} while (SV.GioiTinh != "nam" && SV.GioiTinh != "nu");
	do {
		cout << "\nNhap vao DTB: "; cin >> SV.DTB;
	} while (SV.DTB < 0 || SV.DTB > 10);
	do {
		cout << "\nNhap vao lop cua sinh vien: "; cin >> SV.Lop;
	} while (SV.Lop.length() > 10 || SV.Lop.length() <= 0);

}

void XuatSV(SinhVien SV) {

	cout << endl << setiosflags(ios::left)
		<< setw(20) << SV.MaSV
		<< setw(25) << SV.HovaTenLot
		<< setw(15) << SV.Ten
		<< setw(15) << SV.Lop
		<< setw(20) << SV.GioiTinh
		<< setw(25) << SV.DTB;
}
void NhapDSSV(int n , DSSinhVien DSSV) {


	for (int i = 0; i < n; i++) {
		NhapSV(n,DSSV[i],DSSV);
	}
}

void XuatDSSV( int n,DSSinhVien DSSV) {
	cout << endl << setiosflags(ios::left)
		<< setw(20) << "|Ma Sinh Vien "
		<< setw(25) << "|Ho & Ten lot: "
		<< setw(15) << "|Ten: "
		<< setw(15) << "|Lop: "
		<< setw(20) << "|Gioi Tinh: "
		<< setw(25) << "|Diem Trung Binh: ";
	for (int i = 0; i < n; i++) {
		XuatSV(DSSV[i]);
	}
}
void HoanVi(SinhVien &SV1,SinhVien& SV2) {
	SinhVien temp;
	temp = SV1;
	SV1 = SV2;
	SV2 = temp;
}
void SapXep(int n, DSSinhVien DSSV) {
	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++)
			if (DSSV[i].DTB > DSSV[j].DTB) {
				HoanVi(DSSV[i], DSSV[j]);
		}
	}
}

void SapXepTheoTen(int n, DSSinhVien DSSV) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (DSSV[i].Ten.compare(DSSV[j].Ten) < 0) {
				HoanVi(DSSV[i], DSSV[j]);
			}
			else if (DSSV[i].Ten.compare(DSSV[j].Ten) == 0) {
				if (DSSV[i].HovaTenLot.compare(DSSV[j].HovaTenLot)<0 )
					HoanVi(DSSV[i], DSSV[j]);
				
			}
		}
	}

}
void TimSinhVien(int n, DSSinhVien DSSV,string tenSV) {
	
	for (int i=0; i < n; i++) {
		if (DSSV[i].Ten == tenSV) {
			XuatSV(DSSV[i]);

		}
	}
}
bool KTTenSV(int n, DSSinhVien DSSV, string tenSV) {
	bool t=false;
	
	for (int i = 0; i < n; i++) {
		if (DSSV[i].Ten == tenSV) {
			t=1;
		}
		
	}
	return t;
	
}
bool KTLopSV(int n, DSSinhVien DSSV, string lopSV) {
	bool t = false;

	for (int i = 0; i < n; i++) {
		if (DSSV[i].Lop == lopSV) {
			t = 1;
		}

	}
	return t;
}
void TimSinhVienLop(int n, DSSinhVien DSSV, string lopSV) {

	for (int i = 0; i < n; i++) {
		if (DSSV[i].Lop == lopSV) {
			XuatSV(DSSV[i]);

		}
	}
}
void SVKoDcTotNghiep(int n, DSSinhVien DSSV) {

	for (int i = 0; i < n; i++) {
		if (DSSV[i].DTB <5) {
			XuatSV(DSSV[i]);

		}
	}
}
bool KTMaSo(int n, DSSinhVien DSSV,string maSV) {
	bool c = false;
	for (int i = 0; i < n; i++) {
		if (maSV == DSSV[i].MaSV) {
			c = 1;

		}
	}
	return c;
}
void timThongTin(int n, DSSinhVien DSSV, string maSV) {
	int i;
	int x;
	for (i = 0; i < n; i++) {
		if (DSSV[i].MaSV == maSV) {
			break;
		}
	}
	do{
	do {
		system("cls");
		cout << "\nNHAP THONG TINH CAN TIM";
		cout << "\n1.ho va ten, gioi tinh";
		cout << "\n2.diem trung binh";
		cout << "\n3.lop";
		cout << "\n0.thoat chuong trinh";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cin >> x;
	} while ((x < 1 || x>3));
	switch (x) {
	case 1:
		cout << setw(25) << "|Ho & Ten lot: "
			<< setw(15) << "|Ten: "
			<< setw(20) << "|Gioi Tinh: ";
		cout << endl
			<< setw(25) << DSSV[i].HovaTenLot
			<< setw(15) << DSSV[i].Ten
			<< setw(20) << DSSV[i].GioiTinh;
		break;

	case 2:
		cout << "|Diem Trung Binh: " << endl << DSSV[i].DTB;
		break;
	case 3:
		cout << "|Lop: " << endl << DSSV[i].Lop;
		break;
	default:
		break;
	}
	if (x != 0) {
		cout << "\nfress any key to continue";
		_getch();
	}
	} while (x != 0);
}
double TinhTyLe(int n, DSSinhVien DSSV) {
	double count=0;
	for (int i = 0; i < n; i++) {
		if (DSSV[i].DTB>8) {
			count++;
		}

	}
	return (count / n) * 100;
	
}
void XepLoai(int n, DSSinhVien DSSV) {
	for (int i = 0; i < n; i++) {
		if (DSSV[i].DTB >= 9) {
			DSSV[i].HocLuc = "Xuat Sac";

		}
		else if (DSSV[i].DTB >= 8) {
			DSSV[i].HocLuc = "Gioi";
		}
		else if (DSSV[i].DTB >= 7) {
			DSSV[i].HocLuc = "Kha";
		}
		else if (DSSV[i].DTB >= 6.5) {
			DSSV[i].HocLuc = "Trung Binh Kha";
		}
		else if (DSSV[i].DTB >= 5) {
			DSSV[i].HocLuc = "Trung Binh";
		}
		else if (DSSV[i].DTB >= 3) {
			DSSV[i].HocLuc = "Yeu";
		}
		else {
			DSSV[i].HocLuc = "Kem";
		}
	}
	cout << "danh sach sinh vien theo hoc luc";
	
}
void XuatTheoHL(int n, DSSinhVien DSSV) {
	cout<<endl << setw(25) << "|Ho & Ten lot: "
		<< setw(15) << "|Ten: "
		<< setw(20) << "|HocLuc: ";
	for (int i = 0; i < n; i++) {
		cout << endl
			<< setw(25) << DSSV[i].HovaTenLot
			<< setw(15) << DSSV[i].Ten
			<< setw(20) << DSSV[i].HocLuc;
	}
}
double ThongKeHL(int n, DSSinhVien DSSV,string HocLuc) {
	double count = 0;
	for (int i = 0; i < n; i++) {
		if (DSSV[i].HocLuc == HocLuc)
			count++;
	}
	return count * 100 / n;
	
	
}

void XuatThongKe(int n, DSSinhVien DSSV) {
	XepLoai(n, DSSV);
	cout << endl << setiosflags(ios::left)
		<< setw(20) << "|Xuat sac: "
		<< setw(15) << "|Gioi: "
		<< setw(15) << "|Kha: "
		<< setw(20) << "|Trung binh kha: "
		<< setw(20) << "|Trung binh: "
		<< setw(15) << "|Yeu: "
		<< setw(15) << "|Kem: ";
	cout << endl
		<< setw(20) << setprecision(3) << ThongKeHL(n, DSSV, "Xuat Sac") 
		<< setw(15) << setprecision(3) << ThongKeHL(n, DSSV, "Gioi") 
		<< setw(15) << setprecision(3) << ThongKeHL(n, DSSV, "Kha") 
		<< setw(20) << setprecision(3) << ThongKeHL(n, DSSV, "Trung Binh Kha") 
		<< setw(20) << setprecision(3) << ThongKeHL(n, DSSV, "Trung Binh") 
		<< setw(15) << setprecision(3) << ThongKeHL(n, DSSV, "Yeu") 
		<< setw(15) << setprecision(3) << ThongKeHL(n, DSSV, "Kem") ;
}

double tinhDiemTB(int n, DSSinhVien DSSV) {
	double tong = 0;
	for (int i = 0; i < n; i++) {
		tong += DSSV[i].DTB;
	}
	return tong / n;
}
double TinhChenhLech(int n, DSSinhVien DSSV) {
	double count = 0;
	for (int i = 0; i < n; i++) {
		if (DSSV[i].GioiTinh == "nam") {
			count++;
		}

	}

	return abs(count-(n-count));
	
	
}
void thongKe(int &mb,int n, DSSinhVien DSSV, string DSlop[MAX]) {
	
	int x = 0;
	DSlop[0] = DSSV[0].Lop;
	for (int i = 0; i < n; i++) {
		if (DSSV[i].Lop != DSlop[x]) {
			DSlop[x + 1] = DSSV[i].Lop;
			x++;
			mb++;
		}
	}
}
void DemTheoLop(int mb,int n, DSSinhVien DSSV,string DSLop[MAX], int SoSVLop[MAX]) {
	int count=0;
	for (int j = 0; j < mb; j++) {
		for (int i = 0; i < n; i++) {
			if (DSSV[i].Lop == DSLop[j]){
				count++;
			}
		}
		SoSVLop[j] = count;
		count = 0;
	}
}


void XuatThongKeLop(int n,DSSinhVien DSSV) {
	string DSlop[MAX];
	int SoSVLop[MAX];
	int mb = 1;
	thongKe(mb,n, DSSV, DSlop);
	
	
	DemTheoLop(mb, n, DSSV, DSlop, SoSVLop);
	for (int i = 0; i <mb ; i++) {
		cout << setw(15) << DSlop[i];
		
	}
	cout << endl;
	for (int i = 0; i < mb; i++) {
		cout << setw(15) << SoSVLop[i];
	}
}
double TimDTBCaoNhat(int n, DSSinhVien DSSV) {
	double max=0;
	for (int i = 0; i < n; i++) {
		if (DSSV[i].DTB > max) {
			max = DSSV[i].DTB;
		}
	}
	return max;
}

void XuatThongTinDTB(int n, DSSinhVien DSSV) {
	int i;
	for (i = 0; i < n; i++) {
		if (DSSV[i].DTB == TimDTBCaoNhat(n, DSSV)) {
			break;
		}
	}
	cout << endl << setiosflags(ios::left)
		<< setw(20) << "|Ma Sinh Vien "
		<< setw(25) << "|Ho & Ten lot: "
		<< setw(15) << "|Ten: "
		<< setw(15) << "|Lop: "
		<< setw(20) << "|Gioi Tinh: "
		<< setw(25) << "|Diem Trung Binh: ";	
	XuatSV(DSSV[i]);
	
}