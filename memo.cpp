#include <iostream>
#include <string>


using namespace std;

class LCS
{
public:
	int lcs_length_cal(string A,string B,int,int);
	void lcs_processing();
};

int helpermemo[100][100]={0};
int LCS::lcs_length_cal(string A,string B,int a,int b )
{
	
	
	if (a==0||b==0)
	{
		return 0;
	}
	if (helpermemo[a][b]!=0)
	{
		return helpermemo[a][b];
	}
	else
	{
		if (A[a-1]==B[b-1])
		{
			helpermemo[a][b]=lcs_length_cal(A,B,a-1,b-1)+1;
			return helpermemo[a][b];
		}
		else
		{
			helpermemo[a][b]=max(lcs_length_cal(A,B,a-1,b),lcs_length_cal(A,B,a,b-1));
			return helpermemo[a][b];
		}
	}


}

void LCS :: lcs_processing()
{
    string a="GAACGCCTTCAAGCCAATTATGATTGCTCGCTGCCATGAGAATGGATGTG";
    int k=a.length();
    string b= "AAGGTTTCGATCGAGGGAGAACTATGACGATGACAAAACTACAGCTAATT";
    int kk=b.length();

    cout<<"length of LCS is "<<lcs_length_cal(a,b,k,kk);
}

int main()
{
    LCS l ;
    l.lcs_processing(); 
    cout<<endl;
    return 0; 
}
