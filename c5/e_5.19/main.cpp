#include <iostream>

using namespace std;

int
main()
{
    string s1;
    string s2;
    string try_again;
    do {
        cout << "please enter two strings." << endl;
        cin >> s1 >> s2;

        if (s1.size() > s2.size())
            cout << "The first string is the largest." << endl;
        if (s2.size() > s1.size())
            cout << "The second string is the largest." << endl;
        if (s1.size() == s2.size())
            cout << "The strings are of equal size." << endl;

        cout << "Want to try again? [y/n]";
        cin >> try_again;
    } while (try_again != "n");

    return 0;
}
