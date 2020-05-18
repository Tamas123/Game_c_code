
#include<graphics.h>
#include<fstream>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<winuser.h>


using namespace std;

ifstream file;


typedef struct Coord{

    int x,y;}Coord;

void read();


int main (){
    initwindow(800,500,"Tamas_GAME");
    read();

    int elozohelyzet=0;
    int elozox = 0;
    int i=10;
    int x=0;
    int y=0;

    while(true){

        int iranyertekx = mousex();
        //int iranyerteky = mousey();


        //int elozoy = 0;
        readimagefile("fekete.jpg",elozox,400,elozox+100,500);
        readimagefile("en.jpg",iranyertekx,400,iranyertekx+100,500);
        //delay(1);
        //cout<<getmouseclick(WM_LBUTTONDOWN,10,10);
        getmouseclick(WM_LBUTTONDOWN,x,y);

        cout<<x;
        cout<<y;

        if(x>0&&y>0){
            for(int i=0   ; i<500 ; i++ ){
            setcolor(1);
            line(elozox, 385-i, elozox, 400-i);
            Sleep(1);
            setcolor(0);
            line(elozox, 385-i, elozox, 400-i);


            }
        }



        elozox = iranyertekx;
//cout<<mousex()<<'\t';
cout<<'\n';
//cout<<mousey();


//system("CLS");

//moveto(20,10);
    }

    getch();
return 0;
}

void read(){

    int n;

    file.open("map.txt");
    //FILE* filewrite = fopen("mapellenorzo.txt","w");


    if(!file){
        printf("Sikertelen map megnyitas");
    }

    //fscanf(file,"%i",&n);
    file>>n;
    //printf("%i",n);


    int** helyzet = (int**)calloc(n,sizeof(int*));

    for(int i=0; i< n; i++){

        helyzet[i] = (int*)calloc(n,sizeof(int));

    }

    if(!helyzet){
        printf("sikertelen lefoglalas");
    }

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            file>>helyzet[i][j];
        }
    }


file.close();

for(int i=0; i<n; i++){

    for(int j=0; j<n; j++){

        if(helyzet[i][j]==1){
            readimagefile("ko.jpg",i*30+50,j*30+50,(i+1)*30-3,(j+1)*30-3);
        }

}


    }
}





