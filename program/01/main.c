#include <stdio.h>

int main(int argc, char const *argv[])
{
    //数组长度，并录入个数
    int n;
    scanf("%d", &n);

    //定义固定长度数组，并录入数据
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    //初始化中间变量和最大子列和为0
    int this_sum, max_sum;
    this_sum = max_sum = 0;

    //算法核心-在线算法
    for (int i = 0; i < n; i++)
    {
        this_sum += array[i];

        if (this_sum > max_sum)
        {
            max_sum = this_sum;
        }else if (this_sum < 0)
        {
            //小于零的和对最大子列和没有帮助，就丢弃
            this_sum = 0;
        }
    }
    
    //输出最大子列和

    printf("%d", max_sum);
    return 0;
}
