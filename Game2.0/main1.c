
#include<graphics.h>
#include<fstream.h>
#include<iostream>
#include<math.h>
#include<conio.h>


//using namespace std;

ifstream file;
ofstream filewrite;

typedef struct Coord{

    int x,y;}Coord;

void read();

int main (){
int i,j;
initwindow(800,500,"Tamas_GAME");
read();



getch();
return 0;
}

void read(){

    int n;
    //FILE* file = fopen("maze.txt","rt");
    file.open("map.txt");
    //FILE* filewrite = fopen("mapellenorzo.txt","w");

    filewrite.open("mapki.txt");
    if(!filewrite){
        printf("sikertelen megnyitas");
    }
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

        for(int j=0; j<n; i++){

            file>>helyzet[i][j];
            //fscanf(file,"%i",&helyzet[i][j]);

        }

    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; i++){

        //filewrite<<helyzet[i][j];
        filewrite<<i*j;

        }
    }

file.close();
filewrite.close();

}








