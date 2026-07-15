class Solution {
public:
    string findWindow(unordered_map<char, int>&t_hm, unordered_map<char, int>& s_hm, string s, int l, int r){
        string ls="", rs="";
        if(t_hm.contains(s[l]) && t_hm.contains(s[r]) && s_hm[s[l]]-1 < t_hm[s[l]] && s_hm[s[r]]-1 < t_hm[s[r]]){
            return s.substr(l, r-l+1);
        }

        if(!t_hm.contains(s[l]) && !t_hm.contains(s[r])){
            return findWindow(t_hm, s_hm, s, l+1, r-1);
        }

        if(!t_hm.contains(s[l]) || s_hm[s[l]]>t_hm[s[l]]){
            s_hm[s[l]]-=1;
            ls = findWindow(t_hm, s_hm, s, l+1, r);
            s_hm[s[l]]+=1;
        }
        if(!t_hm.contains(s[r]) || s_hm[s[r]]>t_hm[s[r]]){
            s_hm[s[r]]-=1;
            rs = findWindow(t_hm, s_hm, s, l, r-1);
            s_hm[s[r]]+=1;
        }
        if(ls!="" && rs!=""){
            if(ls.size()<rs.size()){
                return ls;
            }else{
                return rs;
            }
        }else if(ls!=""){
            return ls;
        }else{
            return rs;
        }
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> t_hm, s_hm;
        for(char ch: t){
            t_hm[ch] += 1;
        }
        for(char ch: s){
            s_hm[ch] += 1;
        }
        for(char ch: t){
            if(t_hm[ch]>s_hm[ch])return "";
        }
        return findWindow(t_hm, s_hm, s, 0, s.size()-1);
    }
};
