#include <iostream>
#include <vector>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

int main()
{
  int periods;
  int teams;
  vector<vector<int> > board;

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
   //once created, display the scoreboard
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
  return 0;
}
