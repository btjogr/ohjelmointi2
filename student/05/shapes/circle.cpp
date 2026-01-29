#include "circle.hh"
#include "shape.hh"
using namespace std;
Circle::Circle(char color, double radius) : Shape(color), radius_(radius) {



}

Circle::~Circle()
{

}

double Circle::area()
{


    return PI*radius_*radius_;


}

double Circle::circumference()
{

    return 2*PI*radius_;
}

void Circle::print(int running_number)
{

    Color col=Shape::get_color();
    double a = area();
    double cir = circumference();

    Shape::print(running_number);

    cout<<COLOR_NAMES.at(col)<<" circle with radius "<< radius_<<endl;
    cout<<"Area: "<<a<<endl;
    cout<<"Circumference: "<<cir<<endl;

}
