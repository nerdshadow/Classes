﻿
#include <iostream>

class Rectangle //creating class
{
private:
    int width, height;
public:
    Rectangle(); //creating constructor
    Rectangle(int, int); //creating overloading constructor
    void set_width_height(int, int); 
    int area() 
    {
        return width * height;
    }
};
Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}

Rectangle::Rectangle(int x, int y)
{
    width = x;
    height = y;
}
void Rectangle::set_width_height(int x, int y)
{
    width = x;
    height = y;
}

class Parallelepiped //creating class
{
private:
    Rectangle base; //using object of another class 
    int height;
public:
    Parallelepiped(int a, int b, int c) :base(a, b), height(c) {}; //Because objects of class Rectangle can only be constructed with a parameter, Parallelepiped's constructor needs to call base's constructor, and the only way to do this is in the member initializer list.
    int volume()
    {
        return base.area() * height;
    }
};

int main()
{
    int x, y;
    Rectangle rectangle_1;          //
    Rectangle rectangle_2;          //using different methods to create an object
    Rectangle rectangle_3(6, 6);    //

    rectangle_2.set_width_height(3, 6);

    std::cout <<"Insert width: ";
    std::cin >> x;
    std::cout <<"and height: ";
    std::cin >> y;

    rectangle_1.set_width_height(x, y);

    std::cout << "Area of your rectangle is: " << rectangle_1.area()<<std::endl;
    std::cout << "Area of second rectangle is: " << rectangle_2.area() << std::endl;
    std::cout << "Area of third rectangle is: " << rectangle_3.area()<<std::endl;

    Parallelepiped para_1(3, 4, 8);

    std::cout << "Volume of Parallelepiped is: " << para_1.volume();
}