#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
bool isParenthesesValid(std::string& rString);
 
int main() {
    std::string textVariable(
        R"(asnkajnsasjn(dsdjncds) djnsndsanxhbsab "dskjdsnlkdns" fdnnjsaknjsdlsj sldcsdajn;lsjdncjska[sdkcs] sdlksdnjk <dsdcasdcscsd> {DSCS;JKDC;SK} DFL<VKDFVLK;JDF)"
    );
    std::cout << std::endl;
    std::cout << std::boolalpha <<  "Status: " << isParenthesesValid(textVariable) << std::endl;
 
    return 0;
}

bool isParenthesesValid(std::string& rString) {
    const std::map<char, char> mpParentheses {
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'"', '"'},
        {'>', '<'},
        {'`', '`'},
        {'\'', '\''}
    };
    
    bool parenthesesValidStatus = true;
    std::vector<char> listOfOpenParentheses {};

    for(auto& rChar: rString) {
        auto it_mpParentheses = std::find_if(mpParentheses.begin(), mpParentheses.end(), [&rChar] (const std::pair<char, char>& mpElement) 
        { 
            return mpElement.second == rChar; 
        });

        if( it_mpParentheses != mpParentheses.end() ) {
            listOfOpenParentheses.push_back(rChar);
        }
        else if( mpParentheses.find(rChar) != mpParentheses.end() ) {
            std::cout<< listOfOpenParentheses.back() << "/" << rChar << "   " ;
            if( listOfOpenParentheses.back()==mpParentheses.at(rChar) ) {
                listOfOpenParentheses.pop_back();
            }
            else {
                parenthesesValidStatus = false;
                break;
            }
        }
        else {
            /* Do Nothing */
        }
    }
    return parenthesesValidStatus;
}