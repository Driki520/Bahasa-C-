#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x,y,fruitx,fruity,skor;
int tailx[100],taily[100];
int nTail;
enum eDirecton{
	STOP=0, LEFT,RIGHT,UP,DOWN
};
eDirecton dir;
void Setup(){
	GameOver=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx=rand()%width;
	fruity=rand()%height;
	skor=0;
}
void Draw(){
	int i,j,k;
	system("cls");
	for(i=0;i<width+2;i++)
		cout<<"#";
	cout<<endl;
	
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			if(j==0){
				cout<<"#";
			}
			if(i==y && j==x){
				cout<<"O";
			}else if(i==fruity && j==fruitx){
				cout<<"F";
			}else{
				bool print=false;
				for(k=0;k<nTail;k++){
					if(tailx[k]==j && taily[k]==i){
						cout<<"o";
						print=true;
					}
				}
				if(!print){
					cout<<" ";
				}
			}
			if(j==width-1){
				cout<<"#";
			}
		}
		cout<<endl;
	}
	for(i=0;i<width+2;i++){
		cout<<"#";
	}
	cout<<endl;
	cout<<"Score: "<<skor<<endl;
}
void Input(){
	if(_kbhit()){
		switch(_getch()){
			case'a':
				dir=LEFT;
				break;
			case'd':
				dir=RIGHT;
				break;
			case'w':
				dir=UP;
				break;
			case's':
				dir=DOWN;
				break;
			case'x':
				GameOver=true;
				break;
		}
	}
}
void Logic(){
	
	int prevX=tailx[0];
	int prevY=taily[0];
	int prev2X,prev2Y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<nTail;i++){
		prev2X=tailx[i];
		prev2Y=taily[i];
		tailx[i]=prevX;
		taily[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(dir){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
	if(x>=width){
		x=0;
	}else if(x<0){
		x=width-1;
	}
	if(y>=height){
		y=0;
	}else if(y<0){
		y=height-1;
	}
	
	for(int i=0;i<nTail;i++){
		if(tailx[i]==x && taily[i]==y){
			GameOver=true;
		}
	}
	if(x==fruitx && y==fruity){
		skor+=10;
		fruitx=rand()%width;
		fruity=rand()%height;
		nTail++;
	}
}

int main(){
	Setup();
	while(!GameOver){
		Draw();
		Input();
		Logic();
		Sleep(10);
	}
	return 0;
}
