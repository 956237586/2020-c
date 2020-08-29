#include <stdio.h>
// http://blog.hylstudio.cn/archives/690
// 在1的基础上，根据输入的坐标(x,y)打印图形
// 超出范围提示输入错误
// 例如输入2,3
// 则打印
// |  1 2 3|
// |1      |
// |2     x|
// |3      |
int main(int argc, char const *argv[]) {
  int row = 1;
  int column = 1;
  int i = 0;
  int j = 0;
  int boardColumns = 3;
  int boardRows = 3;
  int board[][3] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
  };
  int chess = 0;
  char chessChar = ' ';
  printf("please input position:");
  scanf("%d,%d", &row, &column);
  board[row - 1][column - 1] = -1;
  if (row < 1 || column < 1 || row > boardRows || column > boardColumns) {
    printf("input position error");
    return -1;
  }
  // print chessboard head
  printf("|  1 2 3|\n");
  for (i = 0; i < boardRows; i++) {
    printf("|");
    printf("%d", i + 1);
    for (j = 0; j < boardColumns; j++) {
      chess = board[i][j];
      if (chess == 0) {
        chessChar = ' ';
      } else if (chess == 1) {
        chessChar = 'o';
      } else if (chess == -1) {
        chessChar = 'x';
      }
      printf(" %c", chessChar);
    }
    printf("|\n");
  }
  printf("\n");

  return 0;
}