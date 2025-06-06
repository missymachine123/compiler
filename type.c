#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "tree.h"
#include "symtab.h"
#include "k0gram.tab.h" 
#include <string.h>
#include <stdbool.h>
#include "tac.h"
 
struct typeinfo null_type = { NULL_TYPE };
struct typeinfo byte_type = { BYTE_TYPE };
struct typeinfo short_type = { SHORT_TYPE };
struct typeinfo integer_type = { INT_TYPE };
struct typeinfo long_type = { LONG_TYPE };
struct typeinfo float_type = { FLOAT_TYPE };
struct typeinfo double_type = { DOUBLE_TYPE };
struct typeinfo boolean_type = { BOOL_TYPE };
struct typeinfo string_type = { STRING_TYPE };
struct typeinfo char_type = { CHAR_TYPE };
struct typeinfo array_type = { ARRAY_TYPE };
struct typeinfo func_type = { FUNC_TYPE };
struct typeinfo class_type = { CLASS_TYPE };
struct typeinfo package_type = { PACKAGE_TYPE };
struct typeinfo any_type = { ANY_TYPE };
struct typeinfo void_type = { VOID_TYPE };

typeptr null_typeptr = &null_type;
typeptr byte_typeptr = &byte_type;
typeptr short_typeptr = &short_type;
typeptr integer_typeptr = &integer_type;
typeptr long_typeptr = &long_type;
typeptr float_typeptr = &float_type;
typeptr double_typeptr = &double_type;
typeptr boolean_typeptr = &boolean_type;
typeptr string_typeptr = &string_type;
typeptr char_typeptr = &char_type;
typeptr array_typeptr = &array_type;
typeptr func_typeptr = &func_type;
typeptr class_typeptr = &class_type;
typeptr package_typeptr = &package_type;
typeptr any_typeptr = &any_type;
typeptr void_typeptr = &void_type;


typeptr get_type(int category){
   typeptr rv;
   switch(category){
      case 385:
      //int
         rv = integer_typeptr;
      break;

      case 392:
      //string 
         rv = string_typeptr;
      break;

      case 383:
      //float 
         rv = float_typeptr;
      break;

      case 384:
      //double 
         rv = double_typeptr;
      break;

      case 386:
      //char literal 
         rv = char_typeptr;
      break;

      case 391:
      //bool literal 
         rv = boolean_typeptr;
      break;
      
      default:
         //fprintf(stderr, "Unknown type name: %s\n", typeName);
         return NULL;
   }
   return rv;

}

char* get_typename(int basetype){
   switch(basetype){
      case 1000000:
            return "NULL";
        case 1000001:
            return "Byte";
        case 1000002:
            return "Short";
        case 1000003:
            return "Int";
        case 1000004:
            return "Long";
        case 1000005:
            return "Float";
        case 1000006:
            return "Double";
        case 1000007:
            return "Boolean";
        case 1000008:
            return "String";
        case 1000009:
            return "Char";
        case 1000010:
            return "Array";
        case 1000011:
            return "Function";
        case 1000012:
            return "Class";
        case 1000013:
            return "Package";
        default:
            return "UNKNOWN_TYPE";
    }
}

typeptr mktype(int kind)
{
   typeptr new_type = (typeptr)malloc(sizeof(struct typeinfo));
   if (new_type == NULL) {
      fprintf(stderr, "Error: Memory allocation failed for type creation.\n");
      exit(EXIT_FAILURE);
   }
   new_type->basetype = kind;
   if (kind == FUNC_TYPE) {
      new_type->u.f.st = NULL; // Initialize symbol table for function types
      new_type->u.f.parameters = NULL; // Initialize parameters to NULL
      new_type->u.f.returntype = NULL; // Initialize return type to NULL
      new_type->u.f.nparams = 0; // Initialize number of parameters to 0
      new_type->u.f.defined = 0; // Default to prototype (not defined)
   }
   return new_type;
}

char *typenam[] =
   {"null","byte","short", "int", "long","float", "double","bool", "string","char",
    "array", "func", "class", "package", "any"}; /* "list", "dict", ... */


typeptr assignType(char *typeName) {
   if (typeName == NULL) {
      fprintf(stderr, "Type name is NULL\n");
      return NULL;
   }

   switch (typeName[0]) { // Use the first character to narrow down cases
      case 'n':
         if (strcmp(typeName, "null") == 0) return null_typeptr;
         break;
      case 'B':
         if (strcmp(typeName, "Byte") == 0) return byte_typeptr;
         else if (strcmp(typeName, "Boolean") == 0) return boolean_typeptr;
         break;
      case 'S':
         if (strcmp(typeName, "Short") == 0) return short_typeptr;
         else if (strcmp(typeName, "String") == 0) return string_typeptr;
         break;
      case 'I':
         if (strcmp(typeName, "Int") == 0) return integer_typeptr;
         break;
      case 'L':
         if (strcmp(typeName, "Long") == 0) return long_typeptr;
         break;
      case 'F':
         if (strcmp(typeName, "Float") == 0) return float_typeptr;
         break;
      case 'D':
         if (strcmp(typeName, "Double") == 0) return double_typeptr;
         break;
      case 'C':
         if (strcmp(typeName, "Char") == 0) return char_typeptr;
         else if (strcmp(typeName, "class") == 0) return class_typeptr;
         break;
      case 'A':
         if (strcmp(typeName, "Array") == 0) return array_typeptr;
         break;
      case 'f':
         if (strcmp(typeName, "func") == 0) return func_typeptr;
         break;
      case 'p':
         if (strcmp(typeName, "package") == 0) return package_typeptr;
         break;
      case 'a':
         if (strcmp(typeName, "any") == 0) return any_typeptr;
         break;
      case 'v':
         if (strcmp(typeName, "void") == 0) return void_typeptr;
         break;
      default:

         fprintf(stderr, "Unknown type name: %s\n", typeName);
         return NULL;
   }
   return NULL;
}

