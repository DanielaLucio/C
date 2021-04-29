#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"archivo.h"
#define MAX 100

main() {
  printf("--------------------------------------------------------------------------------------\n");
  printf("-   Welcome                                                                          -\n");
  printf("-   if you want to add a user use add and write user & password                      -\n");
  printf("-   if you want to delate a user use del and write the user & password (user>4)      -\n");
  printf("-   For the alphabetic view write view                                               -\n");
  printf("--------------------------------------------------------------------------------------\n\n");

	node* n = NULL;
	node* tree = NULL;

	int i, j, countspace;
	char c, username[MAX], pass[MAX], line[MAX], count[MAX];

    i = 0, j = 0, countspace = 0;

	while(1) {
		i = 0, j = 0;
		while(i<MAX-1&&(c = getchar()) != EOF && c != '\n') {
			line[i++] = c;
			if(isspace(c))
				countspace++;
		}
		line[i] = '\0';

		if(countspace >= 2) {
			i = getdata(count, line);
			i += getdata(username, line+i);
			i += getdata(pass, line+i);
		}

		if(strstr(count, "add") && username && pass) {
			n = insert(username, pass, tree);
			if (tree == NULL)
				tree = n;
			view(tree);
		}
		else if (strstr(count, "del"))
		   
			printf("user delate");
			
			
	  else if (strstr(count, "view") != NULL){//when we find view
      
      printf("\n\n");
      countspace=0;
      alpha(tree);
    }
		
		else
			printf("Invalid user, try again\n\n");
	}
}
 void alpha(node* position) {

  if (position != NULL) {
    alpha(position->left);
        if (position->password!=NULL){
            printf(" <%s>\n ", position->username);
        }
    alpha(position->right);
  }
}
void view(node* position) {
	
	if (position != NULL) {
    printf("the user is %s and the password is %s\n", position->username, position->password);
    printf("\n");
	return;
}
}


node *insert(char *username, char *password, node* pos) {

	node* temp;
	if (pos == NULL) {
		pos = (node*)malloc(sizeof(node));
    	pos->username = username;
    	pos->password = password;
	} else if(pos->right == NULL) {
		pos->right = (node*)malloc(sizeof(node));
    	pos->username = username;
    	pos->password = password;
	} else if(pos->left == NULL) {
		pos->left = (node*)malloc(sizeof(node));
    	pos->username = username;
    	pos->password = password;
}

    printf("User succesfully added\n\n");
	return pos;
}

int getdata(char *user, char *line) {

	int i = 0, j = 0;
	if(isspace(line[0]))
		while(isspace(line[++i]));
	while(!isspace(line[i]))
		user[j++] = line[i++];
	user[i] = '\0';
		return i;
}
void del(node* position) {
	
	if (position != NULL) {
    printf("the user is deleated", position->username, position->password);
    printf("\n");
	return;
}
}
//references Toño Cortes, Maria Jose Diaz Chavez, Rogelio Salinas, Dr Satu Elisa
