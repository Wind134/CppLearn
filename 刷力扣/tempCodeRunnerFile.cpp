vector<int> char_map(128, 0);    // 这一步覆盖所有的字符类型
    int maxLen = 0;                  // 最长字串初始值为0
    int left = 0;                    // 左标值
    for (int i = 0; i < s.size(); i++)
    {
        left = max(left, char_map[s[i]]);    
        char_map[s[i]] = i;                 // 记录下每一个遇到的s[i]字符的下标位，遇到之前重复的则更新下标
        maxLen = max(maxLen, i - left);
    }
    return maxLen;