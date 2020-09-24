#include <iostream>

class ListEntry {
  int m_v;
  ListEntry *m_next;

public:
  ListEntry(int v, ListEntry *next = nullptr) : m_v(v), m_next(next) {}
  ListEntry *getNext() { return m_next; }
  void setNext(ListEntry *next) { m_next = next; }

  int getValue() { return m_v; }
};

class List {
  ListEntry *m_head;

public:
  List() : m_head(nullptr) { std::cerr << "List is created\n"; };
  ~List() {
    std::cerr << "List is deleted\n";
    ListEntry *p = m_head;
    while (p) {
      ListEntry *n = p->getNext();
      delete p;
      p = n;
    }
  }

  void insert(int v) {
    ListEntry *entry = new ListEntry(v, m_head);
    m_head = entry;
  }

  typedef std::pair<bool, int> int_bool_pair;
  int_bool_pair remove_at_index(unsigned idx) {
    ListEntry *prev = nullptr;
    ListEntry *curr = m_head;

    unsigned i = 0;
    while (i < idx && curr) {
      prev = curr;
      curr = curr->getNext();
      i = i + 1;
    }

    if (!curr) {
      std::cerr << "remove_at_index: index beyond list size\n";
      return std::make_pair(false, 0);
    }

    prev->setNext(curr->getNext());

    int v = curr->getValue();
    delete curr;

    return std::make_pair(true, v);
  }
  bool is_empty() { return m_head; }

  ListEntry *get_head() { return m_head; }

  void print(std::ostream &out) {
    if (m_head)
      print_rec(out, *m_head);
  }
  void print_rec(std::ostream &out, ListEntry &entry) {

    out << entry.getValue();
    if (entry.getNext()) {
      out << ", ";
      print_rec(out, *(entry.getNext()));
    }
  }
};

std::ostream &operator<<(std::ostream &out, List &v) {
  v.print(out);
  return out;
}

int main(void) {
  std::cout << "Hello world!\n";

  int r;
  std::unique_ptr<List> l(new List());
  l->insert(5);
  l->insert(4);
  l->insert(3);

  // l->print(std::cerr);
  // std::cerr << "\n";
  std::cerr << *l << "\n";

  for (unsigned i = 0; i < 3; i++) {
    auto res = l->remove_at_index(1);
    if (res.first) {
      std::cerr << "Removed element: " << res.second << "\n";
    } else {
      std::cerr << "Index too large: idx=" << i << "\n";
    }
  }

  return 0;
}
