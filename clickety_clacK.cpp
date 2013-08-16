//                         _         _                   _                _        ______ 
//                        | |       | |                 | |              | |       | ___ \
//   _ __ ___    __ _   __| |  ___  | |__   _   _   ___ | | __ ___   ___ | |_  ___ | |_/ /
//  | '_ ` _ \  / _` | / _` | / _ \ | '_ \ | | | | / __|| |/ // _ \ / _ \| __|/ _ \|    / 
//  | | | | | || (_| || (_| ||  __/ | |_) || |_| | \__ \|   <|  __/|  __/| |_|  __/| |\ \ 
//  |_| |_| |_| \__,_| \__,_| \___| |_.__/  \__, | |___/|_|\_\\___| \___| \__|\___|\_| \_|
//                                           __/ |                                        
//                                          |___/  
//_-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-_-
//_-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-_07/28/2013_-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-_-_-_
//_-_-_-_-_-_-_This is a console based dice game.  You play against the computer._-_-_-_-_-_-_   

#include <iostream>

using namespace std;

//a few functions, lets declare them up here 1st :)
int humanTurn(int humanScore);
int computerTurn(int computerScore);

int humanTotalScore=0;
int computerTotalScore=0;
int points = 0;

int main ()
{
	int random;
	char userChoice;

	cout << " Welcome clicketyclacK " << endl; // Welcome User
	cout << " Lets introduce the game... " << endl;
	cout << " The first person to get to or exceed 100 points, wins. \n"; // Explain game
	cout << " Press r to roll again, or press h to hold! " <<endl;
	cout << " Beware, if you roll a 1 then you lose your turn and gain no points! " <<endl;



	while(humanTotalScore < 100 && computerTotalScore < 100) 
	{
		points=0;
		for(bool DontStop=true;DontStop;)
		{
			cout <<" It's your turn " <<endl;
			cin>> userChoice;
			
			if (userChoice=='r')
			{
				random = rand()%6 +1;
				points = points + random;
				cout << " You rolled a " << random << endl;
				cout << " Your temporary score is " << points << endl;
				if(random==1)
				{
					points=0;
					cout <<" You dont get anything this round \n" << " Your current score is " << humanTotalScore << endl;
					x=1000;
				}
			}
			else if (userChoice=='h')
			{
				humanTurn(humanTotalScore);
				cout << " It is now the other person's turn. " <<endl;	
				cout << " Your current score is " << humanTotalScore << endl;
				points = 0;
				DontStop = false;			
			}		
		}

		if(humanTotalScore >= 100)
		{
			cout << " YOU WIN!$$ " << endl;
			y=1000;
		}

		points = 0;
		for(bool DontStop=true;DontStop;)
		{
			cout << " Computer, it's your turn " <<endl;
			random = rand()%6 +1;
			points = points + random;
			cout << " Computer rolled a " << random << endl;
			cout << " Computer's current temporary score is " << points << endl;
			if (random ==1)
			{
			 cout << " Computer rolled a 1 loses all points for this round" <<endl;
			 points = 0;
			 y++;
			}
			if(points >= 20)
			{
				computerTurn(computerTotalScore);
				cout << " Computer decided to hold current score " << computerTotalScore <<endl;
				points = 0;
				DontStop = false;
				
			}
		}
		
	}
	return (0);
}

//lets make a couple functions ^.^

int humanTurn(int humanScore)
{
	humanTotalScore = humanScore +points;
	return (humanScore);
}

int computerTurn(int computerScore)
{
	computerTotalScore = computerScore + points;
	return (computerScore);
}
