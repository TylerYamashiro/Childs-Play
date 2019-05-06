//Tyler Yamashiro
//Project3.cpp
//Purpose:Driver program that utilizes the playerList class in order to play
//the childs play game
//Inputs: N which is the number of players, M which is the number of passses
//before a player is eliminated, and player names as a string.
//Processing: Calls the functions for the playerList object
//Output:Outputs the results of the actions such as the created list, the
//reversed list, the list with the reversed pairs, and the results of the
//Childs play game



#include "playerList.h"

int main()
{
  int N;//N and M store user input as specified in the description
  int M;
  string name;//stores a players name
  int winnerID;//winning players ID
  playerList list1;//playerList object

  cout << "Please input a value for N: ";
  cin >> N;
  cout << "Please input a value for M: ";
  cin >> M;

  

  cout << "Please enter " << N << " player names."<< endl;
  for(int i = 0; i < N ; i++){ //gathering the player names
	cout << "Please enter a name for player " << i+1 << ": ";
	cin >> name;
	list1.appendPlayer(i+1, name); //creating the lsit of players
  }

  cout << endl << endl;
  cout << "Now printing the list." << endl;
  list1.printList();

  cout << endl << endl;
  
  cout << "Now reversing the list." << endl;
  cout << endl;
  
  list1.reverseList(); //reverse the list

  list1.printList(); //print the reversed list
  cout <<endl <<endl;
  cout <<"Now reversing the pairs in the reverse linked list." << endl;
 
  list1.reversePairs(); //reverse the pairs

  list1.printList(); //print the new list
  cout << endl << endl;
  cout << "Now simulating Child's Play." << endl << endl;
  
  winnerID = list1.playGame(M); //simulate the game with the new list
  cout << "The winner is player " << winnerID << "::" <<
	list1.returnWinName() << endl; //returnt the winner
}
