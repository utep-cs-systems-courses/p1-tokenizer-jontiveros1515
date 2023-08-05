#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */

int space_char(char c){
  int dec;
  dec = isspace(c);
  if (dec == 0){
  return 0;
  } 
  else{
    return 1;
  }

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
  int non_space_char(char c){
    int dec;
    dec = isspace(c);
    if (dec == 0){
      return 1;
    }
      else{
	return 0;
      }

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
      char *word_start(char *str){
	if(strcmp(str, "")==0){
	  return NULL;
	}
	while(strcmp(str," ") !=0 || strcmp(str, "")==0)
	  str++;
	return str;
      } 
	
/* Returns a pointer terminator char following *word */
char *word_terminator(char *word);
 if(strcmp(word,"")==0){
   return NULL;
 }
 int i = strlen(str)-1; //here i used the method strlen just to check for the lebgth of the string
 while(strcmp(word[i],"")!=0){
   i--;
 }
 return word[i];
    }

/* Counts the number of words in the string argument. */
int count_words(char *str);
 int count =0,i,n;
 n=strlen(str);
 for(i=0; i<n; i++){
   if(strcmp(str[i],"")==0)
     count++;
 }
 if(strcmp(str,"")==0)
   return 0;
 else if(count ==0)
   return 1;
 else
   return count +1;
  }

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
  char *copy_str(char *inStr, short len){
    char s[strlen(inStr)];
    int start;
    int i =0,j=0;
    for(j=start; j<len; j++){
      s[i++]=inStr[j];
    }
    s[i++]="\0";
    return s;
  }

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
  char **tokenize(char* str){
    int count = count_words(str);
    char** tokens =(char**)malloc((count+1) * (sizeof(char*)));
    char* temp =str;
    for(int i =0; i<count; i++){
      temp = word_start(temp);
      tokens[i] = copy_str(temp,(word_terminator(temp) - word_start(temp)));
      temp = word_terminator(temp);
    }
    tokens[count] = '\0';
    return tokenzs;x
  }

/* Prints all tokens. */
  void print_tokens(char **tokens){
    int end = count_tokens(tokens);
    int counter = 0;

    printf("tokens: %d\n", end+1);
    while(counter<end){
      if(counter ==(end-1)){
	printf("token[%d] = %s", counter, *tokens);;
	printf("token[%d] = 0\n", counter+1);
	counter ++;
      }
      else{
	printf("token[%d] = %\n", counter, *tokens);
	counter++;
	tokens++;
      }
    }
    printf("--------\n");
  }

/* Frees all tokens and the vector containing themx. */
  void free_tokens(char **tokens){
    for(int i=0; tokens[i] !=0; i++){
      free(tokens[i]);
    }
    free(tokens);
  }

#endif

 
