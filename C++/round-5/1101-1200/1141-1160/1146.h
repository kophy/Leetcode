class SnapshotArray {
 public:
  SnapshotArray(int length) {
    data_.resize(length);
    snap_id_ = 0;
  }

  void set(int index, int val) { data_[index][snap_id_] = val; }

  int snap() { return snap_id_++; }

  int get(int index, int snap_id) {
    auto iter = data_[index].upper_bound(snap_id);
    if (iter == data_[index].begin()) {
      return 0;
    }
    --iter;
    return iter->second;
  }

 private:
  vector<map<int, int>> data_;
  int snap_id_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */