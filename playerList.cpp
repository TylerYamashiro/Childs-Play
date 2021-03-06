//Tyler Yamashiro
//playerList.cpp
//The implementation file for the playerList class contains all the functions
//used when interacting with the linked list
//Input: None
//Processing: Allocationg memory for the linked list and de allocating the
//memory when the node is deleted.  Reversing, swapping, and appending to
//the linked list.
//Output:Prints the list to the screen as well as the players eliminated
//when the Childrens Play game is running.

#include "playerList.h"

playerList::playerList()//Constructor
{
  head = nullptr;
  tail = nullptr;
}

playerList::~playerList()//Destructor
{
  Node* temp;
  while(head != nullptr){
	temp = head;
	head = head->next;
	delete temp;
  }
}

bool playerList::isEmpty()//Checks to see if the list is empty
{
  if(head == nullptr)
	return true;
  else{
	return false;
	  }
}
bool playerList::appendPlayer(int ID, string name)
{
  Node* temp;         //Adds a new player to the end of the list
  temp = new Node;
  temp->playerID=ID;
  temp->playerName = name;
  temp->next = nullptr;
  if(isEmpty()){
	head = temp;
	tail = temp;
  }
  else{
	tail->next = temp;
	tail = temp;
  }
  return true;
}

bool playerList::removePlayer(int ID){//removes a player based on ID
  Node *delptr;
  Node *prevptr;
  if(isEmpty())
	return false;
  else{
	delptr = head;
	while(delptr != nullptr && delptr->playerID != ID){//Searches until reach
	  prevptr = delptr;                           //reaches a certain value
	  delptr = delptr->next;
	}
	if(delptr != nullptr && delptr->playerID == ID){ //deletes specified node
	  prevptr->next = delptr->next;
	  delete delptr;
	}
  }
  return true;
}
  

void playerList::printList()//prints everything in the list
{
  Node* temp;
  temp = head;
  if(!head){
	return;
  }
  else{
	while(temp != nullptr){
	  cout << "Player  " << temp->playerID << ", " << temp->playerName;
	  cout << endl;
	  temp = temp->next;
	}
  }
}



void playerList::reverseList()//reverses the order of the list
{
  if(!head)
	return;
  else{
	Node* temp = head;
	Node* nextNode;
	Node* prevNode = nullptr;
	while(temp != nullptr){
	  nextNode = temp->next;
	  temp->next = prevNode;
	  prevNode = temp;
	  temp = nextNode;
	}
	head = prevNode;
  }
  
}

void playerList::reversePairs()
{
  if(!head || head->next == nullptr)
	return;
  else{
	int id;
	string name;
	
	Node* prevNode = head;
	Node* currentNode = prevNode->next;
	while(currentNode){ //creates two nodes and walks down the line
	  id = prevNode->playerID;  //switching the values in the nodes as
	  name = prevNode->playerName; //appropriate
	  prevNode->playerID = currentNode->playerID;
	  prevNode->playerName = currentNode->playerName;
	  currentNode->playerID = id;
	  currentNode->playerName = name;
	  currentNode = currentNode->next;
	  if(currentNode)  //prevents seg faults in case N is even
		currentNode = currentNode->next;
	  prevNode = prevNode->next->next;
	}
	
  }
}


int playerList::playGame(int M)//takes in M to know how many passes to make
{
  if(!head)
	return 0;
  else if( head->next == nullptr)
	return head->playerID;
  else{
	Node* prevPtr = head;
	Node* delPtr = prevPtr->next;
	while(head && head->next != nullptr){
	  for(int i = 0; i < M; i++){ //does m passes before deleting
		if(delPtr == nullptr){ //if while it is moving it hits the end of
		  delPtr = head;  //the list it loops back to head
		}
		prevPtr = delPtr;
		delPtr = delPtr->next; 
	  }
	  if(delPtr != nullptr){ //deletes appropriate node
		prevPtr->next = delPtr->next;
		cout <<"Player " << delPtr->playerID << ", " << delPtr->playerName;
		cout << " has been eliminated." << endl;
		delete delPtr;
		cout << "Players remaining are: " << endl;
		printList();
		cout << endl;
		delPtr = prevPtr->next;
	  }
	  else if(delPtr == nullptr){//if delptr hits nullptr it should delete
		delPtr = head;     //head instead and a new head is assigned
		head = head->next;
		cout <<"Player " << delPtr->playerID << ", " << delPtr->playerName;
		cout << " has been eliminated." << endl;
		delete delPtr;
		cout << "Players remaining are: " << endl;
		printList();
		cout << endl;		
		delPtr = prevPtr->next;
	  }
	}
	winnerName = head->playerName; //stores winner name and ID
	winnerID = head->playerID;
	return head->playerID;
  }
}


string playerList::returnWinName()//returns winners name
{
  return winnerName;
}
