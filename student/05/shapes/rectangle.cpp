#include "rectangle.hh"
#include "shape.hh"
using namespace std;
Rectangle::Rectangle(char color, double width, double height):Shape(color), width_(width), height_(height) {}

Rectangle::~Rectangle()
{

}

double Rectangle::area()
{
    return width_*height_;
}

double Rectangle::circumference()
{
    return 2*height_+2*width_;
}

void Rectangle::print(int running_number)
{

    Color col=Shape::get_color();
    double a = area();
    double cir = circumference();

    Shape::print(running_number);

    cout<<COLOR_NAMES.at(col)<<" rectangle with width "<< width_<<
        " and height "<<height_<<endl;
    cout<<"Area: "<<a<<endl;
    cout<<"Circumference: "<<cir<<endl;


}
