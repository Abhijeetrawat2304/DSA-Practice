bool backspaceCompare(char* s, char* t) {
    char stack1[10000];
    char stack2[10000];
    int top1=-1;
    int top2=-1;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='#'){
            if(top1!=-1){
                top1--;
            } 
        }
        else{
            stack1[++top1]=s[i];
        }
    }
    for(int i=0;t[i]!='\0';i++){
        if(t[i]=='#'){
            if(top2!=-1){
                top2--;
            } 
        }
        else{
            stack2[++top2]=t[i];
        }
    }
    if(top1!=top2){
        return false;
    }

    for(int i=0;i<=top1;i++){
        if(stack1[i]!=stack2[i]){
            return false;
        } 
    }
    return true;
    
}