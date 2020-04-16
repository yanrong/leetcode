#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        stack<char> st;
        st.push('/'); //root dir
        int i = 0;
        while(i < path.length()){
            //cout << "ch "<<path[i] << endl;
            if(path[i] != '.'){
                if(path[i] == '/'){
                    if(st.top() != '/'){
                        //cout <<"a" <<endl;
                        st.push(path[i]);
                    }
                    //cout <<"b" <<endl;
                }else{
                    //cout <<"c" <<endl;
                    st.push(path[i]);
                }
                //cout <<"d" <<endl;
                i++;
            }else{
                if(path[i] == '.'){
                    if(i <= path.length() - 1){
                        if(path[i + 1] == '.'){
                            //cout <<"e" <<endl;
                            if(st.size() > 1){
                                //cout << "es" <<endl;
                                st.pop();
                                while(st.top() != '/'){
                                    //cout <<"f" <<endl;
                                    st.pop();
                                }
                            }
                            i += 2;
                            //continue;
                        }else{
                            //cout <<"k" <<endl;
                            i++;
                        }
                    }else{
                        //cout <<"l" <<endl;
                        i++;
                    }
                }
            } 
        }
        if(st.top() == '/' && st.size() > 1) st.pop();
        while(!st.empty()){
            ret.insert(ret.begin(), st.top());
            st.pop();
        }
        
        return ret;
    }
};