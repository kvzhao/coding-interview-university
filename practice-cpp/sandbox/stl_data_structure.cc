

#include <deque>

using std::deque;


int main() {

  deque<int> deq{5, 6};
  deq.push_front(3);
  auto front =  deq.front();
  deq.pop_back();


  return 0;
}