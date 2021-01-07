class OrderedStream {
 public:
  OrderedStream(int n) {
    stream_ = vector<string>(n, "");
    pointer_ = 0;
  }

  vector<string> insert(int id, string value) {
    stream_[id - 1] = value;
    vector<string> result;
    for (; pointer_ < stream_.size(); ++pointer_) {
      if (stream_[pointer_] == "") {
        break;
      }
      result.push_back(stream_[pointer_]);
    }
    return result;
  }

 private:
  vector<string> stream_;
  int pointer_;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */