#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

typedef std::pair<int,int> xy;

struct mazeStruct 
{
    int rows;
    int columns;
    xy posStart;
    xy posEnd;
    std::vector<std::vector<int>> matrix;
    std::string pathway;
};

struct pointStruct 
{
    xy pos;
};

struct queueNodeStruct 
{
    pointStruct point;
    int distance; //distance from the source
    std::string pathway; //route from start to this point so far
};

// N > W > E > S
const int DirectionY[] = {-1, 0, 0, 1};
const int DirectionX[] = {0, -1, 1, 0};

// Keys
const char CStart = 'A';
const char CEnd = 'B';
const char CWall = 'x';
const char CSpace = '.';

mazeStruct maze {};

void createMatrix(std::ifstream& mazeFile);
void displayMatrix();
std::ifstream readTextFile();
std::string recordDirection(int direction);
int breadthFirstSearch();
bool isInBounds(int row, int column);
bool isValidSpace(int row, int column);