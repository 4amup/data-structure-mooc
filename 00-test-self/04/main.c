#include <stdio.h>
#define SIZE 20

void getResult(char source[SIZE], char result[SIZE], int *source_length, int *result_length);
int convertNumber(char c);
char convertChar(int n);
int compare(char source[SIZE], char result[SIZE], int source_length, int result_length);
int main(int argc, char const *argv[])
{
    char source[SIZE] = "";
    char result[SIZE] = "";
    int source_length = 0;
    int result_length = 0;

    // 字符串录入
    scanf("%s", source);

    getResult(source, result, &source_length, &result_length);

    // 结果
    int message = compare(source, result, source_length, result_length);

    if (message==1)
    {
        printf("Yes");
    } else {
        printf("No");
    }

    printf("\n");

    printf("%s", result);

    return 0;
}

void getResult(char source[SIZE], char result[SIZE], int *source_length, int *result_length)
{
    // 存放数字的数组
    int source_number[SIZE];
    int result_number[SIZE];

    // 遍历源字符串
    for (int i = 0; source[i] != '\0'; i++)
    {
        source_number[i] = convertNumber(source[i]);
        (*source_length)++;
    }

    // 倒置计算
    int extra = 0;
    for (int i = (*source_length) - 1; i >= 0; i--)
    {
        // double一下
        int result_item = source_number[i] * 2;

        // 进位计算
        if (extra == 1)
        {
            result_item += 1;
            extra = 0;
        }

        // 数字
        if (result_item > 9)
        {
            result_item = result_item - 10;
            extra = 1;
        }
        else
        {
            result_item = result_item;
        }

        // 放入结果数字数组
        result_number[*result_length] = result_item;
        (*result_length)++;
    }

    // 循环完毕，如果还有extra，说明进位未完成
    if (extra == 1)
    {
        result_number[*result_length] = extra;
        (*result_length)++;
    }

    // 将结果数字数组转换成字符数组输出-倒置
    int index = *result_length;
    for (int i = 0; i < *result_length; i++)
    {
        index--;
        result[i] = convertChar(result_number[index]);
    }
    result[*result_length] = '\0';
}

int convertNumber(char c)
{
    char number_char[10] = "0123456789";

    for (int i = 0; number_char[i] != '\0'; i++)
    {
        if (c == number_char[i])
        {
            return i;
            break;
        }
    }
}

char convertChar(int n)
{
    char number_char[10] = "0123456789";
    return number_char[n];
}

int compare(char source[SIZE], char result[SIZE], int source_length, int result_length)
{
    if (source_length != result_length)
    {
        return 0;
    }

    int count = 0;
    // 去source里面找，找到就标记为-1
    for (int i = 0; i < source_length; i++)
    {
        char result_c = result[i];
        for (int i = 0; i < source_length; i++)
        {
            if (source[i] == 'X')
            {
                continue;
            }

            if (result_c == source[i])
            {
                count++;
                source[i] = 'X';
                break;
            }
        }
    }

    if (source_length == count)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}