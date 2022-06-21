//
// Created by martin on 28-05-22.
//

#include "employee.h"

employee::employee() : name ("no name"), adresse ("no adresse"), country ("no country"), phone ("no phone"), id (9999)
{
  cout << "calling default constructor" << endl;
}

employee::employee (string name, string adresse, string country, string phone, unsigned int id)
    : name (std::move (name)), adresse (std::move (adresse)), country (std::move (country)), phone (std::move (phone)),
      id (id)
{
}

ostream &operator<< (ostream &os, const employee &employee)
{
  os << "name: " << employee.name << " adresse: " << employee.adresse << " country: " << employee.country
     << " phone: " << employee.phone << " id: " << employee.id;
  return os;
}

istream &operator>> (istream &is, employee &employee)
{
  is >> employee.name >> employee.adresse >> employee.country >> employee.phone >> employee.id;
  if (! is)
    {
      throw runtime_error ("input error");
    }
  return is;
}

bool employee::operator== (const employee &rhs) const
{
  return name == rhs.name && adresse == rhs.adresse && country == rhs.country && phone == rhs.phone && id == rhs.id;
}

bool employee::operator!= (const employee &rhs) const { return ! (rhs == *this); }

employee &employee::operator= (employee &&other) noexcept
{
  cout << "move assignment operatoer called" << endl;

  if (this == &other)
    {
      return *this;
    }

  name = std::move (other.name);
  adresse = std::move (other.adresse);
  country = std::move (other.country);
  phone = std::move (other.phone);
  id = other.id;

  return *this;
}

employee::employee (employee &&other) noexcept
    : name (std::move (other.name)), adresse (std::move (other.adresse)), country (std::move (other.country)),
      phone (std::move (other.phone)), id (other.id)
{
  cout << "move constructor called" << endl;
}

employee::operator bool() const { return id == 666; }
