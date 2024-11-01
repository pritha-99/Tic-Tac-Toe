class User
{
private:
char sym;
public:
User(char);
void turn(char (&board)[3][3]);
char symbol();


};
class System
{
private:
char sym;
public:
System(char);
void turn(char (&board)[3][3]);
char symbol();
};
template<class t1,class t2>
class Game
{
private:
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn;
public:
void display();
/*void play_game(Player p1,Player p2);
void play_game(Player p,System s);
void play_game(System s1,System s2);*/

void play_game(t1 a,t2 b);
bool is_win();
bool is_draw();
};
