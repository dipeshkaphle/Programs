#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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
  int ind;
  unordered_map<int, int> mp;
  TreeNode *helper(vector<int> &preorder, int l, int r) {
    if (l >= r) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[ind]);
    ind++;
    root->left = helper(preorder, l, mp[root->val]);
    root->right = helper(preorder, mp[root->val] + 1, r);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    ind = 0;
    mp.clear();
    int i = 0;
    for (int x : inorder)
      mp[x] = i++;
    return helper(preorder, 0, inorder.size());
  }
};

int main() {}
