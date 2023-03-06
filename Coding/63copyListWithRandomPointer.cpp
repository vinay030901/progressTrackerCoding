#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next, *random;
    Node(int val) : val(val), next(nullptr), random(nullptr) {}
    Node() : val(0), next(nullptr), random(nullptr) {}
    Node(int val, Node *next, Node *random) : val(val), next(next), random(random) {}
};
Node *copyRandomList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        Node *front = temp->next;
        Node *copy = new Node(temp->val);
        temp->next = copy;
        copy->next = front;
        temp = front;
    }
    temp = head;
    while (temp)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    temp = head;
    Node *ans = new Node(0);
    Node *copy = ans;
    while (temp)
    {
        Node *front = temp->next->next;
        copy->next = temp->next;
        temp->next = front;
        copy = copy->next;
        temp = front;
    }
    return ans->next;
}