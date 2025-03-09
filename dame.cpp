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
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'}};

    // An array of pion objects representing all the pieces on the board.
    pion pion_board[64] = {
        pion(0, 0, 'N'),
        pion(0, 1, 'N'),
        pion(0, 2, 'N'),
        pion(0, 3, 'N'),
        pion(0, 4, 'N'),
        pion(0, 5, 'N'),
        pion(0, 6, 'N'),
        pion(0, 7, 'N'),
        pion(1, 0, 'N'),
        pion(1, 1, 'N'),
        pion(1, 2, 'N'),
        pion(1, 3, 'N'),
        pion(1, 4, 'N'),
        pion(1, 5, 'N'),
        pion(1, 6, 'N'),
        pion(1, 7, 'N'),
        pion(2, 0, 'N'),
        pion(2, 1, 'N'),
        pion(2, 2, 'N'),
        pion(2, 3, 'N'),
        pion(2, 4, 'N'),
        pion(2, 5, 'N'),
        pion(2, 6, 'N'),
        pion(2, 7, 'N'),
        pion(3, 0, 'N'),
        pion(3, 1, 'N'),
        pion(3, 2, 'N'),
        pion(3, 3, 'N'),
        pion(3, 4, 'N'),
        pion(3, 5, 'N'),
        pion(3, 6, 'N'),
        pion(3, 7, 'N'),
        pion(4, 0, 'N'),
        pion(4, 1, 'N'),
        pion(4, 2, 'N'),
        pion(4, 3, 'N'),
        pion(4, 4, 'N'),
        pion(4, 5, 'N'),
        pion(4, 6, 'N'),
        pion(4, 7, 'N'),
        pion(5, 0, 'N'),
        pion(5, 1, 'N'),
        pion(5, 2, 'N'),
        pion(5, 3, 'N'),
        pion(5, 4, 'N'),
        pion(5, 5, 'N'),
        pion(5, 6, 'N'),
        pion(5, 7, 'N'),
        pion(6, 0, 'N'),
        pion(6, 1, 'N'),
        pion(6, 2, 'N'),
        pion(6, 3, 'N'),
        pion(6, 4, 'N'),
        pion(6, 5, 'N'),
        pion(6, 6, 'N'),
        pion(6, 7, 'N'),
        pion(7, 0, 'N'),
        pion(7, 1, 'N'),
        pion(7, 2, 'N'),
        pion(7, 3, 'N'),
        pion(7, 4, 'N'),
        pion(7, 5, 'N'),
        pion(7, 6, 'N'),
        pion(7, 7, 'N'),
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

// Function to print the current state of the game board to the console.
void dame::print_board()
{
    for (uint8_t i = 0; i < 8; i++)
    {
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
