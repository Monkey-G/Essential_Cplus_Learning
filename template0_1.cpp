// 指向一维数组的指针
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    int* ptr = array;
    int(*arrayptr)[5] = &array;

    // ptr与arrayptr都是指针类型
    printf("ptr所占字节数: %zu\tarrayptr所占字节数: %zu\n", sizeof(ptr), sizeof(arrayptr));
    cout << ptr
         << '\n'
         << *ptr
         << '\n';
    cout << arrayptr
        << '\n'
        << *arrayptr
        << '\n';
    // *ptr是int类型 *arrayptr是int [5]类型
    printf("*ptr所占字节数: %zu\t*arrayptr所占字节数: %zu\n", sizeof(*ptr), sizeof(*arrayptr));

    // 使用指向一维数组的指针访问数组元素
    int sum = 0;
    int product = 1;
    for (int i = 0; i < 5; i++) {
        sum += (*arrayptr)[i];
        product *= arrayptr[0][i];
    }
    printf("一维数组array元素的和是: %d\t乘积是: %d\n", sum, product);

    int matrix[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    // 指向一维数组的指针指向二维数组的元素
    arrayptr = matrix;      // 相当于arrayptr = &matrix[0]
    arrayptr[0][0]++;       // 相当于matrix[0][0]++
    printf("matrix[0][0]: %d\n", matrix[0][0]);

    (*(arrayptr + 1))[0]++; // 相当于matrix[1][0]++
    printf("matrix[1][0]: %d\n", matrix[1][0]);

    arrayptr[2][0]++;       // 相当于matrix[2][0]++
    printf("matrix[2][0]: %d\n", matrix[2][0]);

    return 0;
}