#include <string>
#include <stack>
#include <vector>
using std::vector;
using std::stringstream;
using std::string;
using std::stack;

class Solution {
public:
    //origin solution, two slow
    string simplifyPath(string path) {
        string ret;
        stack<char> st;
        if(path.length() < 1) return path;
        //the absolution path from root /, first add it
        st.push('/'); //root dir
        int i = 0;
        while(i < path.length()){
            //'.' is special , if not dot, it is possible to add char to stack
            if(path[i] != '.'){
                if(path[i] == '/'){
                    //if char is '/' and not equal the top, add it to stack
                    if(st.top() != '/'){
                        st.push(path[i]);
                    }
                }else{
                    //if not '.' and '/', push to stack
                    st.push(path[i]);
                }
                //if the top is '/', just omit the continous '/' in sequence
                i++;
            }else{
                if(path[i] == '.'){
                    //test next next position is valid
                    if(i + 1 <= path.length() - 1){
                        //it there double dot '.' 
                        if(path[i + 1] == '.'){
                            //check the third char
                            if(i + 2 <= path.length() - 1){
                                // if third char is '/', "../" represent back to parent directory
                                if(path[i + 2] == '/'){
                                    //the absolution path, to avoid pop the root '/' 
                                    if(st.size() > 1){
                                        st.pop();//pop the top '/'
                                        while(st.top() != '/'){ // until to next '/'
                                            st.pop();
                                        }
                                    }
                                    i += 2;
                                }else{
                                    //this case alike /... or /..abc, this is invalid, push them all
                                    st.push(path[i]);
                                    st.push(path[i + 1]);
                                    st.push(path[i + 2]);
                                    i += 3;
                                }
                            }else{ 
                                //the double dot ".." is the end of string,back to parent directory
                                if(st.size() > 1){
                                    st.pop();
                                    while(st.top() != '/'){
                                        st.pop();
                                    }
                                }
                                i += 2; 
                            }
                        }else{
                            // only "./" represent the current directory, otherewise all is invalid
                            // and push them to stack;
                            if(path[i + 1] != '/'){
                                st.push(path[i]);
                            }
                            i++; //skip it
                        }
                    }else{
                        //if the dot is last one char, just skip the, '.' represent current directory
                        i++;
                    }
                }
            } 
        }
        //the last of path show its name directly without separated character, except root
        if(st.top() == '/' && st.size() > 1) st.pop();
        while(!st.empty()){
            ret.insert(ret.begin(), st.top());
            st.pop();
        }
        
        return ret;
    }

    //solution from leetcode
    string simplifyPath(string path) {
        stack<string> st;
        string tmp = "";
        if (path.empty()) return "";
        path += '/';
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!tmp.empty()) {
                    st.push(tmp);
                    tmp.clear();
                }
                while(i < path.size() && path[i] == '/') i++;
                i--;
            } else if (path[i] == '.') {
                int j = i;
                while(j < path.size() && path[j] == '.') {
                    j++;
                }
                if (j == i + 2 && (j == path.size() || path[j] == '/')) {
                    // is ".." to pop
                    if (!st.empty())
                        st.pop();
                    i = j - 1;
                } else if (j == i + 1 && (j == path.size() || path[j] == '/')) {
                    // is "." do noting
                    continue;
                } else {
                    // some path part, add to tmp
                    tmp += path.substr(i, j - i);
                    i = j - 1;
                }
            } else {
                tmp += path[i];
            }
        }
        string res = "";
        while(!st.empty()) {
            tmp.clear();
            tmp += "/";
            tmp +=st.top();
            st.pop();
            res = tmp + res;
        }
        if (res.empty()) return "/";
        return res;
    }

    //solution 2
    string simplifyPath(string path) {
        string res, t;
        stringstream ss(path);
        vector<string> v;
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") continue;
            if (t == ".." && !v.empty()) v.pop_back();
            else if (t != "..") v.push_back(t);
        }
        for (string s : v) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};