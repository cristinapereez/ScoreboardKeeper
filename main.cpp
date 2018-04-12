#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;
void printScoreboard(vector<vector<int> >); //prototype
int randomBetween(int,int); //prototype for random numbers
vector<vector<int> > board;

int main()
{
  srand((int) time(0));
  int periods;
  int teams;
//  vector<vector<int> > board;

  cout<<"How many competitors? ";
  cin>>teams;
  cout<<"How many scoring periods? ";
  cin>>periods;

  if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
      teams > MAX_TEAMS || periods > MAX_PERIODS )
  {
    cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
    cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
    return 0;
  }
  else
  {
   //make scoreboard 
    board.resize(teams);
    for(int row = 0; row < board.size(); row++)
    {
     board[row].resize(periods);
    }
   // traverse through matrix and fill it with zeros
   int current = 0;
   for(int row = 0; row < board.size(); row++)
   {
    for(int col = 0; col < board[row].size(); col++)
    {
        board[row][col] = current;
    }
   }
  }
printScoreboard(board); //call
   // traverse through matrix again and fill it with random numbers
   for(int row = 0; row < board.size(); row++)
   {
    for(int col = 0; col < board[row].size(); col++)
    {
        board[row][col] = randomBetween(5,5);
    }
   }
 printScoreboard(board); //call it again

  return 0;
}
   //once created, display the scoreboard
void printScoreboard(vector<vector<int> > grid) //definition
{
   cout<<"SCOREBOARD"<<endl;
   for(int row = 0; row < board.size(); row++)
   {
     cout<<"Player "<<row+1<<": ";
     for(int col = 0; col < board[row].size(); col++)
     {
//       cout<<"Player "<<row+1;
       cout<<board[row][col]<<"|";
     }
     cout<<endl;
   }
} 
int randomBetween(int first, int second) //definition for random numbers
{
  if(first > second)
  {
    return second + rand()%(first-second+1);
  }
  else if(second > first)
  {
  return first + rand()%(second-first+1);
  }
}






