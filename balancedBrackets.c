string isBalanced(string s) {
   
    stack<char> store;
    bool balanced = true;
   
    for (char x:s) {
        switch(x) {
        case '(':
        case '{':
        case '[': 
             store.push(x);
             break;

        case ')':
            if(!store.empty() && store.top() == '(') {
                store.pop();
                break;
            }
            return "NO";          

        case '}':
            if(!store.empty() && store.top() == '{') {
                store.pop();
                break;
            }
            return "NO"; 
       
        case ']':
            if(!store.empty() && store.top() == '[') {
                store.pop();
                break;
            }
            return "NO";
        default:
            break;  
        }        
    }

   return store.empty() ? "YES" : "NO";
        
}
