// ָ��һά�����ָ��
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    int* ptr = array;
    int(*arrayptr)[5] = &array;

    // ptr��arrayptr����ָ������
    printf("ptr��ռ�ֽ���: %zu\tarrayptr��ռ�ֽ���: %zu\n", sizeof(ptr), sizeof(arrayptr));
    cout << ptr
         << '\n'
         << *ptr
         << '\n';
    cout << arrayptr
        << '\n'
        << *arrayptr
        << '\n';
    // *ptr��int���� *arrayptr��int [5]����
    printf("*ptr��ռ�ֽ���: %zu\t*arrayptr��ռ�ֽ���: %zu\n", sizeof(*ptr), sizeof(*arrayptr));

    // ʹ��ָ��һά�����ָ���������Ԫ��
    int sum = 0;
    int product = 1;
    for (int i = 0; i < 5; i++) {
        sum += (*arrayptr)[i];
        product *= arrayptr[0][i];
    }
    printf("һά����arrayԪ�صĺ���: %d\t�˻���: %d\n", sum, product);

    int matrix[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    // ָ��һά�����ָ��ָ���ά�����Ԫ��
    arrayptr = matrix;      // �൱��arrayptr = &matrix[0]
    arrayptr[0][0]++;       // �൱��matrix[0][0]++
    printf("matrix[0][0]: %d\n", matrix[0][0]);

    (*(arrayptr + 1))[0]++; // �൱��matrix[1][0]++
    printf("matrix[1][0]: %d\n", matrix[1][0]);

    arrayptr[2][0]++;       // �൱��matrix[2][0]++
    printf("matrix[2][0]: %d\n", matrix[2][0]);

    return 0;
}