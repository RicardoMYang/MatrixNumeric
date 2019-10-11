//
//  main.cpp
//  MatrixNumericCal
//
//  Created by YangWenli on 2019/10/10.
//  Copyright © 2019 YangWenli. All rights reserved.
//

#include <iostream>
#include <vector>

#include "Matrix.hpp"
using namespace std;

int main() {
    // insert code here...
    int height1;int width1;
    cout << "输入第1个矩阵的高度：" << endl;
    cin >> height1;
    cout << "输入第1个矩阵的宽度：" << endl;
    cin >> width1;
    vector<vector<double>> data1(height1, vector<double>(width1));
    for(int i = 0;i < height1;i++){
        for(int j = 0;j < width1;j++){
            cout << "输入矩阵1位置(" << i << "," << j << ")处的元素" << endl;
            cin >> data1[i][j];
        }
    }
    Matrix m1(data1);
    cout << "矩阵1:" << endl;
    m1.show();
    
    int height2;int width2;
    cout << "输入第2个矩阵的高度：" << endl;
    cin >> height2;
    cout << "输入第2个矩阵的宽度：" << endl;
    cin >> width2;
    vector<vector<double>> data2(height2, vector<double>(width2));
    for(int i = 0;i < height2;i++){
        for(int j = 0;j < width2;j++){
            cout << "输入矩阵1位置(" << i << "," << j << ")处的元素" << endl;
            cin >> data2[i][j];
        }
    }
    Matrix m2(data2);
    
    Matrix m3 = m1 + m2;
    cout << "矩阵之和：" << endl;
    m3.show();
    
    Matrix m4 = m1 * m2;
    cout << "矩阵之积：" << endl;
    m4.show();
    
    cout << "输入向量的长度：" << endl;
    int length;
    cin >> length;
    vector<double> v(length);
    for(int i = 0;i < length;i++){
        cout << "输入向量第" << i << "个元素：" << endl;
        cin >> v[i];
    }
    (m1 * v).show();
    
    return 0;
}
