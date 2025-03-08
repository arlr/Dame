#include <iostream>

using namespace std;

class pion
{
private:
    unsigned char x_coordinate = 0;
    unsigned char y_coordinate = 0;
    enum color {WHITE, BLACK, DAME_WHITE, DAME_BLACK};
    uint8_t ismove_possible(unsigned char target_x, unsigned char target_y);
    
public:
    pion(unsigned char x, unsigned char y);
    ~pion();
    uint8_t move(unsigned char target_x, unsigned char target_y);
};

pion::pion(unsigned char x, unsigned char y)
// Constructor
{
    x_coordinate = x;
    y_coordinate = y;

}

pion::~pion()
{
}

class dame
{
private:
unsigned char board[8][8] = {
                            {'N','N','N','N','N','N','N','N'},
                            {'N','N','N','N','N','N','N','N'},
                            {'N','N','N','N','N','N','N','N'},
                            {'N','N','N','N','N','N','N','N'},
                            {'N','N','N','N','N','N','N','N'},
                            {'N','N','N','N','N','N','N','N'},
                            {'N','N','N','N','N','N','N','N'},
                            {'N','N','N','N','N','N','N','N'}
                            };

    bool isplayer_white = false;


public:
    dame(/* args */);
    void print_board();
    void print_gameinfo();
    ~dame();

};

dame::dame(/* args */)
{
    // Choose randomly the player color
    srand(time(nullptr));
    int myrand = std::rand();
    if(myrand % 2){
        isplayer_white = true;
    }
}

void dame::print_board()
// Print game board
{
    for( uint8_t i = 0; i < 8; i++){
        for (uint8_t j = 0; j < 8; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << '\n';       
    }
}

void dame::print_gameinfo(){
    if(isplayer_white){
        std::cout << "Player use White pices\n";
    }else{
        std::cout << "Player use Black pices\n";
    }
}

dame::~dame()
{
}



int main()
{
    cout << "Dame game\n";
    dame mygame;
    mygame.print_board();
    mygame.print_gameinfo();
    return 0;
}


