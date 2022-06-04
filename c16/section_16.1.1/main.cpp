#include <bits/stdc++.h>
#include "SalesData.h"

using namespace std;

template < typename T >
int compare (const T &v1, const T &v2)
  {
//    if (v1 < v2)
//      {
//        return -1;
//      }
//    if (v2 < v1)
//      {
//        return 1;
//      }

    if (less<T>()(v1, v2))
      {
        return -1;
      }
    if (less<T>()(v2, v1))
      {
        return 1;
      }

    return 0;
  }

template < typename Iterator, typename T >
Iterator find_in (Iterator begin, Iterator end, const T &find)
  {
    for (; begin != end ; ++begin)
      {
        if (*begin == find)
          {
            return begin;
          }
      }
    return end;
  }

void print (const int ia[], size_t size)
  {
    for (size_t i = 0 ; i != size ; ++i)
      {
        cout << ia[i] << " ";
      }
    cout << endl;
  }

template < typename T, size_t size >
void print_t (const T (&array)[size])
  {
    for (size_t i = 0 ; i != size ; ++i)
      {
        cout << array[i] << " ";
      }
    cout << endl;
  }

template < typename T, size_t size >
T *begin_t (T (&array)[size])
  {
    return array;
  }

template < typename T, size_t size >
T *end_t (T (&array)[size])
  {
    return array + size;
  }

template < typename T, size_t sz >
size_t constexpr size(T (&array)[sz])
  {
    return sz;
  }


int main ()
try
  {
    cout << compare("A", "B") << " ";
    cout << compare("A", "A") << " ";
    cout << compare("B", "A") << endl;
    cout << compare(string("A"), string("B")) << " ";
    cout << compare(string("A"), string("A")) << " ";
    cout << compare(string("B"), string("A")) << endl;
    cout << compare(1, 2) << " ";
    cout << compare(1, 1) << " ";
    cout << compare(2, 1) << endl;

    cout << "------------------" << endl;

    SalesData sales_data_1 { "123-XXX", 10, 10 };
    SalesData sales_data_2 { "123-YYY", 10, 10 };

    // error: no match for ‘operator<’ (operand types are ‘const SalesData’ and ‘const SalesData’)
//    cout << compare(sales_data_1, sales_data_2) << " ";
//    cout << compare(sales_data_1, sales_data_1) << " ";
//    cout << compare(sales_data_2, sales_data_1) << endl;

    vector<int> v1 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << *find_in(v1.begin(), v1.end(), 5) << endl;

    vector<string> v2 { "A", "B", "C", "D", "E", "F" };
    cout << *find_in(v2.begin(), v2.end(), "C") << endl;

    list<int> l1 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << *find_in(l1.begin(), l1.end(), 5) << endl;

    list<string> l2 { "A", "B", "C", "D", "E", "F" };
    cout << *find_in(l2.begin(), l2.end(), "C") << endl;

    cout << "-------------------" << endl;

    const int ia[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    string string_array[] { "A", "B", "C", "D", "E", "F" };

    print(ia, 9);

    print_t(ia);

    print_t(string_array);

    auto b = begin(ia);
    auto e = end(ia);

    cout << *b << " " << *e << endl;

    auto b_t = begin_t(ia);
    auto e_t = end_t(ia);

    cout << *b_t << " " << *( e_t - 1 ) << endl;

    auto b_s = begin(string_array);
    auto e_s = end(string_array);

    cout << *b_s << " " << *( e_s - 1 ) << endl;

    auto b_t_s = begin_t(string_array);
    auto e_t_s = end_t(string_array);

    cout << *b_t_s << " " << *( e_t_s - 1 ) << endl;

    cout << size(ia) << endl;
    cout << size(string_array) << endl;

    return 0;

  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


