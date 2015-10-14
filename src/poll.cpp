//
// Created by gabriel on 10/4/15.
//

#include <iostream>
#include "poll.h"

struct Node {
    int candidate;
    int votes;
    Node *next;
};

bool addVote(Node *&poll, int matricula);

void merge(Node *&listA, Node *prevA, int sizeA, Node *listB, Node *prevB, int sizeB);

void sort(Node *&list, int size, Node *prev = nullptr);

int get_winner(int *S, int n) {
    Node *list = nullptr;

    for (int i = 0; i < n; i++) {
        addVote(list, S[i]);
    }

    Node *node = list;
    int max_votes = 0;
    int winner_candidate = -1;
    while (node) {
        if (node->votes > max_votes) {
            winner_candidate = node->candidate;
            max_votes = node->votes;
        }
        node = node->next;
    }

    while (list) {
        Node *next = list->next;
        delete (list);
        list = next;
    }

    return /*list ->candidate; //*/winner_candidate;
}

void print_stats(int *S, int n) {
    Node *list = nullptr;
    int size = 0;
    for (int i = 0; i < n; i++) {
        if(addVote(list, S[i])) {
            size++;
        };
    }

    sort(list, size);

    Node *node = list;
    for (int i = 0; i < size; i++) {
//        std::cout << node << std::endl;
        std::cout << (i + 1) << ". " << node->candidate << " --- " << node->votes << std::endl;
        list = list->next;
        delete node;
        node = list;
    }
}


bool addVote(Node *&poll, int matricula) {
    if (!poll) {
        poll = new Node;
        poll->candidate = matricula;
        poll->votes = 1;
        poll->next = nullptr;
        return true;
    }

    Node *node = poll;

    do {
        if (node->candidate == matricula) {
            node->votes++;
            return false;
        } else if (!(node->next)) {
            node-> next = new Node;
            node = node->next;
            node->candidate = matricula;
            node->votes = 1;
            node->next = nullptr;
            return true;
        }
        node = node->next;
    } while (node);
    return false;
}

void merge(Node *&list, Node *prevA, int sizeA, Node *listB, Node *prevB, int sizeB) {
    bool firstTime = true;
    Node *listA = list;
    while (sizeA && sizeB) {
        if (listA->votes < listB->votes) {
            prevB->next = listB->next;
            if (prevA) {
                prevA->next = listB;
            }

            if (firstTime) {
                list = listB;
            }
            prevA = listB;
            listB->next = listA;
            listB = prevB->next;
            sizeB--;
        } else {
            prevA = listA;
            listA = listA->next;
            sizeA--;
        }
        firstTime = false;
    }
}

void sort(Node *&list, int size, Node *prev) {
    if (size <= 1) {
        // Se set tiver um elemento ou menos return
        return;
    }

    Node *prevA = prev;
    Node *listA = list;
    int sizeA = size / 2;

    sort(listA, sizeA, prevA);

    list = listA;

    Node *prevB = nullptr;
    Node *listB = list;
    int sizeB = size - sizeA;

    for (int i = 0; i < sizeA; i++) {
        prevB = listB;
        listB = listB->next;
    }

    // Sort ambas as metades
    sort(listB, sizeB, prevB);

    merge(listA, prevA, sizeA, listB, prevB, sizeB);
    list = listA;
}