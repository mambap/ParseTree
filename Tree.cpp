#include <cmath>
#include <iostream>
#include <set>
#include <list>

struct Node
{
    std::string name;
    std::list<Node*> childs;
};

void listNode(Node& head, std::set<std::string>& nodesLists)
{
    for(const auto& child : head.childs)
    {
        if( nodesLists.find(child->name)  == nodesLists.end() )
        {
            nodesLists.insert(child->name);
            listNode(*child, nodesLists);
        }
    }
}
int main()
{
    Node node;
    std::set<std::string> nodesLists;
    listNode(node, nodesLists);
}
