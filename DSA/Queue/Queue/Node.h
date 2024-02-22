#pragma once
#include <iostream>
template <typename T>
class Node
{
	Node <T>* next;
	T value;
	Node <T>(T data) : value(data), next(nullptr) {};
};