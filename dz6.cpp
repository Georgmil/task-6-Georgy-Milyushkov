#include <iostream>
#include <stdio.h>
#include <graphics.h>

void glavder(float x1,float y1,float x2,float y2,float x3,float y3);
void podder(int n,float x1,float y1,float x2,float y2,float x3,float y3);

int main(){

    initwindow(1200,650); // razmer ekrana
    setbkcolor(WHITE);    // tsvet fona
    cleardevice(); // chtobi fon narisovalsja

    setlinestyle(0,0,2); // tolshina linij
    setcolor(BLACK);//tsvet linij
    glavder(100,550,1000,550,550,50); //iznacalnij treuglnik

    getch();
    closegraph();

    return 0;
}

//risuem glavone derevo
void glavder(float x1,float y1,float x2,float y2,float x3,float y3){
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x2,y2,x3,y3);

    // delim poplam, i nahodim seredinu, chtobi potom risovat perevernutij treuglonik tuda
    float ax,ay,bx,by,cx,cy;
    ax=(x1+x2)/2;
    ay=(y1+y2)/2;
    bx=(x1+x3)/2;
    by=(y1+y3)/2;
    cx=(x2+x3)/2;
    cy=(y2+y3)/2;


    return podder(1,ax,ay,bx,by,cx,cy); //zapuskaem rekusivnuju funkciju

}
void podder(int kol,float x1,float y1,float x2,float y2,float x3,float y3){

// risuem liniji meshzdu versjin
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x2,y2,x3,y3);

// skolko raz budem povorat i risovat
    if (kol<6){
            // matematicheskij rachet, versjin s treh storon
        podder(
            kol+1,
            (x1 + x2) / 2 + (x1 - x3) / 2,
            (y1 + y2) / 2 + (y1 - y3) / 2,
            (x1 + x2) / 2 + (x2 - x3) / 2,
            (y1 + y2) / 2 + (y2 - y3) / 2,
            (x1 + x2) / 2,
            (y1 + y2) / 2);


        podder(
            kol+1,
            (x3 + x2) / 2 + (x3 - x1) / 2,
            (y3 + y2) / 2 + (y3 - y1) / 2,
            (x3 + x2) / 2 + (x2 - x1) / 2,
            (y3 + y2) / 2 + (y2 - y1) / 2,
            (x3 + x2) / 2,
            (y3 + y2) / 2);

        podder(
            kol+1,
            (x1 + x3) / 2 + (x1 - x2) / 2,
            (y1 + y3) / 2 + (y1 - y2) / 2,
            (x1 + x3) / 2 + (x3 - x2) / 2,
            (y1 + y3) / 2 + (y3 - y2) / 2,
            (x1 + x3) / 2,
            (y1 + y3) / 2);

    }
}
