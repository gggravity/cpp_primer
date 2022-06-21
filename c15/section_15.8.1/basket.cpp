//
// Created by martin on 02-06-22.
//

#include "basket.h"

void basket::add_item (const shared_ptr<quote> &sale) { items.insert (sale); }

bool basket::compare (const shared_ptr<quote> &lhs, const shared_ptr<quote> &rhs) { return lhs->isbn() < rhs->isbn(); }

double basket::total_receipt (ostream &os) const
{
  double sum {0.0};

  for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound (*iter))
    {
      sum += print_total (os, **iter, items.count (*iter));
    }

  os << "Total Sale: " << sum << endl;

  return 0;
}

void basket::add_item (const quote &sale) { items.insert (shared_ptr<quote> (sale.clone())); }

void basket::add_item (quote &&sale) { items.insert (shared_ptr<quote> (std::move (sale).clone())); }
