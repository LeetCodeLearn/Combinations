//
//  main.cpp
//  Combination
//
//  Created by 李佳 on 14/12/8.
//  Copyright (c) 2014年 LiJia. All rights reserved.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> resultVec;
        if(n != 0 && k != 0 && n >= k)
        {
            vector<int> curVec;
            doCombin(1, n, k, resultVec, curVec);
        }
        return resultVec;
    }
    
    void doCombin(int start, int end, int deep, vector<vector<int>> &resultVec, vector<int> &curVec)
    {
        for (int i = start; i <= end; ++i)
        {
            if (end - i + 1 < deep)
                return;
            curVec.push_back(i);
            if (deep - 1 == 0)
            {
                resultVec.push_back(curVec);
                curVec.pop_back();
            }
            else
            {
                doCombin(i + 1, end, deep - 1, resultVec, curVec);
                curVec.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution obj;
    vector<vector<int>> result = obj.combine(1, 1);
    printf("result");
    return 0;
}