typeptr alctype(int base)
{  
   typeptr rv;
   if (base == NULL_TYPE) return null_typeptr;
   else if (base == BYTE_TYPE) return byte_typeptr;
   else if (base == SHORT_TYPE) return short_typeptr;
   else if (base == INT_TYPE) return integer_typeptr;
   else if (base == LONG_TYPE) return long_typeptr;
   else if (base == FLOAT_TYPE) return float_typeptr;
   else if (base == DOUBLE_TYPE) return double_typeptr;
   else if (base == BOOL_TYPE) return boolean_typeptr;
   else if (base == STRING_TYPE) return string_typeptr;
   else if (base == CHAR_TYPE) return char_typeptr;
   else if (base == ARRAY_TYPE) return array_typeptr;
   else if (base == FUNC_TYPE) return mktype(1000011);
   else if (base == CLASS_TYPE) return class_typeptr;
   else if (base == PACKAGE_TYPE) return package_typeptr;
   else if (base == ANY_TYPE) return any_typeptr;
   else if (base == VOID_TYPE) return void_typeptr;

   rv = (typeptr) calloc(1, sizeof(struct typeinfo));
   if (rv == NULL) return rv;
   rv->basetype = base;
   return rv;
}


// Function to calculate the number of parameters in a syntax tree
// This function traverses the tree and counts the parameters based on production rules.
int calc_nparams(struct tree *n)
{
   if (n == NULL) {
      // If the tree node is NULL, there are no parameters
      return 0;
   }

   int count = 0;

   // Traverse all the kids of the current node
   for (int i = 0; i < n->nkids; i++) {
      count += calc_nparams(n->kids[i]);
   }
   // If the current node represents a parameter, increment the count
   if (n->prodrule == 1007) {
      count++;
   }

   return count;
}
extern struct param * mk_nparams(struct tree *n);
extern int insert_sym(SymbolTable st, char *s, typeptr t);
extern void insert_type(SymbolTable st, char *s, typeptr t);
/* Construct a function type from syntax (sub)tree(s).
 * For this to make any sense, you have to pass in the subtrees
 * for the return type (r) and the parameter list (p).
 */
typeptr alcfunctype(char *returntype, struct tree *p, SymbolTable st)
{
   typeptr rv = alctype(FUNC_TYPE);
   if (rv == NULL) return NULL;
   rv->u.f.st = st; 
   rv->u.f.defined = 0; // 0 for prototype, 1 for defined function

 
   // Process the return type subtree
   if (returntype) {  
      rv->u.f.returntype = assignType(returntype); // Assuming returntype is a string 
   } else {
      rv->u.f.returntype = null_typeptr; // Default to null if no return type is provided
   }

   int nparams = calc_nparams(p);
   // printf("Number of parameters: %d\n", nparams);
   rv->u.f.nparams = nparams; // Set the number of parameters
   
   // Process the parameter list subtree
   if (p->kids[1] != NULL) { 
      rv->u.f.parameters = mk_nparams(p->kids[1]);
   } else {
      rv->u.f.parameters = NULL; // No parameters
   }
   // Print the parameters
   struct param *param = rv->u.f.parameters;

   while (param != NULL) {
      insert_type(st, param->name, param->type); // Insert parameter into the symbol table

      // printf("Parameter: %s, Type: %s\n-----------\n", param->name, typename(param->type));
      param = param->next;
   } 
   

   return rv;
}
 

char *typename(typeptr t)
{
   if (!t) return "(NULL)";
   else if (t->basetype < FIRST_TYPE || t->basetype > LAST_TYPE)
      return "(BOGUS)";
   else return typenam[t->basetype-1000000];
}

bool can_assign_to(int target_type, int value_type) {
   if (target_type == value_type)
       return true;
   
   if (target_type == DOUBLE_TYPE && 
       (value_type == FLOAT_TYPE || value_type == LONG_TYPE || 
        value_type == INT_TYPE || value_type == SHORT_TYPE || value_type == BYTE_TYPE))
       return true;
       
   if (target_type == FLOAT_TYPE && 
       (value_type == INT_TYPE || value_type == SHORT_TYPE || value_type == BYTE_TYPE))
       return true;
       
   if (target_type == LONG_TYPE && 
       (value_type == INT_TYPE || value_type == SHORT_TYPE || value_type == BYTE_TYPE))
       return true;
       
   if (target_type == INT_TYPE && 
       (value_type == SHORT_TYPE || value_type == BYTE_TYPE))
       return true;
       
   if (target_type == SHORT_TYPE && value_type == BYTE_TYPE)
       return true;
   return false;
}


