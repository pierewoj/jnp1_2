#include "cstrdeque"
#include "cstrdequeconst"
#include <deque>
#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace jnp1 {
namespace {

map<unsigned long, deque<string>> &deque_map() {
  static map<unsigned long, deque<string>> *my_map =
      new map<unsigned long, deque<string>>();
  return *my_map;
}
}

unsigned long strdeque_new() {
  static unsigned long id = 0;
  deque<string> q;
  deque_map()[id] = q;
  return id++;
}

void strdeque_delete(unsigned long id) {
  if (id == emptystrdeque()) {
    // TODO PRINT DEBUG INFO
    return;
  }
  deque_map().erase(id);
}

size_t strdeque_size(unsigned long id) {
  if (!deque_map().empty() && deque_map().find(id)->first == id) {
    return deque_map().find(id)->second.size();
  } else
    return 0;
}

void strdeque_insert_at(unsigned long id, size_t pos, const char *value) {
  if (id == emptystrdeque()) {
    // TODO PRINT DEBUG INFO
    return;
  }
  if (!deque_map().empty() && deque_map().find(id)->first == id &&
      value != NULL) {
    string s(value);
    if (strdeque_size(id) <= pos) {
      deque_map().find(id)->second.push_back(s);
    } else {
      if (pos == 0) {
        deque_map().find(id)->second.push_front(s);
      } else {
        deque<string>::iterator it = deque_map().find(id)->second.begin();
        it = it + (pos - 1);
        deque_map().find(id)->second.insert(it, s);
      }
    }
  }
}

void strdeque_remove_at(unsigned long id, size_t pos) {
  if (strdeque_size(id) > pos) {
    deque<string>::iterator it = deque_map().find(id)->second.begin();
    it = it + pos;
    deque_map().find(id)->second.erase(it);
  }
}

const char *strdeque_get_at(unsigned long id, size_t pos) {
  if (strdeque_size(id) > pos && pos >= 0) {
    return deque_map().find(id)->second.at(pos).c_str();
  } else {
    return NULL;
  }
}

void strdeque_clear(unsigned long id) { deque_map().erase(id); }

int strdeque_comp(unsigned long id1, unsigned long id2) {
  if (strdeque_size(id1) == 0 && strdeque_size(id2) == 0)
    return 0;
  if (strdeque_size(id1) == 0)
    return -1;
  if (strdeque_size(id2) == 0)
    return 1;
  if (deque_map().find(id1)->second == deque_map().find(id2)->second)
    return 0;
  if (deque_map().find(id1)->second < deque_map().find(id2)->second)
    return -1;
  return 1;
}
}
