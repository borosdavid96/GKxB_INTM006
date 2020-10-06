#include<vector>
#include<iostream>
namespace szeMatrix {

template<class T>
class Matrix {
  protected:
    std::vector<std::vector<T>> mtx;
  
  public:
    Matrix(std::vector<std::vector<T>> src) {
      mtx = src;
    }
    Matrix<T> mul(Matrix<T> right) const;
    void print() const;
    int getRowCount() const { return mtx.size(); }
    int getColCount() const { return mtx[0].size(); }
    T get(int row, int column) const { return mtx[row][column]; }
};

template<class T>
void Matrix<T>::print() const {
  for(auto row : mtx) {
    for(auto elem : row) {
      std::cout << elem << '\t';
    }
    std::cout << std::endl;
  }
}

template<class T>
Matrix<T> Matrix<T>::mul(Matrix<T> right) const {
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

}
