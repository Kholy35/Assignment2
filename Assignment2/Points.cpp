#include "Points.h"     //includes the points.h header file

using namespace std;

//points:: specifies the scope that the functions belong to

points::points()        //default constructor that initializes x and y to 0
{
    x = 0;
    y = 0;
}

points::points(float x_coordinate, float y_coordinate)      //overloaded constructor that initializes the x and y values
{
    x = x_coordinate;
    y = y_coordinate;
}

void points::SetX(float x_coordinate)       //setter function that sets the x value
{
    x = x_coordinate;
}

void points::SetY(float y_coordinate)        //setter function that sets the y value
{
    y = y_coordinate;
}

float points::GetX()             //getter function that gets the x value
{
    return x;
}

float points::GetY()         //getter function that gets the y value
{
    return y;
}

void points::Display()          //displays or outputs the x and y 
{
    cout << "(" << x << "," << y << ")";
}

float points::Distance(points p)        //function definition to calculate the distance between 2 points of class point
{
    float distance;
    
    distance = sqrt(pow((x - p.x) , 2) + pow((y - p.y) , 2));
    
    return distance;
}
    
points::~points()       //destructor
{
    
}

