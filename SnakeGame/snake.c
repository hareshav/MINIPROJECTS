#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
void display();
void update();
void gendratef();
int checkinarray(int x,int len,int *array);
int checkpoint();
int bordercheck();
int pointupdate();
char board[20][21]={"                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    ","                    "};
int coodx[25]={10,11,12,13,14};
int coody[25]={10,10,10,10,10};
int x=14,y=10;
int p=0;
int fcood[2]={0};
int main(){
    char input;
    board[10][10]='O';
    board[10][11]='O';
    board[10][12]='O';
    board[10][13]='O';
    board[10][14]='O';
    gendratef();
    display();
    while(1){
        input=getch();
        switch(input){
        case 'w':
            x--;
            break;
        case 's':
            x++;
            break;
        case 'a':
            y--;
            break;
        case 'd':
            y++;
            break;
        }
        if(checkpoint()){
            pointupdate();
        }
        else{
            board[coody[0]][coodx[0]]=' ';
            update();
            board[coody[4+p]][coodx[4+p]]='O';
        }
        system("cls");
        display();
        if(bordercheck()){
            printf("\nGame over");
            break;
        }
    }
}
void update(){
    for(int i=0;i<5+p;i++){
        coodx[i]=coodx[i+1];
        coody[i]=coody[i+1];
    }
    coodx[4+p]=x;
    coody[4+p]=y;
}
void display(){
    printf("\tPoints:%d\n",p);
    printf("---------------------\n");
    for(int i=0;i<20;i++){
        printf("|");
        for(int j=0;j<20;j++){
            printf("%c",board[j][i]);
        }
        printf("|\n");
    }
    printf("---------------------\n");
   // for(int i=0;i<5+p;i++){
     //   printf("%d %d\n",coodx[i],coody[i]);
    //}
}
void gendratef(){
    int a=0;
    int b=0;
    do{
        srand(time(0));
        a=rand()%18;
        b=rand()%18;
        fcood[0]=b;
        fcood[1]=a;
    }while(checkinarray(a,5+p,coody)&&checkinarray(b,5+p,coodx));
    board[fcood[0]][fcood[1]]=1;
}
int checkinarray(int a,int len,int *array){
    for(int i=0;i<len;i++){
        if(a==array[i]){
            return 1;
        }}
    return 0;

}
int checkpoint(){
    if(x==fcood[1] && y==fcood[0]){
        gendratef();
        board[y][x]='O';
        return 1;
    }
    return 0;

}
int bordercheck(){
    if(x<0||x>19||y<0||y>18){
        return 1;
    }
    for (int i=1;i<4+p;i++){
        if(x==coodx[i]&&y==coody[i])return 1;
    }
    return 0;
}
int pointupdate(){
    p++;
    coodx[4+p]=x;
    coody[4+p]=y;
}

