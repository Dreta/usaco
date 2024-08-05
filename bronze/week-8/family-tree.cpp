#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Node
{
public:
    string data;
    vector<Node *> children;
    Node *parent;
    Node(string data)
    {
        this->data = data;
        this->parent = nullptr;
    }
};

int main()
{
    int N;
    string queryX;
    string queryY;
    cin >> N >> queryX >> queryY;

    map<string, Node *> nodes;
    for (int i = 0; i < N; i++)
    {
        string parent;
        string child;
        cin >> parent >> child;

        if (nodes.find(parent) == nodes.end())
        {
            nodes[parent] = new Node(parent);
        }
        if (nodes.find(child) == nodes.end())
        {
            nodes[child] = new Node(child);
        }

        nodes[child]->parent = nodes[parent];
        nodes[parent]->children.push_back(nodes[child]);
    }

    // Find all ancestors of queryX and queryY
    vector<Node *> ancestorsX;
    vector<Node *> ancestorsY;
    Node *currentlyAt = nodes[queryX];
    while (currentlyAt != nullptr)
    {
        ancestorsX.push_back(currentlyAt);
        currentlyAt = currentlyAt->parent;
    }
    currentlyAt = nodes[queryY];
    while (currentlyAt != nullptr)
    {
        ancestorsY.push_back(currentlyAt);
        currentlyAt = currentlyAt->parent;
    }

    // Find lowest common ancestor (LCA)
    Node *lca = nullptr;
    int lcaDistanceX = 0;
    int lcaDistanceY = 0;
    for (int i = 0; i < ancestorsX.size(); i++)
    {
        for (int j = 0; j < ancestorsY.size(); j++)
        {
            if (ancestorsX[i] == ancestorsY[j])
            {
                lca = ancestorsX[i];
                lcaDistanceX = i;
                lcaDistanceY = j;
                break;
            }
        }
        if (lca != nullptr)
            break;
    }

    if (lca == nullptr)
    {
        cout << "NOT RELATED" << endl;
        return 0;
    }

    if (lcaDistanceX > 1 && lcaDistanceY > 1)
    {
        cout << "COUSINS" << endl;
        return 0;
    } else if (lcaDistanceX == 1 && lcaDistanceY == 1) {
        cout << "SIBLINGS" << endl;
    } else if (lcaDistanceX == 0 || lcaDistanceY == 0)
    {
        cout << (lcaDistanceX == 0 ? queryX : queryY) << " is the ";
        for (int i = 0; i < (lcaDistanceX == 0 ? lcaDistanceY : lcaDistanceX) - 2; i++)
        {
            cout << "great-";
        }
        if ((lcaDistanceX == 0 ? lcaDistanceY : lcaDistanceX) > 1) {
            cout << "grand-";
        }
        cout << "mother of " << (lcaDistanceX == 0 ? queryY : queryX) << endl;
    }
    else
    {
        cout << (lcaDistanceX == 1 ? queryX : queryY) << " is the ";
        for (int i = 0; i < (lcaDistanceX == 1 ? lcaDistanceY : lcaDistanceX) - 2; i++)
        {
            cout << "great-";
        }
        cout << "aunt of " << (lcaDistanceX == 1 ? queryY : queryX) << endl;
    }
}