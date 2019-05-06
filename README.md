# Childs Play
Implement a game called Child's Play: N kids numbered, 1 to N, are sitting in a circle. Starting at kid 1, a balloon is passed. After M passes, the kid next to the one holding the balloon is eliminated, the circle closes ranks, and the game continues with the kid holding the balloon. The last remaining kid wins. 
If M=0 and N=5, players are eliminated in order: 2, 3, 4, 5 and player 1 wins. If M=1 and N=5, the order of elimination is 3, 5, 2, 1; kid 4 wins. 

Write a program to simulate the Child's Play for general values of M and N. (Your program should ask user for entering values of M and N.) Then, depending on the value of N, the program should ask user to enter player names in order (1 to N). 

Implement a list ADT that is used to store the players in the order they are entered. Each player has an ID (1 to N), and a name (provided by user input). Your list ADT must implement a constructor, destructor, isEmpty(), appendPlayer(), removePlayer(), and printList() functions. You may add other functions as needed.

You must implement your ADT using a linked list. Test the list ADT thoroughly. Your output must explicitly show how the implemented linked list operations are working, and must show boundary conditions when applicable. Here is a sequence of executions that should be demonstrated by your program:

1. Ask user to enter value of N, M, and player names (as mentioned above). Once this information is entered, store it as a linked list (each player is represented by a node). Print the player names and player Ids sequentially, from head to tail of the linked list. 

2. Now reverse the linked list and again print the contents of the linked list from head to tail for the reversed list. 

3. Next, reverse the linked list (from step 2) in pairs. For example, if your linked list contains 1 -> 2 -> 3 -> 4 -> 5 -> NULL, pairwise reversal will result in 2->1->4->3->5->NULL; similarly, if the list was 1 -> 2 -> 3 -> 4 -> 5 -> 6 ->NULL, the pairwise reversal will make it 2 -> 1 -> 4 -> 3 -> 6 -> 5 ->NULL. Print the new list obtained. 

4. Now simulate the Child's play on the list obtained as a result of step 3. Start from the player at the head of the linked list and keep eliminating players according to the values of N and M (as described above). Every time a player is eliminated, print the player name and player id eliminated, and the list of remaining players in the game. Finally print the winning player's name and id. 