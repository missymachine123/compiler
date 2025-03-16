/*
 * If I ever finish this, it will be a stripped down version of symtab
 * that has removed the string buffery stuff.
 */

 #ifndef SYMTAB_H
 #define SYMTAB_H
 
 
 typedef struct sym_table {
  int nBuckets;            /* This is the number of buckets in the hash table. Buckets are used to store entries that hash to the same value.*/
  int nEntries;            /* # of entries in the table */
  struct sym_table *parent; /* enclosing scope, superclass etc. */
  struct sym_entry **tbl;  /* array of pointers to symbol entries */
  /* more per-scope/per-symbol-table attributes go here */
} *SymbolTable;

typedef struct sym_entry {
  SymbolTable table;       /* what symbol table do we belong to */
  char *s;                 /* string representing the symbol */
  struct sym_entry *next;  /* pointer to the next entry in the same bucket */
} *SymbolTableEntry;

#define pushscope(stp) do { stp->parent = current; current = stp; } while (0)
#define popscope() do { current = current->parent; } while(0)
 #endif					/* SYMTAB_H */
 