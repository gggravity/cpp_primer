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

      message &operator= (message &&other) noexcept;

      message (message &&other) noexcept;

      ~message ();

      void save (folder &folder);

      void remove (folder &folder);

      void print_folders();

      void move_folders(message *message);

      friend ostream &operator<< (ostream &os, const message &message);

   private:
      string contents;
      set<folder *> folders;

      void add_to_folders (const message &message);

      void remove_from_folders ();

      friend struct folder;

      friend void swap (folder &lhs, folder &rhs);

      friend void swap (message &lhs, message &rhs);

   };

void swap (message &lhs, message &rhs);