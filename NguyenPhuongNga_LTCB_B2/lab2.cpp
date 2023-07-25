// 0850080033_NguyenPhuongNga_08THMT

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 6
double tinhCuoc(int gioBD, int gioKT, int TGIAN, double MIENGIA, double giamGia)
{
    double cuocTruyCap = TGIAN * MIENGIA;
    if (TGIAN > giamGia)
    {
        cuocTruyCap *= (1.0 - giamGia / 100.0);
    }
    return cuocTruyCap;
}
// 7
double tinhTienThuePhong(int soNgay, char loaiPhong)
{
    double giaPhong;
    switch (loaiPhong)
    {
    case 'A':
        giaPhong = 250000;
        break;
    case 'B':
        giaPhong = 200000;
        break;
    case 'C':
        giaPhong = 150000;
        break;
    default:
        cout << "Loai phong khong hop le" << endl;
        return 0.0;
    }

    double tongTien = soNgay * giaPhong;
    double phanTramGiam;

    if (soNgay >= 12)
    {
        if (loaiPhong == 'A')
        {
            phanTramGiam = 10;
        }
        else
        {
            phanTramGiam = 8;
        }
        tongTien -= tongTien * phanTramGiam / 100.0;
    }

    return tongTien;
}
// 8
bool laNamNhuan(int nam)
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam)
{
    int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && laNamNhuan(nam))
    {
        return 29;
    }
    return ngayTrongThang[thang];
}

bool ngayHopLe(int ngay, int thang, int nam)
{
    if (thang < 1 || thang > 12)
    {
        return false;
    }
    if (ngay < 1 || ngay > soNgayTrongThang(thang, nam))
    {
        return false;
    }
    return true;
}

void timNgayHomSau(int &ngay, int &thang, int &nam)
{
    ngay++;
    if (ngay > soNgayTrongThang(thang, nam))
    {
        ngay = 1;
        thang++;
        if (thang > 12)
        {
            thang = 1;
            nam++;
        }
    }
}

void timNgayHomTruoc(int &ngay, int &thang, int &nam)
{
    ngay--;
    if (ngay == 0)
    {
        thang--;
        if (thang == 0)
        {
            thang = 12;
            nam--;
        }
        ngay = soNgayTrongThang(thang, nam);
    }
}

// 9
double tinhTienTaxi(int soKm)
{
    double giaKmDau = 15000;
    double giaTuKm2Den5 = 13500;
    double giaTuKm6TroDi = 11000;
    double giamGiaTren120Km = 0.10;

    double tongTien = 0.0;

    if (soKm > 0)
    {
        tongTien += giaKmDau;
        soKm--;

        if (soKm > 0)
        {
            int kmDen5 = min(4, soKm);
            tongTien += kmDen5 * giaTuKm2Den5;
            soKm -= kmDen5;
        }

        if (soKm > 0)
        {
            tongTien += soKm * giaTuKm6TroDi;
        }

        if (soKm > 120)
        {
            double giamGia = tongTien * giamGiaTren120Km;
            tongTien -= giamGia;
        }
    }

    return tongTien;
}

// 10
//  Hàm tính điểm trung bình 3 môn
double diemTrungBinh(double diemToan, double diemLy, double diemHoa)
{
    return (diemToan + diemLy + diemHoa) / 3.0;
}

