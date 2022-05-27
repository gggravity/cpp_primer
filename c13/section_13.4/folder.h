#pragma once
//
// Created by martin on 27/05/2022.
//
#include<bits/stdc++.h>
#include "message.h"

using namespace std;

class message;

struct folder
   {
      folder () = default;

      folder (const folder &folder);

      folder &operator= (const folder &rhs);

      ~folder ();

      void insert (message &message);

      void erase (message &message);

      void swap (message &lhs, message &rhs);

      void print ();

   private:
      set<message *> messages;

      void add_message (message *message);

      void remove_message (message *message);

      friend struct message;
   };
