#include <bits/stdc++.h>

using namespace std;

int main()
try
  {

    map<string, function<double (double, double)>> calculator;

    calculator.insert ({"+", plus<>()});
    calculator.insert ({"-", minus<>()});
    calculator.insert ({"*", multiplies<>()});
    calculator.insert ({"/", divides<>()});
    //    calculator.insert({ "%", modulus<>() });
    calculator.insert ({"==", equal_to<>()});
    calculator.insert ({"!=", not_equal_to<>()});
    calculator.insert ({">", greater<>()});
    calculator.insert ({"<", less<>()});
    calculator.insert ({">=", greater_equal<>()});
    calculator.insert ({"<=", less_equal<>()});

    double a {1};
    double b {2};

    cout << a << " + " << b << " = " << calculator["+"](a, b) << endl;
    cout << a << " - " << b << " = " << calculator["-"](a, b) << endl;
    cout << a << " * " << b << " = " << calculator["*"](a, b) << endl;
    cout << a << " / " << b << " = " << calculator["/"](a, b) << endl;
    //    cout << a << " % " << b << " = " << calculator["%"](a, b) << endl;
    cout << a << " == " << b << " = " << calculator["=="](a, b) << endl;
    cout << a << " != " << b << " = " << calculator["!="](a, b) << endl;
    cout << a << " > " << b << " = " << calculator[">"](a, b) << endl;
    cout << a << " < " << b << " = " << calculator["<"](a, b) << endl;
    cout << a << " >= " << b << " = " << calculator[">="](a, b) << endl;
    cout << a << " <= " << b << " = " << calculator["<="](a, b) << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
