    #include<bits/stdc++.h>
    using namespace std;
    string removeDuplicates(string& s) {
        stack<char>ch;
        ch.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(s[i]!=ch.top()) ch.push(s[i]);
        }
        string t="";
        while(ch.size()>0){
            t+=ch.top();
            ch.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
    int main(){
        string s;
        cin>>s;
        string a=removeDuplicates(s);
        cout<<a;
    }