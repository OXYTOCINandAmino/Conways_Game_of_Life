#include <stdio.h>

void emptyBoard(char board[50][50]){
    int i,j;
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            board[i][j]= ' ';
        }
    }
}
void printBoard(char board[50][50]){
    int i,j;
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }    
}
void set_initial_status(char board[50][50]){
    int r, c;
    char status;
    
    printf("enter the initial coordinates \n");
    printf("enter status : \n");
    fflush(stdin);  
    scanf("%c",&status);

    
    while(status != 'N'){
    printf("enter the row numebr:  \n");
    fflush(stdin);  
    scanf("%d",&r);
    
    printf("enter the column number: \n");
    fflush(stdin);  
    scanf("%d",&c);
    
    board[r][c]='*';
    
    printf("enter status : \n");
    fflush(stdin);  
    scanf("%c", &status);
          
    }

}
char live_or_die(char board[50][50],int r,int c ){
   int sum;
   if (board[r][c]=='*'){sum = -1;}
   if (board[r][c]==' '){sum = 0;}
   int i,j,tempt;    
    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
              if (board[r+i][c+j]=='*'){tempt = 1;}
              if (board[r+i][c+j]==' '){tempt = 0;}
        sum = sum + tempt;}
            
        }

    if (board[r][c]=='*'){
        if(sum<2){ return ' ';}
        if(sum==2 || sum==3){return '*';}
        if(sum>3){return ' ';}
    }
    if (board[r][c]==' '){
        if(sum==3){return '*';}
        else{return ' ';}
        }
}
void evolve(char board1[50][50],char board2[50][50]){
    int i,j;
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            board2[i][j]= live_or_die(board1,i,j) ;
        }
    }
}            
void copy_board(char board1[50][50],char board2[50][50]){
    int i,j;
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            board1[i][j]=board2[i][j];
        }
    }
}


//basic type

void spaceship(char board[50][50],int r,int c){
    board[2+r][2+c]='*';
    board[2+r][5+c]='*';
    board[3+r][6+c]='*';
    board[4+r][2+c]='*';
    board[4+r][6+c]='*';
    board[5+r][3+c]='*';
    board[5+r][4+c]='*';
    board[5+r][5+c]='*';
    board[5+r][6+c]='*';
}
void glider(char board[50][50],int r,int c){
    board[2+r][4+c]='*';
    board[3+r][2+c]='*';
    board[3+r][4+c]='*';
    board[4+r][3+c]='*';
    board[4+r][4+c]='*';
}
int main(void)
{
    char board_tempt[50][50];
    char board_new[50][50];


    emptyBoard(board_tempt);
    //set_initial_status(board_tempt);
    
    glider(board_tempt,25,25);            

    int i;
    for(i=0;i<100;i++){
    printBoard(board_tempt);
    evolve(board_tempt,board_new);
    copy_board(board_tempt,board_new);
    printf("__________________________________________________");
    printf("This is run %d",i);
    }
   
    

    
    
    
    
}
