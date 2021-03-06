#pragma once

#include <bits/stdc++.h>

using namespace std;

class quote
{
public:

  quote() = default;

  quote (string book_number, double price);

  [[nodiscard]] string isbn() const;

  [[nodiscard]] virtual double net_price (size_t n) const;

  virtual ~quote() = default;

protected:

  double price {0.0};

private:

  string book_number;
};

double print_total (ostream &os, const quote &item, size_t n);
