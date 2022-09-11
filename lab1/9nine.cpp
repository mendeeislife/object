#include <iostream>
using namespace std;

// Хүснэгтийг өсөх/буурахаар эрэмбэл.

// Сонгон эрэмблэлт ашиглан хүснэгтийг өсөх/буурахаар эрэмблэх хэрэглэгчийн функц
void sort(int a[], int n, bool asc) {
	// Авах параметрууд нь a - хүснэгт
	//                     n - хүснэгтийн урт
	//                     asc - өсөх эсвэл буурахаар эрэмблэх (!asc = desc)

	// Хүснэгтээр нэг нэгээр давтах
	for(int i = 0; i < n - 1; i++) {
		// Их эсвэл бага тоог хадгалж өгөх, бага/их тоо солигдсон эсэхийг илтгэх хувьсагч, бага/их тооны байрлал хадгалах 
		// Их/бага-ыг шалгах тоонд эрэмблээгүй хүснэгтийн эхний элементийг өгөх
		int num = a[i], flag = 0, idx;

		// Эрэмблээгүй хүснэгтийн эхний элементийн дараах элементээс эхлэн давтана
		for(int j = i + 1; j < n; j++)
			// Хэрэглэгчийн функц-д өгсөн asc параметр нь true байх үед 
			// хамгийн бага элементийг олж эрэмблээгүй хэсгийн эхний элементтэй солино
			if(asc) {
				// Эрэблээгүй хэсгийн тухайн тоо нь num тооноос бага үед num тоо-г түүгээр солин байрлалыг idx хувьсагчид хадгална
				// num тоо солигдсон учир flag-г 1 болгон солих үйлдэл хийхэд бэлдэнэ
				if(a[j] < num) {
					num = a[j];
					idx = j;
					flag = 1;
				}
			} else { // !asc байх үед өсөхөөс буурах руу эрэмблэнэ гэж үзээд
				// Эрэблээгүй хэсгийн тухайн тоо нь num тооноос их үед num тоо-г түүгээр солин байрлалыг idx хувьсагчид хадгална
				// num тоо солигдсон учир flag-г 1 болгон солих үйлдэл хийхэд бэлдэнэ
				if(a[j] > num) {
					num = a[j];
					idx = j;
					flag = 1;
				}
			}
		
		// num өөрчлөгдсөн учир flag = 1 болоод доорх байр солидог функц ажиллана
		if(flag != 0) {
			// Тоо түр хадгалах temp хувьсагч зарлан өгч түүндээ a[i] буюу эрэмблээгүй хэсгийн эхний тоог өгөв
			int temp = a[i];
			// a хүснэгтийн i байрлалд өмнө тодорхойлсон хамгийн их/бага тоог өгөв
			a[i] = num;
			// Хадгалсан a[i] тоог тодорхойлсон их/бага тооны байранд солив
			a[idx] = temp;
		}
	}
}

// Эрэмблэх функц-д гурван параметр дамжуулхад төвөгтэй, ойлгомжгүй байсан учраас 
// багшийн зааж өгснөөр хоёр салган арай ойлгомжтой болгож өгсөн

// Хүснэгтийг өсөхөөр эрэмблэх
void sortAsc(int a[], int n) {
	sort(a, n, true);
}

// Хүснэгтийг буурахаар эрэмблэх
void sortDesc(int a[], int n) {
	sort(a, n, false);
}

// Хүснэгтийг хэвлэх хэрэглэгчийн функц
void print(int a[], int n) {
	// Хүснэгтийн элемент бүрээр давтан нэг нэгээр нь дэлгэцэнд хэвлэх
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";

	// Мөр шилжүүлэх
	cout << endl;
}

int main() {
	// Эрэмблэх хүснэгт, түүний уртыг гараас зарлаж өгөв
	int a[] = {4, 3, 9, 6, 0, 1, 5, 8, 7, 2};
	int n = sizeof(a) / sizeof(a[0]);
	
	// Хүснэгтийг өсөхөөр эрэмблэх хэрэглэгчийн функц дуудав
	sortAsc(a, n);
	// Хүснэгтийг хэвлэх
	print(a, n);
	
	// Хүснэгтийг буурахаар эрэмблэх хэрэглэгчийн функц дуудав
	sortDesc(a, n);
	// Хүснэгтийг хэвлэх
	print(a, n);
	
	return 0;
}
