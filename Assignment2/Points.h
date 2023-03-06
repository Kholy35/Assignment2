//Prevents multiple definitions of the class
#ifndef Points_h
#define Points_h

#include <iostream>
#include <cmath>
using namespace std;

class points        //declaring a class called points
{
private:
    float x;        //private data member in class points of type float that stores the x coordinate
    float y;        //private data member in class points of type float that stores the y coordinate
    
public:
    points();       //prototype of default constructor
    points(float, float);       //prototype of overloaded constructor
    
    void SetX(float);       //prototype of setter that sets the x value
    void SetY(float);       //prototype of setter that sets the y value
    
    float GetX();       //prototype of getter that gets the x value
    float GetY();       //prototype of getter that gets the y value
    
    void Display();     //function to display the points that the user entered
    
    
    float Distance(points);     //function prototype to calculate the distance between 2 points of class point
    
    
    ~points();      //destructor
};


#endif 
