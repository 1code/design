//
//  Set.h
//  Set
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Set_Set_h
#define Set_Set_h

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

// Set with STL Library
template<class T>
class SetSTL {
private:
    set<T> S;
    unsigned int max_elem;
    T max_val;
public:
    SetSTL(const unsigned int maxElem, const T maxVal) { max_elem = maxElem; max_val = maxVal; };
    unsigned int size() { return S.size(); };
    void insert(const T t) { if (S.size() < max_elem && t <= max_val) S.insert(t); };
    void print() {
        set<int>::iterator i;
        for (i = S.begin(); i != S.end(); ++i)
            cout << *i << " ";
        cout << endl;
    };
};

// Set Sorted Array
template<class T>
class SetArray {
private:
    T* S;
    unsigned int max_elem;
    unsigned int n;
public:
    SetArray(const unsigned int maxElem, const T maxVal) {
        S = new int[1 + maxElem];
        max_elem = maxElem;
        n = 0;
        S[0] = maxVal;
    };
    unsigned int size() { return n; };
    void insert(const T t) {
        if (t >= S[n] || n == max_elem) return;
        unsigned int i;
        for (i = 0; i < n && S[i] < t; i++);
        if (S[i] == t) return;
        for (unsigned int j = ++n; j > i; j--)
            S[j] = S[j-1];
        S[i] = t;
    };
    void print() {
        for (unsigned int i = 0; i < n; ++i)
            cout << S[i] << " ";
        cout << endl;
    };
};

// Set Sorted Link List
template<class T>
class SetList {
private:
    unsigned int max_elem;
    unsigned int n;
    struct node {
        T val;
        node *next;
        node(T v, node* p) { val = v; next = p; };
    };
    node *head, *sentinel;
public:
    SetList(unsigned int maxElem, T maxVal) {
        max_elem = maxElem;
        sentinel = head = new node(maxVal, NULL);
        n = 0;
    };
    unsigned int size() { return n; };
    node* insertR(T t, node* p) {
        if (t > p->val)
            p->next = insertR(t, p->next);
        else if (t < p->val) {
            p = new node(t, p);
            n++;
        }
        return p;
    };
    void insert (T t) {
        if (n == max_elem || t >= sentinel->val) return;
        head = insertR(t, head);
    };
    void print() {
        for (node* p = head; p != sentinel; p = p->next)
            cout << p->val << " ";
        cout << endl;
    };
};

// Set BST
template<class T>
class SetBST {
private:
    unsigned int max_elem;
    T max_val;
    unsigned int n;
    struct node {
        T val;
        node *left;
        node *right;
        node(T t) {val = t; left = right = NULL; };
    };
    node *root;
public:
    SetBST(unsigned int maxElem, T maxVal) {
        max_elem = maxElem;
        max_val = maxVal;
        root = NULL;
        n = 0;
    };
    unsigned int size() { return n; };
    node* insertR(T t, node* p) {
        if (!p) p = new node(t), n++; 
        else if (t > p->val) p->right = insertR(t, p->right);
        else if (t < p->val) p->left = insertR(t, p->left);
        return p;
    };
    void insert (T t) {
        if (n == max_elem || t >= max_val) return;
        root = insertR(t, root);
    };
    void printR(node *p) {
        if (!p) return;
        printR(p->left);	
        cout << p->val << " ";
        printR(p->right);
    };
    void print() {
        printR(root);
        cout << endl;
    };
};




// Set BitVec
template<class T>
class SetBitVec {
private:
    enum {BITSPERWORD = 32, SHIFT = 5, MASK = 0x1f};
    unsigned int max_elem;
    unsigned int n;
    T max_val;
    T *x;
    void set(T i) { x[i >> SHIFT] |= (1 << (i & MASK)); };
    void unset(T i) { x[i >> SHIFT] &= ~(1 << (i & MASK)); };
    bool isSet(T i) { return x[i >> SHIFT] & (1 << (i & MASK)); };
public:
    SetBitVec(const unsigned int maxElem, const T maxVal) { 
        max_elem = maxElem; 
        max_val = maxVal;
        x = new T[1 + max_val/BITSPERWORD];
        for (T i = 0; i < max_val; i++)
            unset(i);
        n = 0;
    };
    unsigned int size() { return n; };
    void insert(const T t) {
        if (n == max_elem || t >= max_val ) return;
        if (!isSet(t)) set(t), n++;
    };
    void print() {
        for (T i = 0; i < max_val; ++i)
            if (isSet(i)) cout << i << " ";
        cout << endl;
    };
};

// Set Bins
template<class T>
class SetBin {
private:
    unsigned int max_elem;
    unsigned int n;
    struct node {
        T val;
        node *next;
        node(T v, node* p) { val = v; next = p; };
    };
    node **bin, *sentinel;
public:
    SetBin(unsigned int maxElem, T maxVal) {
        max_elem = maxElem;
        bin = new node* [max_elem];
        sentinel = new node(maxVal, NULL);
        for (unsigned int i = 0; i < max_elem; i++)
            bin[i] = sentinel;
        n = 0;
    };
    unsigned int size() { return n; };
    node* insertR(T t, node* p) {
        if (t > p->val)
            p->next = insertR(t, p->next);
        else if (t < p->val) {
            p = new node(t, p);
            n++;
        }
        return p;
    };
    void insert (T t) {
        if (n == max_elem || t >= sentinel->val) return;
        unsigned int i = t / (1 + sentinel->val/max_elem);
        bin[i] = insertR(t, bin[i]);
    };
    void print() {
        for (unsigned int i = 0; i < max_elem; i++)
            for (node* p = bin[i]; p != sentinel; p = p->next)
                cout << p->val << " ";
        cout << endl;
    };
};


#endif
