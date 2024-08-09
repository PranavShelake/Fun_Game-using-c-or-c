#include<iostream>
#include<string>
#include<unistd.h>

using namespace std;

void display(char arr[9]){
	cout<<"|``   ``|"<<endl;
	cout<<"  "<<arr[0]<<" "<<arr[1] <<" "<<arr[2]<<endl;
	cout<<"  "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<endl;
	cout<<"  "<<arr[6]<<" "<<arr[7]<<" "<<arr[8]<<endl;
	
	cout<<"|__   __|\n"<<endl;
}

int win(char arr[9]){
	if((arr[0]=='O' && arr[1]=='O' && arr[2]=='O') || (arr[3]=='O' && arr[4]=='O' && arr[5]=='O') || (arr[6]=='O' && arr[7]=='O' && arr[8]=='O') || (arr[0]=='O' && arr[3]=='O' && arr[6]=='O') || (arr[1]=='O' && arr[4]=='O' && arr[7]=='O') || (arr[2]=='O' && arr[5]=='O' && arr[8]=='O') || (arr[0]=='O' && arr[4]=='O' && arr[8]=='O') || (arr[2]=='O' && arr[4]=='O' && arr[6]=='O') ){
		return 1;
	}
	else if((arr[0]=='X' && arr[1]=='X' && arr[2]=='X') || (arr[3]=='X' && arr[4]=='X' && arr[5]=='X') || (arr[6]=='X' && arr[7]=='X' && arr[8]=='X') || (arr[0]=='X' && arr[3]=='X' && arr[6]=='X') || (arr[1]=='X' && arr[4]=='X' && arr[7]=='X') || (arr[2]=='X' && arr[5]=='X' && arr[8]=='X') || (arr[0]=='X' && arr[4]=='X' && arr[8]=='X') || (arr[2]=='X' && arr[4]=='X' && arr[6]=='X') ){
		return 2;
	}
	else{
		return 3;
	}
}

int key(int a[9],int pos){
	for(int i=0;i<9;i++){
		if(a[i]==pos)return 0;
	}
	return 1;
}

void play(){
	cout<<"Do you want to enter your name insert of player 1 and player 2 press 'y'/'Y' to change your name or press any key:- ";
	
	string player_1="Player_1";
	string player_2="Player_2";
	char choice;
	cin>>choice;
	
	if(choice=='y' || choice=='Y'){
		printf("Enter Player 1 name :- ");
		cin>>player_1;
		printf("Enter Player 2 name :- ");
		cin>>player_2;
	}
	
	cout<<"\n\nYou all know the basic rules of games \n1) who make first triplet they will win this game \n"<<endl;
	
	cout<<"_____________ "<<player_1<<" is O(ZERO)_____________ "<<endl;
	cout<<"_____________ "<<player_2<<" is X(CROSS)_____________ \n\n"<<endl;
	cout<<"So first move gave to \n"<<player_1<<endl;
	char Continue='y';
	while(Continue=='y' || Continue=='Y'){
		char arr[9];
		for(int i=0;i<9;i++){
			arr[i]='.';
		}
		display(arr);
		int a[9];
		for(int i=0;i<9;i++){
			a[i]=9;
		}
		int num=0,k=0,c=0;
		while(num!=9){
			int position;
			if(c==0 ||c%2==0){
				cout<<player_1<<" your turn, Write your postion :- ";
			}
			else{
				cout<<player_2<<" your turn, Write your postion :- ";
			}
			cin>>position;
			cout<<"\n"<<endl;
			if(position >= 0 && position <= 8 ){
				if(key(a,position)==0){
					if(c==0 ||c%2==0){
						cout<<"\n"<<player_1<<" Don't use same position again\n";
					}
					else{
						cout<<"\n"<<player_2<<" Don't use same position again\n";
					}
				}
				else{
					a[k]=position;
					if(k%2==0 || k==0){
						arr[position]='O';
					}
					else{
						arr[position]='X';
					}
					c++;
					display(arr);
					k++;
					num++;
					if(win(arr)==1){
						num=9;
					}
					else if(win(arr)==2){
						num=9;
					}
				}
			}
			else{
				cout<<"Enter the correct position, position should be  in range of(0-8)\n"<<endl;
			}
		}
		
				if(win(arr)==1){
					cout<<player_1<<" Win.....\n"<<endl;
				}
				else if(win(arr)==2){
					cout<<player_2<<" Win.....\n"<<endl;
				}
				else if(win(arr)==3){
					cout<<"Match Draw.....\n"<<endl;
				}
				cout<<"Enter 'y'/'Y' to play again or press any key to go home :- ";
				cin>>Continue;		
	}
}


void info(){
	char arr[9];
		for(int i=0;i<9;i++){
			arr[i]=i+'0';
		}
		cout<<"\n\n";
	display(arr);
	cout<<"It same as matrix \nUse the matrix index(0-8) to write the 'O' or 'X'  \n"<<endl;
	cout<<"Example :-\n1) you enter position 3\n"<<endl;
	arr[3]='O';
	display(arr);
	cout<<"Look in the position of 3 'O'(Zero) has inserted\n"<<endl;
	cout<<"2) you enter position 8\n"<<endl;
	arr[8]='X';
	display(arr);
	cout<<"Look in the position of 8 'X'(Cross) has inserted\n"<<endl;
	cout<<"*************** READ ABOVE MANUAL ***************\n"<<endl;
	return ;
}




void rate_us(){
    char rate;
	cout<<"Rate me out of five (0-5) :- ";
	cin>>rate;
	
	switch (rate){
		case '0':
			cout<<"We still improving....Thank to rate us\n"<<endl;
			break;
		case '1':
			cout<<"We still improving....Thank to rate us\n"<<endl;
			break;
		case '2':
			cout<<"We adding new features soon....Thank to rate us\n"<<endl;
			break;
		case '3':
			cout<<"We adding new features soon....Thank to rate us\n"<<endl;
			break;
		case '4':
			cout<<"we really like that you love our game....\n"<<endl;
			break;
		case '5':
			cout<<"we really like that you love our game....\n"<<endl;
			break;
		default:
			cout<<"Invalid number,Rate me in range (0-5)\n"<<endl;
			return ;
	}
	
}


void exit(){
	return;
}
int main(){
	cout<<"_____________ Please wait-Game loading... _____________ \n\n"<<endl;
	sleep(5);
	
	cout<<"_____________ Welcome to tic tok gameplay _____________ \n\n"<<endl;
	
	lable:
		
		cout<<"1)Play "<<endl;
		cout<<"2)How to play this game"<<endl;
		cout<<"3)Rate us"<<endl;
		cout<<"4)Exit"<<endl;
		int number;
		cout<<"\nchoice the number :- ";
		cin>>number;
		switch (number){
			case 1:
				play();
				goto lable;
				break;
			case 2:
				info();
				goto lable;
				break;
			case 3:
				rate_us();
				goto lable;
				break;
			case 4:
				exit();
				break;         
			default:
				cout<<"Enter valid number \n"<<endl;
				goto lable;
		}
	
	
	
	
	return 0;
}
