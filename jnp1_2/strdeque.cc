#include <iostream>
#include <map>
#include <deque>
#include <string>
#include "cstrdeque"

using namespace std;

namespace jnp1
{
	namespace {

		map < unsigned long, deque <string> > Mapa;

	}

	unsigned long strdeque_new() {
		static unsigned long id = 0;

		deque <string> q;
		Mapa[id] = q;
		return id++;
	}

	void strdeque_delete(unsigned long id) {
		Mapa.erase(id);
	}

	size_t strdeque_size(unsigned long id) {
		if(! Mapa.empty() && Mapa.find(id)->first == id) {
			return Mapa.find(id)->second.size();
		}
		else
			return 0;
	}

	void strdeque_insert_at(unsigned long id, size_t pos, const char* value) {
		if(! Mapa.empty() && Mapa.find(id)->first == id && value != NULL) {
			string s (value);
			if(strdeque_size(id) <= pos) {
				Mapa.find(id)->second.push_back(s);
			}
			else {
				if(pos == 0) {
					Mapa.find(id)->second.push_front(s);
				}
				else {
					deque<string>::iterator it = Mapa.find(id)->second.begin();
					it = it + (pos - 1);
					Mapa.find(id)->second.insert(it, s);
				}
			}
		}
	}

	void strdeque_remove_at(unsigned long id, size_t pos) {
		if(strdeque_size(id) > pos) {
			deque<string>::iterator it = Mapa.find(id)->second.begin();
			it = it + pos;
			Mapa.find(id)->second.erase(it);
		}
	}

	const char* strdeque_get_at(unsigned long id, size_t pos) {
		if(strdeque_size(id) > pos) {
			return Mapa.find(id)->second.at(pos).c_str();
		}
		else {
			return NULL;
		}
	}

	// usuwa elementy, czy usuwa kolejke?
	void strdeque_clear(unsigned long id) {
		Mapa.erase(id);
	}

	/*
	 * To usuwa elementy.
	 void strdeque_clear(unsigned long id) {
	 if(strdeque_size(id) > 0) {
	 Mapa.find(id)->second.clear();
	 }
	 }
	 */

	int strdeque_comp(unsigned long id1, unsigned long id2) {
		if(strdeque_size(id1) == 0 && strdeque_size(id2) == 0)
			return 0;
		if(strdeque_size(id1) == 0)
			return -1;
		if(strdeque_size(id2) == 0)
			return 1;
		if(Mapa.find(id1)->second == Mapa.find(id2)->second)
			return 0;
		if(Mapa.find(id1)->second < Mapa.find(id2)->second)
			return -1;
		return 1;
	}
}
