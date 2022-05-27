//
// Created by martin on 27/05/2022.
//

#include "Folder.h"

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
