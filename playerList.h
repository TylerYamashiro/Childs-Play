//Tyler Yamashiro
//playerList.h
//Purpose: The .h file for the playerList class
//Processing: Creates and alters a linked list in order to play the game
//Childs play.

#include <iostream>
using namespace std;


#ifndef PLAYERLIST_H
#define PLAYERLIST_H

class playerList
{
 public:
  playerList();
  //The constructor which initiates the pointers of type node for the head
  //and the tail of the playerList object.
  ~playerList();
  //PreCondition: A playerList object exists.
  //PostCondition: De allocates the memory taken up by the linked list
  bool isEmpty();
  //PreCondition: A playerList object exists.
  //PostCondition: Returns a bool true if the linked list is empty and
  //false if it is not empty
  bool appendPlayer(int ID, string name);
  //PreCondition:A node needs to be appended with a string name
  //and an int ID
  //PostCondition:Appends a node to the end of the linked list with the
  //Id of the player as well as the player name
  bool removePlayer(int ID);
  //Precondition:A player exists that has the ID int given as a parameter
  //PostCondition: Finds the player with the ID and removes it fromt the
  //list
  void printList();
  //Prints out all the data for each node in the list which is the player
  //name and player ID
  void reverseList();
  //Precondtion: A list exists to be reversed
  //Postcondition: Reverses the order of the list
  void reversePairs();
  //Precondtion: A list exists with at least 2 nodes
  //Postcondition:Switches the values of the two nodes next to each other
  int playGame(int M);
  //Precondtition: A list of player exists
  //Postcondition: Plays the game eliminating players based on user given
  //information then returns the winners player ID
  string returnWinName();
  //Returns the name of the winner of the game.

 
 private:
  struct Node{ ///Node for the linked list
	int playerID; //player ID
	string playerName; //Player Name
	Node* next;  //pointer to the next thing in the list
  };
  Node* head;  //head pointer to front of the list
  Node* tail;  //tail pointer to end of the list
  string winnerName; //Name of the winner
  int winnerID; //Id of the winner.
};
#endif
