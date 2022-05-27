#pragma once
//
// Created by martin on 27/05/2022.
//
#include<bits/stdc++.h>
#include "Message.h"

using namespace std;

class Message;

class Folder
   {
      friend class Message;

   public:
      Folder () = default;

      Folder (const Folder &folder);

      Folder &operator= (const Folder &rhs);

      ~Folder ();

      void insert (Message &message);

      void erase (Message &message);

      void swap (Message &lhs, Message &rhs);

      void print();

   private:
      set<Message *> messages;

      void add_message (Message *message);

      void remove_message (Message *message);

   };
