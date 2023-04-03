#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    int freq;
    Node* left;
    Node* right;
    Node(char data, int freq){
        this->data = data;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

class Compare{
public:
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string str){
    if(root==NULL){
        return;
    }
    if(root->data != '$'){
        cout<<root->data<<": "<<str<<endl;
    }
    printCodes(root->left, str+"1");
    printCodes(root->right, str+"0");
}

void HuffmanEncoding(string str){
    int n = str.length();
    priority_queue<Node*, vector<Node*>, Compare> pq;
    vector<int> freq(26, 0);
    for(int i=0;i<n;i++){
        freq[str[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            pq.push(new Node('a'+i, freq[i]));
        }
    }
    while(pq.size()!=1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* top = new Node('$', left->freq+right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    printCodes(pq.top(), "");
}


int main(){
    string str;
    cin>>str;
    HuffmanEncoding(str);
    return 0;
}