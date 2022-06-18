#pragma once
//
// Created by martin on 18/06/2022.
//
#include <bits/stdc++.h>
#include "SalesData.hpp"

using namespace std;

struct Token
   {
      Token () : m_token(INT),
          ival { 0 }
        {

        }

      Token (const Token &token) : m_token(token.m_token)
        {
          copy_union(token);
        }

      ~Token ()
        {
          if (m_token == STR)
            {
              sval.~string();
            }
          else if (m_token == SALES_DATA)
            {
              sdval.~SalesData();
            }
        }

      Token &operator= (const string &s)
        {
          if (m_token == SALES_DATA)
            {
              sdval.~SalesData();
            }
          if (m_token == STR)
            {
              sval = s;
            }
          else
            {
              new(&sval) string(s);
            }

          m_token = STR;
          return *this;
        }

      Token &operator= (const SalesData &sales_data)
        {
          if (m_token == SALES_DATA)
            {
              sdval = sales_data;
            }
          else
            {
              if (m_token == STR)
                {
                  sval.~string();
                }
              new(&sdval) SalesData(sales_data);
            }

          m_token = SALES_DATA;
          return *this;
        }

      Token &operator= (const Token &token)
        {
          if (m_token == STR && token.m_token != STR)
            {
              sval.~string();
            }
          else if (m_token == STR && token.m_token == STR)
            {
              sval = token.sval;
            }
          else if (m_token == SALES_DATA && token.m_token != SALES_DATA)
            {
              sdval.~SalesData();
            }
          else if (m_token == SALES_DATA && token.m_token == SALES_DATA)
            {
              sdval = token.sdval;
            }
          else
            {
              copy_union(token);
            }
          m_token = token.m_token;
          return *this;
        }

      Token &operator= (char c)
        {
          if (m_token == STR)
            {
              sval.~string();
            }
          cval = c;
          m_token = CHAR;
          return *this;
        }

      Token &operator= (int i)
        {
          if (m_token == STR)
            {
              sval.~string();
            }
          ival = i;
          m_token = INT;
          return *this;
        }

      Token &operator= (double d)
        {
          if (m_token == STR)
            {
              sval.~string();
            }
          else if (m_token == SALES_DATA)
            {
              sdval.~SalesData();
            }
          dval = d;
          m_token = DBL;
          return *this;
        }

      friend std::ostream &operator<< (std::ostream &os, const Token &token)
        {
          switch (token.m_token)
            {
              case Token::INT:
                os << token.ival;
              break;
              case Token::CHAR:
                os << token.cval;
              break;
              case Token::DBL:
                os << token.dval;
              break;
              case Token::STR:
                os << token.sval;
              break;
              case SALES_DATA:
                os << token.sdval;
              break;
            }
          return os;
        }

   private:
      enum
          {
              INT, CHAR, DBL, STR, SALES_DATA
          } m_token;
      union
          {
              char cval;
              int ival;
              double dval;
              string sval;
              SalesData sdval;
          };

      void copy_union (const Token &token)
        {
          switch (token.m_token)
            {
              case Token::INT:
                ival = token.ival;
              break;
              case Token::CHAR:
                cval = token.cval;
              break;
              case Token::DBL:
                dval = token.dval;
              break;
              case Token::STR:
                new(&sval) string(token.sval);
              break;
              case SALES_DATA:
                new(&sdval) SalesData(token.sdval);
              break;
            }
        }
   };