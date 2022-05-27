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

      Folder (const Folder &);

      Folder &operator= (const Folder &);

      ~Folder ();

      void save (Message &);

      void remove (Message &);

      void swap (Message &lhs, Message &rhs);

   private:
      set<Message *> messages;

      void add_message (Message *message);

      void remove_message (Message *message);

   };
