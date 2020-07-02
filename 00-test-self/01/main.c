#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 用户输入参数，个数、符号
    int N;
    char c;

    // 参数录入
    scanf("%d %c", &N, &c);

    // 计算变量，正整数，1 <= n <= 1000
    int count = 0;
    int sum = 0;
    int fore_sum = 0;
    int max = 0;
    int left = 0;
    int item = 0;
    int next = 0;

    // 求和，逐项去掉，1、6、10
    for (int i = 1; i <= N; i++)
    {
        if (i == 1)
        {
            item = 1;
            next = 6;
        }
        else
        {
            item = 2 * (2 * i - 1);
            next = 2 * (2 * (i + 1) - 1);
        }

        // 组数
        count = i;

        // 求和
        sum += item;
        fore_sum = sum;
        fore_sum += next;

        // 停止条件：1+6+10+14=31>19，则剩余字符个数为14-(31-19)，组数为4-1=3，max重置为上一个10/2=5
        if (fore_sum > N)
        {
            count;
            if (item > 1)
            {
                max = item / 2;
            }
            else
            {
                max = 1;
            }
            left = N - sum;
            break;
        }
    }

    // 根据计算结果打印沙漏，上半部分
    for (int i = 1; i <= count; i++)
    {
        // 确定符号开始结束索引
        int index_satrt = i - 1;
        int index_end = max - i;

        for (int j = 0; j < max; j++)
        {
            if (j >= index_satrt && j <= index_end)
            {
                printf("%c", c);
            }
            else if (j < index_satrt)
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    // 根据计算结果打印沙漏，下半部分：注意1的区别，不必再打
    for (int i = 1; i < count; i++)
    {
        // 确定符号开始结束索引
        int index_satrt = max - count - i;
        int index_end = max - count + i;

        for (int j = 0; j < max; j++)
        {
            if (j >= index_satrt && j <= index_end)
            {
                printf("%c", c);
            }
            else if (j < index_satrt)
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    // 打印剩余字符数
    printf("%d", left);

    return 0;
}
