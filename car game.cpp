#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>

#define SWIDTH 89
#define SHEIGHT 29
#define WWIDTH 70

using namespace std; 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorOrientation;

char racecar[4][4] = { ' ','±','±',' ', 
					'±','±','±','±', 
					' ','±','±',' ',
					'±','±','±','±' }; 
					int carPos = WWIDTH/2;
int score = 0;
class RoadSegment  {
	
	public:
		void gotoxy(int x, int y){
	 CursorOrientation.X = x;
	 CursorOrientation.Y = y;
	SetConsoleCursorPosition(console,  CursorOrientation);
}
	void drawBorder(){  
	for(int i=0; i<SHEIGHT; i++){
		for(int j=0; j<17; j++){
		gotoxy(0+j,i); cout<<"±";
			gotoxy(WWIDTH-j,i); cout<<"±";
		}
	} 
	for(int i=0; i<SHEIGHT; i++){
		gotoxy(SWIDTH,i); cout<<"±";
	} 
}
};
class Racer{ 
public:
	void instructions(){
	
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Avoid Cars by moving left or right. ";
	cout<<"\n\n Press 'a' to move left";
	cout<<"\n Press 'd' to move right";
	cout<<"\n Press 'escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}
};

					
class Race : public RoadSegment { 
	
	

public:
int enemyA[3];
int enemyW[3];
int enemyFlag[3];

					
 

void gotoxy(int x, int y){
	 CursorOrientation.X = x;
	 CursorOrientation.Y = y;
	SetConsoleCursorPosition(console,  CursorOrientation);
}
void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void genEnemy(int ind){
	enemyW[ind] = 17 + rand()%(33);  
}
void drawEnemy(int ind){
	if( enemyFlag[ind] == true ){
		system("Color B");
		gotoxy(enemyW[ind], enemyA[ind]);   cout<<"****";  
		gotoxy(enemyW[ind], enemyA[ind]+1); cout<<" ** "; 
		gotoxy(enemyW[ind], enemyA[ind]+2); cout<<"****"; 
		gotoxy(enemyW[ind], enemyA[ind]+3); cout<<" ** ";  
	} 
}
void eraseEnemy(int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyW[ind], enemyA[ind]); cout<<"    ";  
		gotoxy(enemyW[ind], enemyA[ind]+1); cout<<"    "; 
		gotoxy(enemyW[ind], enemyA[ind]+2); cout<<"    "; 
		gotoxy(enemyW[ind], enemyA[ind]+3); cout<<"    "; 
	} 
}
void resetEnemy(int ind){
	eraseEnemy(ind);
	enemyA[ind] = 1;
	genEnemy(ind);
}

void drawCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carPos, i+22); cout<<racecar[i][j];
		}
	}
}
void eraseCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carPos, i+22); cout<<" ";
		}
	}
}
 
int collision(){
	if( enemyA[0]+4 >= 23 ){
		if( enemyW[0] + 4 - carPos >= 0 && enemyW[0] + 4 - carPos < 9  ){
			return 1;
		}
	}
	return 0;
} 
void gameover(){
	system("cls");
		system("Color D");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
}
void updateScore(){
	gotoxy(WWIDTH + 7, 5);cout<<"Score: "<<score<<endl;
}



void play(){
	carPos = -1 + WWIDTH/2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyA[0] = enemyA[1] = 1;
	  
	system("cls"); 
	drawBorder(); 
	updateScore();
	genEnemy(0);
	genEnemy(1);
	
	gotoxy(WWIDTH + 7, 2);cout<<"Car Game";
	gotoxy(WWIDTH + 6, 4);cout<<"***************************";
	gotoxy(WWIDTH + 6, 6);cout<<"***************************";
	gotoxy(WWIDTH + 7, 12);cout<<"Controls of the race game ";
	gotoxy(WWIDTH + 7, 13);cout<<"************************** ";
	gotoxy(WWIDTH + 2, 14);cout<<" Z is for moving  - Left";
	gotoxy(WWIDTH + 2, 15);cout<<" C is for  moving - Right"; 
	
	gotoxy(18, 5);cout<<"Press any key to start";
	getch();
	gotoxy(18, 5);cout<<"                      ";
	
	while(1){
		if(kbhit()){
			char ch = getch();
			if( ch=='z' || ch=='Z' ){
				if( carPos > 18 )
					carPos -= 4;
			}
			if( ch=='c' || ch=='C' ){
				if( carPos < 50 )
					carPos += 4;
			} 
			if(ch==27){
				break;
			}
		} 
		
		drawCar(); 
		drawEnemy(0); 
		drawEnemy(1); 
		if( collision() == 1  ){
			gameover();
			return;
		} 
		Sleep(50);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);   
		
		if( enemyA[0] == 10 )
			if( enemyFlag[1] == 0 )
				enemyFlag[1] = 1;
		
		if( enemyFlag[0] == 1 )
			enemyA[0] += 1;
		
		if( enemyFlag[1] == 1 )
			enemyA[1] += 1;
		 
		if( enemyA[0] > SHEIGHT-4 ){
			resetEnemy(0);
			score++;
			updateScore();
		}
		if( enemyA[1] > SHEIGHT-4 ){
			resetEnemy(1);
			score++;
			updateScore();
		}
	}
}
};
 


int main()
{
	Race r;
	Racer R;
	r.setcursor(0,0); 
	srand( (unsigned)time(NULL)); 
	 
	do{
		
		system("cls");
		
		r.gotoxy(10,5);  cout<<" *************************** "; 
		r.gotoxy(10,6); cout<<"         Race ** Game         "; 
		r.gotoxy(10,7); cout<<" ****************************";
		r.gotoxy(10,9); cout<<"1. Start the Game";
		r.gotoxy(10,10); cout<<"2. Rules ";	 
		r.gotoxy(10,11); cout<<"3. Exit";
		r.gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') r.play();
		else if( op=='2')R.instructions();
		else if( op=='3') exit(0);
		
	}while(1);
	
	return 0;
}
