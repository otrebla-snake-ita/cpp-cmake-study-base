#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg { "hello", "c++", "world", "from", "otreblA!"};

    for (const string& word : msg)
        cout << word << ' ';

    cout << endl;
}