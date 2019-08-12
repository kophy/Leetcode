class Solution {
 public:
  string defangIPaddr(string address) {
    return std::regex_replace(address, std::regex("[.]"), "[.]");
  }
};
