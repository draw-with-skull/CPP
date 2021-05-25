//definire bibleoteci
#include<iostream>
#include<fstream>
#include<stdlib.h>

//definire macro-uri
#define size 30
#define short_U unsigned short

// variabile globale
short_U n,k;
short maze[size][size];

//prototipuri functii
	//functie pentru citire
	void read_maze();
	//functii care se ocupa de randare
	void print_maze();
	//functii de rezolvare a labirintului
	void solve_maze();
using namespace std;

int main(void){
	read_maze();
	print_maze();
	cin.get();cout << "\033[2J\033[1;1H";
	solve_maze();
	print_maze();

}
	//definitie functii
//functie pentru citire
void read_maze(){
	fstream flux("labirint1.txt",ios::in);
	flux>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	flux>>maze[i][j];
}
//functia de afisarea
void print_maze(){
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		switch(maze[i][j]){
			case -1:{cout<<"# ";}break;
			case -2:{cout<<"A ";}break;
			case -3:{cout<<"B ";}break;
			case -4:{cout<<". ";}break;

			//default:{cout<<"  ";}break;
			default:{cout<<maze[i][j]<<" ";}break;
		}
	cout<<endl;
	}
}
//functii de rezolvare
void solve_maze(){
	int i,j,k;
	//unsigned short steps=0;
	unsigned short x,y;
	//determinare pozitia de inceput
	i=0;
	while(i<n){
		j=0;
		while(j<n){
			j++;
			if(maze[i][j]==-2){
				if(maze[i][j+1]==0)maze[i][j+1]=1;
				if(maze[i][j-1]==0)maze[i][j-1]=1;
				if(maze[i+1][j]==0)maze[i+1][j]=1;
				if(maze[i-1][j]==0)maze[i-1][j]=1;
				break;
			}
		}
		i++;
	}
	//determinate pozitie de sfarsit
	i=0;
	while(i<n){
		j=0;
		while(j<n){
			j++;
				if(maze[i][j+1]==-3){x=i;y=j;}
				if(maze[i][j-1]==-3){x=i;y=j;}
				if(maze[i+1][j]==-3){x=i;y=j;}
				if(maze[i-1][j]==-3){x=i;y=j;}
		}
		i++;
	}
	x--;
	//generare drumuri
	k=1;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++){
		for(int i1=0;i1<n;i1++)
			for(int j1=0;j1<n;j1++)
			if(maze[i1][j1]==k){
				if(maze[i1][j1+1]==0){maze[i1][j1+1]=k+1;}
				if(maze[i1][j1-1]==0){maze[i1][j1-1]=k+1;}
				if(maze[i1+1][j1]==0){maze[i1+1][j1]=k+1;}
				if(maze[i1-1][j1]==0){maze[i1-1][j1]=k+1;}

		}
		k++;
	}

	//Determinarea punctului de pornire
	if(maze[x+1][y]!=-1){x++;}else
	if(maze[x-1][y]!=-1){x--;}else
	if(maze[x][y+1]!=-1){y++;}else
	if(maze[x][y-1]!=-1){y--;}
	//generare cale
	do{
	if(maze[x+1][y]+1==maze[x][y]){maze[x][y]=-4;x++;}else
	if(maze[x-1][y]+1==maze[x][y]){maze[x][y]=-4;x--;}else
	if(maze[x][y+1]+1==maze[x][y]){maze[x][y]=-4;y++;}else
	if(maze[x][y-1]+1==maze[x][y]){maze[x][y]=-4;y--;}
	}while(maze[x][y]!=1);
	if(maze[x+1][y]==-2){maze[x][y]=-4;x++;}else
	if(maze[x-1][y]==-2){maze[x][y]=-4;x--;}else
	if(maze[x][y+1]==-2){maze[x][y]=-4;y++;}else
	if(maze[x][y-1]==-2){maze[x][y]=-4;y--;}

}

