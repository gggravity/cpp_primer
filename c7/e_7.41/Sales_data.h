//
// Created by martin on 16/05/2022.
//

#include <bits/stdc++.h>

using namespace std;

// 0-201-78655 5 98.50

class Sales_data
      {
      public:
            // constructors

            Sales_data();

            explicit Sales_data (string book_number);

            Sales_data (string book_number, unsigned units_sold, double price);

            explicit Sales_data (istream &is);

            // methods

            Sales_data &combine (const Sales_data &rhs);

            // getters and setters

            [[nodiscard]] const string &isbn () const;

            void set_isbn (const string &book_no);

            [[nodiscard]] unsigned int units_sold () const;

            void set_units_sold (unsigned int units_sold);

            [[nodiscard]] double revenue () const;

            void set_revenue (double revenue);

      private:

            [[nodiscard]] double avg_price () const;

            std::string m_book_no;
            unsigned m_units_sold { 0 };
            double m_revenue { 0.0 };

            // friends

            friend Sales_data add (const Sales_data &lhs, const Sales_data &rhs);

            friend istream &read (istream &is, Sales_data &item);

            friend ostream &print (ostream &os, const Sales_data &item);

      };



