#ifndef SET_LIST_HPP
#define SET_LIST_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <ranges>

template <typename T>
class SetList {
    struct ListNode {
        T data;
        std::shared_ptr<ListNode> next;
    };

public:
    class ListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit ListIterator(std::shared_ptr<ListNode> ptr = nullptr) : ptr(ptr) {}

        ListIterator& operator++() {
			if (ptr) {
				ptr = ptr->next;
			}
			return *this;
		}
        
		ListIterator operator++(int) {
			ListIterator tmp = *this;
			++(*this);
			return tmp;
		}

        T& operator*() const {
			return (ptr->data);
		}

        T* operator->() const {
			return &(ptr->data);
		}

        bool operator==(const ListIterator& other) const = default;/* {
			return (ptr == other.ptr);
		}*/

    private:
        std::shared_ptr<ListNode> ptr;
    };

    using value_type = T;
    using iterator = ListIterator;
    // Normally there would be a const_iterator too

    SetList() = default;

    template <std::ranges::input_range Rng>
    explicit SetList(Rng&& rng) {
        std::ranges::for_each(std::forward<Rng>(rng),
                              std::bind_front(&SetList::insert, this));
    }

    ListIterator begin() {
		return ListIterator(head);
	}

    ListIterator end() {
		return ListIterator(nullptr);
	}
    bool contains(const T& value) {
		std::shared_ptr<ListNode> curr = head;
		while (curr!=nullptr) {
			if (curr->data == value) {
				return true;
			}
			curr = curr->next;
		}
		return false;
	}

    ListIterator insert(T value) {
		if (contains(value)) {
			return end();
			}

		auto NewNode = std::make_shared<ListNode>(value);
		
		//if (!head || value < head->data) {
			NewNode->next = head;
			head = NewNode;
			return ListIterator(NewNode);
		//} 
		/*
		std::shared_ptr<ListNode> curr = head;
		
		while (curr->next != nullptr && !(value< curr->next->data)) {
			curr = curr->next;
		}
		NewNode->next = curr->next;
		curr->next = NewNode;

		return ListIterator(NewNode);
		*/
	}

private:
    std::shared_ptr<ListNode> head = nullptr;
};

#endif
