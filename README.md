# game of chips i/o game

This program is similiar to a game of chips where users will take a variable number of chips each turn until the chips in the pile are empty. The game requires two players. Each player will be prompted for their name, then prompted to enter a starting number of "chips" in the pile (or 0 for random). You can play against the computer by typing "AI" for the player two name. 

After both user names are taken as input and a starting number of chips in the pile specified. The game loop will begin and the number of current chips in the pile will be displayed as "Chips left in the pile: X" followed by a newline stating the maximum number of chips a player can take for that turn based on the total chips in the pile and MAX_TURN rate. After player one takes 'X' chips, it will be player two's turn to take chips and the game logic continues until a winner is decided.

## Win Condition
The player who takes the last chip in the pile loses.

## Demo
A normal game with a random number of chips to start.

![demo one](https://user-images.githubusercontent.com/48612525/130404797-1f8d63a5-6401-48b1-8061-9bf1abb3fafc.png)

A game where you play against the AI (computer).

![demo two](https://user-images.githubusercontent.com/48612525/130404559-ba12de6d-021c-4b15-b586-185cc5f655ec.png)

## Game history

The game history will be written to the `game-log.txt` file after every game and contains:

- Winning players name
- Number of moves to win
- Starting number of chips in the pile

```txt
Tanner won in 8 turns with 71 chips in the pile to start
Tanner won in 4 turns with 5 chips in the pile to start
AI won in 7 turns with 30 chips in the pile to start
Root won in 7 turns with 42 chips in the pile to start
Tanner won in 8 turns with 85 chips in the pile to start
Tanner won in 8 turns with 15 chips in the pile to start
AI won in 7 turns with 15 chips in the pile to start
Tanner won in 6 turns with 25 chips in the pile to start
```

## Resources

[Learning C++](https://www.linkedin.com/learning/learning-c-plus-plus-3/fun-with-c-plus-plus) - By Erin Colvin on LinkedIn.