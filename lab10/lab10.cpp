#include <iostream>

using namespace std;

class Matrix {
   private:
    int mor, bagana;
    float **_values;

   public:
    Matrix(int m, int n);
    Matrix(const Matrix &mat);
    ~Matrix();
    int getRow() const;                        //Мөрийн тоог буцаана
    int getColumn() const;                     //Баганын тоог буцаана
    void setValues(float **values);            //_values хүснэгтэнд гараас утга авч оноох
    float **getValues();                       //_values хүснэгтийг буцаана
    void setValue(int i, int j, float value);  // i-р мөр j-р баганын утгад value утгыг оноох
    float getValue(int i, int j) const;        // i-р мөр j-р баганын утгыг буцаах
    void resize(int n, int m);                 //Хүснэгтийн хэмжээсийг дахин шинэчлэх, хүснэгтэд дахин санах ой нөөцлөөд хүснэгтийн элементийн утгыг 0 болгох
    void printMatrix();                        //Хүснэгтийн утгыг хэвлэж харах
    void deleteVal();

    //Оператор дахин тодорхойлох
    Matrix operator+(float);
    Matrix operator+(Matrix);
    Matrix operator*(Matrix);
    Matrix operator-(Matrix);
    void operator=(Matrix);
    void operator++();
    void operator--();
    void operator+=(float);
    void operator-=(float);
    void operator*=(float);
    float *operator[](int);
    Matrix operator~();
};

void Matrix::deleteVal() {
    for (int i = 0; i < mor; i++) delete[] _values[i];
    delete[] _values;
}

Matrix::Matrix(int m, int n) {
    mor = m;
    bagana = n;
    _values = new float *[mor];
    int i, j;
    for (i = 0; i < m; i++) _values[i] = new float[mor];
    for (i = 0; i < mor; i++) {
        for (j = 0; j < bagana; j++) {
            _values[i][j] = j;
        }
    }
    cout << "Object uuslee!" << endl;
}

Matrix::Matrix(const Matrix &mat) {
    mor = mat.getRow();
    bagana = mat.getColumn();
    _values = new float *[mor];
    for (int i = 0; i < mor; i++) _values[i] = new float[bagana];
    for (int i = 0; i < mor; i++) {
        for (int j = 0; j < bagana; j++) {
            _values[i][j] = mat._values[i][j];
        }
    }
    cout << "Object uuslee!" << endl;
};
Matrix::~Matrix() {
    cout << "Object ustlaa!" << endl;
    for (int i = 0; i < mor; i++) delete[] _values[i];
    delete[] _values;
}

void Matrix::resize(int n, int m) {
    for (int i = 0; i < mor; i++) delete[] _values[i];
    delete[] _values;
    mor = m;
    bagana = n;
    _values = new float *[mor];
    for (int i = 0; i < mor; i++) _values[i] = new float[bagana];
    for (int i = 0; i < mor; i++) {
        for (int j = 0; j < bagana; j++) {
            _values[i][j] = 1;
        }
    }
}

void Matrix::setValue(int i, int j, float value) {
    _values[i][j] = value;
}

void Matrix::setValues(float **a) {
    int i, j;
    for (i = 0; i < mor; i++) {
        for (j = 0; j < bagana; j++) {
            _values[i][j] = a[i][j];
        }
    }
}

float **Matrix::getValues() {
    return _values;
}
int Matrix::getRow() const {
    return mor;
}

int Matrix::getColumn() const {
    return bagana;
}

float Matrix::getValue(int i, int j) const {
    return _values[i][j];
}

void Matrix::printMatrix() {
    int i, j;
    for (i = 0; i < mor; i++) {
        for (j = 0; j < bagana; j++) {
            if (_values[i][j] > 9)
                cout << _values[i][j] << " ";
            else
                cout << _values[i][j] << " ";
        }
        cout << "\n";
    }
}

//Матрицын элементүүдийг а тоогоор нэмэгдүүлэх
Matrix Matrix::operator+(float a) {
    Matrix new_Matrix(mor, bagana);
    int i, j;
    for (i = 0; i < mor; i++) {
        for (j = 0; j < bagana; j++) {
            new_Matrix._values[i][j] = _values[i][j] + a;
        }
    }
    return new_Matrix;
}

// 2 матрицыг хооронд нэмэх
Matrix Matrix::operator+(Matrix mat) {
    if (bagana == mat.getRow() && mor == mat.getColumn()) {
        Matrix new_Matrix(mor, bagana);
        int i, j;
        for (i = 0; i < mor; i++) {
            for (j = 0; j < bagana; j++) {
                new_Matrix._values[i][j] = _values[i][j] + mat._values[i][j];
            }
        }
        return new_Matrix;
    } else {
        cout << "2 matritsiin hemjee tohirsongui" << endl;
        return *this;
    }
}

// 2 матрицыг хооронд нь үржих
Matrix Matrix::operator*(Matrix mat) {
    if (bagana == mat.getRow()) {
        int i, j, mSize, s, niilber, bagana;
        mSize = mor * bagana;
        Matrix new_Matrix(mor, mat.getColumn());
        for (i = 0; i < mor; i++) {
            for (bagana = 0; bagana < mat.getColumn(); bagana++) {
                niilber = 0;
                for (j = 0; j < bagana; j++) {
                    s = _values[i][j] * mat._values[j][i];
                    niilber = niilber + s;
                }
                new_Matrix._values[i][bagana] = niilber;
            }
        }
        return new_Matrix;
    } else {
        cout << "\n2 matritsiin hemjee tohirsongui:" << endl;
        return *this;
    }
}

