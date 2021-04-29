#define MAX 100
char copy(char name);
int getdata(char *user, char *line);
char *strstr(char*, char*);

typedef struct treenode {
  char *username;
  char *password;
  struct treenode *left;
  struct treenode *right;
} node;

node* insert(char *name, char *password, node* pos);
void alpha(node* position);
