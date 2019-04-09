#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần sẽ thấy sức mạnh của nó
#pragma warning(disable:4996) // bỏ qua các lỗi C4996 về cú pháp cải tiến các hàm của Visual Studio 

// Define thêm một số phím ký tự cần thiết khi thao tác trên bàn phím 
#define    KEY_A    0x41
#define    KEY_B    0x42
#define    KEY_C    0x43
#define    KEY_D    0x44
#define    KEY_E    0x45
#define    KEY_F    0x46
#define    KEY_G    0x47
#define    KEY_H    0x48
#define    KEY_I    0x49
#define    KEY_J    0x4A
#define    KEY_K    0x4B
#define    KEY_L    0x4C
#define    KEY_M    0x4D
#define    KEY_N    0x4E
#define    KEY_O    0x4F
#define    KEY_P    0x50
#define    KEY_Q    0x51
#define    KEY_R    0x52
#define    KEY_S    0x53
#define    KEY_T    0x54
#define    KEY_U    0x55
#define    KEY_V    0x56
#define    KEY_W    0x57
#define    KEY_X    0x58
#define    KEY_Y    0x59
#define    KEY_Z    0x5A
// các phím điều khiển lên xuống trái phải...
#define     KEY_LEFT    VK_LEFT
#define     KEY_RIGHT   VK_RIGHT
#define     KEY_UP      VK_UP
#define     KEY_DOWN    VK_DOWN
#define     KEY_ESC     VK_ESCAPE
#define KEY_NONE	-1
// các mã màu tương ứng
#define BLACK_COLOR			0
#define DARK_BLUE_COLOR		1 
#define DARK_GREEN_COLOR	2
#define DARK_CYAN_COLOR		3
#define DARK_RED_COLOR		4
#define DARK_PINK_COLOR		5
#define DARK_YELLOW_COLOR	6
#define DARK_WHITE_COLOR	7
#define GREY_COLOR			8
#define BLUE_COLOR			9
#define GREEN_COLOR			10
#define CYAN_COLOR			11
#define RED_COLOR			12
#define PINK_COLOR			13
#define YELLOW_COLOR		14
#define WHITE_COLOR			15

/* =================== KHAI BÁO CÁC HÀM HỖ TRỢ TRÊN CỬA SỔ DÒNG LỆNH  ===================*/


// Lấy nút bàn phím do người dùng bấm
// Trả về: Mã của phím
int inputKey();

// Lấy tọa độ x hiện tại của con trỏ console
int whereX();

// Lấy tọa độ y hiện tại của con trỏ console
int whereY();

// Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
void gotoXY(int x, int y);

// Đặt màu cho chữ muốn in lên màn hình
void SetColor(WORD color);

// Đặt màu nền cho chữ muốn in lên màn hình
void SetBGColor(WORD color);

// Thiết lập chế độ hiển thị, có fullscreen hay không
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode);

// Đặt chế độ FullScreen
void setFullScreen();

// Thoát khỏi fullscreen
void exitFullScreen();

// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void ShowCur(bool CursorVisibility);

// Xóa toàn bộ nội dung cửa sổ console - chôm từ MSDN
void cls(HANDLE hConsole);

// Viết lại hàm clrscr, không cần cũng được nhưng để nhìn vào code cho đẹp mắt
void clrscr();

// Kiểm tra xem phím nào được nhấn, trả về true nếu phím đó đã được nhấn xuống
bool checkKey(int key);


// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int , int );
// ============================ HÀM PHÁT SINH ============================
