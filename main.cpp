#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(int argc, char **argv, char **envp){

        for (char **env = envp; *env != 0; env++) {
            char *thisEnv = *env;
            string Searched = argv[argc-1]; // required for toupper conversion
            string s(thisEnv);  // gets chars from pointer to a string
            bool sensetive;

            if (argc <= 1) {
                printf("%s\n", thisEnv);
            }   // Case without any arguments, just print all variables


            if (argc > 2) {     // converts all to upper and sets bool
                if (string(argv[argc - 2]) == "-i" or string(argv[argc - 3]) == "-i") {
                    transform(Searched.begin(), Searched.end(), Searched.begin(),
                              [](unsigned char c) { return toupper(c); });
                    sensetive = true;
                }
            }

            int found = s.find(Searched);
            if (found != string::npos){
                if (argc == 2 or argc == 3 and sensetive == true)   // basic keyword search, or keyword insensetive
                printf("%s\n", thisEnv);
                else{
                    if (string(argv[argc-2]) == "-n" or string(argv[argc-3]) == "-n")   // Copies until "=" to a new string and prints it
                    {
                        string s2;
                        int size = s.size();
                        for (int i = 0; i < size; i++){
                            if (s[i] != '='){
                                s2.push_back(s[i]);
                            }
                            else
                                break;
                        }
                        printf("%s\n",s2.c_str());
                    }
                }
            }
        }

    return 0;
}