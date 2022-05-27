#pragma once
//
// Created by martin on 27/05/2022.
//
#include<bits/stdc++.h>
#include <ostream>
#include "Folder.h"

using namespace std;

class Folder;

class Message
   {
      friend class Folder;

   public:
      explicit Message (const string &str = "");

      Message (const Message &message);

      Message &operator= (const Message &rhs);

      ~Message ();

      void swap (Message &lhs, Message &rhs);

      void save (Folder &folder);

      void remove (Folder &folder);

      friend ostream &operator<< (ostream &os, const Message &message);

   private:
      string contents;
      set<Folder *> folders;

      void add_to_folders (const Message &message);

      void remove_from_folders ();

   };
