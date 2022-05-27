//
// Created by martin on 27/05/2022.
//

#include "Folder.h"

Folder::Folder (const Folder &folder) :
    messages(folder.messages)
  {
    for (auto &message : messages)
      {
        message->folders.insert(this);
      }
  }

Folder &Folder::operator= (const Folder &rhs)
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

Folder::~Folder ()
  {
    for (auto &message : messages)
      {
        message->folders.erase(this);
      }
  }

void Folder::insert (Message &message)
  {
    messages.insert(&message);
    message.folders.insert(this);
  }

void Folder::erase (Message &message)
  {
    messages.erase(&message);
    message.folders.erase(this);
  }

void Folder::add_message (Message *message)
  {
    messages.insert(message);
  }

void Folder::remove_message (Message *message)
  {
    messages.erase(message);
  }

void Folder::swap (Message &lhs, Message &rhs)
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

void Folder::print ()
  {
    for (auto &message : messages)
      {
        cout << *message << " ";
      }
      cout << endl;
  }

