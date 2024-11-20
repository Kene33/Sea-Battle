▎Ship Game

Welcome to the Ship Game! This is a simple console-based game implemented in C#. The objective of the game is to guess the coordinates of hidden ships on a grid. Players take turns guessing the coordinates, and the game provides feedback on whether the guess was a hit or a miss.

▎Features

• Random Ship Placement: Ships are randomly placed on a grid of user-defined dimensions.

• User Input: Players can input their guesses for ship locations.

• Hit or Miss Feedback: The game indicates whether a player's guess hit a ship or not.

• Win Condition: The game continues until all ships have been successfully located.

▎Getting Started

▎Prerequisites

To run this game, you need to have:

• .NET SDK (https://dotnet.microsoft.com/download) installed on your machine.

▎Installation

1. Clone the repository:
   
   git clone https://github.com/yourusername/ship-game.git
   cd ship-game
   

2. Open the project in your preferred IDE (e.g., Visual Studio, Visual Studio Code).

3. Build and run the project:
   
   dotnet run
   

▎How to Play

1. When prompted, enter the number of rows and columns for the game grid.

2. Guess the coordinates of the ships by entering X (row) and Y (column) values.

3. The game will inform you if your guess was a hit or a miss.

4. Continue guessing until all ships have been located.

▎Example Gameplay

Enter number of lines: 5
Enter number of columns: 5
X Y- - - - - - - - - - - - - - - - - -
0|false false false false false 
1|true true false false false 
2|false false false true false 
3|false false false false false 
4|false true false false true 
   0 1 2 3 4 
- - - - - - - - - - - - - - - - - - -
Enter X coordinate: 1
Enter Y coordinate: 0
The ship was shot down! | X1 Y0

...

You shot down all ships.


▎Code Overview

The main components of the code include:

• Main Method: Initializes the game, generates a random grid, and handles user input.

• ShowMap Method: Displays the current state of the game board.

• AllElementsEqual Method: Checks if all ships have been located.

▎Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

---

Enjoy playing the Ship Game! If you have any questions or feedback, please feel free to reach out.
