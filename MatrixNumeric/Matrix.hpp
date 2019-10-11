//
//  Matrix.hpp
//  MatrixNumeric
//
//  Created by YangWenli on 2019/10/10.
//  Copyright © 2019 YangWenli. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include<vector>

using std::vector;

vector<vector<double>> multiply(const vector<vector<double>>& v1, const vector<unsigned long> pos1, const vector<vector<double>>& v2, const vector<unsigned long> pos2);

class Matrix{
private:
    vector<vector<double>> data;

public:
    unsigned long height;
    unsigned long width;
    Matrix(vector<vector<double>> _d);
    vector<double> operator[](int i) const;
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;
    Matrix operator*(int x) const;
    Matrix operator*(const vector<double>& v) const;
    Matrix transpose() const;
    vector<vector<double>> toVector() const;
    vector<Matrix> LU() const;
    double det() const;
    void show() const;
};
#endif /* Matrix_hpp */
