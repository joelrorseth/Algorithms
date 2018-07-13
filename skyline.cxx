//
// The Skyline Problem
// Given building corrdinates, determine the critical points of the skyline
// that is formed. Points are given as [left x, right x, height] vectors.
// Buildings are rectangles always.
//
// Joel Rorseth
//

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> get_skyline(const vector<vector<int>>& buildings) {
  
  multimap<int, int> coords;
  multiset<int> heights = { 0 };
  map<int, int> corners;
  vector<pair<int, int>> results;
  
  // Sort individual coords by inserting into multimap
  // Coords maps beginx -> height, and maps endx -> -height
  
  for (const vector<int> & b : buildings) {
    coords.emplace(b[0], b[2]);
    coords.emplace(b[1], -b[2]);
  }
  
  // Go thru xcoords left to right
  // Add starting xcoords (their heights) to multiset, remove if end xcoords
  
  for (const pair<int, int> & p : coords) {
    
    if (p.second > 0)
      heights.insert(p.second);
    else
      heights.erase(heights.find(-p.second));
    
    // Corner for this xcoord is the largest height in set currently
    corners[p.first] = *heights.rbegin();
  }
  
  
  // Delete points with equal heights, by taking the leftmost (the first)
  unique_copy(corners.begin(), corners.end(),
      back_insert_iterator<vector<pair<int, int>>>(results),
      [](pair<int,int> l, pair<int,int> r) {
        return l.second == r.second;
      });
  
  return results;
}



// Driver
int main() {

  cout << "Buildings:\n";
  const vector<vector<int>> buildings{
    {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
  
  for (const auto & b: buildings) {
    cout << '(' << b[0] << ',' << b[1] << ")->" << b[2] << '\n';
  }
  
  cout << "\n\nSkyline:\n";
  for (const auto & p: get_skyline(buildings)) {
    cout << '(' << p.first << ',' << p.second << ")\n";
  }
}
