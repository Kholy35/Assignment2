//Essam ElKholy
//900222215

#include "Points.h"     //includes the header file for points.h

points Center (points *C, int n)        //function that gets the center of the points cluster by getting the average of the points and takes a pointer that points to an array of objects of class points and an integer
{
    float sumX = 0;     //initializes the sum of the points x to 0
    float sumY = 0;     //initializes the sum of the points y to 0
    
    for (int i = 0; i < n; i++)     //for loop that iterates over the array of points
    {
        sumX += C[i].GetX();        //adds the value of the x coordinate of the current point to the current value of sum and assigns it as the new value of sum
        sumY += C[i].GetY();        //adds the value of the y coordinate of the current point to the current value of sum and assigns it as the new value of sum
    }
    
    float CenterX = sumX / n;       //calculates the x coordinate of the center by dividing the sum of the coordinates over the total points
    float CenterY = sumY / n;       //calculates the y coordinate of the center by dividing the sum of the coordinates over the total points
    
    points center (CenterX, CenterY);       //creates a points object that uses the centerx and centery variables and represenets the center point
    
    return center;
}


void Closest_Cluster (points *A, int sizeA, points *B, int sizeB, points P)     //function that takes 2 pointers pointing to an array of objects of class points and 2 integer variables and 1 variable of type points; it calculates to which cluster is the point entered closest to
{
    float distanceA, distanceB;     //declares 2 variables of type float
    points centerA = Center(A, sizeA);      //creates a variable of type points  and calls the center function to assign a value to it which is the center of point A
    points centerB = Center(B, sizeB);       //creates a variable of type points  and calls the center function to assign a value to it which is the center of point B
    
    distanceA = P.Distance(centerA);        //calls the distance function to calculate the distacne between the point and the center of cluster A
    distanceB = P.Distance(centerB);        //calls the distance function to calculate the distacne between the point and the center of cluster B
    
    if (distanceA > distanceB)      //if the distance between the point and the center of cluster A is greater than the distance between the point and the center of cluster B then execute the body
    {
        cout << "The point ";
        P.Display();        //displays the point
        cout <<  " Belongs to cluster B" << endl;
    }
    
    else if (distanceA < distanceB)     //if the distance between the point and the center of cluster B is greater than the distance between the point and the center of cluster A then execute the body
    {
        cout << "The point ";
        P.Display();        //displays the point
        cout << " Belongs to cluster A" << endl;
    }
    else        //if the distance between the point and the center of cluster A is equal to the distance between the point and the center of cluster B
    
    {
        cout << "The point ";
        P.Display();        //displays the point
        cout << " is placed with equal distance from both clusters" << endl;
    }
}

int main ()
{
    
    //declares pointers that point to arrays of objects of points a and b and p
    points * A;
    points * B;
    points * P;
    
    //declares variables of type int
    int sizeA, sizeB;
    
    //prompts the user to enter the sizes of cluster A and B
    cout << "Please enter the size of cluster A: ";
    cin >> sizeA;
    
    cout << "Please enter the size of cluster B: ";
    cin >> sizeB;
    
    //dynamically allocates memory for A and B of size sizeA and size sizeB
    A = new points[sizeA];
    B = new points[sizeB];
    
    
    for (int i = 0; i < sizeA; i++)     //iterates over the array of points in cluster A
    {
        A[i].SetX(rand() % 19 + 71);        //sets the x-coordinate of point A[i] to a random number between 70 and 90 by modulus dividing the rand by 19 making the values that can appear between 0 and 18 and adding 71 to it to shift the range upwards making it between 70 and 90 while 70 and 90 are excluded
        A[i].SetY(rand() % 19 + 71);        //sets the y-coordinate of point A[i] to a random number between 70 and 90 by modulus dividing the rand by 19 making the values that can appear between 0 and 18 and adding 71 to it to shift the range upwards making it between 70 and 90 while 70 and 90 are excluded
    }
    
    for (int i = 0; i < sizeB; i++)     //iterates over the array of points in cluster B
    {
        B[i].SetX(rand() % 19 + 71);        //sets the x-coordinate of point B[i] to a random number between 70 and 90 by modulus dividing the rand by 19 making the values that can appear between 0 and 18 and adding 71 to it to shift the range upwards making it between 70 and 90 while 70 and 90 are excluded
        B[i].SetY(rand() % 19 + 71);        //sets the y-coordinate of point B[i] to a random number between 71 and 89 by modulus dividing the rand by 19 making the values that can appear between 0 and 18 and adding 71 to it to shift the range upwards making it between 70 and 90 while 70 and 90 are excluded
    }
    
    P = new points[20];     //allocates memory for P of size 20
    
    points centerA = Center(A, sizeA);      //creates a variable of type points  and calls the center function to assign a value to it which is the center of point A
    points centerB = Center(B, sizeB);      //creates a variable of type points  and calls the center function to assign a value to it which is the center of point B
    
    cout<<"Center of Cluster A: ";
    centerA.Display();      //displays the center point of cluster A
    
    cout<<endl;
    
    cout<<"Center of Cluster B: ";
    centerB.Display();      //displays the center point of cluster B
    
    cout<<endl;
    
    for (int i = 0; i < 20; i++)        //iterates over the random 20 points outside of the clusters
    {
        P[i].SetX(rand() % 94 + 6);     //sets the x-coordinate of point P[i] to a random number between 5 and 100 by modulus dividing the rand by 94 making the values that can appear between 0 and 94 and adding 6 to it to shift the range upwards making it between 5 and 100 while 5 and 100 are excluded
        P[i].SetY(rand() % 94 + 6);     //sets the y-coordinate of point P[i] to a random number between 5 and 100 by modulus dividing the rand by 94 making the values that can appear between 0 and 94 and adding 6 to it to shift the range upwards making it between 5 and 100 while 5 and 100 are excluded
        
        Closest_Cluster(A, sizeA, B, sizeB, P[i]);      //calls the function closest cluster
    }
    
    delete[] A;
    delete[] B;         //deallocates the memory that was allocated for arrays A and B and P
    delete[] P;
        
    return 0;
    
}
