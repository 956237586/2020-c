#include <stdio.h>
#include <windows.h>
// 5.(meduim)在4的基础上，增加规则判定
// 先手x后，后手必须是o，否则报错
// 当横竖斜满足都是x或都是o后，提示x方或o方获胜，程序退出
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
  char lastChessChar = ' ';
  int winFlag = 0;
  int firstInput = 1;
  while (1) {
    printf("please input position:");
    scanf("%d,%d", &row, &column);
    getchar();//处理掉回车
    if (row < 1 || column < 1 || row > boardRows || column > boardColumns) {
      printf("input position error\n");
      continue;
    }
    if (board[row - 1][column - 1] != 0) {
      printf("input position erro, already has chess\n");
      continue;
    }
    printf("please input chess:");
    scanf("%c", &chessChar);
    getchar();//处理掉回车
    if ((firstInput == 1 && chessChar == 'x') ||
        (chessChar == 'x' && lastChessChar == 'o')) {
      board[row - 1][column - 1] = -1;
    } else if ((firstInput == 1 && chessChar == 'o') ||
               (chessChar == 'o' && lastChessChar == 'x')) {
      board[row - 1][column - 1] = 1;
    } else {
      printf("input chess error\n");
      continue;
    }
    if (firstInput == 1) {
      firstInput = 0;
    }
    lastChessChar = chessChar;
    system("cls");  // vscode下debug有问题,需要debug的话暂时去掉这行
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

    //判断规则是否有胜利的
    //按行
    for (i = 0; i < boardRows; i++) {
      winFlag = board[i][0] + board[i][1] + board[i][2];
      if (winFlag == 3) {
        printf("o win");
        return 0;
      } else if (winFlag == -3) {
        printf("x win");
        return 0;
      }
    }
    //按列
    for (j = 0; j < boardColumns; j++) {
      winFlag = board[0][j] + board[1][j] + board[2][j];
      if (winFlag == 3) {
        printf("o win");
        return 0;
      } else if (winFlag == -3) {
        printf("x win");
        return 0;
      }
    }

    //斜着的
    winFlag = board[0][0] + board[1][1] + board[2][2];
    if (winFlag == 3) {
      printf("o win");
      return 0;
    } else if (winFlag == -3) {
      printf("x win");
      return 0;
    }
    winFlag = board[0][0] + board[1][1] + board[2][2];
    if (winFlag == 3) {
      printf("o win");
      return 0;
    } else if (winFlag == -3) {
      printf("x win");
      return 0;
    }
  }
  return 0;
}