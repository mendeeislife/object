#include <iostream>
using namespace std;

// a, b, c гурван тооны хамгийн ихийг олж дэлгэцэнд хэвлэ
int main() {
	// Гараас авах 3 тоо бас хамгийн их тоог хадгалах хувьсагч зарлаж өгч байна
	int a, b, c, max;
	
	// Гурван тоо-г гараас авах
	cin >> a >> b >> c;
	
	// Ternary оператор ашиглан гурван тооны аль нь их гэдгийг жишиж олоод max хувьсагчид хийх
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);
	
	// Олсон хамгийн их утгаа хэвлэж өгч байна
	cout << "Max: " << max << endl;
	
	return 0;
}
