#include <iostream>
#include <string>


using namespace std;

class LCS
{
public:
	int lcs_length_cal(string,string);
	void lcs_processing();
};

int LCS::lcs_length_cal(string A,string B)
{
	
	int m=A.length();
	int n=B.length();
	int C[m+1][n+1]={0};
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if (i==0|| j==0)
				C[i][j]=0;
			else if (A[i-1]==B[j-1])
				C[i][j]=C[i-1][j-1]+1;
			else
				C[i][j]=max(C[i-1][j],C[i][j-1]);
		}
	}

	return C[m][n];
}

void LCS :: lcs_processing()
{
    string a="GAACGCCTTCAAGCCAATTATGATTGCTCGCTGCCATGAGAATGGATGTG";
    string b= "AAGGTTTCGATCGAGGGAGAACTATGACGATGACAAAACTACAGCTAATT";
    cout<<"length of LCS is "<<lcs_length_cal(a,b);
}
int main()


{
	LCS l;
	l.lcs_processing();
	cout<<endl;

	return 0;
}


