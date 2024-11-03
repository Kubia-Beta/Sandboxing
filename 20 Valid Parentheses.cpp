class Solution {
public:
    bool isValid(string s) {
        vector<bool> closureFlag (s.size(), false);
        bool shouldBreak = false;
        if ((s[0] == ')') || (s[0] == ']') || (s[0] == '}')) { // if the first item closes
            return false; // then dont bother in continuing
        } // this is how you can get Ω(1)
        else if (s.size() % 2 != 0) { // If our size is odd
            return false; // we cannot have an odd number of open/close
        }

        for (int i = 0; i < s.length(); i++){
            if (true == shouldBreak){
                break;
            }
            char current = s[i];
            switch (current){
                case '(': // when we see a new unclosed statement
                    break;
                case '[':
                    break;
                case '{':
                    break;
                case ')': // when we see a new closing statement
                    if (s[i-1] == '('){ // lookback one char and find a match
                        closureFlag[i] = true;
                        closureFlag[i-1] = true;
                        break;
                    } else if (true == closureFlag[i-1]) { // if there is a prior match
                        int j = i-2; // hold a prior iterator
                        while (j > -1){ // in range of vector
                            if (false == closureFlag[j] && '(' != s[j]) { // if the preceding char is unclosed and not a match
                                closureFlag[i] = false;
                                shouldBreak = true;
                                break;
                            } else if (false == closureFlag[j] && '(' == s[j]){ // if preceding char is unclosed and a match
                                closureFlag[j] = true;
                                closureFlag[i] = true;
                                break;
                            } else {
                            j--;
                            }
                        }
                        break;
                    } else { // no match, break out of the for loop, we're done
                        closureFlag[i] = false;
                        shouldBreak = true;
                        break;
                    }
                case ']':
                    if (s[i-1] == '['){ // lookback one char and find a match
                        closureFlag[i] = true;
                        closureFlag[i-1] = true;
                        break;
                    } else if (true == closureFlag[i-1]) { // if there is a prior match
                        int j = i-2; // hold a prior iterator
                        while (j > -1){ // in range of vector
                            if (false == closureFlag[j] && '[' != s[j]) { // if the preceding char is unclosed and not a match
                                closureFlag[i] = false;
                                shouldBreak = true;
                                break;
                            } else if (false == closureFlag[j] && '[' == s[j]){ // if preceding char is unclosed and a match
                                closureFlag[j] = true;
                                closureFlag[i] = true;
                                break;
                            } else {
                            j--;
                            }
                        }
                        break;
                    } else { // no match, break out of the for loop, we're done
                        closureFlag[i] = false;
                        shouldBreak = true;
                        break;
                    }
                case '}':
                    if (s[i-1] == '{'){ // lookback one char and find a match
                        closureFlag[i] = true;
                        closureFlag[i-1] = true;
                        break;
                    } else if (true == closureFlag[i-1]) { // if there is a prior match
                        int j = i-2; // hold a prior iterator
                        while (j > -1){ // in range of vector
                            if (false == closureFlag[j] && '{' != s[j]) { // if the preceding char is unclosed and not a match
                                closureFlag[i] = false;
                                shouldBreak = true;
                                break;
                            } else if (false == closureFlag[j] && '{' == s[j]){ // if preceding char is unclosed and a match
                                closureFlag[j] = true;
                                closureFlag[i] = true;
                                break;
                            } else {
                            j--;
                            }
                        }
                        break;
                    } else { // no match, break out of the for loop, we're done
                        closureFlag[i] = false;
                        shouldBreak = true;
                        break;
                    }
            }
        } // End iteration of string

        for (int i = 0; i < closureFlag.size(); i++){ // Process the closure vector
            if (false == closureFlag[i]){ // If any of them are false
                return false; // then it cannot be closed
            }
        } // all items are true
        return true;
    }
};
