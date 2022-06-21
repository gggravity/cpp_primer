#pragma once
//
// Created by martin on 27/05/2022.
//
#include "message.h"
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class message;

struct folder
{
  explicit folder (string name = "unknown folder");

  folder (const folder &folder);

  folder &operator= (const folder &rhs);

  ~folder();

  void insert (message &message);

  void erase (message &message);

  void print_content();

  [[nodiscard]] const string &name() const;

  friend ostream &operator<< (ostream &os, const folder &folder);

private:

  string m_name;

  set<message *> messages;

  void add_message (message *message);

  void remove_message (message *message);

  friend struct message;

  friend void swap (folder &lhs, folder &rhs);

  friend void swap (message &lhs, message &rhs);
};

void swap (folder &lhs, folder &rhs);