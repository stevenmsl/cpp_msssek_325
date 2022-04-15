#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
using namespace sol325;
using namespace std;

/*takeaways
  - to achieve time O(n), you can only scan the array once
  - using [1,-1,5,-2,3], k=3  as an example
    - first we introduce a initial condition {0,-1}
      meaning the very first time all numbers sum up to 0,
      occurred at index -1
    - fast-forwarded and we scanned the first 4 numbers,
      at this point the sum is (1+(-1)+5+(-2)) = 3.
      3 - k = 3-3 = 0 so we need to know at which index
      it was the very first time we added up all numbers
      to a sum of 0, because after that index up to the
      4th number the sum will add up to k as 0 (up to that index) +
      k (every thing after that index up to the 4th number) = k
    - that index is -1, so the len is 3-(-1)=4, the
      subarray is [1,-1,5,-2]
    - now we scanned in the 5th number, the sum is now
      (1+(-1)+5+(-2)) + 3 = 6, we need to find at which
      index the sum is added up to 6-3 = 3 the very first
      time. That index is 3. So the then is 4-3=1, and
      the subarray is [3]
    - the max len is then 4



*/
int Solution::getMax(vector<int> &nums, int k)
{
  auto maxLen = 0;
  int sum = 0;
  /* record various accumulated sums along with their
     smallest index - when this first happened
     - if nums[0] = k, by introducing nums[0],
       the sum has gone up to k, so we need to
       find out the last time at which index we
       added up the sum to 0. Every thing
       after that index up to nums[0] the
       sum will add up to k again! the index
       is -1 in this case so len=0-(-1)=1
     - this is why we set up the edge case
       like this
  */
  auto sums = unordered_map<int, int>{{0, -1}};

  for (auto i = 0; i < nums.size(); i++)
  {
    sum += nums[i];

    const int base = sum - k;
    /*
      - from nums[0..sums[base]] the sum is base = sum-k
      - from nums[sums[base]+1..i] the sum has to be k
        as nums[0..i] the sum is sum by definition
        and (sum-k) + k = sum
    */
    if (sums.count(base))
      /* not including the sums[base] */
      maxLen = max(maxLen, i - sums[base]);
    /*only record the smallest index that this sum
      can be produced so we can find the longest subarray
    */
    if (!sums.count(sum))
      sums[sum] = i;
  }

  return maxLen;
}