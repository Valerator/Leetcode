// Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

// In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

// The canonical path should have the following format:

// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
// Return the simplified canonical path.

 

// Example 1:

// Input: path = "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory name.

// Example 2:

// Input: path = "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

// Example 3:

// Input: path = "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string dir;
        string res;
        res.append("/"); //по условию этот элемент всегдадолжен быть в начале
        for (int i = 0; i < path.size(); i++) {
            dir.clear();
            while (path[i] == '/') //если слэш, то просто увеличиваем счетчик
                i++;
            while (i < path.size() && path[i] != '/') {//если стоит слэш, а до этого его не было, вставляем его
                dir.push_back(path[i]);
                i++;
            }
        
            if (dir.compare("..") == 0) { // если две точки, то не вставляем их
                if (!st.empty())
                    st.pop();           
            }
 
            else if (dir.compare(".") == 0) 
                continue;

            else if (dir.length() != 0)
                st.push(dir);//вставляем строку в стэк       
        }

        stack<string> st1;
        while (!st.empty()) {
            st1.push(st.top());
            st.pop();
        }
 
        while (!st1.empty()) {//из стэка вставляем в строку
           string temp = st1.top();
         
            if (st1.size() != 1)
               res.append(temp + "/");
            else
                res.append(temp);
 
            st1.pop();
        }
 
    return res;
    }
};
