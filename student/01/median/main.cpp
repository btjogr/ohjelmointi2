#include <iostream>
#include <vector>
#include <cctype>

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

double mean(const string& input)  // Don't change the function definition!
{


    vector<string> numbers = split(input, ' ', true);


    double sum = 0.0;
    int count = 0;

    for (const string& num_str : numbers) {
        try {
            double num = stod(num_str);  // Muunnetaan merkkijono doubleksi
            sum += num;
            count++;

        }catch (const invalid_argument&) {
            throw invalid_argument("Not a valid number: " + num_str);}
    }
    if (input.empty()) {
        throw domain_error("No input");
    }

    return sum / count;
}

// Don't remove! Needed for tests.
#ifndef MEAN_TEST
int main()
{
    vector<string> vec;
    string input;
    double ans = 0.0;

    cout << "Enter numbers: ";
    getline(cin, input);

    try {
        ans = mean(input);
        cout << "Mean: " << ans << endl;
    } catch (const domain_error ex) {
        cout << "No input" << endl;
    } catch (const invalid_argument & ex) {
        cout << "Not a double" << endl;
    }

    return 0;
}
// Don't remove! Needed for tests.
#endif // MEAN_TEST
// Don't remove! Needed for tests.
