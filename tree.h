#ifndef TREE_H
#define TREE_H

struct tree {
    int prodrule;          // Production rule associated with this node
    char *symbolname;      // Symbol name for this node
    int nkids;             // Number of children
    int id;                // Identifier for the node
    struct tree *kids[10]; // Array of pointers to child nodes (if nkids > 0)
    struct token *leaf;    // Pointer to token (if nkids == 0; NULL for ε productions)
    struct addr *first; // Pointer to address information (if applicable)
    struct addr *follow; // Pointer to follow information (if applicable)
    struct addr *ontrue; // Pointer to true address (if applicable)
    struct addr *onfalse; // Pointer to false address (if applicable)

    bool firstflag;
    bool followflag;
    bool ontrueflag;
    bool onfalseflag;
};


#endif /* TREE_H */
