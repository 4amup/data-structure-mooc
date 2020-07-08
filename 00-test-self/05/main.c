#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 54

// 参数：牌的顺序号和牌的总数
// 功能：按照给定的顺序洗牌
void shuffleCards(int shuffle[SIZE], char *card[SIZE], int length);

int main(int argc, char const *argv[])
{
    int repeat;
    int shuffle[SIZE];
    char *card[SIZE] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                        "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                        "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                        "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                        "J1", "J2"};

    // 录入重复次数
    scanf("%d", &repeat);

    // 录入初始顺序
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d ", &shuffle[i]);
    }

    // 洗牌N次
    for (int i = 0; i < repeat; i++)
    {
        shuffleCards(shuffle, card, SIZE);
    }

    // 打印洗牌多次后的结果
    for (int i = 0; i < SIZE; i++)
    {
        printf("%s", card[i]);
        if (i != (SIZE - 1))
        {
            printf(" ");
        }
    }
    return 0;
}

void shuffleCards(int shuffle[SIZE], char *card[SIZE], int length)
{
    char *copy[SIZE];

    // 54张牌里面一张张往出拿，逐渐减少随机数取数范围
    for (int i = 0; i < length; i++)
    {
        int index_to = shuffle[i] - 1;
        copy[index_to] = card[i];
    }

    // 将copy数组值拷贝给原数组
    for (int i = 0; i < length; i++)
    {
        card[i] = copy[i];
    }
}