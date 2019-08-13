class Foo {
 public:
  Foo() { count = 1; }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    count = 2;
  }

  void second(function<void()> printSecond) {
    while (count != 2) {
      std::this_thread::yield();
    }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    count = 3;
  }

  void third(function<void()> printThird) {
    while (count != 3) {
      std::this_thread::yield();
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  int count;
};
