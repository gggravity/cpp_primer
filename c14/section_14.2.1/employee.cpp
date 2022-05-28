//
// Created by martin on 28-05-22.
//

#include "employee.h"

ostream &operator<< (ostream &os, const employee &employee)
  {
    os << "name: " << employee.name << " adresse: " << employee.adresse << " country: " << employee.country
       << " phone: " << employee.phone << " id: " << employee.id;
    return os;
  }

istream &operator>> (istream &is, employee &employee)
  {
    is >> employee.name >> employee.adresse >> employee.country >> employee.phone >> employee.id;
    if (!is)
      {
        throw runtime_error("input error");
      }
      return is;
  }

bool employee::operator== (const employee &rhs) const
  {
    return name == rhs.name &&
           adresse == rhs.adresse &&
           country == rhs.country &&
           phone == rhs.phone &&
           id == rhs.id;
  }

bool employee::operator!= (const employee &rhs) const
  {
    return !( rhs == *this );
  }
