#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void PrintAllPermutations(vector<string> &permList,vector<string> &nameList) {
  unsigned int i;
  string tempname;
  if (nameList.size() == 0) {
    for (i = 0; i < permList.size(); i++) {
      cout << permList.at(i);
      if (i == permList.size() - 1) {
        cout << endl;
      } else {
        cout << ", ";
      }
    }
  }
  else {
    for(i = 0; i < nameList.size(); i++) {
      tempname = nameList.at(i);
      nameList.erase(nameList.begin() + i);
      permList.push_back(tempname);

      PrintAllPermutations(permList, nameList);

      nameList.insert(nameList.begin() + i, tempname);
      permList.pop_back();
    }
  }
}

int main() {
   vector<string> nameList;
   vector<string> permList;
   string name;

   cin >> name;
   while (name != "-1") {
     nameList.push_back(name);
     cin >> name;
   }
   
   PrintAllPermutations(permList, nameList);
   
   return 0;
}
