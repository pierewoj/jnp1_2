#include <iostream>
#include <map>
#include <deque>
#include <string>
#include "cstrdeque"
#include "cstrdequeconst"

using namespace std;

namespace jnp1 {
	namespace {

		map<unsigned long, deque <string> >& Map()
		{
			static map<unsigned long, deque <string> >* myMap =
					new map< unsigned long, deque<string> > ();
			return *myMap;
		}
		
		bool debug() {
			#ifndef NDEBUG
				return true;
			#else
				return false;
			#endif
		}
	}

	unsigned long strdeque_new()
	{
		static unsigned long id = 0;
		deque <string> q;
		Map() [id] = q;
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_new:\n";
		}
		return id++;
	}

	void strdeque_delete(unsigned long id)
	{
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_delete: ";
		}
		if (id == emptystrdeque()) {
			if (debug()) {
				cerr << "attempt to delete the Empty Deque\n";
			}
			return;
		}
		Map().erase(id);
		if (debug()) {
			cerr << "deleted\n";
		}
	}

	size_t strdeque_size(unsigned long id)
	{
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_size: ";
		}
		if (!Map().empty() && Map().find(id)->first == id) {
			if (debug()) {
				cerr << "OK\n";
			}
			return Map().find(id)->second.size();
		} else {
			if (debug()) {
				cerr << "not exist\n";
			}
			return 0;
		}
	}

	void strdeque_insert_at(unsigned long id, size_t pos, const char* value)
	{
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_insert_at: ";
		}
		if (id == emptystrdeque()) {
			if (debug()) {
				cerr << "attempt to insert into the Empty Deque\n";
			}
			return;
		}
		if (!Map().empty() && Map().find(id)->first == id && value != NULL) {
			string s(value);
			if (strdeque_size(id) <= pos) {
				Map().find(id)->second.push_back(s);
			} else {
				if (pos == 0) {
					Map().find(id)->second.push_front(s);
				} else {
					deque<string>::iterator it = Map().find(id)->second.begin();
					it = it + (pos - 1);
					Map().find(id)->second.insert(it, s);
				}
			}
			if (debug()) {
				cerr << "inserted\n";
			}
		}
	}

	void strdeque_remove_at(unsigned long id, size_t pos)
	{
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_remove_at:";
		}
		if (strdeque_size(id) > pos) {
			deque<string>::iterator it = Map().find(id)->second.begin();
			it = it + pos;
			Map().find(id)->second.erase(it);
			if (debug()) {
				cerr << "removed\n";
			}
		} else {
			if (debug()) {
				cerr << " element not exist\n";
			}
		}
	}

	const char* strdeque_get_at(unsigned long id, size_t pos)
	{
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_get_at: ";
		}
		if (strdeque_size(id) > pos) {
			if (debug()) {
				cerr << "OK\n";
			}
			return Map().find(id)->second.at(pos).c_str();
		} else {
			if (debug()) {
				cerr << " element not exist\n";
			}
			return NULL;
		}
	}

	void strdeque_clear(unsigned long id)
	{
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_clear: ";
		}
		if (strdeque_size(id) > 0) {
			Map().find(id)->second.clear();
			if (debug()) {
				cerr << "cleared\n";
			}
		} else {
			if (debug()) {
				cerr << "not exist or has 0 elements\n";
			}
		}
	}

	int strdeque_comp(unsigned long id1, unsigned long id2)
	{
		if (debug()) {
			ios_base::Init();
			cerr << "strdeque_comp:\n";
		}
		if (strdeque_size(id1) == 0 && strdeque_size(id2) == 0)
			return 0;
		if (strdeque_size(id1) == 0)
			return -1;
		if (strdeque_size(id2) == 0)
			return 1;
		if (Map().find(id1)->second == Map().find(id2)->second)
			return 0;
		if (Map().find(id1)->second < Map().find(id2)->second)
			return -1;
		return 1;
	}
}
