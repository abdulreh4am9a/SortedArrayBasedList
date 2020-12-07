#include<iostream>
using namespace std;
template<typename T>
class list {
	T* data;
	int size, n, it;
public:
	list(int s = 100) {
		size = s;
		data = new T[size];
		n = -1;
		it = -1;
	}
	~list() {
		delete[]data;
	}
	void insert(const T& val) {
		if (full()) {
			throw("List is full");
		}
		int i, j;
		for (i = 0;i <= n;i++) {
			if (val < data[i]) {
				break;
			}
		}
		for (j = n + 1;j > i;j--) {
			data[j] = data[j - 1];
		}
		data[i] = val;
		n++;
	}
	bool find(T& val) const {
		int start, mid, end;
		start = 0;
		end = n;
		while (start <= end) {
			mid = (start + end) / 2;
			if (val < data[mid]) {
				end = mid - 1;
			}
			else if (val > data[mid]) {
				start = mid + 1;
			}
			else {
				val = data[mid];
				return true;
			}
		}
		return false;
	}
	bool update(const T& old_val, const T& new_val) {
		if (erase(old_val)) {
			insert(new_val);
			return true;
		}
		else {
			return false;
		}
	}
	bool erase(const T& val) {
		int i, j;
		for (i = 0;i <= n;i++) {
			if (val == data[i]) {
				break;
			}
		}
		if (i > n) {
			return false;
		}
		for (j = i;j < n;j++) {
			data[j] = data[j + 1];
		}
		n--;
		return true;
	}
	bool empty() const {
		return n == -1;
	}
	bool full() const {
		return n == size - 1;
	}
	void make_empty() {
		n = -1;
	}
	int length()const {
		return n + 1;
	}
	void reset() {
		it = -1;
	}
	bool is_last() const {
		return it == n;
	}
	T get_next() {
		if (is_last()) {
			throw("Last Element Reached");
		}
		it++;
		return data[it];
	}
	void operator=(const list<T>& rhs) {
		delete[]data;
		size = rhs.size;
		data = new T[size];
		n = rhs.n;
		it = -1;
		for (int i = 0;i < size;i++) {
			data[i] = rhs.data[i];
		}
	}
	list(const list<T>& rhs) {
		size = rhs.size;
		data = new T[size];
		n = rhs.n;
		it = -1;
		for (int i = 0;i < size;i++) {
			data[i] = rhs.data[i];
		}
	}
};