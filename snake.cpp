#include <iostream>
#include <conio.h>
#include <windows.h>


bool gameOver;

// set boundary width and height
const int width = 80;
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

    //std::cout << "\x1B[2J\x1B[H";

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
        }
        std::cout << std::endl; 
    }

        for (int i = 0; i < width + 2; i++) 
        {
            std::cout << "-";
        }

        std::cout << std::endl;
        

        std::cout << player << "'s Score: " << score << std::endl;

}

void UpdateGame()
{
    int lastX = tailX[0];
    int lastY = tailY[0];
    int last2X, last2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < lenTail; i++)
    {
        last2X = tailX[i];
        last2Y = tailY[i];
        tailX[i] = lastX;
        tailY[i] = lastY;
        lastX = last2X;
        lastY = last2Y;
    }

    // Check the snake direction and move accordingly
    switch (snakeDir) 
    {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    }

    // See whether the snake touches the wall
    if (x >= width || x < 0 || y >= height || y < 0)
    {
        gameOver = true;
    }

    // See whether the snake touched the tail
    for (int i = 0; i < lenTail; i++) 
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }

    // See whether the snake touches the food
    if (x == fruitX && y == fruitY) 
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        lenTail++;
    }
}

void UserInput() 
{
    if (_kbhit())
    {
        // If a key is pressed, get the key which was pressed
        switch (_getch())
        {
            case 'w':
                snakeDir = UP;
                break;
            case 's':
                snakeDir = DOWN;
                break;
            case 'a':
                snakeDir = LEFT;
                break;
            case 'd':
                snakeDir = RIGHT;
                break;
        }
    }
}


int main()
{
    std::string player;
    std::cout << "What is your name?";
    std::cin >> player;

    GameInit();

    while (!gameOver)
    {
        RenderGame(player);
        UserInput();
        UpdateGame();

        Sleep(150);
    }

    return 0;
}

