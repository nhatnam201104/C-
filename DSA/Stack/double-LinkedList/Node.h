#pragma once
class Node 
{
    public:
    Node*next,*previous;
    int data;
    Node (int value) : data (value),next (nullptr),previous (nullptr){};
};