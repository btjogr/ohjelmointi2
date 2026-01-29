#include "shape.hh"
#include "circle.hh"
#include "rectangle.hh"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Splits the given string into several strings, by using the given delimiter
// as a separator.
// Returns the splitted string as a vector such that each string part is an
// element of the vector.
// User can specify if empty parts will be ignored or not.
vector<string> split(const string& str, const char delimiter,
                     bool ignore_empty = false)
{
    vector<string> result;
    string tmp = str;

    while(tmp.find(delimiter) != string::npos)
    {
        string word = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and word.empty()))
        {
            result.push_back(word);
        }

    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

// Goes through the given vector of Shapes and prints each element
// (by calling their print functions).
void print_shapes(vector<shared_ptr<Shape>> shapes)
{
    for(long long unsigned int i =0;i<shapes.size();i++){

        cout<<endl;
        shapes[i]->print(i+1);

    }
}

int main()
{
    cout << "Enter file name: ";
    string file_name = "";
    getline(cin, file_name);
    ifstream file(file_name);
    if(not file)
    {
        cout << "File not found" << endl;
        return EXIT_FAILURE;
    }
    string line = "";

    vector<shared_ptr<Shape>> shapes;

    // Goes through the input file line by line and splits each line.
    // Based on the content of each line, creates either a Circle
    // or a Rectangle, and pushes the shape to the vector shapes.

    try{

        while(getline(file, line))
        {

            vector<string> rivi = split(line,'\n');

            for(auto rv : rivi){

                vector<string> osio = split(rv,' ');


                    char c = osio[0][0];
                    double d1 = stod(osio[1]);

                    if(osio.size()==2){






                        shared_ptr<Circle> cir = make_shared<Circle>(c,d1);

                        shapes.push_back(cir);

                    }
                    else if(osio.size()==3){
                        double d2 = stod(osio[2]);

                        shared_ptr<Rectangle> rec = make_shared<Rectangle>(c,d1,d2);

                        shapes.push_back(rec);


                    }







                // for(auto r : osio){

                //     std::cout<<"::"<<r<<std::endl;

                // }



               // std::cout<<rv<<std::endl;








            }







            // TODO:
            // Each line should start with a color code. After it, there should
            // be either one or two double values.
            // - If there is a single double value, create a Circle object.
            // - If there are two double values, create a Rectangle object.
            // - In both cases, push the newly created object to the vector shapes.

        }

        print_shapes(shapes);
    }
    catch(...){
        return EXIT_FAILURE;
    }




    return 0;
}
