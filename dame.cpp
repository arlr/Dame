#include <iostream>
#include "pion.cpp"
using namespace std;

#define R_OK    1
#define R_NOK   0

// Define a class to represent the game of Dame with its board, pieces, and player color.
class dame
{
private:
    // A 2D array representing the game board with characters 'N' indicating an empty space.
    unsigned char board[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    // An array of pion objects representing all the pieces on the board.
    pion pion_board[24] = {
        pion(0, 1, 'B'),
        pion(0, 3, 'B'),
        pion(0, 5, 'B'),
        pion(0, 7, 'B'),
        pion(1, 0, 'B'),
        pion(1, 2, 'B'),
        pion(1, 4, 'B'),
        pion(1, 6, 'B'),
        pion(2, 1, 'B'),
        pion(2, 3, 'B'),
        pion(2, 5, 'B'),
        pion(2, 7, 'B'),
        pion(5, 0, 'W'),
        pion(5, 2, 'W'),
        pion(5, 4, 'W'),
        pion(5, 6, 'W'),
        pion(6, 1, 'W'),
        pion(6, 3, 'W'),
        pion(6, 5, 'W'),
        pion(6, 7, 'W'),
        pion(7, 0, 'W'),
        pion(7, 2, 'W'),
        pion(7, 4, 'W'),
        pion(7, 6, 'W'),
    };

    // Boolean variable to indicate if the player is using white pieces or not.
    bool isplayer_white;

    // Enumerated type to represent different colors in the game, including special "dame" colors.
    enum color
    {
        WHITE,
        BLACK,
        DAME_WHITE,
        DAME_BLACK
    };

public:
    // Constructor for the dame class.
    dame();

    // Function to print the current state of the game board.
    void print_board();

    // Function to print information about the game, including which player is using which pieces.
    void print_gameinfo();

    // Function to get the pion at a given x and y coordinate on the board.
    int get_pion(unsigned char x, unsigned char y, pion &pout_pion);

    void populate_board();

    // Destructor for the dame class (currently empty).
    ~dame();
};

// Implement the constructor for the dame class. Randomly choose which player is using white pieces.
dame::dame()
{
    srand(time(nullptr));
    int myrand = std::rand();
    if (myrand % 2)
    {
        isplayer_white = true;
    }
}

void dame::populate_board()
{
    pion tmp_pion = pion(0, 0,' ');
    for (unsigned char i = 0; i < 8; i++)
    {
        for (unsigned char j = 0; j < 8; j++)
        {
            if(get_pion(i, j, tmp_pion))
            {
                board[i][j] = tmp_pion.get_color();
            }
            else
            {
                board[i][j] = ' ';
            }
            
        }
    }
}

// Function to print the current state of the game board to the console.
void dame::print_board()
{
    populate_board();
    cout << "  A B C D E F G H" << endl;
    for (uint8_t i = 0; i < 8; i++)
    {   cout << i + 1 << " ";
        for (uint8_t j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

// Function to print information about the game, including which player is using which pieces.
void dame::print_gameinfo()
{
    if (isplayer_white)
    {
        cout << "Player uses White pieces\n";
    }
    else
    {
        cout << "Player uses Black pieces\n";
    }
}

// Function to get the pion at a given x and y coordinate on the board. Returns a default pion object if no piece is found.
int dame::get_pion(unsigned char x, unsigned char y, pion &pout_pion)
{
    int ReturnStatus = R_NOK;
    for (unsigned char i = 0; i < 64; i++)
    {
        if (pion_board[i].get_x() == x && pion_board[i].get_y() == y)
        {
            pout_pion = pion_board[i];
            ReturnStatus = R_OK;
            break;
        }
    }
    return ReturnStatus;
}

// Destructor for the dame class (currently empty).
dame::~dame() {}

int main()
{
    cout << "Dame game\n";
    dame mygame;
    mygame.print_board();
    mygame.print_gameinfo();
    pion out_pion = pion(0, 0, 'X');
    mygame.get_pion(2, 3, out_pion);
    char color = out_pion.get_color();
    std::cout << "Pion color: " << color << endl;
    // ou of bound pion
    if (mygame.get_pion(0, 8, out_pion))
    {
        color = out_pion.get_color();
        std::cout << "Pion color: " << color << endl;
    }
    else
    {
        cout << "Out of bound\n"; // ou of bound pion
    }

    return 1;
}
