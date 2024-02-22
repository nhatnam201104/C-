#pragma once
class Node
{
public:
	Node* prev, * next;
	int data;
	Node(int value) : data(value), next(nullptr), prev(nullptr) {} ;


};