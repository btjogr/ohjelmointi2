#include <iostream>
#include <vector>
#include <cctype>
#include <stdexcept> // domain_error, invalid_argument

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
    size_t pos = 0;

    while ((pos = tmp.find(delimiter)) != string::npos)
    {
        string word = tmp.substr(0, pos);
        tmp = tmp.substr(pos + 1);  // Move past the delimiter
        if (!(ignore_empty && word.empty())) {
            result.push_back(word);
        }
    }
    if (!(ignore_empty && tmp.empty())) {
        result.push_back(tmp);
    }
    return result;
}

double mean(const string& input)  // Don't change the function definition!
{
    // Tarkistetaan, ettei syöte ole tyhjä ennen kuin aloitetaan laskentaa
    if (input.empty()) {
        throw domain_error("No input");
    }

    vector<string> numbers = split(input, ' ', true);

    double sum = 0.0;
    int count = 0;

    for (const string& num_str : numbers) {
        try {
            double num = stod(num_str);  // Muunnetaan merkkijono doubleksi
            sum += num;
            count++;
        } catch (invalid_argument&) {
            throw invalid_argument("Not a valid number: " + num_str);
        }
    }

    if (count == 0) {
        throw domain_error("No valid numbers to compute mean");
    }

    return sum / count;
}

// Don't remove! Needed for tests.
#ifndef MEAN_TEST
int main()
{
    string input;
    double ans = 0.0;

    cout << "Enter numbers: ";
    getline(cin, input);

    try {
        ans = mean(input);
        cout << "Mean: " << ans << endl;
    } catch (domain_error&) {
        cout << "domain_error: No numbers"<< endl;
    } catch (invalid_argument&) {
        cout << "invalid_argument: stod" << endl;
    }

    return 0;
}
// Don't remove! Needed for tests.
#endif // MEAN_TEST
