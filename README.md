# Green vs Red 
### _A simple console game implemented in C++_

### Description
Green vs Red is a game that only consists of a 2D grid whose cells could be coloured in either red or green.
In this implementation the colour red is represented by 0 and the colour green by 1. 
The initial state of the 2D grid or the initial way of colouring the grid is called Generation Zero.
Each subsequent generation is accomplished using the following 4 rules:
1. If a red cell is surrounded by exactly 3 or exactly 6 green cells, it will become green in the next generation.
2. If a red cell is surrounded by any other number (0, 1, 2, 4, 5, 7, 8) of green cells, it will remain red in the
next generation.
3. If a green cell is surrounded by 0, 1, 4, 5, 7, 8 red cells, it will become red in the next generation.
2. If a green cell is surrounded by exactly 2, 3 or 6 red cells, it will remain green in the
next generation.
The goal of the game is to find in how many generations from the initial one to a given generation N a particular cell was green. 

### _**Important Facts:**_
* _An inner cell that is a cell that is not located on the border of the grid has exactly 8 neighbours._
* _A cell that is positioned on one of the 4 corners has 3 neighbouring cells._
* _A cell that is located on the sides but not on the corners has 5 neighbours._

### Instructions:
1. In the beginning of the game the user is prompted to enter the size of the grid.

*If WxH is the dimension of the grid as W - width and H - height, there are the following restrictions:*
*- W <= H*
*- H < 1000*
2. After that he should enter H lines containing 0 and 1, the initial state - Generation Zero of the grid. 
3. Lastly, he should enter the coordinates of the cell that the game will examine for being green and a number N which 
is the generation up to which the game is being played.

*The game calculates Generation Zero and Generation N as well if they meet the condition.*
4. The result - the number of generations in which the given cell was green - is printed on the console. 

Enjoy! :smiley: