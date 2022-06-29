#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(struct stack *ptr, char ch)
{
    if (isfull(ptr))
    {
        printf("stack is full !\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = ch;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("nothing to pop");
        return -1;
    }
    else{
        char ch=ptr->arr[ptr->top];
        ptr->top--;
        return ch;
    }
}
 int stacktop(struct stack *ptr){
       return ptr->arr[ptr->top];
 }
int pra(char *exp){
struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
sp->size=1000;
sp->top=-1;
sp->arr=(char*)malloc(sp->size*sizeof(char));
for(int i=0;exp[i]!='\0';i++){
    if(exp[i]=='('){
        push(sp,exp[i]);
    }
   else if(exp[i]==')'){
        if(isempty(sp)){
        return 0;
        }
        else {
            pop(sp);
        }
    }
}
if(isempty(sp)){
    return 1;
}
else{
    return 0;
}
}
int main(){
    char *exp=")jdfhjahsdfh(";
    if(pra(exp)){
        printf("parnthesis matching!\n");
    }
    else{
        printf("parenthesis not matching!\n");
    }


    
    return 0;
}
