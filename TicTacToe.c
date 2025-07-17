#include <stdio.h>

char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printBoard()
{
    system("cls");
    printf("\n~~~~~~~~~TIC-TAC-TOE~~~~~~~~~\n\n");
    printf("         |         |         \n");
    printf("    %c    |    %c    |     %c   \n", board[0], board[1], board[2]);
    printf("_________|_________|_________\n");
    printf("         |         |         \n");
    printf("    %c    |    %c    |    %c    \n", board[3], board[4], board[5]);
    printf("_________|_________|_________\n");
    printf("         |         |         \n");
    printf("    %c    |    %c    |    %c    \n", board[6], board[7], board[8]);
    printf("         |         |         \n");
    printf("\n\n");
}

int checkWin(){
    int count = 0;
    if(board[0]==board[1] && board[1]==board[21]){
        return 1;
    }
    if(board[0]==board[3] && board[3]==board[6]){
        return 1;
    }
    
    if(board[0]==board[4]&& board[4]==board[8]){
        return 1;
    }
    if(board[3]==board[4] && board[4]==board[5]){
        return 1;
    }
    if(board[6]==board[7] && board[7]==board[8]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    if(board[2]==board[4] && board[4]==board[6]){
        return 1;
    }

    for(int i=0; i<=9; i++){
        if(board[i]=='X' || board[i]=='O'){
            count++;
        }
    }
    if(count == 9){
        return 0;
    }

    return -1;
}

int main()
{
    int player = 1, input, status = -1;
    printBoard();

    while (status == -1)
    {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        printf("\nPlease enter Number for player %d: ",player);
        scanf("%d", &input);
        if (input < 1 || input > 9)
        {
            printf("INVALID INPUT...");
        }
        board[input-1] = mark;

        printBoard();

        int result = checkWin();

        if(result == 1){
            printf("\nPlayer %d is a winner.\n",player);
            break;
        }else if(result == 0){
            printf("\nDraw\n");
        }

        player++;
    }

    return 0;
}