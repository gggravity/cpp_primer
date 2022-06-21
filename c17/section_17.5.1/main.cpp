#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    cout << boolalpha << true << " " << false << endl;
    cout << noboolalpha << true << " " << false << endl;

    cout << hex << showbase << 123 << endl;
    cout << hex << noshowbase << 123 << endl;

    cout << dec << showpoint << 123.0 << endl;
    cout << noshowpoint << 123.0 << endl;

    cout << showpos << 123.0 << endl;
    cout << noshowpos << 123.0 << endl;

    cout << uppercase << 123e123 << endl;
    cout << nouppercase << 123e123 << endl;

    cout << oct << 123 << endl;
    cout << dec << 123 << endl;

    cout << left << setw (10) << 321 << endl;
    cout << right << setw (10) << 321 << endl;
    cout << internal << setw (10) << 321 << endl;

    cout << fixed << setw (10) << 123e2 << endl;
    cout << scientific << setw (10) << 123e2 << endl;
    cout << hexfloat << setw (10) << 123e2 << endl;
    cout << defaultfloat << setw (10) << 123e2 << endl;

    cout << "----------------------------------------" << endl;

    cout << "default format: " << 100 * sqrt (2.0) << '\n'
         << "scientific: " << scientific << 100 * sqrt (2.0) << '\n'
         << "fixed decimal: " << fixed << 100 * sqrt (2.0) << '\n'
         << "dexadecimal: " << hexfloat << 100 * sqrt (2.0) << '\n'
         << "use default: " << defaultfloat << 100 * sqrt (2.0) << "\n\n";

    cout << "----------------------------------------" << endl;

    cout << setw (20) << left << "default format: " << right << setw (20) << 100 * sqrt (2.0) << '\n'
         << setw (20) << left << "scientific: " << right << setw (20) << scientific << 100 * sqrt (2.0) << '\n'
         << setw (20) << left << "fixed decimal: " << right << setw (20) << fixed << 100 * sqrt (2.0) << '\n'
         << setw (20) << left << "dexadecimal: " << right << setw (20) << hexfloat << 100 * sqrt (2.0) << '\n'
         << setw (20) << left << "use default: " << right << setw (20) << defaultfloat << 100 * sqrt (2.0) << "\n\n";

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