// 2 матрицыг хооронд нь хасах
Matrix Matrix::operator-(Matrix mat) {
    if (bagana == mat.getRow() && mor == mat.getColumn()) {
        Matrix new_Matrix(mor, bagana);
        int i, j;
        for (i = 0; i < mor; i++) {
            for (j = 0; j < bagana; j++) {
                new_Matrix._values[i][j] = _values[i][j] - mat._values[i][j];
            }
        }
        return new_Matrix;
    } else {
        cout << "2 matritsiin hemjee tohirsongui" << endl;
        return *this;
    }
}

void Matrix::operator=(Matrix mat) {
    if (bagana == mat.getColumn() && mor == mat.getRow()) {
        for (int i = 0; i < mor; i++) {
            for (int j = 0; j < bagana; j++) {
                _values[i][j] = mat._values[i][j];
            }
        }
    } else {
        cout << "2 matritsiin hemjee tohirsongui" << endl;
    }
}

//Матрицыг нэгээр нэмэгдүүлэх
void Matrix::operator++() {
    for (int i = 0; i < mor; i++) {
        for (int j = 0; j < bagana; j++) {
            _values[i][j]++;
        }
    }
}

//Матрицыг нэгээр хорогдуулах
void Matrix::operator--() {
    for (int i = 0; i < mor; i++) {
        for (int j = 0; j < bagana; j++) {
            _values[i][j]--;
        }
    }
}

//Матриц элементүүд дээр а тоог нэмэх
void Matrix::operator+=(float a) {
    for (int i = 0; i < mor; i++) {
        for (int j = 0; j < bagana; j++) {
            _values[i][j] += a;
        }
    }
}

//Матрицын элементүүдээс а тоог хасах
void Matrix::operator-=(float a) {
    for (int i = 0; i < mor; i++)
        for (int j = 0; j < bagana; j++)
            _values[i][j] -= a;
}

//Матрицын элементүүдийг а тоогоор үржүүлэх
void Matrix::operator*=(float a) {
    for (int i = 0; i < mor; i++)
        for (int j = 0; j < bagana; j++)
            _values[i][j] *= a;
}

// i-р мөр j-р багана утга авах
float *Matrix::operator[](int index) {
    return _values[index];
}

//Матриц хөрвүүлэх
Matrix Matrix::operator~() {
    Matrix copyMatrix(bagana, mor);  //Шинэ объект үүсгэх
    for (int i = 0; i < mor; i++) {
        for (int j = 0; j < bagana; j++) {
            copyMatrix._values[j][i] = _values[i][j];  //Матриц хөрвүүлэх
        }
    }
    return copyMatrix;  //Хөрвүүлсэн матрицаа буцаах
}

int main() {
    //Хүснэгтийн хэмжээг гараас авах
    int m1, n1, m2, n2;
    cout << "1-r matritsiin moriin toog oruulna uu : ";
    cin >> m1;
    cout << "1-r matritsiin Baganiin toog oruulna uu : ";
    cin >> n1;

    Matrix matrix1(m1, n1);
    //Үр дүнг хэвлэж харна
    printf("m : %d\nn : %d\n", matrix1.getRow(), matrix1.getColumn());
    cout << "Matrits : 1" << endl;
    matrix1.printMatrix();
    
    cout << "2-r matritsiin moriin toog oruulna uu : ";
    cin >> m2;
    cout << "2-r matritsiin Baganiin toog oruulna uu : ";
    cin >> n2;
    
    Matrix matrix2(m2, n2);
    //Үр дүнг хэвлэж харна
    printf("m : %d\nn : %d\n", matrix2.getRow(), matrix2.getColumn());
    cout << "Matrits : 2" << endl;
    matrix2.printMatrix();
    
    Matrix matrix = matrix1 + 12.5;
    cout << "\nR = R1 + 12.5: " << endl;
    matrix.printMatrix();
    
    Matrix matrix3 = matrix1 + matrix2;
    cout << "\nR = R1 + R2:" << endl;
    matrix3.printMatrix();
    
    Matrix matrix4 = matrix1 * matrix2;
    cout << "\nR = R1 * R2" << endl;
    matrix4.printMatrix();
    
    Matrix matrix5 = matrix1 - matrix2;
    cout << "\nR = R1 - R2" << endl;
    matrix5.printMatrix();
    
    cout << "\nR1 = R2" << endl;
    matrix1 = matrix2;
    matrix1.printMatrix();
    
    cout << "\nR++" << endl;
    ++matrix1;
    matrix1.printMatrix();
    
    cout << "\nR--" << endl;
    --matrix1;
    matrix1.printMatrix();
    
    matrix1 += 5;
    cout << "\nR+=" << endl;
    matrix1.printMatrix();
    
    matrix1 -= 3;
    cout << "\nR-=" << endl;
    matrix1.printMatrix();
    
    matrix1 *= 2;
    cout << "\nR*=" << endl;
    matrix1.printMatrix();
    
    cout << "\nR[]\n" << matrix1[1][2] << endl;
    Matrix matrix6 = ~matrix1;
    cout << "\n~R" << endl;
    matrix5.printMatrix();

    return 0;
}