#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Matrix
{
    int **data;
    int Rows, Cols;
public:
    Matrix();
    Matrix(int row, int col);
    ~Matrix();
    void Input(int row, int col);
    void setAt(int i, int j, int x);
    int getAt(int i, int j);
    void display();
    void resize(int r, int c);
    friend Matrix operator+(const Matrix &m1, const Matrix &m2)
    {
        Matrix m(m1.Rows, m1.Cols);
        for(int i = 0; i < m1.Rows; i++)
        {
            for(int j = 0; j < m1.Cols; j++)
            {
                m.data[i][j] = m1.data[i][j] + m2.data[i][j];
            }
        }
       return m;
    }
    friend Matrix operator-(const Matrix &m1, const Matrix &m2)
    {
        Matrix m(m1.Rows, m2.Cols);
        for(int i = 0; i < m1.Rows; i++)
        {
            for(int j = 0; j < m2.Cols; j++)
            {
                m.data[i][j] = 0;
                for(int t = 0; t < m1. Rows; t++)
                    m.data[i][j] += m1.data[i][t] * m2.data[t][j];
            }
        }
        return m;
    }
};

Matrix ::Matrix()
{
    Rows = Cols = 0;
}

Matrix ::Matrix(int row, int col)
{
    Rows = row;
    Cols = col;
    data = new int *[Rows];
    for(int i = 0; i < Rows; i++)
    {
        *(data + i) = new int[Cols];
    }
}

Matrix ::~Matrix()
{
    for(int i = 0; i < Rows; i++)
    {
        delete [] data[i];
    }
    delete[] data;
}

void Matrix ::Input(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> data[i][j];
            setAt(i, j, data[i][j]);
        }
    }
}

void Matrix ::setAt(int i, int j, int x)
{
    data[i][j] = x;
}

int Matrix ::getAt(int i, int j)
{
    return data[i][j];
}

void Matrix ::display()
{
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Cols; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::resize(int r,int c)
{
    if(r<=Rows)
        Rows=r;
    if(c<=Cols)
        Cols=c;
    if(r>Rows)
    {
        for(int i=Rows; i<r; i++)
            for(int j=0;j<Cols;j++)
            {
                cout << "PT " << i+1 << j+1 << " : ";
                cin >> data[i][j];
            }
        Rows=r;
    }
    if(c>Cols)
    {
        for(int i=0; i<Rows; i++)
            for(int j=Cols; j<c; j++)
            {
                cout << "PT " << i+1 << j+1 << " : ";
                cin >> data[i][j];
            }
        Cols=c;
    }
}

int main()
{
    int row,col,col1;
    do
    {
        cout << "Nhap hang cua Ma Tran A : ";   cin >> row;
        cout << "Nhap cot cua Ma Tran A : ";    cin >> col;
    }while(row==1 && col==1);
    Matrix A(row,col),B(row,col);
    cout << "Nhap cac PT cua Ma Tran A : " << endl;
    A.Input(row,col);
    cout << "Ma Tran A la : " << endl;
    A.display();
    cout << "Ma Tran B co so cot , hang nhu Ma Tran A " << endl;
    cout << "Nhap cac PT cua Ma Tran B : " << endl;
    B.Input(row,col);
    cout << "Ma Tran B la : " << endl;
    B.display();

    //Tong cua 2 Ma Tran C=A+B
    Matrix C = A + B;
    cout << "Tong cua 2 Ma Tran C = A + B la : " << endl;
    C.display();

    //Tich cua hai Ma Tran
    cout << "Ma Tran D co so hang = so cot cua Ma Tran A = " << col;
    cout << endl << "Nhap so cot cua Ma Tran D : ";
    cin >> col1;
    Matrix D(col,col1);
    D.Input(col,col1);
    cout << "Ma Tran D la : " << endl;
    D.display();
    Matrix E = A - D;
    cout << "Tich cua 2 Ma Tran E = A * D la : " << endl;
    E.display();
    system("pause");
}
