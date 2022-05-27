//
// Created by martin on 27/05/2022.
//

#include "folder.h"

folder::folder (const folder &folder) :
    messages(folder.messages)
  {
    for (auto &message : messages)
      {
        message->folders.insert(this);
      }
  }

folder &folder::operator= (const folder &rhs)
  {
    for (auto &message : messages)
      {
        message->folders.erase(this);
      }

    messages = rhs.messages;

    for (auto &message : messages)
      {
        message->folders.insert(this);
      }

    return *this;
  }

folder::~folder ()
  {
    for (auto &message : messages)
      {
        message->folders.erase(this);
      }
  }

void folder::insert (message &message)
  {
    messages.insert(&message);
    message.folders.insert(this);
  }

void folder::erase (message &message)
  {
    messages.erase(&message);
    message.folders.erase(this);
  }

void folder::add_message (message *message)
  {
    messages.insert(message);
  }

void folder::remove_message (message *message)
  {
    messages.erase(message);
  }

void folder::swap (message &lhs, message &rhs)
  {
    using std::swap;

    for (auto folder : lhs.folders)
      {
        folder->remove_message(&lhs);
      }
    for (auto folder : rhs.folders)
      {
        folder->remove_message(&rhs);
      }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto folder : lhs.folders)
      {
        folder->add_message(&lhs);
      }
    for (auto folder : rhs.folders)
      {
        folder->add_message(&rhs);
      }
  }

void folder::print ()
  {
    for (auto &message : messages)
      {
        cout << *message << " ";
      }
      cout << endl;
  }

