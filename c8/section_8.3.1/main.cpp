#include <bits/stdc++.h>

using namespace std;

struct Person_info
    {
        string name;
        vector<string> phones;
    };

istream &print (istream &is)
  {
    string temp;
    while (!is.eof())
      {
        is >> temp;
        cout << "Read: " << temp << endl;
      }
    return is;
  }

vector<string> read_from_file (const string &filename)
  {
    ifstream ifs { filename };

    if (!ifs)
      {
        cerr << "Error can't read file " << filename << endl;
        exit(EXIT_FAILURE);
      }

    vector<string> vec;

    for (string line ; !ifs.eof() ;)
      {
        getline(ifs, line);
        vec.push_back(line);
      }
    return vec;
  }

int main (int argc, char *argv[])
try
  {
//    string s { "Der var en gang en mand som boede i en spand." };
//    istringstream iss { s };
//    print(iss);
//
//    auto vec = read_from_file("../input_file.txt");
//
//    string s;
//    for (auto &line : vec)
//      {
//        istringstream iss { line };
//        while (iss >> s) // >> needed in while () or last word are printed twice.
//          {
//            cout << s << endl;
//          }
//      }

    ifstream ifs { "../input_file_persons.txt" };

    if (!ifs)
      {
        cerr << "Error can't read file " << endl;
        exit(EXIT_FAILURE);
      }

//    string line, word;
//    vector<Person_info> people;
//
//    while (getline(ifs, line))
//      {
//        Person_info info;
//        istringstream record { line };
//        record >> info.name;
//        while (record >> word)
//          {
//            info.phones.push_back(word);
//          }
//        people.push_back(info);
//      }

    string line, word;
    vector<Person_info> people;

    istringstream record;

    while (getline(ifs, line))
      {
        Person_info info;
        record.str(line);

        record >> info.name;
        while (record >> word)
          {
            info.phones.push_back(word);
          }
        people.push_back(info);
        record.clear();
      }

    for (auto &person : people)
      {
        cout << person.name << " ";
        for (auto &phone : person.phones)
          {
            cout << phone << " ";
          }
        cout << endl;
      }

      // e 8.12 there are multiple phones stored in a vector.

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }














