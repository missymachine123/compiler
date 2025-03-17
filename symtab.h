typedef struct sym_table {
   int nBuckets;			/* # of buckets */
   int nEntries;		   
   char *name;
   struct sym_table *parent;		/* enclosing scope, superclass etc. */
   struct sym_entry **tbl;
   /* more per-scope/per-symbol-table attributes go here */
   } *SymbolTable;

   typedef struct sym_entry {
      SymbolTable table;			/* what symbol table do we belong to*/
       char *s;				/* string */
       struct sym_entry *next;
       } *SymbolTableEntry;

