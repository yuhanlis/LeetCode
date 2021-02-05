#include <vector>
#include <string>
using namespace std;
class Solution {
public:
bool exist(vector<vector<char> >& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtracking(board,word,i,j,0))
                return true;
            }
        }
        return false;
    }
bool backtracking(vector<vector<char> >& board,string word,int i,int j,int k){
       if(!(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]==word[k]))
       return false;
       if(k==word.size()-1)
       return true;
       board[i][j]='\0';
       bool res= 
            backtracking(board,word,i+1,j,k+1)||
            backtracking(board,word,i-1,j,k+1)||
            backtracking(board,word,i,j-1,k+1)||
            backtracking(board,word,i,j+1,k+1);
        board[i][j]=word[k];
        return res;
        }
};

int main(int argc, char const *argv[])
{
    char test[]={'A','B','C'};
    vector<char>temp(test,test+3);
    string word="ABC";
    vector< vector<char> > board;
    board.push_back(temp);
    board.push_back(temp);
    Solution a;
    a.exist(board,word);
    return 0;
}
