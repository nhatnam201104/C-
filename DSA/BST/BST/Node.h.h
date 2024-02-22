#pragma once
template <typename T> 
class Node {
public:
	Node <T>* left, * right;
	T value;
	Node(T value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
	typedef* Node<T> tree;
};