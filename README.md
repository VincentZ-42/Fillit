# TetrisMap (Fillit)
* Program that produces the smallest possible square board that can fit given Tetris pieces. Among all possibilities, Tetris pieces were placed on their most upper-left position. 

<p align="center">
 <img width="648" alt="Screen Shot 2019-12-26 at 4 02 29 PM" src="https://user-images.githubusercontent.com/49771001/71494091-3eabae00-27f9-11ea-8ab4-475f4b560a26.png">

### Table Of Contents
* [Objective](#objective)
* [Understanding the Program](#understanding-the-program)
  * [Input](#input)
  * [Output](#output)
* [Usage](#usage)
* [Further Thoughts](#further-thoughts)
* [References](#references)

# Objective
* Learn about string manipulation (string parsing from reading a file) and memory management
* Learn how to use and traverse a linked list (data structure)
* Learn how implement recursive backtracking algorithm

# Understanding the Program
## Input
The input is a file that contains a list of Tetris pieces. Every Tetris piece fits in a 4x4 chars square and all Tetris pieces are separated by a newline each. Each Tetris piece follows the four rules below:
  * Each Tetris piece is precisely 4 lines of 4 characters, each followed by a new line (4x4 square)
  * A Tetris piece is composed of 4 blocks.
  * Each character must be either a block character (#) or an empty character (.)
  * Each block of a Tetris piece must touch at least one other block on any of its 4 sides (up, down, left, and right)
  
<p align="center">
 <img width="694" alt="Screen Shot 2019-12-26 at 4 24 10 PM" src="https://user-images.githubusercontent.com/49771001/71494442-30ab5c80-27fc-11ea-9c06-5c7a86cfbddb.png">

## Output

<img align="right" width="225" alt="Screen Shot 2019-12-26 at 4 51 15 PM" src="https://user-images.githubusercontent.com/49771001/71494971-11aec980-2800-11ea-910a-6e00ef5a6683.png">

The smallest assembled square of Tetris pieces will be produced on the standard output, with letters A - Z representing the order of the Tetris pieces in the list and placed on the board.

* Because there are only 26 letters in the alphabet, the list of Tetris pieces is limited to 26 when reading the input file.
* Please refer to the example to the right

# Usage
*Please ensure you have gcc compiler and that you are using a Unix/Linux terminal*
1. Open Terminal and clone Repository into desired location
2. Type "make" in the command line to create the executable program called "fillit"
3. Run the executable by typing "./fillit file" where file is the text file containing the list of Tetris pieces 
 * Typing "./fillit input" should give the below result: 
 <img width="100" alt="Screen Shot 2020-03-05 at 5 18 21 PM" src="https://user-images.githubusercontent.com/49771001/76040890-79227d00-5f05-11ea-9348-129b0f0ea0b1.png">

# Further Thoughts
* Program can be further optimized by storing each Tetris piece as bits instead of an integer array in our data structure

# References 
* Jinyu Liu (Partner for this project)
* [Medium blog by Beth Locke](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909)
