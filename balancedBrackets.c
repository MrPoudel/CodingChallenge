string isBalanced(string s) {
   
    stack<char> store;
    bool balanced = true;
   
    for (char x:s) {
        switch(x) {
        case '(':
             store.push(x);
             break;

        case ')':
            if(!store.empty() && store.top() == '(') {
                store.pop();
                break;
            }
            else {
                balanced = false;
                break;
            } 

        case '{':
             store.push(x);
             break;        

        case '}':
            if(!store.empty() && store.top() == '{') {
                store.pop();
                break;
            }
            else {
                balanced = false;
                break;
            }
   
        case '[': 
            store.push(x);
            break;

        case ']':
            if(!store.empty() && store.top() == '[') {
                store.pop();
                break;
            }
            else {
                balanced = false;
                break;
            }

        default:
            break;  
        }            
    }

    if(balanced) {      
        return "YES";
    }
    else{        
        return "NO";
    } 
        
}
