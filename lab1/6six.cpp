#include <iostream>
using namespace std;

// Өгөгдсөн N ширхэг тооны хамгийн их/хамгийн багийг ол.
int main() {
	// Гараас авах n тоог зарлан, авч байна
	int n;
	cin >> n;

	// n ширхэг тоог хадгалах хүснэгт зарлан, гараас түүнд утга оруулах
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	// Хамгийн их/бага тоог хадгалах хувьсагч зарлан түүнд тоонуудын хүснэгтийн эхний тоог өгөв
	int max = a[0], min = a[0];
	// Өмнө нь эхний тоонуудыг өгсөн учир давталтыг 1-ээс эхлүүлэн, оруулж өгсөн тоонуудаар давтав
	for(int i = 1; i < n; i++) {
		// Давталтанд харгалзах тоо нь зарлаж өгсөн max тооноос их үед тухайн тоог хамгийн их гэж үзээд max хувьсагчид өгнө
		if(a[i] > max)
			max = a[i];
		// Давталтанд харгалзах тоо нь зарлаж өгсөн min тооноос бага үед тухайн тоог хамгийн бага гэж үзээд min хувьсагчид өгнө
		if(a[i] < min)
			min = a[i];
	}
	
	// Үр дүнг хэвлэх
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	
	return 0;
}
