
#include <list>
#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::list;
using std::cout;
using std::min;

// Least Recently Used (LRU) cache
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
      if (cache.find(key) != cache.end()) {
        touch(key);
        return cache[key];
      }
      return -1;
    }
    
    void put(int key, int value) {
      touch(key);
      cache[key] = value;
    }

private:

  void touch(int key) {

    // found
    if (pos.find(key) != pos.end()) {
      recent.erase(pos[key]);
    }

    if (recent.size() >= capacity_) {
      int last = recent.back();
      recent.pop_back();
      cache.erase(last);
      pos.erase(last);
    }

    recent.push_front(key);
    pos[key] = recent.begin();

  }

  int capacity_ = 0;
  list<int> recent;
  unordered_map<int, int> cache;
  unordered_map<int, list<int>::iterator> pos;

};



int main() {
  int capacity = 2;
  LRUCache* obj = new LRUCache(capacity);
  obj->put(1, 1);
  obj->put(2, 2);
  if (obj->get(1) != 1) {
    cout << "Faild\n";
    return 0;
  }

  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  obj->put(3, 3);
  if (obj->get(2) != -1) {
    cout << "Faild\n";
    return 0;
  }

  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  obj->put(4, 4);
  if (obj->get(2) != -1) {
    cout << "Faild\n";
    return 0;
  }
  if (obj->get(3) != 3) {
    cout << "Faild\n";
    return 0;
  }
  if (obj->get(4) != 4) {
    cout << "Faild\n";
    return 0;
  }

  cout << "Passed\n";
  return 0;
}