// Hàm phân loại học sinh dựa trên điểm trung bình
string phanLoai(double diemTrungBinh)
{
    if (diemTrungBinh >= 9.0)
    {
        return "Xuat sac";
    }
    else if (diemTrungBinh >= 8.0)
    {
        return "Gioi";
    }
    else if (diemTrungBinh >= 6.5)
    {
        return "Kha";
    }
    else if (diemTrungBinh >= 5.0)
    {
        return "Trung binh";
    }
    else if (diemTrungBinh >= 3.0)
    {
        return "Yeu";
    }
    else
    {
        return "Kem";
    }
}
// 12
// double Tinh(int n)
// {
//     float s = 0, t = 0;
//     long p = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         t = t + i;
//         p = p * i;
//         s = s + (double)t / p;
//     }
//     return s;

    // ===========================================================
    int main()
    {
        cout << "Nhập câu hỏi của bài LAB2?" << endl;
        cout << "1. Tích 2 số bằng 2 lần tổng" << endl;
        cout << "2. Nhập số ngto và in ra các số ngto nhỏ hơn" << endl;
        cout << "3. Mã ASCII" << endl;
        cout << "4. Số đảo ngược" << endl;
        cout << "5. Đếm số lượng số và tính tổng" << endl;
        cout << "6. Tính cước truy cập Internet" << endl;
        cout << "7. Tính tiền thuê phòng" << endl;
        cout << "8. Tính ngày tháng năm" << endl;
        cout << "9. Tính tiền taxi" << endl;
        cout << "10. Tính điểm TB và phân loại" << endl;
        cout << "11. In mã ASCII và nhấn Enter qua trang" << endl;
        cout << "Số nhập là: ";

        int n;
        cin >> n;
        switch (n)
        {
            // =========================================
        case 1:
        {
            int b, c, n, c1, c2;
            cout << "Nhập số nguyên dương từ 10 - 99: ";
            cin >> n;
            if (n < 10 || n > 99)
            {
                cout << "Từ 10 - 99";
            }
            else
            {
                c = n / 10;
                b = n % 10;
                c1 = c * b;
                c2 = 2 * (c + b);
                if (c1 == c2)
                {
                    cout << "Số " << n << " Thoả mãn " << endl;
                }
                else
                {
                    cout << "Số " << n << " Không thoả mãn " << endl;
                }
            }
        }
        break;

        case 2:
        {
            int n;
            cout << "NHập số nguyên n: ";
            cin >> n;
            cout << "Các số ngto nhỏ hơn " << n << " là: " << endl;
            for (int i = 2; i < n; ++i)
            {
                bool number = true;
                for (int j = 2; j * j <= i; ++j)
                {
                    if (i % j == 0)
                    {
                        number = false;
                        break;
                    }
                }
                if (number)
                {
                    cout << i << " ";
                }
            }
            cout << endl;
            break;
        }

        case 3:
        {
            for (int i = 0; i <= 256; i++)
            {
                cout << "Kí tự: " << (char)i << " | Mã ASCII: " << i << endl;
                if (i % 32 == 0)
                {
                    cout << endl;
                }
            }
            break;
        }

        case 4:
        {
            int n;
            cout << "Nhập số" << endl;
            cin >> n;
            cout << "Số đảo ngược là" << endl;
            int sdn = 0;
            while (n > 0)
            {
                int x = n % 10;
                sdn = sdn * 10 + x;
                n = n / 10;
            }
            cout << sdn;
            break;
        }
        case 5:
        {
            int n;
            cout << "Nhập số n : ";
            cin >> n;
            int sonhap = n;

            int count = 0;
            for (int i = 1; n > 0; i++)
            {
                n /= 10;
                count++;
            }

            int sum = 0;
            for (int i = 0; sonhap > 0; i++)
            {
                sum += sonhap % 10;
                sonhap /= 10;
            }

            cout << "Số lượng chữ số là : " << count << endl;
            cout << "Tổng của số là: " << sum << endl;
            break;
        }
        case 6:
        {
            int gioBD, gioKT;
            cout << "Nhap gio bat dau truy cap: ";
            cin >> gioBD;
            cout << "Nhap gio ket thuc truy cap: ";
            cin >> gioKT;

            // Xác định khoảng thời gian truy cập và tính cước truy cập
            int TGIAN = (gioKT - gioBD + 24) % 24;
            double cuocTruyCap = 0.0;

            if (gioBD >= 7 && gioBD < 17)
            {
                // Khoảng thời gian từ 7 giờ - 17 giờ
                cuocTruyCap = tinhCuoc(gioBD, gioKT, TGIAN, 400, 10);
            }
            else if (gioBD >= 17 || gioKT < 7)
            {
                // Khoảng thời gian từ 17 giờ - 24 giờ và từ 0 giờ - 7 giờ
                cuocTruyCap = tinhCuoc(gioBD, gioKT, TGIAN, 350, 12);
            }
            else
            {
                // Trường hợp còn lại (từ 0 giờ - 7 giờ đang ở trong khoảng 7 giờ - 17 giờ)
                int truoc17Gio = (17 - gioBD + 24) % 24;
                double cuocTruoc17Gio = tinhCuoc(gioBD, gioBD + truoc17Gio, truoc17Gio, 400, 10);

                int sau7Gio = (gioKT - 7 + 24) % 24;
                double cuocSau7Gio = tinhCuoc(gioKT - sau7Gio, gioKT, sau7Gio, 300, 15);

                cuocTruyCap = cuocTruoc17Gio + cuocSau7Gio;
            }

            cout << "Cước truy cập Internet là: " << cuocTruyCap << " VND" << endl;
            break;
        }

        case 7:
        {
            int soNgay;
            char loaiPhong;

            cout << "Nhap so ngay thue phong: ";
            cin >> soNgay;

            cout << "Nhap loai phong (A, B, C): ";
            cin >> loaiPhong;

            double tienThuePhong = tinhTienThuePhong(soNgay, toupper(loaiPhong));
            if (tienThuePhong > 0)
            {
                cout << "Tien thue phong la: " << tienThuePhong << " dong" << endl;
            }
        }

        case 8:
        {
            int ngay, thang, nam;
            cout << "Nhap ngay: ";
            cin >> ngay;
            cout << "Nhap thang: ";
            cin >> thang;
            cout << "Nhap nam: ";
            cin >> nam;

            if (ngayHopLe(ngay, thang, nam))
            {
                cout << "Ngay thang nam hop le." << endl;
                cout << "Thang " << thang << " co " << soNgayTrongThang(thang, nam) << " ngay." << endl;

                int ngayHomSau = ngay, thangHomSau = thang, namHomSau = nam;
                timNgayHomSau(ngayHomSau, thangHomSau, namHomSau);
                cout << "Ngay hom sau la: " << ngayHomSau << "/" << thangHomSau << "/" << namHomSau << endl;

                int ngayHomTruoc = ngay, thangHomTruoc = thang, namHomTruoc = nam;
                timNgayHomTruoc(ngayHomTruoc, thangHomTruoc, namHomTruoc);
                cout << "Ngay hom truoc la: " << ngayHomTruoc << "/" << thangHomTruoc << "/" << namHomTruoc << endl;
            }
            else
            {
                cout << "Ngay thang nam khong hop le." << endl;
            }
            break;
        }

        case 9:
        {
            int soKm;
            cout << "Nhap so km da di: ";
            cin >> soKm;

            if (soKm > 0)
            {
                double tienTaxi = tinhTienTaxi(soKm);
                cout << "Tien di taxi: " << tienTaxi << " dong" << endl;
            }
            else
            {
                cout << "So km khong hop le." << endl;
            }
        }
        case 10:
        {
            string hoTen;
            double diemToan, diemLy, diemHoa;

            cout << "Nhập họ tên: ";
            cin.ignore();
            getline(cin, hoTen);

            cout << "Điểm Toán: ";
            cin >> diemToan;

            cout << "Điểm Lý: ";
            cin >> diemLy;

            cout << "Điểm Hoá: ";
            cin >> diemHoa;

            double dtb = diemTrungBinh(diemToan, diemLy, diemHoa);

            cout << "Điểm TB của HS là " << hoTen << " là: " << dtb << endl;
            cout << "Phân loại " << hoTen << " như sau: " << phanLoai(dtb) << endl;

            return 0;
        }

        case 11:
        {
            int itemsPerPage = 22;
            int start = 0;
            int end = 255;
            char input;
            do
            {
                system("cls");
                cout << "Mã: "
                        " | Kí tự: "
                     << endl;
                // cout << "Mã\t\tKí tự" << endl;
                for (int i = start; i <= start + itemsPerPage - 1 && i <= end; i++)
                {
                    cout << i << "\t |      " << static_cast<char>(i) << endl;
                }

                cout << "\nNhấn Enter để hiển thị trang kế tiếp...";
                do
                {
                    input = getchar();
                } while (input != '\n');

                start += itemsPerPage;

            } while (start <= end);
            break;

        // case 12:
        // {

        //     int Nhap()
        //     {
        //         int x;
        //         do
        //         {
        //             cin >> x;
        //             if (x < 0)
        //                 cout << "Nhap sai, yeu cau nhap lai!";
        //         } while (x < 0);
        //         return x;
        //         cout << "Nhap so nguyen n: ";
        //         n = Nhap();
        //         cout << "Ket qua la: " << Tinh(n) << endl;

        //         return 0;
            }
        }
        }