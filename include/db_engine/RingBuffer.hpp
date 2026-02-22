#pragma once
#include <cassert>
#include <vector>

// head == tail == empty
// (tail + 1) % capacity == head // keep one space empty to avoid risks


// 1,2,5,4
// head = 2 tail = 3

template <typename T>
class RingBuffer {
public:
	explicit RingBuffer(size_t capacity) : buffer_capacity(capacity), buffer_data(capacity), head(0), tail(0) {
		assert(capacity >  1 && "capacity must be greater than 1");
	}

	bool push(const T& value) {
		auto next_tail = (tail + 1) % buffer_capacity;
		// is buffer empty?
		if (head == tail) {
			// buffer empty
			buffer_data[tail] = value;
			tail = next_tail;
			return true;
		}
		// is buffer full?

		if (next_tail == head) {
			//buffer full
			return false;
		}
		// not empty and not full
		buffer_data[tail] = value;
		tail = next_tail;
		return true;

	}
	bool pop(T& out) {
		// is it empty?
		if (head == tail) {
			// nothing to pop
			return false;
		}
		// return head
		out = buffer_data[head];
		head = (head + 1) % buffer_capacity;
		return true;
	}

private:
	// your data members
	size_t buffer_capacity{0};
	std::vector<T> buffer_data;
	size_t head{0};
	size_t tail{0};
};