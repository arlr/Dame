#include <iostream>

using namespace std;

class pion
{
private:
    unsigned char x_coordinate = 0;
    unsigned char y_coordinate = 0;
    enum color {WHITE, BLACK, DAME_WHITE, DAME_WHITE};
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

uint8_t pion::move(unsigned char target_x, unsigned char target_y)
{
    // Test the move
    uint8_t ret = 1; 
    return ret;
}

uint8_t pion::ismove_possible(unsigned char target_x, unsigned char target_y)
{
    // Ruturn 1 if the move is possible
    uint8_t ret = 0;
    // Test if the target position is taken by an other piece

    // Test if the target position is eating a adversary

}
class dame
{
private:
    unsigned char board[8][8] = {{'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'}};
    bool isplayer_white = false;


public:
    dame(/* args */);
    ~dame();

};

dame::dame(/* args */)
{
}

dame::~dame()
{
}

pion::~pion()
{
}


int main()
{
    unsigned char board[8][8] = {{'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'},
                                {'N','N','N','N','N','N','N','N'}};
    cout << "Dame game";
    return 0;
}


