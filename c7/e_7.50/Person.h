//
// Created by martin on 17/05/2022.
//
#pragma once
#include <bits/stdc++.h>

using namespace std;

class Person
      {
      public:
            // constructors

            Person () = default;

            Person (string n, string a);

            // getters

            [[nodiscard]] string name () const;

            [[nodiscard]] string address () const;

            // setters

            void set_name (const string &m_name);

            void set_address (const string &m_address);

            // IO methods

            static istream &read (istream &is, Person &person);

            static ostream &print (ostream &os, const Person &person);

      private:
            string m_name;
            string m_address;


      };

