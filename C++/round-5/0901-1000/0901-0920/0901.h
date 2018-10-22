class StockSpanner {
 public:
  StockSpanner() { index = 0; }

  int next(int price) {
    while (!data.empty() && data.top().second <= price) {
      data.pop();
    }
    int span = (data.empty()) ? index + 1 : (index - data.top().first);
    data.push(make_pair(index, price));
    ++index;
    return span;
  }

 private:
  stack<pair<int, int>> data;
  int index;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
