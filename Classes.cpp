
#include <iostream>
//using namespace std;
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
    Rectangle operator+ (const Rectangle&); //overloading operator
};

Rectangle Rectangle::operator+ (const Rectangle& parameters)    //what happens when overloading
{
    Rectangle new_param;
    new_param.width = width + parameters.width;     //adding parameters of classes
    new_param.height = height + parameters.height;  //adding parameters of classes
    return new_param;
}

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

template <class temp>   //creating template

class Other_Rectangle
{
private:
    temp width;                //radius in any template (int or float for example)
    temp height;
public:
    Other_Rectangle();
    Other_Rectangle(temp x, temp y);
   
    temp area()
    {
        temp r;
        r = width * height;
        return r;
    }
};

template <class temp>       //necessary
Other_Rectangle<temp>::Other_Rectangle()
{
    width = 1;
    height = 1;
}

template <class temp>       //necessary
Other_Rectangle<temp>::Other_Rectangle(temp x, temp y)
{
    width = x;
    height = y;
}

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

    std::cout << "Volume of Parallelepiped is: " << para_1.volume() << std::endl;

    Rectangle sum_of_classes;

    sum_of_classes = rectangle_1 + rectangle_2;

    std::cout << "Area of sum of classes: " << sum_of_classes.area() << std::endl;  

    Other_Rectangle<int> circle_1(5, 4);
    Other_Rectangle<double> circle_2(3.6, 7.2);

    std::cout << "Area of circle 1: " << circle_1.area() << std::endl;
    std::cout << "Area of circle 2: " << circle_2.area() << std::endl;

}
