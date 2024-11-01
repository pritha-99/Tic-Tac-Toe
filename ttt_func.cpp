#include"ttt.h"
#include<iostream>
#include<cstdlib>
using namespace std;
User::User(char s)
{
sym=s;
}

System::System(char s)
{
sym=s;
}

void User::turn(char (&board)[3][3])
{
int choice;
int r,c;
cout<<"Enter your choice of position:";
cin>>choice;
switch(choice)
{
case 1:r=0;
c=0;
break;
case 2:r=0;
c=1;
break;
case 3:r=0;
c=2;
break;
case 4:r=1;
c=0;
break;
case 5:r=1;
c=1;
break;
case 6:r=1;
c=2;
break;
case 7:r=2;
c=0;
break;
case 8:r=2;
c=1;
break;
case 9:r=2;
c=2;
break;
default:cout<<"Invalid position choice. Enter again!!!"<<endl;
turn(board);
break;
}
if(board[r][c]!='X'&&board[r][c]!='O')
{
board[r][c]=sym;
}
else
{
cout<<"Box already filled in. Enter another position"<<endl;
turn(board);
}
}

char User::symbol()
{
return sym;
}
void System::turn(char (&board)[3][3])
{
int choice=(rand()%9)+1;
int r,c;
switch(choice)
{
case 1:r=0;
c=0;
break;
case 2:r=0;
c=1;
break;
case 3:r=0;
c=2;
break;
case 4:r=1;
c=0;
break;
case 5:r=1;
c=1;
break;
case 6:r=1;
c=2;
break;
case 7:r=2;
c=0;
break;
case 8:r=2;
c=1;
break;
case 9:r=2;
c=2;
break;
}
if(board[r][c]!='X'&&board[r][c]!='O')
{
board[r][c]=sym;
}
else
{
turn(board);
}
}

char System::symbol()
{
return sym;
}
template<class t1,class t2>
void Game<t1,t2>::display()
{
for(int i=0;i<3;i++)
{
cout<<"\t  \t|\t  \t|\t  \t"<<endl;
for(int j=0;j<3;j++)
{
cout<<"\t "<<board[i][j];
if(j!=2)

cout<<"\t|";
}
cout<<"\n\t___\t|\t___\t|\t___\t"<<endl;
}
}
template<class t1,class t2>
bool Game<t1,t2>::is_win()
{
  for(int i=0;i<3;i++)
  {
  if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
  return 1;
  if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
  return 1;
  }
  if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
  return 1;
  if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
  return 1;
  return 0;
}
template<class t1,class t2>
bool Game<t1,t2>::is_draw()
{
for(int i=0;i<3;i++)
{

for(int j=0;j<3;j++)
{
if(board[i][j]!='X'&&board[i][j]!='O')
return 0;
}
}
return 1;
}

template<class t1,class t2>
void Game<t1,t2>::play_game(t1 a,t2 b)
{
display();
while(!is_win()&&!is_draw())
{
cout<<"\n******PLAYER 1 [X] TURN******"<<endl;
turn=a.symbol();
a.turn(board);
display();
if(is_draw()||is_win())
break;
cout<<"\n******PLAYER 2 [O] TURN******"<<endl;
turn=b.symbol();
b.turn(board);
display();
}
if(is_win())
{
if(turn==a.symbol())
cout<<"\nPlayer 1 ["<<turn<<"] wins!!!\n\n"<<endl;
else
cout<<"\nPlayer 2 ["<<turn<<"] wins!!!\n\n"<<endl;
}
else
cout<<"\nThe game is a draw!!!\n\n"<<endl;
}

template class Game<User,User>;
template class Game<User,System>;
template class Game<System,User>;
template class Game<System,System>;

/*
void Game:: play_game(Player p1,Player p2)
{
display();
while(!is_win()&&!is_draw())
{
cout<<"\n******PLAYER 1 TURN******"<<endl;
turn=p1.symbol();
p1.player_turn(board);
display();
if(is_draw()||is_win())
break;
cout<<"\n******PLAYER 2 TURN******"<<endl;
turn=p2.symbol();
p2.player_turn(board);
display();
}
if(is_win())
{
if(turn==p1.symbol())
cout<<"Player with "<<turn<<" wins!!!"<<endl;
else
cout<<"Player with "<<turn<<" wins!!!"<<endl;
}
else
cout<<"The game is a draw!!!"<<endl;

}

void Game:: play_game(Player p1,System s)
{
display();
while(!is_win()&&!is_draw())
{
cout<<"\n******PLAYER TURN******"<<endl;
turn=p1.symbol();
p1.player_turn(board);
display();
if(is_draw()||is_win())
break;
cout<<"\n******SYSTEM TURN******"<<endl;
turn=s.symbol();
s.system_turn(board);
display();
}
if(is_win())
{
if(turn==p1.symbol())
cout<<"Player with "<<turn<<" wins!!!"<<endl;
else
cout<<"System with "<<turn<<" wins!!!"<<endl;
}
else
cout<<"The game is a draw!!!"<<endl;
}

void Game::play_game(System s1,System s2)
{
display();
while(!is_win()&&!is_draw())
{
cout<<"\n******SYSTEM 1 TURN******"<<endl;
turn=s1.symbol();
s1.system_turn(board);
display();
if(is_draw()||is_win())
break;
cout<<"\n******SYSTEM 2 TURN******"<<endl;
turn=s2.symbol();
s2.system_turn(board);
display();
}
if(is_win())
{
if(turn==s1.symbol())
cout<<"System with "<<turn<<" wins!!!"<<endl;
else
cout<<"System with "<<turn<<" wins!!!"<<endl;
}
else
cout<<"The game is a draw!!!"<<endl;

}*/
