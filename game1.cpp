//////////////////////////////////////bbbbbbbbbooooooooooooommmmmmmmmbbbbbbbbbbbbbbbbbbb//////////////////////////
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cmath>
using namespace std;
                        // Pre-game menu and its functionalities
void header(int x, int y);              // Display header
void menu();                            // Display main menu
// int ValidateInput(int optcount, int x, int y); // Get user menu choice
void mode(char opt);                     // Set game mode
bool validation(string);                // Validate user input
void levelendscreen(string teXt);       // Display end-level screen
void Level1Selection();                 // Allow level selection
void level2Selection();
void print3Characters(string arr[][3], int size, string color, int x, int y); // Display characters (3x3 grid)
void print4Characters(string arr[][4], int size, string color, int x, int y); // Display characters (4x4 grid)
void print5Characters(string arr[][5], int size, string color, int x, int y); // Display characters (5x5 grid)

// Enemy functionalities
void printEnemy(int x, int y);    // Display enemy
void displayEnemy2(int x, int y); // Display second type of enemy

// Display third type of enemy facing right and left
void displayEnemy3Right(int x, int y);
void displayEnemy3Left(int x, int y);
void enemy1Movement();           // Movement logic for enemy type 1
void enemy2Movement();           // Movement logic for enemy type 2
void enemy3Movement();           // Movement logic for enemy type 3
void enemy3Direction();          // Direction change for enemy type 3
void enemy3Death(int x, int y);  // Handling enemy type 3 death
void enemy1Health(int x, int y); // Display enemy type 1 health
void enemy1Death(int x, int y);  // Handle enemy death
void enemy2Death(int x, int y);
void enemy1HealthDamage(int damage); // Inflict damage to enemy type 1
void enemy2Health(int x, int y);     // Display enemy type 2 health
void enemy2HealthDamage(int damage); // Inflict damage to enemy type 2
void enemy3Health(int x, int y);     // Display enemy type 3 health
void enemy3HealthDamage(int damage); // Inflict damage to enemy type 3
void eraseEnemy1(int x, int y);      // Remove enemy type 1
void eraseEnemy2(int x, int y);      // Remove enemy type 2
void eraseEnemy3(int x, int y);      // Remove enemy type 3

// Enemy bullets functionalities
void removeEnemyBullets(int c, string direction); // Remove enemy bullets
void enemyBulletStarter();                        // Initialize enemy bullets
void resetEnemyBullets();                         // Reset enemy bullets
void enemyBullet(int x, int y, string direction); // Create enemy bullet
void displayEnemyBullets(int x, int y);           // Display enemy bullet
void enemyBulletMovement();                       // Handle enemy bullet movement
void enemyBulletCollision();                      // Handle enemy bullet collision

// Player functionalities
void displayRightPlayer(int x, int y); // Display player facing right
void displayLeftPlayer(int x, int y);  // Display player facing left
void playerMovement();                 // Handle player movement
void playerDirection();                // Handle player direction change
void erasePlayer(int x, int y);        // Erase player

// Player bullet functionalities
void playerBulletStarter();                        // Initialize player bullets
void removePlayerBullets(int c, string direction); // Remove player bullets
void resetPlayerBullets();                         // Reset player bullets
void playerBulletCollision();                      // Handle bullet collision
void playerBulletMovement();                       // Handle bullet movement
void bullet(int x, int y);                         // Create bullet
void erasePlayerBullet(int x, int y);              // Erase bullet

// On-screen navigators
void gotoxy(int x, int y);                  // Move cursor to (x, y) position
char getCharAtxy(short int x, short int y); // Get character at (x, y) position

// Basic game functions
void addScore();                                   // Add score
void magazineCollision(int x, int y);              // Handle magazine collision(magzine ko touch kre gi to goliya brh jayen gi)
void pillCollision(int x, int y);                  // Handle pill collision(pill ko touch kre gi to health brh jayen gi)
void checkItems(int x, int y);                     // Check collected items (health)
void playerHealth(int x, int y);                   // Display player health
void playerHealthDamage(int damage, int x, int y); // damage to player
void displayScore();                               // Display current score
void displayBulletCount();                         // Display remaining bullet count
void eraser(int x, int y);                         // Erase at (x, y) position

// Functions for InnerMaps
void Maze(); // Draw game Maze
void headbar();  // Display top bar
void InnerMap();      // Display InnerMap
void innerMap2();
void InnerMapBoxes(int x, int y, int size);                      // Display InnerMapBoxes
void verticalInnerMapBoxes(int x, int y, int width, int height); // Display vertical InnerMapBoxes
void placeObjects();                                        // Initialize game objects
void RowsOfMaze(int x, int y);                               // Draw outer rows
void ColumnsOfMaze(int x, int y);                               // Draw inner rows
void healthPill(int x, int y);                              // Display health pill
void magazine(int x, int y);                                // Display magazine
void displayHealthPill();                                   // Display health pill status

// End Key Functions

void printEndKey(int x, int y);
void eraseEndKey(int x, int y);
void touchEndKey(int x, int y);
// Levels

void displayLevel(int x);
void level_1(); // Level 1 gameplay logic

void level_2(); // Level 2 gameplay logic

// Coordinates of characters
int pX, pY, eX, eY, eX2, eY2, eX3, eY3;

// Timer for enemy 3 movement
int enemy3Timer;

// Random values for enemy movements
int randomValue;

// Counts for various types of bullets that enemy or player has fired
int rightPlayerBulletCount, leftPlayerBulletCount, playerBulletCount, rightEnemyBulletCount, leftEnemyBulletCount;

// Health variables for characters
int maxPlayerHealth, maxEnemy1Health, maxEnemy2Health, maxEnemy3Health;

// Game score
int score;
// Bomb Coordinates
int bombX=160;int bombY=17;
// Coordinates for items on the InnerMap
int healtendKeyX, healtendKeyY, magazineX, magazineY, levelNumber;

// End Key
int endKeyX, endKeyY;
// ASCII characters used for display
char box = 219;
char heart = static_cast<char>(3);
char Magazine = static_cast<char>(178);
char endKey = static_cast<char>(175);

// Direction tracking for characters
string playerdirection = "right", enemy1direction = "down", enemy2direction = "down", enemy3direction = "right";

// Player's name
string playername1 = "Player";

// Level state tracking
bool LevelRunning;
bool enemy1IsLive, enemy2IsLive, enemy3IsLive, playerIsLive;

// Arrays for player and enemy bullets' coordinates
int playerRightBulletX[1000] = {-1}, playerRightBulletY[1000] = {-1},
 playerLeftBulletX[1000] = {-1}, playerLeftBulletY[1000] = {-1};
bool activatePlayerRightBullet[1000], activatePlayerLeftBullet[1000];
int enemyRightBulletX[10000], enemyRightBulletY[10000], enemyLeftBulletX[10000],
enemyLeftBulletY[10000];
bool activateEnemyRightBullet[10000], activateEnemyLeftBullet[10000];

