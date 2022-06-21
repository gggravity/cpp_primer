#pragma once

#include <bits/stdc++.h>

using namespace std;

class quote
{
public:

  quote() = default;

  quote (string book_number, double price);

  quote (const quote &other);  // copy constructor

  quote &operator= (const quote &other);  // copy assignment operator

  quote (quote &&other) noexcept;  // move constructor

  quote &operator= (quote &&other) noexcept;  // move assignment operator

  virtual ~quote();

  [[nodiscard]] string isbn() const;

  virtual void debug();

  [[nodiscard]] virtual double net_price (size_t count) const;

protected:

  double price {0.0};

private:

  string book_number;
};

double print_total (ostream &os, const quote &item, size_t n);
