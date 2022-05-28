//
// Created by martin on 27/05/2022.
//

#include "message.h"
#include "folder.h"

message::message (const string &str) :
    contents(str)
  {

  }

// copy constructor
message::message (const message &message) :
    contents(message.contents),
    folders(message.folders)
  {
    add_to_folders(message);
  }

// copy assignment
message &message::operator= (const message &rhs)
  {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
  }

message::~message ()
  {
    remove_from_folders();
  }

void message::save (folder &folder)
  {
    folders.insert(&folder);
    folder.add_message(this);
  }

void message::remove (folder &folder)
  {
    folders.erase(&folder);
    folder.remove_message(this);
  }

void message::add_to_folders (const message &message)
  {
    for (auto folder : message.folders)
      {
        folder->add_message(this);
      }
  }

void message::remove_from_folders ()
  {
    for (auto folder : folders)
      {
        folder->remove_message(this);
      }
  }

ostream &operator<< (ostream &os, const message &message)
  {
    os << "\"" << message.contents << "\"";
    return os;
  }

void swap (message &lhs, message &rhs)
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

void message::print_folders ()
  {
    if (folders.empty())
      {
        cout << "the folder is empty";
      }
    for (auto &folder : folders)
      {
        cout << "\"" << *folder << "\"" << " ";
      }
  }

message &message::operator= (message &&other) noexcept
  {
    cout << "calling message move assignment operator..." << endl;
    if (this != &other)
      {
        remove_from_folders();
        contents = std::move(other.contents);
        move_folders(&other);
      }
    return *this;
  }

message::message (message &&other) noexcept :
    contents(std::move(other.contents))
  {
    cout << "calling message move constructor..." << endl;
    move_folders(&other);
  }

void message::move_folders (message *message)
  {
    folders = std::move(message->folders);
    for (auto folder : folders)
      {
        folder->remove_message(message);
        folder->add_message(this);
      }
    message->folders.clear();
  }
