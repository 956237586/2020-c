#include <stdio.h>
// http://blog.hylstudio.cn/archives/690
// 3.在2的基础上，输入坐标后再输入x或o，在对应位置打印
// 超出范围提示输入错误
// 输入的不是x或o,提示错误
int main() {
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
  if (row < 1 || column < 1 || row > boardRows || column > boardColumns) {
    printf("input position error");
    return -1;
  }

  printf("please input chess:");
  scanf("\n%c", &chessChar);  //这里多写一个\n是为了处理输入完位置之后的回车键
  if (chessChar == 'x') {
    board[row - 1][column - 1] = -1;
  } else if (chessChar == 'o') {
    board[row - 1][column - 1] = 1;
  } else {
    printf("input chess error");
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