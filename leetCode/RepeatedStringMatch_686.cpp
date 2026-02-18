class Solution {
public:
    int repeatedStringMatch(string a, string b) {
      string temp = a;
      int count = 1;
      while(temp.length() < b.length()) {
        temp += a;
        count++;
      }
      if(temp.find(b) != string::npos) {
        return count;
      }
      temp += a;
      if(temp.find(b) != string::npos) {
        return count+1;
      }
      return -1;
    }
};

// not by me of course !!!!!!!!!
class OptimisedSolution{
public:
    int repeatedStringMatch(string a, string b) {

        int repeat = -1;
        int start = b.find(a);

        string temp = "";

        if(start < b.size()){

            repeat = 1;
            

            if(!isSuffix(a,b.substr(0,start))){
                return -1;
            }else{
                repeat += (start>0);
            }

            start += a.size();

            
      
            while(b.substr(start,a.size()) == a){

                ++repeat;

                start += a.size();
            }

            if(!isPrefix(a,b.substr(start))){
                return -1;
            }else{
                repeat += (start<b.size());
            }
        }

        int norepeat = -1;
        if(a.find(b)<a.size()){
            norepeat = 1;
        }else{
            string double_a = a + a;

            if(double_a.find(b)<double_a.size()){
                norepeat = 2;
            }
        }

        if(norepeat>-1 && repeat >-1){
            return min(norepeat, repeat);
        }

        return repeat == -1 ? norepeat : repeat;
    }

private:

    bool isSuffix(string source, string target){

        int n = source.size();
        int m = target.size();

        if(n<m){
            return false;
        }
        int i = n-1;
        int j = m-1;

        while(j>=0 && source[i] == target[j]){

            --i;
            --j;
        }

        return j<0;
    }

    bool isPrefix(string source, string target){

        int n = source.size();
        int m = target.size();

        if(n<m){
            return false;
        }
        int i = 0;
        int j = 0;

        while(j<m && source[i] == target[j]){

            ++i;
            ++j;
        }

        return j==m;
    }
};
