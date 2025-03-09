class pion {
private:
    char pion_color = ' '; // stores the color of the pawn (either 'X' or 'O')
    unsigned char x_coordinate = 0; // stores the x-coordinate of the pawn on a chessboard
    unsigned char y_coordinate = 0; // stores the y-coordinate of the pawn on a chessboard
public:
    pion(unsigned char x, unsigned char y, char color); // constructor that initializes the coordinates and color of the pawn
    void set_x(unsigned char x); // sets the x-coordinate of the pawn
    unsigned char get_x(); // returns the current x-coordinate of the pawn
    void set_y(unsigned char y); // sets the y-coordinate of the pawn
    unsigned char get_y(); // returns the current y-coordinate of the pawn
    void set_color(char color); // sets the color of the pawn (either 'X' or 'O')
    char get_color(void); // returns the current color of the pawn
    ~pion(); // destructor that cleans up any resources used by the pawn object
};

// constructor implementation for pion class
pion::pion(unsigned char x, unsigned char y, char color) {
    x_coordinate = x;
    y_coordinate = y;
    pion_color = color;
}

// setter method to set the x-coordinate of the pawn
void pion::set_x(unsigned char x) {
    x_coordinate = x;
}

// getter method to return the current x-coordinate of the pawn
unsigned char pion::get_x() {
    return x_coordinate;
}

// setter method to set the y-coordinate of the pawn
void pion::set_y(unsigned char y) {
    y_coordinate = y;
}

// getter method to return the current y-coordinate of the pawn
unsigned char pion::get_y() {
    return y_coordinate;
}

// setter method to set the color of the pawn (either 'X' or 'O')
char pion::get_color() {
    return pion_color;
}

// getter method to return the current color of the pawn
void pion::set_color(char color) {
    pion_color = color;
}

// destructor implementation for pion class
pion::~pion() {
}