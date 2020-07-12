#include <stdio.h>

int IsPrime(int i);
int main(int argc, char const *argv[])
{
    int N = 0;
    int count_prime = 0;
    int count_double = 0;

    scanf("%d", &N);

    int prev = 0;
    int curr = 0;

    // 逐个确认是否是素数，将素数放入数组
    for (int i = 1; i <= N; i++)
    {
        if (IsPrime(i) == 1)
        {
            prev = curr;
            curr = i;
            count_prime++;

            // 至少两个素数才能计算差值
            if (count_prime >= 2)
            {
                int dif = curr - prev;

                if (dif == 2)
                {
                    count_double++;
                }
            }
        }
    }

    printf("%d", count_double);
    return 0;
}

int IsPrime(int n)
{
    int result = 1;

    // 1不是素数
    if (n == 1)
    {
        result = 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            result = 0;
            break;
        }
    }

    return result;
}