#include "timer.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

/* Problem = I want to remove duplicates from a list of numbers
   I want to benchmark the two different approaches.
   Doing a benchmark you want to test for every different possibility,
   varying type, number of elements... */

/* Time class from header-file timer.hpp */
timer<> t;

/* using std::set, a tree that automatically get rid of duplicates if
   there is already the same key inserted in the tree */
template <typename I>
void set_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  /* std::set definition contains all the complexity of the algorithm */
  std::set<value_type> set{first, last}; 
  t.stop();
}

/* store in a std::vector, order the vector and call std::unique
   to reorganize and get rid of duplicates */
template <typename I>
void vector_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  //std::vector<value_type> v{first, last};
  //std::sort(v.begin(), v.end());
  std::sort(first,last);
  //auto it = std::unique(v.begin(), v.end());
  /* std::unique is not modifying the size of the original vector,
     only returning an operator to the last element before undefined
     elements
     
     e.g. 1 1 2 3 3 5
          1 2 3 5 * *
                 | iterator       */
  auto it = std::unique(first,last);
  t.stop();
  (void)std::distance(first,it);
}

using namespace std::chrono;
int main() {
  using value_type = int;
  /* For loop written with bit-shift, faster than multiplications
     n <<= 1 is equivalent to say n *= 2 */
  for (std::size_t n = 16; n < (1 << 25); n <<= 1) {
    std::vector<value_type> v(n);
    std::iota(v.begin(), v.end(), value_type(-1024));
    std::random_shuffle(v.begin(), v.end());
    for (std::size_t i = 0; i < n; ++i) {
      v[i] = int{v[i]} & 1023; // bitwise operation
      /* number above 1023 will be brought back to 0-1023 range
         creating repetitions in the vector */
    }
    std::cout << std::setw(15) << n << "\t";
    set_timed(n,v.begin(),v.end());
    //vector_timed(n, v.begin(), v.end());
  }
}
