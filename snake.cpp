#include <iostream>
#include <conio.h>
#include <windows.h>

bool gameOver;

// set boundary width and height
const int width = 60;
const int height = 20;

// initialise the other necessary variables.
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; // squares taken up by tail
int lenTail; // length of the snake's tail

// initialise snake direction variable
enum snakeDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
snakeDirection snakeDir;



void GameInit()
{
    gameOver = false;
    snakeDir = STOP;
    
    // start in the middle of the screen
    x = width/2;
    y = height/2;

    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;

}

void RenderGame(std::string player) 
{
    system("cls"); // clear the terminal output

    for (int i = 0; i < width + 2; i++) 
        std::cout << "-";
        std::cout << std::endl;

    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j <= width; j++) 
        {
            if (j == 0 || j == width) 
            {
                std::cout << "|";
            }
            if (i == y && j == x)
            {
                std::cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                std::cout << "#";
            } 
            else 
            {
                bool onTail = false;
                for (int k = 0; k < lenTail; k++) 
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        onTail = true;
                    }
                }
                if (!onTail)
                {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;    
        }
        
        for (int i = 0; i < width + 2; i++) 
        {
            std::cout << std::endl;
        }

        std::cout << player << "'s Score: " << score << std::endl;

    }
}

void updateGame()
{
    int lastX = tailX[0];
    int lastY = tailY[0];
    int last2X, last2Y;
    lastX = x;
    lastY = y;
}


