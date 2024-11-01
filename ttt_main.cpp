#include"ttt.h"
#include<iostream>
using namespace std;

int main()
{
cout<<"*****TIC-TAC-TOE IMPLEMENTATION*****\n"<<endl;
char q,r;
while(1)
{
int ch;
cout<<"Enter   1.Player vs Player\n\t2.Player vs System\n\t3.System vs System"<<endl;
cout<<"Enter your choice:";
cin>>ch;
if(ch==1)
{
Game<User,User> g1;
while(1)
{
cout<<"Enter your symbol of preference(X or O):";
cin>>q;
if(q!='X'&&q!='O')
{
cout<<"Invalid symbol. Enter again!!!"<<endl;
}
else
break;
}
User p1(q);
r=(q=='X')?'O':'X';
User p2(r);
if(q=='X')
g1.play_game(p1,p2);
else
g1.play_game(p2,p1);
}
else if(ch==2)
{


while(1)
{
cout<<"Enter your symbol of preference(X or O):";
cin>>q;
if(q!='X'&&q!='O')
{
cout<<"Invalid symbol. Enter again!!!"<<endl;
}
else
break;
}
User p(q);
r=(q=='X')?'O':'X';
System s(r);
if(q=='X')
{
Game<User,System> g2;
g2.play_game(p,s);
}
else
{
Game<System,User> g3;
g3.play_game(s,p);
}
}
else if(ch==3)
{
Game<System,System> g4;
System s1('X'),s2('O');
g4.play_game(s1,s2);
}

cout<<"Do you want to continue?0 to quit & any other number to continue:";
cin>>ch;
if(!ch)
{
cout<<"Thank you :)"<<endl;
break;
}
}
}

