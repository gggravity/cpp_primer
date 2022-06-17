#pragma once
//
// Created by martin on 03-06-22.
//

class QueryResult;

#include <bits/stdc++.h>
#include "TextQuery.h"

using namespace std;

class QueryBase
   {
      friend class Query;

   protected:
      virtual ~QueryBase () = default;

   private:
      [[nodiscard]] virtual QueryResult eval (const TextQuery &text_query) const = 0;

      [[nodiscard]] virtual string rep () const = 0;
   };
