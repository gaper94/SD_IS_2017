#pragma once

#include <iostream>

template<typename K, typename V>
class BinaryTree
{
public:
    BinaryTree()
        : root(nullptr)
    {
    }

    void insert(const K&, const V&);
    V* find(const K&);
    void remove(const K&);
    void print();
private:
    struct Node
    {
        Node() : key(), value(), left(nullptr), right(nullptr) {}
        K key;
        V value;
        Node* left;
        Node* right;
    };
    void insert_helper(const K&, const V&, Node*&);
    V* find_helper(const K&, Node*);
    void remove_helper(const K&, Node*&);
    void print_helper(Node*);
    Node* find_min(Node*);
    Node* root;
};

template<typename K, typename V>
void BinaryTree<K,V>::insert(const K& key, const V& value)
{
    insert_helper(key, value, root);
}

template<typename K, typename V>
V* BinaryTree<K,V>::find(const K& key)
{
    return find_helper(key, root);
}

template<typename K, typename V>
void BinaryTree<K,V>::remove(const K& key)
{
    remove_helper(key, root);
}

template<typename K, typename V>
void BinaryTree<K,V>::print()
{
    print_helper(root);
}

template<typename K, typename V>
void BinaryTree<K,V>::insert_helper(const K& key, const V& value, Node*& node)
{
    if(node == nullptr)
    {
        node = new Node;
        node->key = key;
        node->value = value;
    }
    // Go left
    else if(key < node->key)
    {
        insert_helper(key, value, node->left);
    }
    // Go right
    else if(key > node->key)
    {
        insert_helper(key, value, node->right);
    }
    // Node is already in tree
    else
    {
        std::cout << "Node is already in node\n";
    }
}

template<typename K, typename V>
V* BinaryTree<K,V>::find_helper(const K& key, Node* node)
{
    // key is not found
    if(node == nullptr)
    {
        return nullptr;
    }
    // Go search left
    else if(key < node->key)
    {
        return find_helper(key, node->left);
    }
    // Go search right
    else if(key > node->key)
    {
        return find_helper(key, node->right);
    }
    // Yeah, found it
    else
    {
        return &node->value;
    }
}
template<typename K, typename V>
void BinaryTree<K,V>::remove_helper(const K& key, Node*& node)
{
    // key is not in the tree
    if(node == nullptr)
    {
        std::cout << "Key is not in the tree\n";
    }
    // Search it left
    else if(key < node->key)
    {
        remove_helper(key, node->left);
    }
    // search it right
    else if(key > node->key)
    {
        remove_helper(key, node->right);
    }
    else
    {
        // two ancessors
        if(node->right != nullptr && node->left != nullptr)
        {
            Node* to_delete = find_min(node->right);
            node->key = to_delete->key;
            node->value = to_delete->value;
            remove_helper(node->key, node->right);
        }
        else
        {
            Node* to_delete = node;
            if(node->left != nullptr)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
            delete to_delete;
        }
    }
}

template<typename K, typename V>
void BinaryTree<K,V>::print_helper(Node* node)
{
    if(node != nullptr)
    {
        std::cout << node->value << std::endl;
        print_helper(node->left);
        print_helper(node->right);
    }
}

template<typename K, typename V>
typename BinaryTree<K,V>::Node* BinaryTree<K,V>::find_min(BinaryTree::Node* node)
{
    if(node->left == nullptr)
    {
        return node;
    }
    else
    {
        find_min(node->left);
    }
}
