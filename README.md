# Words With Friends Puzzle Solver
Inspired by the popular facebook game
[Words With Friends](https://www.zynga.com/games/words-with-friends-2/),
this application generates all possible moves for a given word layout, ordered by score.

## Dependencies
Dependencies are minimal; this application requires SDL2 and Google Test.

## Building
Please build using CMake. Tested to work on Linux + Windows/MinGW.

## Running
The application runs as an SDL2 application and outputs solutions to stdout.

Tiles can be placed by navigating the cursor and typing the desired character.

The rack of available tiles can be modified by moving the cursor to the bottom of the screen.

An asterisk (*) denotes a blank tile. For the rules of Words With Friends, see
[here](https://www.zyngawithfriends.com/wordswithfriends/support/WWF_Rulebook.html).