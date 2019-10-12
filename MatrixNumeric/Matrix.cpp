//
//  Matrix.cpp
//  MatrixNumericCal
//
//  Created by YangWenli on 2019/10/10.
//  Copyright © 2019 YangWenli. All rights reserved.
//

#include "Matrix.hpp"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

vector<vector<double>> multiply(const vector<vector<double>>& v1, const vector<vector<double>>& v2){
    vector<vector<double>> v(v1.size(), vector<double>(v2[0].size(), 0));
    for(int i = 0;i < v1.size();i++){
        for(int j = 0;j < v2[0].size();j++){
            for(int k = 0;k < v2.size();k++){
                v[i][j] += v1[i][k] * v2[k][j];
            }
        }
    }
    return v;
}

Matrix::Matrix(vector<vector<double>> _data){
    data = _data;
    height = _data.size();
    unsigned long _width = _data[0].size();
    for(int i = 0;i < height;i++){
        if(_data[i].size() != width){
            
        }
    }
    width = _width;
}

vector<double> Matrix::operator[](int i) const{
    return data[i];
}

Matrix Matrix::operator+(const Matrix& m) const{
    if(height != m.height || width != m.width){
        throw "Ivalid Dimention!";
    }
    vector<vector<double>> d2 = data;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            d2[i][j] += m.data[i][j];
        }
    }
    
    return Matrix(d2);
}

Matrix Matrix::operator-(const Matrix& m) const {
    if(height != m.height || width != m.width){
        throw "Ivalid Dimention!";
    }
    vector<vector<double>> d2 = data;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            d2[i][j] -= m.data[i][j];
        }
    }
    
    return Matrix(d2);
}

Matrix Matrix::operator*(const Matrix& m) const{
    if(width != m.height){
        throw "Ivalid Dimention!";
    }
    vector<vector<double>> d2(height, vector<double>(m.width));
    
    return Matrix(d2);
}

Matrix Matrix::operator*(const vector<double>& v) const{
    vector<vector<double>> v_(v.size(), vector<double>(1));
    for(int i = 0;i < v.size();i++){
        v_[i][0] = v[i];
    }
    vector<vector<double>> vNew = multiply(data, v_);
    return Matrix(vNew);
}

Matrix Matrix::operator*(int x) const{
    vector<vector<double>> d2 = data;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            d2[i][j] = d2[i][j] * x;
        }
    }
    return Matrix(d2);
}

Matrix Matrix::transpose() const{
    vector<vector<double>> d2 = vector<vector<double>>(width, vector<double>(height));
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            d2[j][i] = data[i][j];
        }
    }
    return Matrix(d2);
}

void Matrix::show() const{
    cout << "[";
    for(int i = 0;i < height;i++){
        if(i != 0) cout << " ";
        cout << "[";
        for(int j = 0;j < width;j++){
            cout << data[i][j];
            if(j == width - 1) continue;
            cout << ",";
        }
        cout << "]";
        if(i == height - 1) continue;
        cout << "," << endl;
    }
    cout << "]" << endl;
}
