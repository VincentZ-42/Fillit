# TetrisMap (Fillit)
* Program that produces the smallest possible square board that can fit given Tetris pieces. Among all possibilities, Tetris pieces were placed on their most upper-left position. 

<img align="center" width="648" alt="Screen Shot 2019-12-26 at 4 02 29 PM" src="https://user-images.githubusercontent.com/49771001/71494091-3eabae00-27f9-11ea-8ab4-475f4b560a26.png">

### Table Of Contents
* [Objective](#objective)
* [Understanding the Program](#understanding-the-program)
  * [Input](#input)
* [Usage](#usage)
* [References](#references)

# Objective
* To arrange Tetris pieces with each other to make the smallest possible square
* Learn how use recursive backtracking algorithm
* Learn how to manage memory in a program and parse a file to read inputs 

# Understanding the Program
## Input
* The input is a file that contains a list of Tetris pieces. Every Tetris piece fits in a 4x4 chars square and all Tetris pieces are separated by a newline each. Each Tetris piece follows the below 4 rules:
  * Each Tetris piece is precisely 4 lines of 4 characters, each followed by a new line (4x4 square)
  * A Tetris piece is composed of 4 blocks.
  * Each character must be either a block character (#) or an empty character (.)
  * Each block of a Tetris piece must touch at least one other block on any of its 4 sides (up, down, left, and right)
  
<img align="center" width="694" alt="Screen Shot 2019-12-26 at 4 24 10 PM" src="https://user-images.githubusercontent.com/49771001/71494442-30ab5c80-27fc-11ea-9c06-5c7a86cfbddb.png">

# Usage

# References 
