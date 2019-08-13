class FooBar {
 private:
  int n;
  std::mutex m1, m2;

 public:
  FooBar(int n) {
    this->n = n;
    m2.lock();
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      m1.lock();
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      m2.unlock();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      m2.lock();
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      m1.unlock();
    }
  }
};