int main()
{
    menu();
}

void       screenFrame()
{
    // Set up screen for the level
    playername1 = "Player";
    system("cls");
    headbar();
    Maze();//
}
//////////////////////////////////////////////// LEVEL 1 ///////////////////////////////////////////////////////////////////////////////////
void level_1()
{
    // Variables for level 1
    int timer = 0;       // Timer for enemy 3 random direction
    int belletTimer = 0; // Timer for player's bullet removal

    // Initial assignments for global variables
    healtendKeyX = 51, healtendKeyY = 20, magazineX = 95, magazineY = 21;
    rightPlayerBulletCount = 0, leftPlayerBulletCount = 0, playerBulletCount = 500, rightEnemyBulletCount = 0, leftEnemyBulletCount = 0;
    maxPlayerHealth = 100, maxEnemy1Health = 100, maxEnemy2Health = 100, maxEnemy3Health = 100, score = 0, enemy3Timer = 0;
    pX = 10, pY = 48, eX = 30, eY = 20, eX2 = 170, eY2 = 19, eX3 = 90, eY3 = 27, levelNumber = 1;
    enemy1IsLive = true, enemy2IsLive = true, enemy3IsLive = true, playerIsLive = true;
    LevelRunning = true;

    // Set up the level interface
    screenFrame();//
    InnerMap();//
    printEnemy(eX, eY);
    displayEnemy2(eX2, eY2);
    displayEnemy3Right(eX3, eY3);
    displayLeftPlayer(pX, pY);
    displayLevel(levelNumber);
    playerBulletStarter();////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    enemyBulletStarter();////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Main game loop for level 1
    while (LevelRunning)
    {
        // Player's movement and actions
        if (maxPlayerHealth > 0 && (enemy1IsLive == true || enemy2IsLive == true || enemy3IsLive == true))
        {
            playerMovement();
        }
        else if (enemy1IsLive == false && enemy2IsLive == false && enemy3IsLive == false)
        {

            LevelRunning = true;
            levelendscreen("  CONGRATULATIONS! LEVEL PASSED ");
        }
        else
        {
            LevelRunning = false;
            playerIsLive = false;
            levelendscreen("  Game Over! ");
        }

        // Enemy 1 movements and actions
        if (maxEnemy1Health > 0)
        {
            enemy1Movement();//
        }
        else
        {
            enemy1Death(eX, eY);
            enemy1IsLive = false;
        }

        // Enemy 2 movements and actions
        if (maxEnemy2Health > 0)
        {
            enemy2Movement();
        }
        else
        {
            enemy2Death(eX2, eY2);
            enemy2IsLive = false;
        }

        // Enemy 3 movements and actions
        if (maxEnemy3Health > 0)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        {
            if (timer == 5)
            {
                randomValue = rand() % 4;
                timer = 0;
            }
            enemy3Direction();
        }
        else
        {
            enemy3Death(eX3, eY3);
            enemy3IsLive = false;
        }

        // Reset timers and handle bullet movements and collisions
        if (enemy3Timer == 120)
        {
            enemy3Timer = 0;
        }
        if (belletTimer == 20)
        {
            resetPlayerBullets();
            resetEnemyBullets();
            belletTimer = 0;
        }
        // Display health and handle bullet movements
        gotoxy(1, 0);
        playerHealth(45, 8);
        enemy1Health(45, 10);
        enemy2Health(45, 11);
        enemy3Health(45, 12);
        playerBulletMovement();
        playerBulletCollision();
        enemyBulletMovement();
        enemyBulletCollision();
        timer++;
        enemy3Timer++;
        belletTimer++;
        Sleep(50);
    }
    LevelRunning = false;
}

void level_2()
{
    // Variables for level 2
    int timer = 0;       // Timer for enemy 3 random direction
    int belletTimer = 0; // Timer for player's bullet removal

    // Initial assignments for global variables
    healtendKeyX = 49, healtendKeyY = 20, magazineX = 154, magazineY = 26, levelNumber = 2;
    rightPlayerBulletCount = 0, leftPlayerBulletCount = 0, playerBulletCount = 500,//Number of total bullets
    rightEnemyBulletCount = 0, leftEnemyBulletCount = 0,score = 0, enemy3Timer = 0;
    maxPlayerHealth = 100, maxEnemy1Health = 100, maxEnemy2Health = 100, maxEnemy3Health = 100;//Total Healths Of Characters
    pX = 10, pY = 48, eX = 30, eY = 20, eX2 = 170, eY2 = 19, eX3 = 90, eY3 = 27, endKeyX = 165, endKeyY = 15;// initiall printing coordinates
    enemy1IsLive = true, enemy2IsLive = true, enemy3IsLive = true, playerIsLive = true, LevelRunning = true;

    // Set up the level interface
    screenFrame();
    innerMap2();
    printEnemy(eX, eY);
    displayEnemy2(eX2, eY2);
    displayEnemy3Right(eX3, eY3);
    displayLeftPlayer(pX, pY);
    displayLevel(levelNumber);
    playerBulletStarter();
    enemyBulletStarter();

    // Main game loop for level 2
    while (LevelRunning)
    {
        // Player's movement and actions
        if (maxPlayerHealth > 0)
        {
            if (enemy1IsLive == false && enemy2IsLive == false && enemy3IsLive == false)
            {
                printEndKey(endKeyX,endKeyY);
            }
            playerMovement();
        }
        else if (maxPlayerHealth == 0 || (pX==160 && pX==17))
        {
            LevelRunning = false;
            playerIsLive = false;
            levelendscreen("  Game Over! ");
            break;
        }

        // Enemy 1 movements and actions
        if (maxEnemy1Health > 0)
        {
            enemy1Movement();
        }
        else
        {
            enemy1Death(eX, eY);
            enemy1IsLive = false;
        }

        // Enemy 2 movements and actions
        if (maxEnemy2Health > 0)
        {
            enemy2Movement();
        }
        else
        {
            enemy2Death(eX2, eY2);
            enemy2IsLive = false;
        }

        // Enemy 3 movements and actions
        if (maxEnemy3Health > 0)////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        {
            if (timer == 5)
            {
                randomValue = rand() % 4;
                timer = 0;
            }
            enemy3Direction();
        }
        else
        {
            enemy3Death(eX3, eY3);
            enemy3IsLive = false;
        }

        // Reset timers and handle bullet movements and collisions
        if (enemy3Timer == 120)
        {
            enemy3Timer = 0;
        }
        if (belletTimer == 20)//
        {
            resetPlayerBullets();
            resetEnemyBullets();
            belletTimer = 0;
        }
        // Display health and handle bullet movements
        gotoxy(1, 0);
        playerHealth(45, 8);
        enemy1Health(45, 10);
        enemy2Health(45, 11);
        enemy3Health(45, 12);
        playerBulletMovement();
        playerBulletCollision();
        enemyBulletMovement();
        enemyBulletCollision();
        timer++;
        enemy3Timer++;
        belletTimer++;
        Sleep(50);
    }
    LevelRunning = false;
}

void playerMovement() // movement functionalities of player
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        checkItems(pX + 3, pY);
        if (getCharAtxy(pX + 3, pY) == ' ' && getCharAtxy(pX + 3, pY + 1) == ' ' && getCharAtxy(pX + 3, pY + 2) == ' ')
        {
            erasePlayer(pX, pY);
            pX++;
            playerdirection = "right";
            displayRightPlayer(pX, pY);
        }
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        checkItems(pX - 1, pY);
        if (getCharAtxy(pX - 1, pY) == ' ' && getCharAtxy(pX - 1, pY + 1) == ' ' && getCharAtxy(pX - 1, pY + 2) == ' ')
        {
            erasePlayer(pX, pY);
            pX--;
            playerdirection = "left";
            displayLeftPlayer(pX, pY);
        } 
    }
    else if (GetAsyncKeyState(VK_UP))
    {
        checkItems(pX, pY - 1);
        if (getCharAtxy(pX, pY - 1) == ' ' && getCharAtxy(pX + 1, pY - 1) == ' ' && getCharAtxy(pX + 2, pY - 1) == ' ')
        {
            erasePlayer(pX, pY);
            pY--;
            playerDirection();
        }
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        checkItems(pX, pY + 3);
        if (getCharAtxy(pX, pY + 3) == ' ' && getCharAtxy(pX + 1, pY + 3) == ' ' && getCharAtxy(pX + 2, pY + 3) == ' ')
        {
            erasePlayer(pX, pY);
            pY++;
            playerDirection();
        }
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (playerBulletCount > 0 && (getCharAtxy(pX, pY) == ' ' && getCharAtxy(pX - 1, pY + 1) == ' ' && getCharAtxy(pX + 3, pY + 1) == ' '))
        {
            bullet(pX, pY);// fire a bullet
            playerBulletCount--;// decrease the player's bullet count
            displayBulletCount();// update display total bullrts on the top of screen
        }
    }
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        Sleep(500);
        menu();
    }
}

void playerDirection()
{
    // Determines direction of player and calls the respective side face function
    if (playerdirection == "right")
    {
        displayRightPlayer(pX, pY);
    }
    else if (playerdirection == "left")
    {
        displayLeftPlayer(pX, pY);
    }
}

void displayRightPlayer(int x, int y)
{
    // Prints player facing right side of the console
    string body[3][3] = {{" ", "0", " "}, {"(", "=", ">"}, {"/", "/", " "}};
    print3Characters(body, 3, "\33[32m", x, y);
}

void displayLeftPlayer(int x, int y)
{
    // Prints player facing left side of the console
    string body[3][3] = {{" ", "0", " "}, {"<", "=", ")"}, {" ", "\\", "\\"}};
    print3Characters(body, 3, "\33[32m", x, y);
}

void erasePlayer(int x, int y)
{
    // Erases player sprite from console
    string body[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
    print3Characters(body, 3, "\33[36m", x, y);
}    

void print3Characters(string arr[][3], int size, string color, int x, int y)
{
    // Prints characters in a 3x3 grid
    int bx;
    for (int i = 0; i < size; i++)
    {
        bx = x;
        for (int j = 0; j < 3; j++)
        {
            gotoxy(bx, y);
            cout << color << arr[i][j] << "\33[0m";
            bx++;//Increments the x-coordinate for the next character in the same row.
        }
        y++;//y-coordinate is incremented to move to the next row.
    }
}

void print4Characters(string arr[][4], int size, string color, int x, int y)
{
    // Prints characters in a 3x4 grid
    int bx;
    for (int i = 0; i < size; i++)
    {
        bx = x;
        for (int j = 0; j < 4; j++)
        {
            gotoxy(bx, y);
            cout << color << arr[i][j] << "\33[0m";
            bx++;
        }
        y++;
    }
}

void print5Characters(string arr[][5], int size, string color, int x, int y)
{
    // Prints characters in a 3x5 grid
    int bx;
    for (int i = 0; i < size; i++)//rows
    {
        bx = x;
        for (int j = 0; j < 5; j++)//columns
        {
            gotoxy(bx, y);
            cout << color << arr[i][j] << "\33[0m";
            bx++;
        }
        y++;
    }
}

void printEnemy(int x, int y) // printing enemy 1
{
    string body[4][4] = {{"(", "O", " ", " "}, {"\\", "=", "=", ">"}, {" ", "^", "'", " "}, {"/", " ", "|", " "}};
    print4Characters(body, 4, "\33[96m", x, y);
}

void eraseEnemy1(int x, int y) // erase enemy 1
{
    string body[4][4] = {{" ", " ", " ", " "}, {" ", " ", " ", " "}, {" ", " ", " ", " "}, {" ", " ", " ", " "}};
    print4Characters(body, 4, "\33[96m", x, y);
}

void enemy1Death(int x, int y) // enemy 1 death
{
    string body[4][4] = {{"X", "X", "X", "X"}, {"X", "X", "X", "X"}, {"X", "X", "X", "X"}, {"X", "X", "X", "X"}};
    print4Characters(body, 4, "\33[32m", x, y);
}
void enemy1Movement() // movement functionality of enemy 1
{
    if (enemy1direction == "down") // To change enemy direction 
    {
        if (eY == 25)
        {
            enemy1direction = "up";
        }
        else if (eY == pY)// fire iff player x and enemy x matches
        {
            enemyBullet(eX + 4, eY + 1, "right");
        }
        else
        {
            // simple enemy movent logiccs
            if (getCharAtxy(eX, eY + 5) == ' ' && getCharAtxy(eX + 2, eY + 5) == ' ' && getCharAtxy(eX + 3, eY + 5) == ' ' && getCharAtxy(eX + 4, eY + 5) == ' ')//?
            {
                eraseEnemy1(eX, eY);
                eY++;
                printEnemy(eX, eY);
            }
        }
    }

    else if (enemy1direction == "up")
    {
        if (eY == 15)
        {
            enemy1direction = "down";
        }
        else if (eY == pY)
        {
            enemyBullet(eX + 4, eY + 1, "right");
        }
        else
        {
            if (getCharAtxy(eX, eY - 1) == ' ' && getCharAtxy(eX + 2, eY - 1) == ' ' && getCharAtxy(eX + 3, eY - 1) == ' ' && getCharAtxy(eX + 4, eY - 1))
            {
                eraseEnemy1(eX, eY);
                eY--;
                printEnemy(eX, eY);
            }
        }
    }
}

void displayEnemy2(int x, int y) // printing enemy 2
{
    string body[3][5] = {{" ", "_", "_", "_", " "},
        {"<", "=", "@", "|", ")"},
        {" ", "O", "/", "\\", "O"}};
    print5Characters(body, 3, "\33[93m", x, y);
}

void eraseEnemy2(int x, int y) // erasing enemy 2
{
    string body[3][5] = {{" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}};
    print5Characters(body, 3, "\33[93m", x, y);
}
void enemy2Death(int x, int y) //// enemy 2 death

{
    string body[3][5] = {{"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}};
    print5Characters(body, 3, "\33[93m", x, y);
}
void enemy2Movement() // movement functionality of enemy 2
{
    if (enemy2direction == "down")
    {
        if (eY2 == 50)
        {
            enemy2direction = "up";
        }
        else if (eY2 == pY)
        {
            enemyBullet(eX2, eY2, "left");
        }
        else
        {
            if (getCharAtxy(eX2, eY2 + 4) == ' ' && getCharAtxy(eX2 + 2, eY2 + 4) == ' ' && getCharAtxy(eX2 + 4, eY2 + 4) == ' ')
            {
                eraseEnemy2(eX2, eY2);
                eY2++;
                displayEnemy2(eX2, eY2);
            }
        }
    }
    else if (enemy2direction == "up")
    {
        if (eY2 == 19)
        {
            enemy2direction = "down";
        }
        else if (eY2 == pY)
        {
            enemyBullet(eX2, eY2, "left");
        }
        else
        {
            if (getCharAtxy(eX2, eY2 - 1) == ' ' && getCharAtxy(eX2 + 3, eY2 - 1) == ' ' && getCharAtxy(eX2 + 4, eY2 - 1))
            {
                eraseEnemy2(eX2, eY2);
                eY2--;
                displayEnemy2(eX2, eY2);
            }
        }
    }
}

void displayEnemy3Right(int x, int y) // printing enemy 3 right face
{
    string body[3][5] = 
    {
        {" ", " ", "^", " ", " "},
        {"<", "=", "=", "=", ">"},
        {" ", " ", ",", " ", " "}
    };
    print5Characters(body, 3, "\33[95m", x, y);
}

void displayEnemy3Left(int x, int y) // printing enemy 3 left face
{
    string body[3][5] = 
    {
        {" ", " ", "^", " ", " "},
        {"<", "=", "=", "=", ">"},
        {" ", " ", "'", " ", " "}
    };
    print5Characters(body, 3, "\33[95m", x, y);
}

void eraseEnemy3(int x, int y) // erase enemy 3
{
    string body[3][5] = {{" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}};
    print5Characters(body, 3, "\33[95m", x, y);
}

void enemy3Death(int x, int y) // enemy 3 death
{
    string body[3][5] = {{"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}};
    print5Characters(body, 3, "\33[95m", x, y);
}

void enemy3Direction() // control direction of enemy 3
{
    // for shooting player if their y coordinates match
    if ((eY3 == pY || eY3 == pY - 1 || eY3 == pY - 2 || eY3 == pY + 3 || eY3 == pY + 1 || eY3 == pY + 2) && enemy3Timer <= 60)
    {
        if (eX3 > pX)
        {
            displayEnemy3Left(eX3, eY3);
            enemyBullet(eX3 - 1, eY3, "left");
        }
        else if (eX3 < pX)
        {
            displayEnemy3Right(eX3, eY3);
            enemyBullet(eX3 + 5, eY3 + 1, "right");
        }
        if (enemy3Timer == 60)
        {
            enemy3Timer = 100;
        }
    }

    // for random movement of enemy 3 in case it is not shooting player
    else
    {
        if (randomValue == 0)
        {
            enemy3direction = "left";
        }
        else if (randomValue == 1)
        {
            enemy3direction = "right";
        }
        else if (randomValue == 2)
        {
            enemy3direction = "up";
        }
        else if (randomValue == 3)
        {
            enemy3direction = "down";
        }
        enemy3Movement();
    }
}

void enemy3Movement() // moves enemy 3
{
    if (enemy3direction == "right")
    {
        if (getCharAtxy(eX3 + 5, eY3) == ' ' && getCharAtxy(eX3 + 5, eY3 + 1) == ' ' && getCharAtxy(eX3 + 5, eY3 + 2) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eX3++;
            displayEnemy3Right(eX3, eY3);
        }
        else
        {
            enemy3direction = "left";
        }
    }
    else if (enemy3direction == "left")
    {
        if (getCharAtxy(eX3 - 1, eY3) == ' ' && getCharAtxy(eX3 - 1, eY3 + 1) == ' ' && getCharAtxy(eX3 - 1, eY3 + 2) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eX3--;
            displayEnemy3Left(eX3, eY3);
        }
        else
        {
            enemy3direction = "right";
        }
    }
    else if (enemy3direction == "up")
    {
        if (getCharAtxy(eX3, eY3 - 1) == ' ' && getCharAtxy(eX3 + 2, eY3 - 1) == ' ' && getCharAtxy(eX3 + 3, eY3 - 1) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eY3--;
            displayEnemy3Left(eX3, eY3);
        }
        else
        {
            enemy3direction = "down";
        }
    }
    else if (enemy3direction == "down")
    {
        if (getCharAtxy(eX3, eY3 + 3) == ' ' && getCharAtxy(eX3 + 2, eY3 + 3) == ' ' && getCharAtxy(eX3 + 3, eY3 + 3) == ' ' && getCharAtxy(eX3 + 4, eY3 + 3) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eY3++;
            displayEnemy3Left(eX3, eY3);
        }
        else
        {
            enemy3direction = "up";
        }
    }
}

void displayEnemyBullets(int x, int y) // prints enemy bullets
{
    gotoxy(x, y);
    cout << "\33[31m"
         << "+"
         << "\33[0m";
}

void enemyBulletStarter() // start enemy bullets
{
    for (int i = 0; i < 10000; i++)
    {
        activateEnemyRightBullet[i] = false;
        activateEnemyLeftBullet[i] = false;
    }
}

void enemyBullet(int x, int y, string direction) // generates an enemy bullet and add indeX in the array also activate the bullet
{
    // generating right side bullets of enemies
    if (direction == "right")
    {
        enemyRightBulletX[rightEnemyBulletCount] = x;
        enemyRightBulletY[rightEnemyBulletCount] = y;
        activateEnemyRightBullet[rightEnemyBulletCount] = true;
        rightEnemyBulletCount++;
        displayEnemyBullets(x, y);//
    }

    // generating left side bullets of enemies
    else if (direction == "left")
    {
        enemyLeftBulletX[leftEnemyBulletCount] = x - 1;
        enemyLeftBulletY[leftEnemyBulletCount] = y + 1;
        activateEnemyLeftBullet[leftEnemyBulletCount] = true;
        leftEnemyBulletCount++;
        displayEnemyBullets(x - 1, y + 1);
    }
}

void enemyBulletMovement() // move bullets of enemies
{
    // for right hand side bullet
    for (int i = 0; i < rightEnemyBulletCount; i++)
    {
        if (activateEnemyRightBullet[i])
        {
            erasePlayerBullet(enemyRightBulletX[i], enemyRightBulletY[i]);
            enemyRightBulletX[i] += 1;
            displayEnemyBullets(enemyRightBulletX[i], enemyRightBulletY[i]);
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftEnemyBulletCount; i++)
    {
        if (activateEnemyLeftBullet[i])
        {
            erasePlayerBullet(enemyLeftBulletX[i], enemyLeftBulletY[i]);
            enemyLeftBulletX[i] -= 1;
            displayEnemyBullets(enemyLeftBulletX[i], enemyLeftBulletY[i]);
        }
    }
}

void enemyBulletCollision() // enemy bullet collsion detection
{
    // for right hand side bullet
    for (int i = 0; i < rightEnemyBulletCount; i++)//
    {
        if (activateEnemyRightBullet[i])// Check if the right bullet is active
        {
            int x = enemyRightBulletX[i], y = enemyRightBulletY[i];
            char next = getCharAtxy(x + 1, y);
            if ((x + 1 == pX + 1 && y == pY) || (x + 1 == pX && y == pY + 1) || (x + 1 == pX + 2 && y == pY + 1) || (x + 1 == pX && y == pY + 2) || (x + 1 == pX + 1 && y == pY + 2) || (x + 1 == pX + 2 && y == pY + 2))
            {
                erasePlayerBullet(x, y);
                if (i)
                {
                    playerHealthDamage(2, 45, 8);
                }
                removeEnemyBullets(i, "right");
            }
            else if (next != ' ')
            {
                erasePlayerBullet(x, y);
                removeEnemyBullets(i, "right");
            }
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftEnemyBulletCount; i++)
    {
        if (activateEnemyLeftBullet[i])
        {
            int x = enemyLeftBulletX[i], y = enemyLeftBulletY[i];
            char next = getCharAtxy(x - 1, y);
            if ((x - 1 == pX + 1 && y == pY) || (x - 1 == pX && y == pY + 1) || (x - 1 == pX + 2 && y == pY + 1) || (x - 1 == pX && y == pY + 2) || (x - 1 == pX + 1 && y == pY + 2) || (x - 1 == pX + 2 && y == pY + 2))
            {
                erasePlayerBullet(x, y);
                if (maxPlayerHealth)
                {
                    playerHealthDamage(2, 45, 8);
                }
                removeEnemyBullets(i, "left");
            }
            else if (next != ' ')
            {
                erasePlayerBullet(x, y);
                removeEnemyBullets(i, "left");
            }
        }
    }
}

void removeEnemyBullets(int c, string direction) // removes enemy bullet from the arrays
{
    // for right hand side bullet
    if (direction == "right")
    {
        activateEnemyRightBullet[c] = false;
    }

    // for left hand side bullet
    else if (direction == "left")
    {
        activateEnemyLeftBullet[c] = false;
    }
}

void resetEnemyBullets()
{
    // for right bullets
    for (int i = 0; i < rightEnemyBulletCount; i++)
    {
        if (!activateEnemyRightBullet[i])
        {
            for (int j = i; j < rightEnemyBulletCount - 1; j++)
            {
                enemyRightBulletX[j] = enemyRightBulletX[j + 1];
                enemyRightBulletY[j] = enemyRightBulletY[j + 1];
                activateEnemyRightBullet[j] = activateEnemyRightBullet[j + 1];
            }
            rightEnemyBulletCount--;
        }
    }

    // for left bullets
    for (int i = 0; i < leftEnemyBulletCount; i++)
    {
        if (!activateEnemyLeftBullet[i])
        {
            for (int j = i; j < leftEnemyBulletCount - 1; j++)
            {
                enemyLeftBulletX[j] = enemyLeftBulletX[j + 1];
                enemyLeftBulletY[j] = enemyLeftBulletY[j + 1];
                activateEnemyLeftBullet[j] = activateEnemyLeftBullet[j + 1];
            }
            leftEnemyBulletCount--;
        }
    }
}

void erasePlayerBullet(int x, int y) // erases the bullet
{
    gotoxy(x, y);
    cout << " ";
}

void printbullet(int x, int y) // prints the bullet
{
    gotoxy(x, y);
    cout << "\33[31m"
         << "."
         << "\33[0m";
}

void bullet(int x, int y) // generates a player bullet and adds bullet indeX in the array
{
    // generating right hand side bullet
    if (playerdirection == "right")
    {
        playerRightBulletX[rightPlayerBulletCount] = x + 3;
        playerRightBulletY[rightPlayerBulletCount] = y + 1;
        activatePlayerRightBullet[rightPlayerBulletCount] = true;// to fore a bullet
        rightPlayerBulletCount++;
        printbullet(x + 3, y + 1);
    }

    // generating left hand side bullet
    else if (playerdirection == "left")
    {
        playerLeftBulletX[leftPlayerBulletCount] = x - 1;
        playerLeftBulletY[leftPlayerBulletCount] = y + 1;
        activatePlayerLeftBullet[leftPlayerBulletCount] = true;
        leftPlayerBulletCount++;
        printbullet(x - 1, y + 1);
    }
}

void playerBulletMovement() // moves all the bullets of player
{
    // for right hand side bullet
    for (int i = 0; i < rightPlayerBulletCount; i++)
    {
        if (activatePlayerRightBullet[i])
        {
            erasePlayerBullet(playerRightBulletX[i], playerRightBulletY[i]);
            playerRightBulletX[i] += 1;
            printbullet(playerRightBulletX[i], playerRightBulletY[i]);
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftPlayerBulletCount; i++)
    {
        if (activatePlayerLeftBullet[i])
        {
            erasePlayerBullet(playerLeftBulletX[i], playerLeftBulletY[i]);
            playerLeftBulletX[i] -= 1;
            printbullet(playerLeftBulletX[i], playerLeftBulletY[i]);
        }
    }
}

void playerBulletCollision() // Remove the bullet in case of collision with the enemy
{
    // for right hand side bullet
    for (int i = 0; i < rightPlayerBulletCount; i++)
    {
        if (activatePlayerRightBullet[i])
        {
            int x = playerRightBulletX[i], y = playerRightBulletY[i];
            char next = getCharAtxy(x + 1, y);
            if ((x + 1 == eX && y == eY) || (x + 1 == eX + 1 && y == eY) || (x + 1 == eX && y == eY + 1) || (x + 1 == eX + 4 && y == eY + 1) || (x + 1 == eX + 1 && y == eY + 2) || (x + 1 == eX + 2 && y == eY + 2) || (x + 1 == eX && y == eY + 3) || (x + 1 == eX + 1 && y == eY + 3) || (x + 1 == eX + 2 && y == eY + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy1IsLive)
                {
                    addScore();
                    enemy1HealthDamage(5);
                }
                removePlayerBullets(i, "right");
            }
            else if ((x + 1 == eX2 && y == eY2) || (x + 1 == eX2 && y == eY2 + 1) || (x + 1 == eX2 && y == eY2 + 2) || (x + 1 == eX2 && y == eY2 + 3) || (x + 1 == eX2 + 2 && y == eY2) || (x + 1 == eX2 + 2 && y == eY2 + 1) || (x + 1 == eX2 + 2 && y == eY2 + 2) || (x + 1 == eX2 + 2 && y == eY2 + 3) || (x + 1 == eX2 + 1 && y == eY2) || (x + 1 == eX2 + 1 && y == eY2 + 1) || (x + 1 == eX2 + 1 && y == eY2 + 2) || (x + 1 == eX2 + 1 && y == eY2 + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy2IsLive)
                {
                    addScore();
                    enemy2HealthDamage(5);
                }
                removePlayerBullets(i, "right");
            }
            else if ((x + 1 == eX3 && y == eY3) || (x + 1 == eX3 + 1 && y == eY3) || (x + 1 == eX3 + 2 && y == eY3) || (x + 1 == eX3 + 3 && y == eY3) || (x + 1 == eX3 && y == eY3 + 1) || (x + 1 == eX3 + 2 && y == eY3 + 1) || (x + 1 == eX3 + 3 && y == eY3 + 1) || (x + 1 == eX3 && y == eY3 + 2) || (x + 1 == eX3 + 3 && y == eY3 + 2) || (x + 1 == eX3 && y == eY3 + 3) || (x + 1 == eX3 + 3 && y == eY3 + 3) || (x + 1 == eX3 && y == eY3 + 4) || (x + 1 == eX3 + 3 && y == eY3 + 4))
            {
                erasePlayerBullet(x, y);
                if (enemy3IsLive)
                {
                    addScore();
                    enemy3HealthDamage(5);
                }
                removePlayerBullets(i, "right");
            }
            else if (next != ' ')
            {
                erasePlayerBullet(x, y);
                removePlayerBullets(i, "right");
            }
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftPlayerBulletCount; i++)
    {
        if (activatePlayerLeftBullet[i])
        {
            int x = playerLeftBulletX[i], y = playerLeftBulletY[i];
            char next = getCharAtxy(x - 1, y);
            if ((x - 1 == eX && y == eY) || (x - 1 == eX + 1 && y == eY) || (x - 1 == eX && y == eY + 1) || (x - 1 == eX + 4 && y == eY + 1) || (x - 1 == eX + 1 && y == eY + 2) || (x - 1 == eX + 2 && y == eY + 2) || (x - 1 == eX && y == eY + 3) || (x - 1 == eX + 1 && y == eY + 3) || (x - 1 == eX + 2 && y == eY + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy1IsLive)
                {
                    addScore();
                    enemy1HealthDamage(5);
                }
                removePlayerBullets(i, "left");
            }
            else if ((x - 1 == eX3 && y == eY3) || (x - 1 == eX3 + 3 && y == eY3) || (x - 1 == eX3 && y == eY3 + 1) || (x - 1 == eX3 + 3 && y == eY3 + 1) || (x - 1 == eX3 && y == eY3 + 2) || (x - 1 == eX3 + 3 && y == eY3 + 2) || (x - 1 == eX3 && y == eY3 + 3) || (x - 1 == eX3 + 3 && y == eY3 + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy3IsLive)
                {
                    addScore();
                    enemy3HealthDamage(5);
                }
                removePlayerBullets(i, "left");
            }

            else if (next != ' ')
            {
                erasePlayerBullet(x, y);
                removePlayerBullets(i, "left");
            }
        }
    }
}

void playerBulletStarter()
{
    for (int i = 0; i < 1000; i++)
    {
        activatePlayerRightBullet[i] = false;
        activatePlayerLeftBullet[i] = false;
    }
}

void removePlayerBullets(int c, string direction) // makes bullet inactive
{
    // for right hand side bullet
    if (direction == "right")
    {
        activatePlayerRightBullet[c] = false;
    }

    // for left hand side bullet
    else if (direction == "left")
    {
        activatePlayerLeftBullet[c] = false;
    }
}

void resetPlayerBullets() // removes inactive bullets from arrays
{
    // right side bullets
    for (int i = 0; i < rightPlayerBulletCount; i++)
    {
        if (!activatePlayerRightBullet[i])
        {
            for (int j = i; j < rightPlayerBulletCount - 1; j++)
            {
                playerRightBulletX[j] = playerRightBulletX[j + 1];
                playerRightBulletY[j] = playerRightBulletY[j + 1];
                activatePlayerRightBullet[j] = activatePlayerRightBullet[j + 1];
            }
            rightPlayerBulletCount--;
        }
    }

    // left side bullets
    for (int i = 0; i < leftPlayerBulletCount; i++)
    {
        if (!activatePlayerLeftBullet[i])
        {
            for (int j = i; j < leftPlayerBulletCount - 1; j++)
            {
                playerLeftBulletX[j] = playerLeftBulletX[j + 1];
                playerLeftBulletY[j] = playerLeftBulletY[j + 1];
                activatePlayerLeftBullet[j] = activatePlayerLeftBullet[j + 1];
            }
            leftPlayerBulletCount--;
        }
    }
}

void playerHealth(int x, int y) // prints player health
{
    eraser(x, y);
    gotoxy(x, y);
    cout << "\33[41m"
         << "Player Health:  " << maxPlayerHealth << "\33[0m";
}

void playerHealthDamage(int damage, int x, int y) // calculates health of player after damage from enemies
{
    maxPlayerHealth -= damage;
    playerHealth(x, y);
}

void enemy1Health(int x, int y) // prints health of enemy 2
{
    eraser(x, y);
    gotoxy(x, y);
    cout << "\33[41m"
         << "Enemy 1 Health: " << maxEnemy1Health << "\33[0m";
}

void enemy1HealthDamage(int damage) // calculates enemy 1 health after damage from player bullet
{
    maxEnemy1Health -= damage;
    if(maxEnemy1Health<0)
    {
        maxEnemy1Health=0;
    }
}

void enemy2Health(int x, int y) // prints enemy 2 health on header bar
{
    eraser(x, y);
    gotoxy(x, y);
    cout << "\33[41m"
         << "Enemy 2 Health: " << maxEnemy2Health << "\33[0m";
}

void enemy2HealthDamage(int damage) // calcualtes health of enemy after damage by player bullet
{
    maxEnemy2Health -= damage;
    if(maxEnemy2Health<0)
    {
        maxEnemy2Health=0;
    }
}

void enemy3Health(int x, int y) // prints enemy 3 health on header bar
{
    eraser(x, y);
    gotoxy(x, y);
    cout << "\33[41m"
         << "Enemy 3 Health: " << maxEnemy3Health << "\33[0m";
}

void enemy3HealthDamage(int damage) // calcualtes health of enemy after damage by player bullet
{
    maxEnemy3Health -= damage;
    if(maxEnemy3Health<0)
    {
        maxEnemy3Health=0;
    }
}

void displayScore() // prints score
{
    gotoxy(1, 9);
    cout << "\33[1m"
         << "Score: " << score;
    cout << "\33[0m";
}

void displayHealthPill() // print health pill on header bar
{
    gotoxy(1, 11);
    cout << "\33[5;31m"
         << "Health Boost = "
         << "\33[0m";
    healthPill(17, 11);
}

void eraser(int x, int y) // erases the previous value of health and bullet count
{
    gotoxy(x, y);
    cout << "                      ";
}

void displayBulletCount() // displays bullet count
{
    eraser(1, 10);
    gotoxy(1, 10);
    cout << "\33[1m"
         << "Bullets: " << playerBulletCount;
    cout << "\33[0m";
}

void printmagazine() // print bullet crate on header bar
{
    gotoxy(1, 12);
    cout << "\33[35m"
         << "Magazine = "
         << "\33[0m";
    magazine(13, 11);
}

void headbar() // player, enemy, health and score bar
{
    playerHealth(45, 8);
    displayScore();
    displayBulletCount();
    printmagazine();
    displayHealthPill();
}
void printEndKey(int x, int y)
{
    gotoxy(x, y);
    cout << "\33[5;31m" << endKey << endKey;
    gotoxy(x, y + 1);
    cout << "\33[5;31m" << endKey << endKey;
    cout << "\33[0m";
}
void eraseEndKey(int x, int y)
{
    gotoxy(x, y);
    cout << "\33[5;31m"
         << "  ";
    gotoxy(x, y + 1);
    cout << "\33[5;31m"
         << "  ";
    cout << "\33[0m";
}
void touchEndKey(int x, int y)
{
        if ((x == endKeyX || x + 1 == endKeyX || x + 2 == endKeyX || x == endKeyX + 2 || x + 1 == endKeyX + 2 || x + 3 == endKeyX + 2) && (y == endKeyY || y + 1 == endKeyY || y + 2 == endKeyY))
        {
            eraseEndKey(endKeyX, endKeyY);
            LevelRunning = false;
            levelendscreen("CONRATULATIONS! LEVEL PASSED ");
        }
    
}

void displayLevel(int x)
{    
    header(1, 1);
    gotoxy(1, 8);
    cout << "\33[94m"
         << "Level: " << x << "\33[0m";
}
void RowsOfMaze(int x, int y) // first & last row of InnerMap
{
    
    gotoxy(x, y);
    for (int i = 0; i < 186; i++)
    {
        cout << "\33[94m"
             << box
             << "\33[0m";
        x++;
        gotoxy(x, y);
    }
}

void ColumnsOfMaze(int x, int y) // Columns of InnerMap
{
 
    gotoxy(x, y);
    cout << "\33[94m"
         << box
         << "\33[0m";
    x++;
    for (int i = 0; i < 184; i++)
    {
        gotoxy(x, y);
        cout << " ";
        x++;
    }
    gotoxy(x, y);
    cout << "\33[94m"
         << box
         << "\33[0m";
}

void Maze() // Maze 
{
    int x = 1, y = 14;
    RowsOfMaze(x, y);
    y++;
    for (int i = 0; i < 39; i++)
    {
        ColumnsOfMaze(x, y + i);//
    }
    RowsOfMaze(x, y + 39);
}

void InnerMapBoxes(int x, int y, int size) // InnerMapBoxess for InnerMaps(size bolay tou : number of blocks u wanna print)
{
    char box = 219;
    for (int i = 0; i < size; i++)
    {
        gotoxy(x + i, y);
        cout << "\33[34m" << box << "\33[0m";
    }
}

void verticalInnerMapBoxes(int x, int y, int width, int height) // to print lambii line in the maze (width bolay tou: how many boxes to print horizontly)
{
    for (int i = 0; i < height; i++)
    {
        InnerMapBoxes(x, y + i, width);
    }
}

void placeObjects() // to print magazine and health pills
{
    healthPill(healtendKeyX, healtendKeyY);
    magazine(magazineX, magazineY);
}

void InnerMap() // printing InnerMap of the game(androoni khaddokhaal)
{
    placeObjects();//
    // bottom line
    InnerMapBoxes(75, 48, 18);
    InnerMapBoxes(76, 48, 18);
    InnerMapBoxes(77, 48, 18);// (x,y,width of box)
    InnerMapBoxes(78, 48, 18);
    // left side |____________|
    InnerMapBoxes(23, 32, 34);
    InnerMapBoxes(23, 31, 2);    
    InnerMapBoxes(23, 30, 2);
    InnerMapBoxes(55, 31, 2);
    InnerMapBoxes(55, 30, 2);
    //magazine walay
    InnerMapBoxes(83, 21,  2);
    InnerMapBoxes(83, 22,  2);
    InnerMapBoxes(83, 23,  2);
    InnerMapBoxes(83, 24, 12);

    
    // InnerMapBoxes(140, 29, 2);
    InnerMapBoxes(140, 30, 2);
    InnerMapBoxes(140, 31, 2);
    InnerMapBoxes(140, 32, 2);
    InnerMapBoxes(140, 33, 2);
    InnerMapBoxes(140, 27, 2);
    InnerMapBoxes(140, 26, 2);
    InnerMapBoxes(140, 34, 2);
    InnerMapBoxes(140, 35, 2);
    InnerMapBoxes(140, 36, 2);
}

void innerMap2() // printing InnerMap of the game
{

    placeObjects();
    verticalInnerMapBoxes(24, 15, 2, 13);
    InnerMapBoxes(24, 33, 34);
    InnerMapBoxes(24, 31, 2);
    InnerMapBoxes(24, 32, 2);   
    InnerMapBoxes(56, 32, 2);    
    InnerMapBoxes(56, 31, 2);
    InnerMapBoxes(51, 43, 30);
    verticalInnerMapBoxes(70, 25, 2, 19);//x,y,width,hieght
    verticalInnerMapBoxes(150, 15, 2, 30);
    verticalInnerMapBoxes(100, 24, 2, 30);
    InnerMapBoxes(48, 25, 22);
    InnerMapBoxes(90, 23, 50);
    InnerMapBoxes(130, 36, 20);
}

void healthPill(int x, int y) // printing health pill sprite
{
    gotoxy(x, y);
    cout << "\33[5;31m" << heart << "\33[0m";
}

void erasehealthPill(int x, int y) // erases the health pill
{
    gotoxy(x, y);
    cout << " ";
}

void magazine(int x, int y) // print magazine
{
    gotoxy(x, y);
    cout << "\33[5;32m" << Magazine << "\33[0m";
}

void pillCollision(int x, int y) // determines whether player touches the health pill and resets player's health
{
    if ((x == healtendKeyX || x + 1 == healtendKeyX || x + 2 == healtendKeyY) && (y == healtendKeyY || y + 1 == healtendKeyY || y + 2 == healtendKeyY))
    {
        erasehealthPill(healtendKeyX, healtendKeyY);
        maxPlayerHealth = 100;
        playerHealth(45, 8);
    }
}

void erasemagazine(int x, int y) // erases bullet crate
{
    gotoxy(x, y);
    cout << " ";
}

void magazineCollision(int x, int y) // detects if player touches magazine and resets bullet count
{
    if ((x == magazineX || x + 1 == magazineX || x + 2 == magazineX || x == magazineX + 3 || x + 1 == magazineX + 3 || x + 2 == magazineX + 3) && (y == magazineY || y + 1 == magazineY || y + 2 == magazineY))
    {
        erasemagazine(magazineX, magazineY);
        playerBulletCount = 500;
        displayBulletCount();
    }
}

void checkItems(int x, int y) // checks whether player touches items in the InnerMap
{
    touchEndKey( x, y);
    pillCollision(x, y);
    magazineCollision(x, y);
}

void Level1Selection() // screen for selecting levels
{
    system("cls");
    int x = 45, y = 8;
    header(x, y);
    gotoxy(62, 20);
    for (int i = 0; i < 45; i++)
    {
        cout << "\33[33m"
             << "_";
    }
    gotoxy(62, 21);
    cout << "\33[33m"
         << "|                                           |";
    gotoxy(62, 22);
    cout << "\33[33m"
         << "|              -> PRESS 1 FOR LEVEL 1       |";
    gotoxy(62, 23);
    cout << "\33[33m"
         << "|              -> PRESS 2 TO GO BACK        |";
    gotoxy(62, 24);
    cout << "\33[33m"
         << "|";
    gotoxy(62, 25);
    cout << "\33[33m"
         << "|";
    gotoxy(106, 24);
    cout << "\33[33m"
         << "|";
    gotoxy(106, 25);
    cout << "\33[33m"
         << "|";
    gotoxy(62, 25);
    for (int i = 0; i < 45; i++)
    {
        cout << "\33[32m"
             << "_"
             << "\33[0m";
    }

    while(1) 
    {
    char opt = getch();

    if (opt == '1')
    {
        level_1();
    }
    else if(opt == '2')
    {
        menu();
    }
    else 
    cout<<"\n\t\t\t\t\t\t\t Invalid input, Enter again.";
    }
}

void level2Selection() // screen for selecting levels
{
    system("cls");
    int x = 45, y = 8;
    header(x, y);
    gotoxy(62, 20);
    for (int i = 0; i < 45; i++)
    {
        cout << "\33[33m"
             << "_";
    }
    gotoxy(62, 21);
    cout << "\33[33m"
         << "|                                           |";
    gotoxy(62, 22);
    cout << "\33[33m"
         << "|              -> PRESS 1 FOR LEVEL 2       |";
    gotoxy(62, 23);
    cout << "\33[33m"
         << "|              -> PRESS 2 TO GO BACK        |";
    gotoxy(62, 24);
    cout << "\33[33m"
         << "|";
    gotoxy(62, 25);
    cout << "\33[33m"
         << "|";
    gotoxy(106, 24);
    cout << "\33[33m"
         << "|";
    gotoxy(106, 25);
    cout << "\33[33m"
         << "|";
    gotoxy(62, 25);
    for (int i = 0; i < 45; i++)
    {
        cout << "\33[32m"
             << "_"
             << "\33[0m";
    }

    while(1) 
    {
    char opt = getch();

    if (opt == '1')
    {
        level_2();
    }
    else if(opt == '2')
    {
        menu();
    }
    else 
    cout<<"\n\t\t\t\t\t\t\t Invalid input, Enter again.";
    }
}
void levelendscreen(string text) // screen appears at the end of each level
{
    Sleep(1000);
    gotoxy(70, 21);
    for (int i = 0; i < 30; i++)
    {
        cout << "\33[32m"<< "_"<< "\33[0m";
    }
    gotoxy(71, 23);
    cout << "\33[32m" << text << "\33[0m";
    gotoxy(70, 25);
    for (int i = 0; i < 30; i++)
    {
        cout << "\33[32m" << "_"<< "\33[0m";
    }
    Sleep(3000);
    if (LevelRunning == true)
    {
        level2Selection();
    }
    else
    {
        menu();
    }
}

void addScore() // increments score
{
    score++;
    displayScore();
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void mode(char opt) // selects mode of game
{
    if (opt == '1')
    {
        level2Selection();
    }
    else if (opt == '2')
    {
        system("cls");
        exit(0);
    }
}

void menu() // prints main starting menu
{
    system("cls");
    int x = 60, y = 8;
    header(x, y);
    cout << "\33[1;3;96m";
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t+==============================================+" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|    "<< "        >  PRESS 1 TO START GAME        "<< "  |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|    "<< "        >  PRESS 2 TO EXIT            "<< "    |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\33[1;3;96m";
    cout << "\t\t\t\t\t\t\t\t+==============================================+" << endl;
    cout << "\33[1;3;32m";
    gotoxy(58,33);
    char opt=getch();
    // cout << "Enter Your Choice :";
    // cout << "\33[1;3;0m";
    // int opt = ValidateInput(2, 78, 33);
    mode(opt);
}

// int ValidateInput(int optcount, int x, int y) // takes in user input of ValidateInput
// {
//     bool found = false;
//     string opt = "\0";
//     gotoxy(x, y);//
//     getline(cin, opt);
//     cout << "\33[0m";
//     while (!found)
//     {
//         if (validation(opt) && opt != "\0")
//         {
//             if (stoi(opt) > 0 && stoi(opt) <= optcount)
//             {
//                 found = true;
//                 break;
//             }
//         }
//         y++;
//         gotoxy(x, y);
//         cout << "\33[1;3;96m"
//              << "Invalid input! Try again: ";
//         getline(cin, opt);
//         cout << "\33[0m";
//     }
//     return stoi(opt);
// }

bool validation(string num) // validation of user input of ValidateInput
{
    string digits = "0123456789 ";
    for (int i = 0; i < num.length(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (digits[j] == num[i])
            {
                break;
            }
            else if (j == 9)
            {
                return false;
            }
        }
    }
    return true;
}

void header(int x, int y) // header of game on main starting screen
{

    gotoxy(x, y);
    cout << "\33[1;91m";
    cout << " ______        _ _              _______              " << endl;
    gotoxy(x, y+1);
     cout << "\33[1;92m";
    cout << "(____  \\      | | |      _     (_______)        _    " <<endl;
    gotoxy(x, y+2);
     cout << "\33[1;93m";
    cout << " ____)  )_   _| | | ____| |_    _____ ____  ___| |_  " << endl;
    gotoxy(x, y+3);
     cout << "\33[1;94m";
    cout << "|  __  (| | | | | |/ _  )  _)  |  ___) _  )/___)  _) " << endl;
    gotoxy(x, y+4);
     cout << "\33[1;95m";
    cout << "| |__)  ) |_| | | ( (/ /| |__  | |  ( (/ /|___ | |__ " << endl;
    gotoxy(x, y+5);
     cout << "\33[1;96m";
    cout << "|______/ \\____|_|_|\\____)\\___) )_|   \\____|___/ \\___)"<<endl;
    cout << "\33[1;0m";


}

