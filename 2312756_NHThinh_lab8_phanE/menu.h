#pragma once
void xuatMenu() {
	cout << "~~~~~~~~~~~~MENU CAC BAI~~~~~~~~~~~~";
	cout << "\n1.Nhap vao danh sach sinh vien";
	cout << "\n2.In ra danh sach sinh vien";
	cout << "\n3.Sap xep va xuat danh sach sinh vien giam dan theo diem trung binh";
	cout << "\n4.Sap xep va xuat danh sach sinh vien tang dan theo ten";
	cout << "\n5.Tim va xuat thong tin cua sinh vien co ten cho truoc";
	cout << "\n6.Xuat DSSV cua lop cho truoc";
	cout << "\n7.Xuat DSSV co kha nang khong duoc tot nghiep";
	cout << "\n8.Tim thong tin sinh vien theo ma so sv";
	cout << "\n9.Tinh ty le so sinh vien dat gioi tro len";
	cout << "\n10.Xep loai hoc luc cua sinh vien dua vao diem tb";
	cout << "\n11.Thong ke ty le hoc sinh theo xep loai hoc luc";
	cout << "\n12.Tinh diem tb cua tat ca sinh vien";
	cout << "\n13.Cho biet chenh lech ve so luong sinh vien nam va nu";
	cout << "\n14.Thong ke so luong sinh vien cua tung lop";
	cout << "\n15.Tim va  xuat thong tin cua nhung sinh vien co diem tb cao nhat";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

}

int chonMenu(int soMenu) {
	int so;

	cin >> so;
	return so;
}
void xuLiMenu(int so, int& n) {
	string tenSV;
	string lopSV;
	string maSV;
	
	switch (so) {

	case 1:;
		
		cout << "\n1.Nhap vao danh sach sinh vien";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n1.1.Nhap vao ca danh sach sinh vien";
		cout << "\n1.2.Du lieu mau: ";
		
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\nchon chuong trinh: ";
		
		int p;
		do {
			cin >> p;
		} while (p < 0 || p>2);
			switch (p) {
			case 1:
				NhapDSSV(n, DSSV);
				
				break;
			case 2:
				DuLieuMau(DSSV);
				
				break;
		}
			
		break;
	case 2:
		
		cout << "\n2.In ra danh sach sinh vien";
		XuatDSSV(n, DSSV);
		break;
	case 3:
		cout << "\n3.Sap xep va xuat danh sach sinh vien giam dan theo diem trung binh";
		cout << "\ndanh sach truoc khi sap xep: \n";
		XuatDSSV(n, DSSV);
		SapXep(n, DSSV);
		cout << "\ndanh sach sau khi sap xep: \n";
		XuatDSSV(n,DSSV);
		break;
	case 4:

		cout << "\n4.Sap xep va xuat danh sach sinh vien tang dan theo ten";
		cout << "\ndanh sach truoc khi sap xep: \n";
		XuatDSSV(n, DSSV);
		SapXepTheoTen(n, DSSV);
		cout << "\ndanh sach sau khi sap xep: \n";
		XuatDSSV(n, DSSV);
		break;
	case 5:
		cout << "\n5.Tim va xuat thong tin cua sinh vien co ten cho truoc";
		cout << "\ndanh sach sinh vien: ";
		XuatDSSV(n,DSSV);
		cout << "\nnhap vao ten sinh vien can tim: ";
		cin >> tenSV; 
		while (KTTenSV(n,DSSV,tenSV) == false) {
			cout << "\nten sinh vien khong ton tai hoac khong dung";
			cout << "\nnhap lai ten sinh vien can tim: ";
			cin >> tenSV;
		}
		
		cout << "danh sach sinh vien co ten "<<tenSV<<" la: \n";
		TimSinhVien(n, DSSV, tenSV);
		break;

	case 6:
		cout << "\n6.Xuat DSSV cua lop cho truoc";
		cout << "\ndanh sach sinh vien:";
		XuatDSSV(n, DSSV);
		cout << "\nnhap vao lop sinh vien: "; cin >> lopSV;
		while (KTLopSV(n, DSSV, lopSV) == false) {
			cout << "\nlop sinh vien khong ton tai hoac khong dung";
			cout << "\nnhap lai lop sinh vien can tim: ";
			cin >> lopSV;
		}
		
		cout << "danh sach sinh vien co lop " << lopSV << " la: \n";
		TimSinhVienLop(n, DSSV, lopSV);
		break;
	case 7:

		cout << "\n7.Xuat DSSV co kha nang khong duoc tot nghiep";
		cout << "\ndanh sach sinh vien: ";
		XuatDSSV(n,DSSV);
		cout << "\ndanh sach sinh vien ko duoc tot nghiep la: ";
		SVKoDcTotNghiep(n, DSSV);
		
		break;
	case 8:
		cout << "\n8.Tim thong tin sinh vien theo ma so sv";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		cout << "\nnhap vao ma sinh vien: "; cin >> maSV;
		while (KTMaSo(n,DSSV,maSV) == false) {
			cout << "\nMa sinh vien khong ton tai hoac khong dung";
			cout << "\nnhap lai ma sinh vien can tim: ";
			cin >> maSV;
		}
		
		timThongTin(n, DSSV,maSV);
		break;
	
	case 9:
		
		cout << "\n9.Tinh ty le so sinh vien dat gioi tro len";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		cout << "\nty le phan tram sinh vien gioi: " << setprecision(3) << TinhTyLe(n,DSSV)<<"%";

		break;

	case 10:
		

		cout << "\n10.Xep loai hoc luc cua sinh vien dua vao diem tb";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		XepLoai(n,DSSV);
		XuatTheoHL(n, DSSV);
		break;
	
	case 11:

		cout << "\n11.Thong ke ty le hoc sinh theo xep loai hoc luc";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		cout << "\nbang thong ke(%): ";
		XuatThongKe(n, DSSV);
		break;
	
	case 12:

		cout << "\n12.Tinh diem tb cua tat ca sinh vien";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		cout << "\nDiem tb cua tat ca sinh vien la: " << setprecision(3) << tinhDiemTB(n, DSSV);
		break;
	
	case 13:

		cout << "\n13.Cho biet chenh lech ve so luong sinh vien nam va nu";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		cout << "\nchenh lech ve so luong sinh vien nam nu la: " << TinhChenhLech(n,DSSV);
		break;
	
	case 14:

		cout << "\n14.Thong ke so luong sinh vien cua tung lop";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		cout << "\nBang thong ke so hoc sinh tung lop: \n";
		XuatThongKeLop(n, DSSV);

		break;
	
	case 15:

		cout << "\n15.Tim va xuat thong tin cua nhung sinh vien co diem tb cao nhat";
		cout << "\ndanh sach sinh vien";
		XuatDSSV(n, DSSV);
		cout << "\nNhung sinh vien co DTB cao nhat la: ";
		XuatThongTinDTB(n, DSSV);
		break;
	}
}
void hamXuLy(int soMenu) {
	int so;
	int n;
	
	cout << "So sinh vien: "; cin >> n;
	
	do {

		system("cls");
		xuatMenu();
		cout << "\nnhap 1 so de chon: ";
		so = chonMenu(soMenu);
		system("cls");
		xuLiMenu(so, n);

		if (so != 0) {
			cout << "\nfress any key to continue";
			_getch();
		}
		cout << "\nprogram ended!";
	} while (so != 0);

}