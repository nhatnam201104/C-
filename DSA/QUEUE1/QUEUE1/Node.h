#pragma once
#include <iostream>
template <typename T>
class Node
{
public:
	Node <T>* next;
	T value;
	Node <T>(T data) : value(data), next(nullptr) {};
};