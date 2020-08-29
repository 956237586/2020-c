#include <stdio.h>
#include <windows.h>
// 4.先打印空棋盘，再重复过程3，每次清屏
// 超出范围提示输入错误
// 输入的不是x或o，提示错误
// 输入的坐标已经有内容了，提示错误
// 提示：清屏操作如下
// #include<windows.h>
// system("cls");
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
  while (1) {
    printf("please input position:");
    scanf("%d,%d", &row, &column);
    if (row < 1 || column < 1 || row > boardRows || column > boardColumns) {
      printf("input position error\n");
      continue;
    }
    if (board[row - 1][column - 1] != 0) {
      printf("input position erro, already has chess\n");
      continue;
    }
    printf("please input chess:");
    scanf("\n%c", &chessChar);  //这里多写一个\n是为了处理输入完位置之后的回车键

    if (chessChar == 'x') {
      board[row - 1][column - 1] = -1;
    } else if (chessChar == 'o') {
      board[row - 1][column - 1] = 1;
    } else {
      printf("input chess error\n");
      continue;
    }
    system("cls");//vscode下debug有问题,需要debug的话暂时去掉这行
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
  }
  return 0;
}