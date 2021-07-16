
#include <vector>
#include <limits>
#include <iostream>


 bool is_sorted(const std::vector<int>& numbers) {
   int last_num = -std::numeric_limits<int>::max();
   bool sorted = true;

   for (int i = 0; i < numbers.size(); ++i) {
     if (numbers[i] < (int)last_num) {

       std::cout << "inversion a[" << i << "]: " << numbers[i] << ", a[" << i -1 << "]: " << last_num << "\n";

       sorted = false;
     }
     last_num = numbers[i];
   }
   return sorted;
 }