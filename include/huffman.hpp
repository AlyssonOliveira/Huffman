#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <cstring>
#include "huffTree.hpp"
#include "converter.hpp"



class Huffman{
    private:
        Node *huffTree;
        std::string inFileName;
        std::string outFileName;
        std::fstream inFile;
        std::fstream outFile;
        class Comparable{
            public:
                bool operator()(Node *, Node *);
        };
        std::map<char,int> frequencies;
        std::map<char,int>::iterator mapIterator;
        std::map<char,std::string> codes;
        std::priority_queue<Node *, std::vector<Node *>, Comparable> ordFrequencies;
        BinDecConverter *converter;

        void fillFrequencies();
        void fillQueue();
        void buildTree();
        void printTree(); //Debug only
        void codify();

        int readHeader();
    public:
        Huffman();
        ~Huffman();
        void setInFile(std::string);
        void setOutFile(std::string);
        
        void compress();
        
        void decompress();
        void print();
};

#endif