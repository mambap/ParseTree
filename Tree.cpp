#include <cmath>
#include <iostream>
#include <set>
#include <list>

struct Node
{
    std::string name;
    std::list<Node*> childs;
    void populate()
    {       
           static int i = 0;
           if( i > 50)
           {
                return;
           }
           this->childs.push_back(new Node {std::to_string(i++), {}});
           this->childs.push_back(new Node {std::to_string(i++), {}});
           std::cout <<"value of i = " <<i <<"\n";
           for(auto child : this->childs)
           {
                child->populate();       
           }
    }
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
    node.populate();
    std::set<std::string> nodesLists;
    listNode(node, nodesLists);
    for(auto name : nodesLists)
    {
        std::cout << name << "\n";
    }
}
