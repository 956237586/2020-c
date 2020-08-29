// 3.在2的基础上，自定义输入字符c，打印
// |c c c c c c|
// | c c c c c |
// |c c c c c c|
// | c c c c c |
// 例如，如果输入a，则打印
// |a a a a a a|
// | a a a a a |
// |a a a a a a|
// | a a a a a |
#include <stdio.h>
// http://blog.hylstudio.cn/archives/686
int main(int argc, char const *argv[]) {
  char input = '*';
  scanf("%c", &input);
  printf("|%c %c %c %c %c %c|\n", input, input, input, input, input, input);
  printf("| %c %c %c %c %c |\n", input, input, input, input, input);
  printf("|%c %c %c %c %c %c|\n", input, input, input, input, input, input);
  printf("| %c %c %c %c %c |\n", input, input, input, input, input);

  return 0;
}