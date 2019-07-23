#include<vector>
#include<iostream>
#include<sstream>
namespace szeMatrix {

template<class T>
class Matrix {
  protected:
    std::vector<std::vector<T>> mtx;
  
  public:
    Matrix(std::vector<std::vector<T>> src) {
      mtx = src;
    }
    Matrix<T> mul(Matrix<T> right);
    void print();
    std::string toString();
    const char* toCString();
    int getRowCount() { return mtx.size(); }
    int getColCount() { return mtx[0].size(); }
    T get(int row, int column) { return mtx[row][column]; }
    template<class U>
    friend bool operator==(const Matrix<U> &m1, const Matrix<U> &m2);
};

template<class T>
void Matrix<T>::print() {
  for(std::vector<T> row : mtx) {
    for(T elem : row) {
      std::cout << elem << '\t';
    }
    std::cout << std::endl;
  }
}

template<class T>
std::string Matrix<T>::toString() {
  std::stringstream ss;
  for(std::vector<T> row : mtx) {
    for(T elem : row) {
      ss << elem << '\t';
    }
    ss << std::endl;
  }
  return ss.str();
}

template<class T>
const char* Matrix<T>::toCString() {
  return toString().c_str();
}

template<class T>
Matrix<T> Matrix<T>::mul(Matrix<T> right) {
  // Rows of left matrix and result matrix
  int i = mtx.size();
  // Columns of right matrix and res. matrix
  int j = right.mtx[0].size();
  // Columns of left matrix and rows of right matrix
  int k = right.mtx.size();
  
  // Creating an empty result matrix
  std::vector<std::vector<T>> res; 
  // Resizing and filling it with zeros
  res.resize(i, std::vector<T>(j, 0.)); 
  
  for(int r=0; r<i; r++) { // Matrix multiplication
    for(int c=0; c<j; c++) {
      for(int item=0; item<k; item++) {
        res[r][c] += mtx[r][item]*right.mtx[item][c];
      }
    }
  }
  
  return Matrix(res);
}

template<class U>
bool operator==(const Matrix<U> &m1, const Matrix<U> &m2) { 
  return m1.mtx==m2.mtx;
}

}
