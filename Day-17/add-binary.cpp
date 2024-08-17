class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int carry = 0;

        int i=a.length()-1,j=b.length()-1;
        while(i>=0 && j>=0){
            if(a[i]=='0' && b[j]=='0'){
                carry==0?sum.push_back('0'):sum.push_back('1');
                carry = 0;
            }else if((a[i]=='1' && b[j]=='0') || (a[i]=='0' && b[j]=='1')){
                carry==1?sum.push_back('0'):sum.push_back('1');
            }else if(a[i]=='1' && b[j]=='1'){
                carry==1?sum.push_back('1'):sum.push_back('0');
                carry=1;
            }
            i--;
            j--;
        }

        while(i>=0){
            if(carry==1 && a[i]=='1'){
                sum.push_back('0');
                carry = 1;
            }else if(carry==1 && a[i]=='0'){
                sum.push_back('1');
                carry = 0;
            }else{
                sum.push_back(a[i]);
            }
            i--;
        }

        while(j>=0){
            if(carry==1 && b[j]=='1'){
                sum.push_back('0');
                carry = 1;
            }else if(carry==1 && b[j]=='0'){
                sum.push_back('1');
                carry = 0;
            }else{
                sum.push_back(b[j]);
            }
            j--;
        }

        if(carry==1) sum.push_back('1');

        reverse(sum.begin(),sum.end());
        return sum;
    }
};
