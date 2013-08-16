//                         _         _                   _                _        ______ 
//                        | |       | |                 | |              | |       | ___ \
//   _ __ ___    __ _   __| |  ___  | |__   _   _   ___ | | __ ___   ___ | |_  ___ | |_/ /
//  | '_ ` _ \  / _` | / _` | / _ \ | '_ \ | | | | / __|| |/ // _ \ / _ \| __|/ _ \|    / 
//  | | | | | || (_| || (_| ||  __/ | |_) || |_| | \__ \|   <|  __/|  __/| |_|  __/| |\ \ 
//  |_| |_| |_| \__,_| \__,_| \___| |_.__/  \__, | |___/|_|\_\\___| \___| \__|\___|\_| \_|
//                                           __/ |                                        
//                                          |___/                                          
// 08/01/2013

#include<iostream>

using namespace std;

int main()
{
    int playerTurn=1;
    const int ROW=3; 
    const int COL=3;
    bool bGameOver= false;
    char board[ROW][COL] = {{ '1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'}};
    
    
    while (!bGameOver)//main game loop
    {
    
          // print board
          for (int i = 0; i<ROW; ++i)
          {
              cout<<board[i][0]<<"|"<<board[i][1]<<"|"<<board[i][2]<<endl;
              if (i==0 || i==1)
              {
                      cout<<"-+-+-"<<endl;
              }
          }
          
          // set player mark
          char playerMark;
          if (playerTurn == 1) // sets player mark, X for player 1 O for play 2
          {
              playerMark = 'X';
          }
          else
          {
              playerMark = 'O';
          }
                   
          // ask for player move
          char nextMove;
          cout<<"Player "<<playerTurn<<" please pick a spot to place "<<playerMark<<" using numbers from the board"<<endl;
          
          
          
          bool validMove=false;
          
          while (!validMove) // checks for valid move
          {
                validMove=true;
                cin>>nextMove;
                if(nextMove == '1' && board[0][0] == '1')
                {
                            board[0][0] = playerMark;
                }
                else if(nextMove == '2' && board[0][1] == '2')
                {
                            board[0][1] = playerMark;
                }
                else if(nextMove == '3' && board[0][2] == '3')
                {
                            board[0][2] = playerMark;
                }
                else if(nextMove == '4' && board[1][0] == '4')
                {
                            board[1][0] = playerMark;
                }
                else if(nextMove == '5' && board[1][1] == '5')
                {
                            board[1][1] = playerMark;
                }
                else if(nextMove == '6' && board[1][2] == '6')
                {
                            board[1][2] = playerMark;
                } 
                else if(nextMove == '7' && board[2][0] == '7')
                {
                            board[2][0] = playerMark;
                } 
                else if(nextMove == '8' && board[2][1] == '8')
                {
                            board[2][1] = playerMark;
                }
                else if(nextMove == '9' && board[2][2] == '9')
                {
                            board[2][2] = playerMark;
                } 
                else 
                {
                                 cout<<"Invalid Move, please try again!"<<endl;
                                 validMove = false;
                }
          }
          // check for game over conditions
          if (board[0][0] != '1') // see if row 0 or col 0 are the same playerMark
          {
                          if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) // checks row 0
                          {
                                          bGameOver=true;
                          }
                          if (board[0][0] == board[1][0] && board[0][0] == board[2][0])//checks col 0
                          {
                                          bGameOver=true;
                          }
          }
          if (board[2][2] != '9')// see if row 2 or col 2 are the same playrMark
          {
                          if (board[2][2] == board[2][1] && board[2][2] == board[2][0])// checks row 2
                          {
                                          bGameOver=true;
                          }
                          if (board[2][2] == board[1][2] && board[2][2] == board[0][2])// checks col 2
                          {
                                          bGameOver=true;
                          }
          }
          if (board[1][1] != '5')
          {
                          if(board[1][1] == board[0][1] && board[1][1] == board[2][1])// checks col 1
                          {
                                         bGameOver=true;
                          }
                          if(board[1][1] == board[1][0] && board[1][1] == board[1][2])// checks row 1
                          {
                                         bGameOver=true;
                          }
                          if(board[1][1] == board[0][0] && board[1][1] == board[2][2])// check if 1 and 9 are equal to 5
                          {
                                         bGameOver=true;
                          }
                          if(board[1][1] == board[2][0] && board[1][1] == board[0][2])// check if 3 and 7 are equal to 5
                          {
                                         bGameOver=true;
                          }
          }
          
          // check for a tie
          bool bWinGame=true; // assumes someone won
          if (board[0][0] !='1' && board[0][1] !='2' && board[0][2] !='3' && 
              board[1][0] !='4' && board[1][1] !='5' && board[1][2] !='6' &&
              board[2][0] !='7' && board[2][1] !='8' && board[2][2] !='9' &&
              !bGameOver)
          {
              bGameOver=true;
              bWinGame=false;
              cout<<"Its a Tie!"<<endl;
          }
          
          // congradulate winner if bGameOver and ask to play again
          
          while (bGameOver)
          {
                        // print board
                        for (int i = 0; i<ROW; ++i)
                        {
                            cout<<board[i][0]<<"|"<<board[i][1]<<"|"<<board[i][2]<<endl;
                            if (i==0 || i==1)
                            {
                                     cout<<"-+-+-"<<endl;
                            }
                        }
                        
                        if(bWinGame) // gratz on winning
                        {
                                    cout<<"Player "<<playerTurn<<" wins!\n";
                        }
                        
                        char again;
                        cout<<"Would you like to play again? (y/n)";
                        cin>>again;
                        
                        if (again == 'y' || again == 'Y')
                        {
                                  bGameOver=false; // reset game
                                  bWinGame=true; // assume someone will win next game
                                  
                                  board[0][0] = '1';
                                  board[0][1] = '2';
                                  board[0][2] = '3';
                                  board[1][0] = '4';
                                  board[1][1] = '5';
                                  board[1][2] = '6';
                                  board[2][0] = '7';
                                  board[2][1] = '8';
                                  board[2][2] = '9';
                        }
                        
                        else if (again == 'n' || again == 'N')
                        {
                                  cout<<"Thanks for playing!\n"; // say thanks for playing
                                  break;
                        }
                        
                        else
                        {
                            cout<<"Please use y or n only"<<endl;
                        }
          }
          
          if (!bGameOver) // if the game is not over switch turns
          {
                         if (playerTurn==1)
                         {
                                         playerTurn=2;
                         }
                         else
                         {
                                         playerTurn=1;
                         }
          }    
    } // game loop over
 system("Pause");
 return 0;
