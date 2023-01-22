#include<bits/stdc++.h>
using namespace std;

vector<int> smallerInLeft(int arr[], int n){
    vector<int> v;
    stack<pair<int, int>> s;

    for(int i = 0;i<n;i++){
        if(s.empty() == true){
            v.push_back(-1);
        }

        else if(s.empty() == false && s.top().first < arr[i]){
            v.push_back(s.top().second);
        }

        else if(s.empty() == false && s.top().first >= arr[i]){
            while(s.empty() == false && s.top().first >= arr[i]){
                s.pop();
            }

            if(s.empty() == true){
                v.push_back(-1);
            }

            else if(s.top().first < arr[i]){
                v.push_back(s.top().second);
            }
        }

        s.push({arr[i], i});
    }

    return v;
}

vector<int> smallerInRight(int arr[], int n){
    vector<int> v;
    stack<pair<int, int>> s;

    for(int i = n - 1;i>=0;i--){
        if(s.empty() == true){
            v.push_back(-1);
        }

        else if(s.empty() == false && s.top().first < arr[i]){
            v.push_back(s.top().second);
        }

        else if(s.empty() == false && s.top().first >= arr[i]){
            while(s.empty() == false && s.top().first >= arr[i]){
                s.pop();
            }

            if(s.empty() == true){
                v.push_back(-1);
            }

            else if(s.top().first < arr[i]){
                v.push_back(s.top().second);
            }
        }

        s.push({arr[i], i});
    }

    reverse(v.begin(), v.end());
    return v;
}

int max(int a, int b){
    return a>b?a:b;
}

int tempMaxArea(vector<int> left, vector<int>right, int arr[], int n){
    int result = INT_MIN;

    for(int i = 0;i<n;i++){
        int term = 0;

        if(left[i] != -1 && right[i] != -1){
            term = right[i] - left[i] - 1;
        }

        else if(left[i] == -1 && right[i] != -1){
            term = right[i];
        }

        else if(right[i] == -1 && left[i] != -1){
            term = i - left[i];
        }

        else if(right[i] == -1 && left[i] == -1){
            term = 1;
        }

        int area = arr[i] * term;

        result = max(result, area);
    }

    return result;
}

int maxArea(){
    int matrix[4][4] = {
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}, 
        {1, 1, 0, 0}
    };

    int arr[4] = {0, 0, 0, 0};

    int result = INT_MIN;

    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(matrix[i][j] == 0){
                arr[j] = 0;
            }

            else{
                arr[j] += matrix[i][j];
            }
        }

        int area = tempMaxArea(smallerInLeft(arr, 4), smallerInRight(arr, 4), arr, 4);
        result = max(result, area);
    }

    return result;
}

int main(){
    int result = maxArea();

    cout<<result<<endl;
    return 0;
}