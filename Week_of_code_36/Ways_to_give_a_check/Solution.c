#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int checkForN(int x,int y,char board[8][8]) {
    if(x>=0&&x<8&&y>=0&&y<8)
        if(board[x][y] == 'N')
            return 1;
    return 0;
}
int checkWithCondition(int a,int b,int x,int y,char board[8][8]) {
    //printf("King = %d,%d Checking for %c (%d,%d) ",a,b,board[x][y],x,y);
    //Right
    for(int i=1;b+i<8;i++) {
        if(board[a][b+i] == 'Q' || board[a][b+i] == 'R')
            return 1;
        else if(board[a][b+i] != '#')
            break;
    }
    //Left
    for(int i=1;b-i>=0;i++) {
        if(board[a][b-i] == 'Q' || board[a][b-i] == 'R')
            return 1;
        else if(board[a][b-i] != '#')
            break;
    }
    //Up
    for(int i=1;a-i>=0;i++) {
        if(board[a-i][b] == 'Q' || board[a-i][b] == 'R')
            return 1;
        else if(board[a-i][b] != '#')
            break;
    }
    //Down
    for(int i=1;a+i<8;i++) {
        if(board[a+i][b] == 'Q' || board[a+i][b] == 'R')
            return 1;
        else if(board[a+i][b] != '#')
            break;
    }
    //left-up
    for(int i=1;a-i>=0&&b-i>=0;i++) {
        //printf("L-U %d,%d\n",a-i,b-i);
        if(board[a-i][b-i] == 'Q' || board[a-i][b-i] == 'B')
            return 1;
        else if(board[a-i][b-i] != '#' && board[a-i][b-i] != 'k')
            break;
    }
    //left-down
    for(int i=1;a+i<8&&b-i>=0;i++) {
        //printf("L-D %d,%d\n",a+i,b-i);
        if(board[a+i][b-i] == 'Q' || board[a+i][b-i] == 'B')
            return 1;
        else if(board[a+i][b-i] != '#')
            break;
    }
    //right-up
    for(int i=1;a-i>=0&&b+i<8;i++) {
        //printf("R-U %d,%d\n",a-i,b+i);
        if(board[a-i][b+i] == 'Q' || board[a-i][b+i] == 'B')
            return 1;
        else if(board[a-i][b+i] != '#')
            break;
    }
    //right-down
    for(int i=1;a+i<8&&b+i<8;i++) {
        //printf("R-D %d,%d\n",a+i,b+i);
        if(board[a+i][b+i] == 'Q' || board[a+i][b+i] == 'B')
            return 1;
        else if(board[a+i][b+i] != '#')
            break;
    }
    if(checkForN(a-1,b-2,board))
        return 1;
    if(checkForN(a-2,b-1,board))
        return 1;
    if(checkForN(a-1,b+2,board))
        return 1;
    if(checkForN(a-2,b+1,board))
        return 1;
    if(checkForN(a+1,b-2,board))
        return 1;
    if(checkForN(a+2,b-1,board))
        return 1;
    if(checkForN(a+1,b+2,board))
        return 1;
    if(checkForN(a+2,b+1,board))
        return 1;
    
    return 0;
    
    
    
}
int waysToGiveACheck(int board_size_rows, int board_size_cols, char board[8][8]) {
    // Complete this function
    int i,j=0,posX,posY;
    for(i=0;i<8;i++) {
        for(j=0;j<8;j++)
            if(board[i][j] =='k')
                break;
        if(j!=8)
            break;
    }
        
    posX= i;
    posY= j;
    j=0;
    //printf("k at %d %d",posX,posY);
    for(i=0;i<8;i++) {
        if(board[1][i]== 'P' && board[0][i] =='#') {
            //printf("Found = %d,%d ",1,i);
            board[1][i] = '#';
            
            board[0][i] = 'R';
            j+= checkWithCondition(posX,posY,0,i,board);
            //printf("Count = %d\n",j);
            board[0][i] = 'N';
            j+= checkWithCondition(posX,posY,0,i,board);
            //printf("Count = %d\n",j);
            board[0][i] = 'B';
            j+= checkWithCondition(posX,posY,0,i,board);
            //printf("Count = %d\n",j);
            board[0][i] = 'Q';
            j+= checkWithCondition(posX,posY,0,i,board);
            //printf("Count = %d\n",j);
            board[0][i] = '#';
            board[1][i] = 'P';
            //j+=checksCount(0,i,board);
        }
    }
    return j;
    //return 0;
}

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        char board[8][8];
        for (int board_i = 0; board_i < 8; board_i++) {
            scanf("%s",board[board_i]);
        }
        int result = waysToGiveACheck(8,8,board);
        printf("%d\n", result);
    }
    return 0;
}
