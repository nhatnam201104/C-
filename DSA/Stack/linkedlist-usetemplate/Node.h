#pragma once
template <typename T> 
class Node
{
    public:
    Node <T> *Next;
    T Value;
    Node (T value) : Value (value),Next (nullptr){} ;
};