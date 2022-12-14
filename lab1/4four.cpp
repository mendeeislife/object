#include <iostream>
using namespace std;

// Өгөгдсөн N хүртэлх тооны нийлбэр, арифметик дундажыг ол.
int main() {
	// Гараас авах n тоо болон n хүрвэлх тоонуудын нийлбэрийг хадгалах хувьсагч зарлах
	int n, sum = 0;

	// Гараас n тоог авах
	cin >> n;
	
	// 1 ээс эхлэн n хүртэлх тоонуудын нийлбэрийг олох
	for(int i = 1; i <= n; i++)
		sum += i;
	
	// Тооны нийлбэрийг хэвлэх
	cout << "Sum: " << sum << endl;
	// Нийлбэрийг нийт хэдэн тоо нэмсэндээ хуваан дундажыг олоод хэвлэх.
	// (double) ашигласан нь дундаж тоо нь бодит тоо байж болзошгүй учраас аль нэг тоог нь бодит тоо болгон шилжүүлсэн
	cout << "AVG: " << sum / (double)n << endl;
	
	return 0;
}
