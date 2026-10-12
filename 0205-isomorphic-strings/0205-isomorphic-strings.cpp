class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int sToT[256];
       int tToS[256];
       
       fill(sToT,sToT+256,-1);
       fill(tToS,tToS+256,-1);

       for(int i=0;i<s.size();i++){
        char a=s[i];
        char b=t[i];

        if(sToT[a]!= -1 && sToT[a]!= b){
            return false;
        }
        if(tToS[b]!= -1 && tToS[b]!= a){
            return false;
        }
        sToT[a]=b;
        tToS[b]=a;
        }
        return true;

    }
};