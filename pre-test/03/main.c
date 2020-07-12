#include <stdio.h>
#define MAXSIZE 100

void moveArray(int *array, int length);
int main(int argc, char const *argv[])
{
    int N;
    int M;
    int array[MAXSIZE];

    // 参数赋值
    scanf("%d %d", &N, &M);

    // 数组赋值
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }

    // 循环往右移动，超过数组长度只需要移动超过的次数
    int count = M % N;

    // N=6,M=2, 数组是123456
    for (int i = 0; i < count; i++)
    {
        moveArray(array, N);
    }

    // 输出数组
    for (int i = 0; i < N; i++)
    {
        printf("%d", array[i]);
        if (i < (N - 1))
        {
            printf(" ");
        }
    }
    return 0;
}

void moveArray(int *array, int length)
{
    int max_idx = length - 1;
    int max = array[max_idx];
    for (int i = max_idx - 1; i >= 0; i--)
    {
        array[i + 1] = array[i];
    }
    array[0] = max;
};
