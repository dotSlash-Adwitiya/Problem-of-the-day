#include<bits/stdc++.h>
using namespace std;

long long convert(string str) {
  long long num = 0; 
  for(int i = 0; i < str.size(); i++){
      if(str[i] == '9') // * If the num consists of a 9 then it cannot be our ans
          return -1;
      num = num * 10 + str[i] - '0';
  }
  // cout << "Num is: " << num << endl;
  return num;
}

long long ExtractNumber(string sentence) {
  
  string temp = "";
  long long num = -1;
  
  for(int i = 0; i < sentence.size(); i++) {
      if(isdigit(sentence[i])){
          while(isdigit(sentence[i])) temp += sentence[i++];
      }
      if(i != 0 && !isdigit(sentence[i]) && isdigit(sentence[i - 1])) {
          
          // * Converted string to integer
          long long tempNum = convert(temp);
          
          // * Overwrite the larger one
          if(tempNum > num) num = tempNum;

          temp.clear();
      }
      else if(isdigit(sentence[i]) && sentence[i] == '9'){
              while(i < sentence.size() && isdigit(sentence[i])) i++;
              temp.clear();
      }
          
  }
  // * Its possible that the last num, at or till last index is the ans
  // * Which will not be included because 
  // * the 2nd IF Condition is written that way
  if(temp.size() != 0){
      long long tempNum = convert(temp);
      // * Overwrite the larger one
      if(tempNum > num) num = tempNum;
      
  }
  
  return num;
  
}