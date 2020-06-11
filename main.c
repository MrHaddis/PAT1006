#include <stdio.h>
//MrHaddis PAT系列

int main() {
    int number;
    int length = 0;
    //注意必须初始化为0  否则随机Int值
    int index = 0;
    scanf("%d", &number);
    if (number > 1000 || number < 1) {
        return 0;
    } else if (number >= 1 && number < 10) {
        length = 1;
    } else if (number >= 10 && number < 100) {
        length = 2;
    } else {
        length = 3;
    }
    //因为题目规定是三位以内的整数，所以最长3的长度就够用了
    int numbers[length];
    //循环计算
    while (number != 0) {
        // 获取number每一位的值，每循环一次 numbers的位置就多写一次
        //number % 10 就是依次计算各位十位百位等。
        numbers[index++] = number % 10;
        //取余以后要除以十，这样才可以依次取到每位的值。
        //注意个位数的时候 5/10 不足为整数，int就取0了
        number /= 10;
    }
    //倒序遍历，从大到小输出
    for (int i = length - 1; i >= 0; i--) {
        if (i == 0) {
            for (int j = 1; j <= numbers[i]; j++) {
                printf("%d", j);
            }
        }
        if (i == 1) {
            for (int j = 0; j < numbers[i]; ++j) {
                printf("S");
            }
        }
        if (i == 2) {
            for (int j = 0; j < numbers[i]; ++j) {
                printf("B");
            }
        }
    }
    return 0;
}
