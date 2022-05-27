//
// Created by martin on 27/05/2022.
//

#include "Message.h"
#include "Folder.h"

Message::Message (const string &str) :
    contents(str)
  {

  }

// copy constructor
Message::Message (const Message &message) :
    contents(message.contents),
    folders(message.folders)
  {
    add_to_folders(message);
  }

// copy assignment
Message &Message::operator= (const Message &rhs)
  {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
  }

Message::~Message ()
  {
    remove_from_folders();
  }

void Message::swap (Message &lhs, Message &rhs)
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

void Message::save (Folder &folder)
  {
    folders.insert(&folder);
    folder.add_message(this);
  }

void Message::remove (Folder &folder)
  {
    folders.erase(&folder);
    folder.remove_message(this);
  }

void Message::add_to_folders (const Message &message)
  {
    for (auto folder : message.folders)
      {
        folder->add_message(this);
      }
  }

void Message::remove_from_folders ()
  {
    for (auto folder : folders)
      {
        folder->remove_message(this);
      }
  }
