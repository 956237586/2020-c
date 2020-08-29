// 4.在3的基础上，自定义输入行号n(n >= 1),
// 如果n是奇数
// 打印|c c c c c c|
// 如果n是偶数
// 打印| c c c c c |
// 如果n是负数
// 提示输入错误
#include <stdio.h>
// http://blog.hylstudio.cn/archives/686
int main(int argc, char const *argv[]) {
  char input = '*';
  int lineNum = 1;
  // input character
  scanf("%c", &input);
  // input lineNum
  scanf("%d", &lineNum);
  // check lineNum range
  if (lineNum < 1) {
    printf("input n error, n should greater than equal 1!\n");
    return -1;
  }
  if (lineNum % 2 == 1) {
    printf("|%c %c %c %c %c %c|\n", input, input, input, input, input, input);
  } else {
    printf("| %c %c %c %c %c |\n", input, input, input, input, input);
  }

  return 0;
}