#include <string>
#include <iostream>
#include <list>
using namespace std;


/**
TODOS:

- make the game playable for 2
- define a finish

**/

/**
Map which contains playground
Init fills stringarray with empty spaces
setDot draws a value on the field
*//
class Map {
    string field[3][3];
    public:
    void init();
    void drawField();
    void setDot(string value,  int x, int y);
};

void Map::setDot(string value, int x, int y){
    field[x][y] = value;
}

void Map::init() {
    for (int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            field[i][j] = " ";
        }
    }
}

void Map::drawField() {
    for (int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++){
            cout << "[ " << field[i][j] << " ]";
    }
    cout << "\n";
}
}



/**
Class Player can move on a injected Map
**/
class Player {
    int x;
    int y;
    Map *m;
    string mark;
    public:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    Player(int x,int y, string mark, Map *m); 
};

Player::Player(int xa,int yb, string Inmark, Map *ma) {
    x = xa;
    y = yb;
    mark = Inmark;
    m = ma;
    m->setDot(mark,x,y);
}

void Player::moveLeft() {
    m->setDot(" ", x,y);
    if(y != 0) {
        y--;
    }
    else if(y ==0) {
        y = 2;
    }
    m->setDot(mark, x,y);
}

void Player::moveRight() {
    m->setDot(" ", x,y);
    if(y != 2) {
        y++;
    }
    else if(y ==2) {
        y = 0;
    } 
    m->setDot(mark,x,y);
}

void Player::moveUp() {
    m->setDot(" ", x,y);
    if(x != 0) {
        x--;
    }
    else if(x ==0) {
        x = 2;
    }
    m->setDot(mark, x,y);
}

void Player::moveDown() {
    m->setDot(" ", x,y);
    if(x != 2) {
        x++;
    }
    else if(x ==2) {
        x = 0;
    } 
    m->setDot(mark,x,y);
}



const int ESCAPE=27;

int main() {
    Map playerfield;
    playerfield.init();
    Player p1 (0,0, "x", &playerfield);
    bool loop = true;
    playerfield.drawField();
    while(loop) {
        cout<<"press escape to end loop"<<endl;
        int ch= getchar();
        if(ch==ESCAPE)
            loop=false;
        if(ch==119) p1.moveUp();
        if(ch==115) p1.moveDown();
        if(ch==97) p1.moveLeft();
        if(ch==100) p1.moveRight();
        
        playerfield.drawField();
       }


    }
    
