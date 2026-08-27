int minAddToMakeValid(char* s) {
    char stack[10000];
    int top = -1;
    int count=0;

    for(int i = 0; s[i] != '\0'; i++)
    {
        
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[++top] = s[i];
        }
        else
        {
            
            if(top == -1)
            {
                count++;
                continue;
            
            }

            if((s[i] == ')' && stack[top] == '(') ||
               (s[i] == ']' && stack[top] == '[') ||
               (s[i] == '}' && stack[top] == '{'))
            {
                top--;  
                
            }else
            {
                count++;
                top--;
            }
        }
    }
    return count+top+1;
}