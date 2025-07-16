#ifndef TREE_H
#define TREE_H

typedef struct Tree Tree;

struct Tree {
    char ope;
    Tree* lop;
    Tree* rop;
    double ln;
};

double eval(Tree* tree);

#endif