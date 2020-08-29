// 5.在2的基础上，自定义输入字符c,个数n，行数m
// 打印奇数行n个c，偶数行n-1个c

#include <stdio.h>
// http://blog.hylstudio.cn/archives/686
int main() {
  char input = '*';
  int charPerLine = 6;
  int lineNum = 1;
  int lines = 4;
  // input character
  scanf("%c", &input);
  // input charPerLine
  scanf("%d", &charPerLine);
  // input lines
  scanf("%d", &lines);
  // check lineNum range
  if (charPerLine < 1) {
    printf("input n error, n should greater than equal 1!\n");
    return -1;
  }
  // check lines range
  if (lines <= 0) {
    printf("input m error, n should greater than equal 1!\n");
    return -1;
  }
  for (lineNum = 1; lineNum <= lines; lineNum++) {
    printf("|");
    if (lineNum % 2 == 1) {
      for (int i = 0; i < charPerLine - 1; i++) {
        printf("%c ", input);
      }
      printf("%c", input);
    } else {
      printf(" ", input);
      for (int i = 0; i < charPerLine - 1; i++) {
        printf("%c ", input);
      }
    }
    printf("|\n");
  }

  return 0;
}