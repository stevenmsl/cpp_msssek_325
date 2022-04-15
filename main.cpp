#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol325;

/*
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
*/

tuple<vector<int>, int, int> testFixture1()
{

  return make_tuple(vector<int>{1, -1, 5, -2, 3}, 3, 4);
}

/*
Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
*/
tuple<vector<int>, int, int> testFixture2()
{
  return make_tuple(vector<int>{-2, -1, 2, 1}, 1, 2);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << "result: " << to_string(sol.getMax(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << "result: " << to_string(sol.getMax(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}