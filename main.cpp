#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

char connect[6][7];
void Print()
{
  system("clear");
  cout<<" 1   2   3   4   5   6   7\n";
  for(int a = 0; a<= 5; a++)
 {
  for(int b =0; b <= 6; b++) 
  cout<<char(124)<<connect[a][b]<<char(124)<<" ";
  cout<<'\n';
 }
}

bool CheckSpace(int a, int b)
{
int vertical = 1;
int horizontal = 1;
int diagonal1 = 1;
int diagonal2 = 1;
char player = connect[a][b];
int i;
int j;

for(i = a +1;connect[i][b] == player && i <= 5;i++,vertical++);
for(i = a -1;connect[i][b] == player && i >= 0;i--,vertical++);
if(vertical >= 4)return true;

for(j = b -1;connect[a][j] == player && j >= 0;j--,horizontal++);
for(j = b +1;connect[a][j] == player && j <= 6;j++,horizontal++);
if(horizontal >= 4) return true;

for(i = a -1, j= b -1;connect[i][j] == player && i>=0 && j >=0; diagonal1 ++, i --, j --);
for(i = a +1, j = b+1;connect[i][j] == player && i<=5 && j <=6;diagonal1 ++, i ++, j++);
if(diagonal1 >= 4) return true;

for(i = a -1, j= b +1;connect[i][j] == player && i>=0 && j<= 6; diagonal2 ++, i --, j ++);
for(i = a +1, j= b -1;connect[i][j] == player && i<=5 && j >=0; diagonal2 ++, i ++, j --);
if(diagonal2 >= 4) return true;
return false;
}

int drop(int b, char player)
{
 if(b >=0 && b<= 6)
 { 
  if(connect[0][b] == ' ')
 {
  int i;
  for(i = 0;connect[i][b] == ' ';i++)
  if(i == 5)
 {
  connect[i][b] = player;
  return i;
 }
   i--;
  connect[i][b] =player;
  return i;
 }
 else
 {  
  return -1;
 }
}
 else
 {
  return -1;
 }
}

int main()
{
 string player_1;
 string player_2;
 cout << " Hello! Welcome to...\n";
 cout << " _______ _______ __ __ __ __ _______ _______ _______\n";
 cout << "| _____|| ___ || | | || | | || _____|| _____||__ __|\n";
 cout << "| | | | | || || || || || |____ | | | |\n";
 cout << "| | | | | || || || || || ____| | | | |\n";
 cout << "| |_____ | |___| || | | || | | || |_____ | |_____ | |\n";
 cout << "|_______||_______||_| |__||_| |__||_______||_______| |_|\n";
 cout << " _______ _______ __ __ _______\n";
 cout << " | _____|| ___ || | | || ___ |\n";
 cout << " | |____ | | | || | | || |___| |\n";
 cout << " | ____| | | | || | | || __ _|\n";
 cout << " | | | |___| || |_| || | | |\n";
 cout << " |_| |_______||_______||_| |_|\n";
 cout<<"Enter Player 1's Name : ";
 cin>> player_1;
 cout<<"Enter Player 2's Name : ";
 cin>> player_2;
{
 for(int a =0;a <= 5; a++)
 { 
   for(int b = 0; b<=6; b++)
  {
     connect[a][b] = ' ';
  }
 }
  Print();
  int value;
  int value_2 = 0;
  int charValue = 0;
  bool playGame = false; 
  char player = 66;
  while(!playGame)
{
  if(value_2 != -1)
  {
    if(player == 66)
    {
      cout<<player_1<<" (R)"<<" Enter the Column No between 1 to 7: ";
      player= 82;
    }
    else
    {
     cout<<player_2<<" (B)"<<" Enter the Column No between 1 to 7: ";
     player= 66;
    }
  }
  while(true)
  {
      if(charValue == 42)
      break;
      cin >> value;
      value--;
      if(value <=6 && value>= 0) 
      break;
      else
    {
     cout<< "\nplease enter a value between 1 and 7 : "; 
    }
      if (cin.fail())
    { 
      cin.clear(); 
      char c;
      cin>>c;
    } 

  }
      if(charValue == 42) break;
      value_2 = drop(value,player);
      if(value_2 == -1) cout<<"Column is full\nPlease enter another number between 1 and 7:";
    else
    {
      playGame = CheckSpace(value_2,value);
      charValue++;
      Print();
    }
}

if(charValue == 42)
{
  cout<<"No winner, Game is a draw.\n";
  return 0;
}
  if(player == 66)
  cout<<player_2<<" won the game!\n";
  else 
  cout<<player_1<<" won the game!\n";
  return 0;
}
}

