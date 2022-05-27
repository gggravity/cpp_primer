#pragma once
//
// Created by martin on 27/05/2022.
//
#include<bits/stdc++.h>
#include <ostream>
#include "folder.h"

using namespace std;

class folder;

struct message
   {
      explicit message (const string &str = "");

      message (const message &message);

      message &operator= (const message &rhs);

      ~message ();

      void swap (message &lhs, message &rhs);

      void save (folder &folder);

      void remove (folder &folder);

      friend ostream &operator<< (ostream &os, const message &message);

   private:
      string contents;
      set<folder *> folders;

      void add_to_folders (const message &message);

      void remove_from_folders ();

      friend struct folder;

   };
