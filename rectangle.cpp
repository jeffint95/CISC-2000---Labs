/*
Jeffrey Interiano
Instructor: Dakota Hernandez
CS 2000
*/

#include <iostream>

using namespace std;

// rectangle has a vertical height and horizontal width
// The class below is a rectangle. It has two private
// data members: height and width.
// TODO: Complete the class declaration and definition.
class rectangle {

public:
    
    // TODO: declare a default constructor
    // sets height and width to the unit rectangle which is a square 1x1 size.
    rectangle()
    {
        height = 1;
        width = 1;
    }
    
    void add(int addHeight, int addWidth);
    void set(int new_height, int new_width);
    
    // TODO: declare member function add
    // add the given addHeight to height and addWidth to width
    // @param int addHeight, int addWidth
    // @returns void

    // TODO: delcare member function void set
    // set the height to new_height and width to new_width
    // @param int new_height, int new_width
    // @returns void
    
    void draw();
    // TODO: declare member function draw
    // uses height as the vertical dimension (outer loop) and width as the horizontal
    // dimension (inner loop) to draw the rectangle with '#' characters.
    int getWidth()
    {
        return width;
    }
    // TODO: define accessor for width
    // TODO: define accessor for height
    int getHeight()
    {
        return height;
    }
    // TODO: declare a function that tells if a
    // rectangle is a square
    bool isSquare();
    // rectangle has a vertical height and horizontal width
    private:
        int height;
        int width;

};

// TODO: implement a default constructor
// sets height and width to the unit rectangle which is
// a square 1x1 size.
// TODO: Implement add member function
// @param int addHeight, int addWidth
// to addHeight to height and add addWidth to width

void rectangle::add(int addHeight, int addWidth)
{
    width += addWidth;
    height += addHeight;
}

void rectangle :: set(int new_height, int new_width)
{
    width = new_width;
    height = new_height;
}

void rectangle :: draw() 
{
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }

// TODO: implement member function void set that assigns
bool rectangle ::isSquare(){
    return(height == width);
}

// uses the height in an outer loop and the width in an
int main(){
    // Declare 2 rectangles
    rectangle r1, r2;
    // Draw the unit rectangle
    cout << "unit rectangle" << endl;
    r1.draw();
    
    // Set, print dimensions and draw
    r1.set(4, 3);
    cout << "r1 is " << r1.getHeight() << " x " << r1.getWidth() << endl;
    
    r1.draw();
    // Assign, increment, print dimensions and draw
    r2 = r1;
    r2.add(3, 4);
    cout << "r2 is " << r2.getHeight() << " x " << r2.getWidth() << endl;
    r2.draw();
    
    if (r2.isSquare())
        cout << "r2 is a square" << endl;
    else
        cout << "r2 is not a square" << endl;
    return 0;
}