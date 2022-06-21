//
// Created by martin on 27/05/2022.
//

#include "folder.h"

#include <utility>

folder::folder (string name) : m_name (move (name)) {}

folder::folder (const folder &folder) : messages (folder.messages), m_name (folder.m_name)
{
  for (auto &message : messages)
    {
      message->folders.insert (this);
    }
}

folder &folder::operator= (const folder &rhs)
{
  m_name = rhs.m_name;

  for (auto &message : messages)
    {
      message->folders.erase (this);
    }

  messages = rhs.messages;

  for (auto &message : messages)
    {
      message->folders.insert (this);
    }

  return *this;
}

folder::~folder()
{
  for (auto &message : messages)
    {
      message->folders.erase (this);
    }
}

void folder::insert (message &message)
{
  messages.insert (&message);
  message.folders.insert (this);
}

void folder::erase (message &message)
{
  messages.erase (&message);
  message.folders.erase (this);
}

void folder::add_message (message *message) { messages.insert (message); }

void folder::remove_message (message *message) { messages.erase (message); }

void folder::print_content()
{
  for (auto &message : messages)
    {
      cout << *message << " ";
    }
  cout << endl;
}

void swap (folder &lhs, folder &rhs)
{
  using std::swap;

  for (auto &message : lhs.messages)
    {
      message->folders.erase (&lhs);
    }
  for (auto &message : rhs.messages)
    {
      message->folders.erase (&rhs);
    }

  swap (lhs.m_name, rhs.m_name);
  swap (lhs.messages, rhs.messages);

  for (auto &message : lhs.messages)
    {
      message->folders.insert (&lhs);
    }
  for (auto &message : rhs.messages)
    {
      message->folders.insert (&rhs);
    }
}

const string &folder::name() const { return m_name; }

ostream &operator<< (ostream &os, const folder &folder)
{
  os << folder.name();
  return os;
}
