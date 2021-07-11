#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = size_t;

using ll = long long;
template <typename T> using Vec = std::vector<T>;

template <typename T> using o_set = std::set<T>;

template <typename T> using u_set = std::unordered_set<T>;

template <typename K, typename V> using u_map = std::unordered_map<K, V>;

template <typename K, typename V> using o_map = std::map<K, V>;

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  bool issame(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot)
      return true;
    if (!root || !subRoot)
      return false;
    return root->val == subRoot->val && issame(root->left, subRoot->left) &&
           issame(root->right, subRoot->right);
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot)
      return true;
    if (!root || !subRoot)
      return false;
    return issame(root, subRoot) || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }
};
int main() {}
